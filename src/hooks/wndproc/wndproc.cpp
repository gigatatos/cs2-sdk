#include "includes.hpp"

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );

LRESULT __stdcall hooks::wndproc::hook( HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam )
{
    if ( ImGui_ImplWin32_WndProcHandler( hwnd, msg, wparam, lparam ) )
        return true;

    return CallWindowProcA( m_hook_original, hwnd, msg, wparam, lparam );
}

void hooks::wndproc::init( )
{
    m_hook_original = reinterpret_cast< WNDPROC >( SetWindowLongPtrA( g_interfaces.m_window, GWLP_WNDPROC,
                                                                      reinterpret_cast< LONG_PTR >( hook ) ) );
}

void hooks::wndproc::shutdown( )
{
    SetWindowLongPtrA( g_interfaces.m_window, GWLP_WNDPROC, reinterpret_cast< LONG_PTR >( m_hook_original ) );
}