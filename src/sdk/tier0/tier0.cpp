#include "includes.hpp"

void tier0::impl::console_color_msg( const math::color &color, const char *fmt, ... )
{
    static auto console_color_msg = g_winapi.get_exported_function< void( __cdecl * )( const math::color &, const char *, ... ) >( HASH( "tier0.dll" ), HASH( "?ConColorMsg@@YAXAEBVColor@@PEBDZZ" ) );

    if ( !console_color_msg )
        return;

    char buffer[ 1024 ]{ };
    va_list args;

    va_start( args, fmt );
    vsprintf_s( buffer, fmt, args );
    va_end( args );

    console_color_msg( color, buffer );
}