#include "includes.hpp"

__int64 __fastcall hooks::level_init::hook( void* ecx, __int64 a2 )
{
    g_interfaces.m_global_vars = utils::resolve_rip( signature::search( HASH( "client.dll" ), XOR( "48 8B 05 ? ? ? ? 48 8B D8 80 78 3D 00 75 1D 80 78 3C 00 75" ) ).get( ), 3, 7 ).deref( ).get< sdk::c_global_vars_base * >( );

    return m_hook.call_original< decltype( &hook ) >( )( ecx, a2 );
}

void hooks::level_init::init( )
{
    auto status = m_hook.create_hook( signature::search( HASH( "client.dll" ),
                                                         XOR( "48 89 5C 24 ? 57 48 83 EC 20 48 8B 0D ? ? ? ? 48 8B DA 45 33 C9" ) ).get< void * >( ), reinterpret_cast< void * >( &hook ) );

    assert_hook( status );
}