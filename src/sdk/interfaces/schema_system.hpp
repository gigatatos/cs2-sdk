#ifndef CS2_PROJECT_SCHEMA_SYSTEM_HPP
#define CS2_PROJECT_SCHEMA_SYSTEM_HPP

namespace sdk
{
    struct schema_class_info_data_t;
    class c_schema_system_type_scope;

    class c_schema_enum_binding {
    public:
        virtual const char *get_binding_name( ) = 0;
        virtual void *as_class_binding( ) = 0;
        virtual c_schema_enum_binding *as_enum_binding( ) = 0;
        virtual const char *get_binary_name( ) = 0;
        virtual const char *get_project_name( ) = 0;
    public:
        char *m_binding_name; // 0x0008
    };

    class c_schema_type {
    public:
        bool get_sizes( int* out_size1, uint8_t* unk_probably_not_size )
        {
            return reinterpret_cast< int( __thiscall* )( void*, int*, uint8_t* ) >( m_vtable[ 3 ] )( this, out_size1, unk_probably_not_size );
        }
    public:
        bool get_size( int* out_size ) {
            uint8_t smh = 0;
            return get_sizes( out_size, &smh );
        }
    public:
        uintptr_t* m_vtable; // 0x0000
        const char* m_name; // 0x0008
        c_schema_system_type_scope* m_type_scope; // 0x0010
        uint8_t m_type_category; // ETypeCategory 0x0018
        uint8_t m_atomic_category; // EAtomicCategory 0x0019

        // find out to what class pointer points.
        c_schema_type* get_ref_class( ) {
            if ( m_type_category != 1 )
                return nullptr;

            auto ptr = this->m_schema_type_;

            while ( ptr && ptr->m_type_category == 1 )
                ptr = ptr->m_schema_type_;

            return ptr;
        }

        struct array_t {
            uint32_t array_size;
            uint32_t unknown;
            c_schema_type* element_type_;
        };

        struct atomic_t { // same goes for CollectionOfT
            uint64_t gap[ 2 ];
            c_schema_type* template_typename;
        };

        struct atomic_tt {
            uint64_t gap[ 2 ];
            c_schema_type* templates[ 2 ];
        };

        struct atomic_i {
            uint64_t gap[ 2 ];
            uint64_t integer;
        };

        // this union depends on CSchema implementation, all members above
        // is from base class ( CSchemaType )
        union // 0x020
        {
            c_schema_type* m_schema_type_;
            schema_class_info_data_t* m_class_info;
            void* m_enum_binding_;
            array_t m_array_;
            atomic_t m_atomic_t_;
            atomic_tt m_atomic_tt_;
            atomic_i m_atomic_i_;
        };
    };

    struct schema_class_field_data_t {
        const char *m_name;// 0x0000
        c_schema_type *m_type; // 0x0008
        short m_offset;    // 0x0010
        PAD( 0xE );        // 0x0012
    };

    struct schema_class_info_data_t {
        PAD( 0x8 );                         // 0x0000
        const char *m_name;                 // 0x0008
        char *m_module;                     // 0x0010
        int m_size;                         // 0x0018
        __int16 m_field_size;               // 0x001C
        __int16 m_static_size;              // 0x001E
        __int16 m_metadata_size;            // 0x0020
        __int16 m_i_unk1;                   // 0x0022
        __int16 m_i_unk2;                   // 0x0024
        __int16 m_i_unk3;                   // 0x0026
        schema_class_field_data_t *m_fields;// 0x0028
    };

    struct schema_type_t {
        uintptr_t *m_vtable; // 0x0000
        const char *m_name; // 0x0008
    };

    struct schema_class_binding_t {
        schema_class_binding_t *parent;
        const char *m_binary_name; // ex: C_World
        const char *m_module_name; // ex: libclient.so
        const char *m_class_name; // ex: client
        void *m_class_info_old_synthesized;
        void *m_class_info;
        void *m_this_module_binding_pointer;
        schema_type_t *m_schema_type;
    };

    class c_schema_system_type_scope {
    public:
        __forceinline schema_class_info_data_t *find_type_declared_class( const char *name )
        {
            using find_type_declared_class_t = schema_class_info_data_t *( __thiscall * )( void *, const char * );
            return utils::get_method< find_type_declared_class_t >( this, 2 )( this, name );
        }

        __forceinline c_utl_ts_hash< schema_class_binding_t * > get_classes( )
        {
            return m_classes;
        }

    private:
        PAD( 0x8 ); // 0x0000
        std::array< char, 256 > m_name = { };
        PAD( 0x450 );
        c_utl_ts_hash< schema_class_binding_t * > m_classes; // 0x0558
        PAD( 0x2804 );
    };

    class c_schema_system {
    public:
        __forceinline c_schema_system_type_scope *global_type_scope( )
        {
            using global_type_scope_t = c_schema_system_type_scope *( __thiscall * )( void * );
            return utils::get_method< global_type_scope_t >( this, 11 )( this );
        }

        __forceinline c_schema_system_type_scope *find_type_scope_for_module( const char *module )
        {
            using find_type_scope_for_module_t = c_schema_system_type_scope *( __thiscall * )( void *, const char * );
            return utils::get_method< find_type_scope_for_module_t >( this, 13 )( this, module );
        }
    };
}// namespace sdk

#endif//CS2_PROJECT_SCHEMA_SYSTEM_HPP