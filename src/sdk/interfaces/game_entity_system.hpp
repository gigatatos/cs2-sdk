#ifndef CS2_PROJECT_GAME_ENTITY_SYSTEM_HPP
#define CS2_PROJECT_GAME_ENTITY_SYSTEM_HPP

namespace game
{
    template < typename T >
    __forceinline T get_entity_index( int index ) {
        static auto get_entity_index = utils::resolve_rip( signature::search( HASH( "client.dll" ), XOR( "E8 ? ? ? ? 48 8B C8 48 8B F8 E8 ? ? ? ? 48 8B D8 39" ) ).get( ), 1,  5 ).get< void* ( __fastcall * )( int ) >( );

        if ( !get_entity_index )
            return nullptr;

        return reinterpret_cast< T >( get_entity_index( index ) );
    }

    template < typename T >
    __forceinline T get_player_pawn( void* entity ) {
        static auto get_player_pawn = utils::resolve_rip( signature::search( HASH( "client.dll" ), XOR( "E8 ?? ?? ?? ?? 48 8B D0 48 85 C0 75 21" ) ).get( ), 1,  5 ).get< void* ( __fastcall * )( void* ) >( );

        if ( !get_player_pawn )
            return nullptr;

        return reinterpret_cast< T >( get_player_pawn( entity ) );
    }

    template < typename T >
    __forceinline T get_player_pawn_handle( uint16_t h ) {
        static auto get_player_pawn_handle = utils::resolve_rip( signature::search( HASH( "client.dll" ), XOR( "E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 4C 8B 00 48 8B D3 48 8B" ) ).get( ), 1,  5 ).get< void* ( __fastcall * )( int ) >( );

        if ( !get_player_pawn_handle )
            return nullptr;

        return reinterpret_cast< T >( get_player_pawn_handle( h ) );
    }
}

namespace sdk
{
    class c_game_entity_system {
    public:
    };
}

#endif//CS2_PROJECT_GAME_ENTITY_SYSTEM_HPP
