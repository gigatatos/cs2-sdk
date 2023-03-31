#ifndef CS2_PROJECT_FRAME_STAGE_NOTIFY_HPP
#define CS2_PROJECT_FRAME_STAGE_NOTIFY_HPP

namespace hooks
{
    namespace frame_stage_notify
    {
        inline hook::detour m_hook;

        void __fastcall hook( void *ecx, int a1 );

        void init( );
    }// namespace frame_stage_notify
}// namespace hooks

#endif//CS2_PROJECT_FRAME_STAGE_NOTIFY_HPP
