#ifndef CS2_PROJECT_PRESENT_HPP
#define CS2_PROJECT_PRESENT_HPP

namespace hooks
{
    namespace present
    {
        inline hook::detour m_hook;

        HRESULT __stdcall hook( IDXGISwapChain *swap_chain, unsigned int sync_interval, unsigned int flags );

        void init( );
    }// namespace present
}// namespace hooks

#endif//CS2_PROJECT_PRESENT_HPP
