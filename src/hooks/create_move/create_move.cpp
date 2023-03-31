#include "includes.hpp"

bool __fastcall hooks::create_move::hook( void *ecx, int slot, unsigned __int8 a3 )
{
    auto cmd = globals::cmd = g_interfaces.m_csgo_input->get_user_cmd( slot );

    if ( !cmd )
        return m_hook.call_original< decltype( &hook ) >( )( ecx, slot, a3 );

    g_movement.run( cmd );

    return m_hook.call_original< decltype( &hook ) >( )( ecx, slot, a3 );
}

void hooks::create_move::init()
{
    auto status = m_hook.create_hook( signature::search( HASH( "client.dll" ),
                                                         XOR( "48 8B C4 48 89 58 10 48 89 48 08 55 56 57 41 54 41 55" ) ).get< void * >( ), reinterpret_cast< void * >( &hook ) );

    assert_hook( status );
}