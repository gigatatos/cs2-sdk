#include "includes.hpp"

void __fastcall hooks::frame_stage_notify::hook( void *ecx, int a1 )
{
    m_hook.call_original< decltype( &hook ) >( )( ecx, a1 );

    int stage = a1 - 1; // stages go up to 8.

    globals::local = ( g_interfaces.m_engine_client->is_connected( ) && g_interfaces.m_engine_client->is_in_game( ) ) ? game::get_player_pawn_handle< sdk::c_base_player_pawn* >( 0 ) : nullptr;
}

void hooks::frame_stage_notify::init( )
{
    auto status = m_hook.create_hook( signature::search( HASH( "client.dll" ),
                                                         XOR( "48 89 5C 24 ? 56 48 83 EC 30 8B 05 ? ? ? ? 8D 5A FF 3B C2 48" ) ).get< void * >( ), reinterpret_cast< void * >( &hook ) );

    assert_hook( status );
}