#include "includes.hpp"

void render::impl::init()
{
    m_screen_size = g_interfaces.m_engine_client->get_screen_size();
}

void render::impl::rect_filled( int x, int y, int w, int h, math::color color )
{
    ImGui::GetBackgroundDrawList()->AddRectFilled(
            ImVec2( ImFloor( x ), ImFloor( y ) ),
            ImVec2( ImFloor( x ) + ImFloor( w ), ImFloor( y ) + ImFloor( h ) ),
            ImColor{ color.r, color.g, color.b, color.a } );
}

void render::impl::rect_outlined( int x, int y, int w, int h, math::color color )
{
    ImGui::GetBackgroundDrawList()->AddRect(
            ImVec2( ImFloor( x ), ImFloor( y ) ),
            ImVec2( ImFloor( x ) + ImFloor( w ), ImFloor( y ) + ImFloor( h ) ),
            ImColor{ color.r, color.g, color.b, color.a } );
}