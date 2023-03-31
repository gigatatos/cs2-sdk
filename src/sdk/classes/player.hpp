#ifndef CS2_PROJECT_PLAYER_HPP
#define CS2_PROJECT_PLAYER_HPP

namespace sdk
{
    class c_game_scene_node {
    public:
        SCHEMA( math::vec3_t, abs_origin, "CGameSceneNode", "m_vecAbsOrigin" )
    };

    class c_base_player_pawn_base {
    public:
        SCHEMA( flags_t, flags, "C_BaseEntity", "m_fFlags" )
        SCHEMA( movetype_t, move_type, "C_BaseEntity", "m_MoveType" )
        SCHEMA( c_game_scene_node*, game_scene_node, "C_BaseEntity", "m_pGameSceneNode" )
    };

    class c_base_player_pawn : public c_base_player_pawn_base {
    public:
        SCHEMA( int32_t, health, "C_BaseEntity", "m_iHealth" )
        SCHEMA( int32_t, max_health, "C_BaseEntity", "m_iMaxHealth" )
        SCHEMA( uint8_t, team, "C_BaseEntity", "m_iTeamNum" )
        SCHEMA( c_collision_property*, collision, "C_BaseEntity", "m_pCollision" )

        bool alive( );
    };

    class c_base_entity {
    public:
    };
}

#endif//CS2_PROJECT_PLAYER_HPP
