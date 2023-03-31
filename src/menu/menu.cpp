#include "includes.hpp"

void menu::impl::init( )
{
    ImGui::CreateContext( );
    ImGuiIO &io = ImGui::GetIO( );
    ( void ) io;

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;// Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark( );

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init( g_interfaces.m_window );
    ImGui_ImplDX11_Init( g_interfaces.m_device, g_interfaces.m_device_context );
}

void menu::impl::render( )
{
    ImGui::ShowDemoWindow( nullptr );
}