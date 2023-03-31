#include "includes.hpp"

HRESULT __stdcall hooks::resize_buffers::hook( IDXGISwapChain* swap_chain, unsigned int buffer_count, unsigned int width, unsigned int height, DXGI_FORMAT new_format, unsigned int swap_chain_flags )
{
    const auto hr = m_hook.call_original< decltype( &hook ) >( )( swap_chain, buffer_count, width, height, new_format, swap_chain_flags );

    g_interfaces.m_render_target_view->Release( );
    ImGui_ImplDX11_InvalidateDeviceObjects( );

    if ( SUCCEEDED( hr ) )
    {
        ID3D11Texture2D *render_target_texture = nullptr;

        swap_chain->GetDevice( __uuidof( ID3D11Device ), reinterpret_cast< void ** >( &g_interfaces.m_device ));
        g_interfaces.m_device->GetImmediateContext( &g_interfaces.m_device_context );
        swap_chain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), reinterpret_cast< void ** >( &render_target_texture ));

        D3D11_RENDER_TARGET_VIEW_DESC desc{ };
        memset( &desc, 0, sizeof( desc ) );
        desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2DMS;

        g_interfaces.m_device->CreateRenderTargetView( render_target_texture, &desc, &g_interfaces.m_render_target_view );
        render_target_texture->Release( );
        ImGui_ImplDX11_CreateDeviceObjects( );

        g_render.m_screen_size = {
            static_cast< float >( width ),
            static_cast< float >( height )
        };
    }

    return hr;
}

void hooks::resize_buffers::init( )
{
    auto status = m_hook.create_hook( utils::get_method< void * >( g_interfaces.m_swap_chain, 13 ),
                                      reinterpret_cast< void * >( &hook ) );

    assert_hook( status );
}