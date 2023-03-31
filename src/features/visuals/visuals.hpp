#ifndef CS2_PROJECT_VISUALS_HPP
#define CS2_PROJECT_VISUALS_HPP

namespace visuals
{
    class impl {
    public:
        bool get_box_bounds( sdk::c_base_player_pawn *pawn, math::vec4_t &bbox );
        void run( );
    };
}// namespace visuals

inline visuals::impl g_visuals{ };

#endif//CS2_PROJECT_VISUALS_HPP
