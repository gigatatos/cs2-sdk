#ifndef CS2_PROJECT_VECTOR_HPP
#define CS2_PROJECT_VECTOR_HPP

namespace math
{
    class vec2_t {
    public:
        vec2_t( ) = default;
        vec2_t( const float x, const float y ) : x( x ), y( y ) { }

        float x{ };
        float y{ };
    };

    struct vec4_t {
        float x, y, z, w;
    };

    class vec3_t {
    public:
        vec3_t( ) = default;
        vec3_t( float x, float y, float z ) : x( x ), y( y ), z( z ) { }

        void init( )
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }

        bool is_zero( )
        {
            return x == 0.0f && y == 0.0f && z == 0.0f;
        }

        void init( float x, float y, float z )
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        vec3_t( const float *v )
        {
            this->x = v[ 0 ];
            this->y = v[ 1 ];
            this->z = v[ 2 ];
        }

        float &operator[]( int i )
        {
            return (( float * ) this )[ i ];
        }

        float operator[]( int i ) const
        {
            return (( float * ) this )[ i ];
        }

        void zero( )
        {
            this->x = this->y = this->z = 0.0f;
        }

        bool operator==( const vec3_t &src ) const
        {
            return ( src.x == this->x ) && ( src.y == y ) && ( src.z == z );
        }

        bool operator!=( const vec3_t &src ) const
        {
            return ( src.x != this->x ) || ( src.y != y ) || ( src.z != z );
        }

        vec3_t &operator+=( const vec3_t &v )
        {
            this->x += v.x;
            this->y += v.y;
            this->z += v.z;

            return *this;
        }

        vec3_t &operator-=( const vec3_t &v )
        {
            this->x -= v.x;
            this->y -= v.y;
            this->z -= v.z;

            return *this;
        }

        vec3_t &operator*=( float fl )
        {
            this->x *= fl;
            this->y *= fl;
            this->z *= fl;

            return *this;
        }

        vec3_t &operator*=( const vec3_t &v )
        {
            this->x *= v.x;
            this->y *= v.y;
            this->z *= v.z;

            return *this;
        }

        vec3_t &operator/=( const vec3_t &v )
        {
            this->x /= v.x;
            this->y /= v.y;
            this->z /= v.z;

            return *this;
        }

        vec3_t &operator+=( float fl )
        {
            this->x += fl;
            this->y += fl;
            this->z += fl;

            return *this;
        }

        vec3_t &operator/=( float fl )
        {
            this->x /= fl;
            this->y /= fl;
            this->z /= fl;

            return *this;
        }

        vec3_t &operator-=( float fl )
        {
            this->x -= fl;
            this->y -= fl;
            this->z -= fl;

            return *this;
        }

        float length_2d( ) const
        {
            return std::sqrtf( this->x * this->x + this->y * this->y );
        }

        float length( ) const
        {
            return std::sqrtf( this->x * this->x + this->y * this->y + this->z * this->z );
        }

        float dist_to( const vec3_t &other )
        {
            vec3_t delta{ };

            delta.x = this->x - other.x;
            delta.y = this->y - other.y;
            delta.z = this->z - other.z;

            return delta.length( );
        }

        void normalize( )
        {
            float length = this->length( );

            if ( length != 0.0f ) {
                this->x /= length + std::numeric_limits< float >::epsilon( );
                this->y /= length + std::numeric_limits< float >::epsilon( );
                this->z /= length + std::numeric_limits< float >::epsilon( );
            }
        }

        float normalize_place( )
        {
            auto radius = std::sqrtf( x * x + y * y + z * z );
            auto iradius = 1.0f / ( radius + std::numeric_limits< float >::epsilon( ));

            x *= iradius;
            y *= iradius;
            z *= iradius;

            return radius;
        }

        vec3_t normalized( ) const
        {
            auto res = *this;
            auto l = res.length( );

            if ( l != 0.0f )
                res /= l;
            else
                res.x = res.y = res.z = 0.0f;

            return res;
        }

        vec3_t cross( const vec3_t &other ) const
        {
            return { this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z,
                     this->x * other.y - this->y * other.x };
        }

        float dot( const vec3_t &vec ) const
        {
            return { this->x * vec.x + this->y * vec.y + this->z * vec.z };
        }

        float length_2d_sqr( ) const
        {
            return this->x * this->x + this->y * this->y;
        }

        float length_sqr( ) const
        {
            return this->x * this->x + this->y * this->y + this->z * this->z;
        }

        float x, y, z;

        vec3_t &operator=( const vec3_t &vec )
        {
            this->x = vec.x;
            this->y = vec.y;
            this->z = vec.z;

            return *this;
        }

        vec3_t operator-( ) const
        {
            return vec3_t( -this->x, -this->y, -this->z );
        }

        vec3_t operator+( const vec3_t &v ) const
        {
            return vec3_t( this->x + v.x, this->y + v.y, this->z + v.z );
        }

        vec3_t operator-( const vec3_t &v ) const
        {
            return vec3_t( this->x - v.x, this->y - v.y, this->z - v.z );
        }

        vec3_t operator*( float fl ) const
        {
            return vec3_t( this->x * fl, this->y * fl, this->z * fl );
        }

        vec3_t operator*( const vec3_t &v ) const
        {
            return vec3_t( this->x * v.x, this->y * v.y, this->z * v.z );
        }

        vec3_t operator/( float fl ) const
        {
            return vec3_t( this->x / fl, this->y / fl, this->z / fl );
        }

        vec3_t operator/( const vec3_t &v ) const
        {
            return vec3_t( this->x / v.x, this->y / v.y, this->z / v.z );
        }
    };

    __forceinline vec3_t operator*( float lhs, const vec3_t &rhs )
    {
        return rhs * lhs;
    }

    __forceinline vec3_t operator/( float lhs, const vec3_t &rhs )
    {
        return rhs / lhs;
    }

} // namespace math

#endif //CS2_PROJECT_VECTOR_HPP
