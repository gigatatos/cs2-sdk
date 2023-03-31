#ifndef CS2_PROJECT_LEVEL_INIT_HPP
#define CS2_PROJECT_LEVEL_INIT_HPP

namespace hooks
{
    namespace level_init
    {
        inline hook::detour m_hook;

        __int64 __fastcall hook( void* ecx, __int64 a2 );
        void init( );
    }
}


#endif//CS2_PROJECT_LEVEL_INIT_HPP
