#ifndef CS2_PROJECT_MOVEMENT_HPP
#define CS2_PROJECT_MOVEMENT_HPP

namespace movement
{
    class impl {
    public:
        void run( sdk::c_user_cmd* cmd );
    };
}

inline movement::impl g_movement{ };

#endif//CS2_PROJECT_MOVEMENT_HPP
