#ifndef CS2_PROJECT_RESIZE_BUFFERS_HPP
#define CS2_PROJECT_RESIZE_BUFFERS_HPP

namespace hooks
{
    namespace resize_buffers
    {
        inline hook::detour m_hook;

        HRESULT __stdcall hook( IDXGISwapChain* swap_chain, unsigned int buffer_count, unsigned int width, unsigned int height, DXGI_FORMAT new_format, unsigned int swap_chain_flags );

        void init( );
    }
}

#endif//CS2_PROJECT_RESIZE_BUFFERS_HPP
