#include "includes.hpp"

void visuals::impl::run( )
{
    if ( !g_interfaces.m_engine_client->is_connected( ) || !g_interfaces.m_engine_client->is_in_game( ) )
        return;

    for ( int i = 1; i < g_interfaces.m_global_vars->m_max_clients; i++ ) {
        auto entity = game::get_entity_index< sdk::c_base_entity * >( i );

        if ( !entity )
            continue;

        auto pawn = game::get_player_pawn< sdk::c_base_player_pawn * >( entity );

        if ( !pawn || !pawn->alive( ) || pawn == globals::local || pawn->team( ) == globals::local->team( ) )
            continue;

        math::vec4_t bbox;

        if ( !get_box_bounds( pawn, bbox ) )
            continue;

        g_render.rect_outlined( bbox.x - 1, bbox.y - 1, bbox.z + 2, bbox.w + 2, { 0, 0, 0 } );
        g_render.rect_outlined( bbox.x, bbox.y, bbox.z, bbox.w, { 255, 255, 255 } );
        g_render.rect_outlined( bbox.x + 1, bbox.y + 1, bbox.z - 2, bbox.w - 2, { 0, 0, 0 } );
    }
}

bool visuals::impl::get_box_bounds( sdk::c_base_player_pawn *pawn, math::vec4_t &bbox )
{
    auto origin = pawn->game_scene_node( )->abs_origin( );

    math::vec3_t flb, brt, blb, frt, frb, brb, blt, flt;
    float left, top, right, bottom;

    auto min = pawn->collision( )->mins( ) + origin;
    auto max = pawn->collision( )->maxs( ) + origin;

    math::vec3_t points [ ] = {
            math::vec3_t( min.x, min.y, min.z ),
            math::vec3_t( min.x, min.y, max.z ),
            math::vec3_t( min.x, max.y, min.z ),
            math::vec3_t( min.x, max.y, max.z ),
            math::vec3_t( max.x, min.y, min.z ),
            math::vec3_t( max.x, min.y, max.z ),
            math::vec3_t( max.x, max.y, min.z ),
            math::vec3_t( max.x, max.y, max.z ),
    };

    if ( !math::world_to_screen( points[ 3 ], flb )
         || !math::world_to_screen( points[ 5 ], brt )
         || !math::world_to_screen( points[ 0 ], blb )
         || !math::world_to_screen( points[ 4 ], frt )
         || !math::world_to_screen( points[ 2 ], frb )
         || !math::world_to_screen( points[ 1 ], brb )
         || !math::world_to_screen( points[ 6 ], blt )
         || !math::world_to_screen( points[ 7 ], flt ) )
    {
        return false;
    }

    math::vec3_t arr [ ] = {
        flb,
        brt, 
        blb, 
        frt,
        frb, 
        brb, 
        blt, 
        flt 
    };

    left = flb.x;
    top = flb.y;
    right = flb.x;
    bottom = flb.y;

    for ( auto i = 1; i < 8; i++ ) {
        if ( left > arr[ i ].x )
            left = arr[ i ].x;

        if ( bottom < arr[ i ].y )
            bottom = arr[ i ].y;

        if ( right < arr[ i ].x )
            right = arr[ i ].x;

        if ( top > arr[ i ].y )
            top = arr[ i ].y;
    }

    bbox.x = static_cast< int >( left );
    bbox.y = static_cast< int >( top );
    bbox.z = static_cast< int >( right - left );
    bbox.w = static_cast< int >( bottom - top );

    return true;
}