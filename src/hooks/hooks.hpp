#ifndef CS2_PROJECT_HOOKS_HPP
#define CS2_PROJECT_HOOKS_HPP

namespace hooks
{
    class impl {
    public:
        void init( );
        void shutdown( );
    };
}// namespace hooks

inline hooks::impl g_hooks{ };

#endif//CS2_PROJECT_HOOKS_HPP
