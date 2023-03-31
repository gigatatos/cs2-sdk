#ifndef CS2_PROJECT_RENDER_HPP
#define CS2_PROJECT_RENDER_HPP

namespace render
{
    class impl {
    public:
        math::vec2_t m_screen_size { };

        void init( );
        void rect_filled( int x, int y, int w, int h, math::color color );
        void rect_outlined( int x, int y, int w, int h, math::color color );
    };
}// namespace render

inline render::impl g_render{ };

#endif//CS2_PROJECT_RENDER_HPP
