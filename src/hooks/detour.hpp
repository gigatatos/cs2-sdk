#ifndef CS2_PROJECT_VMT_HPP
#define CS2_PROJECT_VMT_HPP

namespace hook
{
    class detour {
    public:
        __forceinline MH_STATUS create_hook( void *address, void *function )
        {
            auto status = MH_CreateHook( address, function, &this->m_original );

            return status;
        }

        template< typename T >
        __forceinline T call_original( )
        {
            return reinterpret_cast< T >( this->m_original );
        }

    private:
        void *m_original = nullptr;
    };
}// namespace hook

#define assert_hook( x )                                               \
    if ( x != MH_OK ) {                                                \
        return;                                                        \
    }                                                                  \
#endif//CS2_PROJECT_VMT_HPP