#ifndef CS2_PROJECT_CONSOLE_HPP
#define CS2_PROJECT_CONSOLE_HPP

namespace console
{
    class impl {
    public:
        FILE *stdout_file = nullptr;

        void init( );

        void shutdown( );
    };
}// namespace console

inline console::impl g_console{ };

#endif//CS2_PROJECT_CONSOLE_HPP
