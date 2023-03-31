#ifndef CS2_PROJECT_INTERFACES_HPP
#define CS2_PROJECT_INTERFACES_HPP

namespace sdk
{
    class c_render {
    public:
        PAD( 0x178 );
        IDXGISwapChain* m_swap_chain;
    };
}

namespace interfaces
{
    class impl {
    public:
        void init( );

        template< typename T >
        T create_interface( const hash32_t &module_name, const hash32_t &interface_name );

        HWND m_window = nullptr;
        ID3D11RenderTargetView *m_render_target_view = nullptr;
        ID3D11Device *m_device = nullptr;
        ID3D11DeviceContext *m_device_context = nullptr;
        IDXGISwapChain *m_swap_chain = nullptr;
        sdk::c_global_vars_base *m_global_vars = nullptr;
        sdk::c_client *m_client = nullptr;
        sdk::c_schema_system *m_schema_system = nullptr;
        sdk::c_render *m_render = nullptr;
        sdk::c_engine_client *m_engine_client = nullptr;
        sdk::c_csgo_input *m_csgo_input = nullptr;
        sdk::c_game_entity_system *m_game_entity_system = nullptr;
    };
}// namespace interfaces

inline interfaces::impl g_interfaces{ };

#endif//CS2_PROJECT_INTERFACES_HPP
