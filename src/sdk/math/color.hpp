#ifndef CS2_PROJECT_COLOR_HPP
#define CS2_PROJECT_COLOR_HPP

namespace math
{
    class color {
    public:
        __forceinline color( int r, int g, int b, int a = 255 ) : r( r ), g( g ), b( b ), a( a ) { }
        __forceinline color( ) : r( 0.f ), g( 0.f ), b( 0.f ), a( 255 ) { }

        __forceinline color( color const &other, int a )
        {
            this->r = other.r;
            this->g = other.g;
            this->b = other.b;
            this->a = a;
        }

        unsigned char r, g, b, a;
    };
}// namespace math

#endif//CS2_PROJECT_COLOR_HPP
