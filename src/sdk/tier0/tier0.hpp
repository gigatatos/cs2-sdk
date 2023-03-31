#ifndef CS2_PROJECT_TIER0_HPP
#define CS2_PROJECT_TIER0_HPP

namespace tier0
{
    class impl {
    public:
        void console_color_msg( const math::color &color, const char *fmt, ... );
    };
}// namespace tier0

inline tier0::impl g_tier0{ };

#endif//CS2_PROJECT_TIER0_HPP