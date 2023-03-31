#ifndef CS2_PROJECT_COLLISION_PROPERTY_HPP
#define CS2_PROJECT_COLLISION_PROPERTY_HPP

namespace sdk
{
    class c_collision_property {
    public:
        SCHEMA( math::vec3_t, mins, "CCollisionProperty", "m_vecMins" )
        SCHEMA( math::vec3_t, maxs, "CCollisionProperty", "m_vecMaxs" )
    };
}

#endif//CS2_PROJECT_COLLISION_PROPERTY_HPP
