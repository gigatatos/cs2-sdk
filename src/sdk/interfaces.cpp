#include "includes.hpp"

void interfaces::impl::init( )
{
    // interfaces.
    m_global_vars        = utils::resolve_rip( signature::search( HASH( "client.dll" ), XOR( "48 8B 05 ? ? ? ? 48 8B D8 80 78 3D 00 75 1D 80 78 3C 00 75" ) ).get( ), 3, 7 ).deref( ).get< sdk::c_global_vars_base * >( );
    m_game_entity_system = utils::resolve_rip( signature::search( HASH( "client.dll" ), XOR( "48 8B 05 ? ? ? ? 48 8B 88 ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50" ) ).get( ), 3, 7 ).deref( ).get< sdk::c_game_entity_system * >( );
    m_render             = utils::resolve_rip( signature::search( HASH( "rendersystemdx11.dll" ), XOR( "66 0F 7F 05 ? ? ? ? 66 0F 7F 0D ? ? ? ? 48 89 35 ? ? ? ?" ) ).get( ), 4, 8 ).deref( 2 ).get< sdk::c_render * >( );
    m_csgo_input         = utils::resolve_rip( signature::search( HASH( "client.dll" ), XOR( "48 8B 0D ? ? ? ? 48 8B 01 FF 50 18 8B DF 66 0F 1F 44 00 ? 48 8B 0D" ) ).get( ), 3, 7 ).deref( ).get< sdk::c_csgo_input * >( );
    m_swap_chain         = m_render->m_swap_chain;
    m_client             = create_interface< sdk::c_client * >( HASH( "client.dll" ), HASH( "Source2Client002" ) );
    m_schema_system      = create_interface< sdk::c_schema_system * >( HASH( "schemasystem.dll" ), HASH( "SchemaSystem_001" ) );
    m_engine_client      = create_interface< sdk::c_engine_client * >( HASH( "engine2.dll" ), HASH( "Source2EngineToClient001" ) );
}

template< typename T = void * >
T interfaces::impl::create_interface( const hash32_t &module_name, const hash32_t &interface_name )
{
    auto create_interface_fn = g_winapi.get_exported_function< __int64( __fastcall * )( const char *, DWORD * ) >( module_name, HASH( "CreateInterface" ) );

    if ( !create_interface_fn )
        return nullptr;

    using interface_callback_fn = void *( __cdecl * )( );

    struct interface_reg_t
    {
        interface_callback_fn m_callback;
        const char *m_name;
        interface_reg_t *m_next;
    };

    auto interface_list = utils::resolve_rip( reinterpret_cast< std::uint8_t * >( create_interface_fn ), 3,
                                              7 ).deref( ).get< interface_reg_t * >( );

    for ( auto it = interface_list; it; it = it->m_next ) {
        if ( HASH( it->m_name ) != interface_name )
            continue;

        auto callback = reinterpret_cast< T >( it->m_callback( ) );

        return callback;
    }

    return nullptr;
}