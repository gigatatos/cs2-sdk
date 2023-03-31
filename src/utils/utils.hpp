#ifndef CS2_PROJECT_UTILS_HPP
#define CS2_PROJECT_UTILS_HPP

namespace utils
{
    template< typename T >
    __forceinline T get_method( void *thisptr, uintptr_t idx )
    {
        return reinterpret_cast< T >(( *static_cast< uintptr_t ** >( thisptr ))[ idx ] );
    }

    signature resolve_rip( std::uint8_t *addr, std::uint32_t rva, std::uint32_t size );
}// namespace utils

#endif//CS2_PROJECT_UTILS_HPP
