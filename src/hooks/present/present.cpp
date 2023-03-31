#include "includes.hpp"

HRESULT __stdcall hooks::present::hook( IDXGISwapChain *swap_chain, unsigned int sync_interval, unsigned int flags )
{
    static bool init = false;

    if ( !init )
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

        g_menu.init( );
        g_render.init( );

        init = true;
    }

    ImGui_ImplDX11_NewFrame( );
    ImGui_ImplWin32_NewFrame( );
    ImGui::NewFrame( );

    g_visuals.run( );
    g_menu.render( );
    ImGui::Render( );

    g_interfaces.m_device_context->OMSetRenderTargets( 1, &g_interfaces.m_render_target_view, nullptr );
    ImGui_ImplDX11_RenderDrawData( ImGui::GetDrawData( ));

    return m_hook.call_original< decltype( &hook ) >( )( swap_chain, sync_interval, flags );
}

void hooks::present::init( )
{
    auto status = m_hook.create_hook( utils::get_method< void * >( g_interfaces.m_swap_chain, 8 ),
            reinterpret_cast< void * >( &hook ) );

    assert_hook( status );
}