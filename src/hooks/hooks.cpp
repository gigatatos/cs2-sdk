#include "includes.hpp"

void hooks::impl::init( )
{
    g_interfaces.m_window = FindWindowA( XOR( "SDL_app" ), nullptr );

    MH_Initialize( );
    {
        hooks::resize_buffers::init( );
        hooks::present::init( );
        hooks::wndproc::init( );
        hooks::level_init::init( );
        hooks::frame_stage_notify::init( );
        hooks::create_move::init( );
    }
    MH_EnableHook( MH_ALL_HOOKS );
}

void hooks::impl::shutdown( )
{
    // TODO: Fix crash on shutdown
    hooks::wndproc::shutdown( );

    MH_DisableHook( MH_ALL_HOOKS );
    MH_RemoveHook( MH_ALL_HOOKS );
    MH_Uninitialize( );
}