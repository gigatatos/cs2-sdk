#include "includes.hpp"

void console::impl::init( )
{
    AllocConsole( );
    freopen_s( &stdout_file, "CONOUT$", "w", stdout );
}

void console::impl::shutdown( )
{
    fclose( reinterpret_cast< FILE * >( GetStdHandle( STD_OUTPUT_HANDLE ) ) );
    FreeConsole( );
}