#ifndef CS2_PROJECT_SCHEMA_MANAGER_HPP
#define CS2_PROJECT_SCHEMA_MANAGER_HPP

#define SCHEMA( type, function, class, prop ) \
__forceinline type& function( ) \
{ \
    const auto offset = g_schema.get_schema_offset( HASH( class ), HASH( prop ) );  \
    return *reinterpret_cast< type* >( reinterpret_cast< uintptr_t >( this ) + offset ); \
} \

namespace schema
{
    struct schema_offset_t {
        hash32_t m_class;
        hash32_t m_prop;
        short m_offset;
    };

    inline std::unordered_map< hash32_t, std::unordered_map< hash32_t, schema_offset_t > > g_schema_data;

    class impl {
    public:
        short get_schema_offset( const hash32_t& class_hash, const hash32_t& prop_hash );
        void  init( );
    };
}// namespace schema

inline schema::impl g_schema{ };

#endif//CS2_PROJECT_SCHEMA_MANAGER_HPP
