#ifndef CS2_PROJECT_MENU_HPP
#define CS2_PROJECT_MENU_HPP

namespace menu
{
    class impl {
    public:
        void init( );

        void render( );
    };
}// namespace menu

inline menu::impl g_menu{ };

#endif//CS2_PROJECT_MENU_HPP
