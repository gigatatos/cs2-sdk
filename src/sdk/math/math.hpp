#ifndef CS2_PROJECT_MATH_HPP
#define CS2_PROJECT_MATH_HPP

namespace math
{
    bool world_to_screen( math::vec3_t &origin, math::vec3_t &out );

    class impl {
    public:
        void init( );
    };
} // namespace math

inline math::impl g_math{ };

#endif //CS2_PROJECT_MATH_HPP
