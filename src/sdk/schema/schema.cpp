#include "includes.hpp"

void schema::impl::init( )
{
    std::deque< const char * > schema_modules = { XOR( "client.dll" ),
                                                  XOR( "engine2.dll" ),
                                                  XOR( "schemasystem.dll" )
    }; // not nessecary to hardcode module names.

    for ( auto & module : schema_modules ) {
        auto schema_class = g_interfaces.m_schema_system->find_type_scope_for_module( module );

        if ( !schema_class )
            continue;

        auto classes = schema_class->get_classes( );

        for ( const auto class_binding : classes.GetElements( ) ) {
            auto client_class_info = schema_class->find_type_declared_class( class_binding->m_binary_name );

            if ( !client_class_info )
                continue;

            auto field_hash = HASH( class_binding->m_binary_name );

            for ( auto j = 0; j < client_class_info->m_field_size; j++ ) {
                const auto field = &client_class_info->m_fields[ j ];

                if ( !field )
                    continue;

                auto ptr = field->m_type->get_ref_class( );
                auto actual_type = ptr ? ptr : field->m_type;
                auto name_hash = HASH( field->m_name );

                g_schema_data[ field_hash ][ name_hash ].m_class = field_hash;
                g_schema_data[ field_hash ][ name_hash ].m_prop = name_hash;
                g_schema_data[ field_hash ][ name_hash ].m_offset = field->m_offset;
            }
        }
    }

}

short schema::impl::get_schema_offset( const hash32_t& class_hash, const hash32_t& prop_hash )
{
    return g_schema_data[ class_hash ][ prop_hash ].m_offset;
}