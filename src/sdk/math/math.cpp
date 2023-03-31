#include "includes.hpp"

void math::impl::init( )
{
    // initialize math exports.
}

bool math::world_to_screen( math::vec3_t &origin, math::vec3_t &out )
{
    static auto world_to_screen_internal = utils::resolve_rip( signature::search( HASH( "client.dll" ), XOR( "E8 ? ? ? ? F3 0F 10 45 ? 8B D0" ) ).get( ), 1, 5 ).get< bool( __fastcall * )( math::vec3_t &, math::vec3_t & ) >( );

    if ( !world_to_screen_internal )
        return false;

    auto ret = !( world_to_screen_internal( origin, out ) );

    out.x = ( ( out.x + 1.0 ) * 0.5 ) * ( float ) g_render.m_screen_size.x;
    out.y = ( float ) g_render.m_screen_size.y - ( ( ( out.y + 1.0 ) * 0.5 ) * ( float ) g_render.m_screen_size.y );

    return ret;
}