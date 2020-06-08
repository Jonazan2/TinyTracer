#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "external/stb_image_write.h"


using byte = char;
using u32 = unsigned int;

struct RGBA
{
    byte R;
    byte G;
    byte B;
    byte A;
};

int main( int argc, char **argv )
{
    const char *filename = "test.bmp";

    /*
    
        0,0 +-------------------->
         +  +--------------------+
         |  |                    |
         |  |                    |
         |  |                    |
         |  |                    |
         |  |                    |
         |  |                    |
         |  |                    |
         v  +--------------------+

    */

    int w = 1024;
    int h = 720;

    RGBA *rgba = new RGBA[ w * h ];
    u32 size = sizeof( RGBA );

    for ( u32 row = 0; row < h; ++row )
    {
        for ( u32 column = 0; column < w; ++column )
        {
            const float rowRatio = row / static_cast< float >( h );
            const float columnRatio = column / static_cast< float >( w );

            const u32 index = row * w + column;

            rgba[ index ].R = static_cast< u32 >( 255 * rowRatio );
            rgba[ index ].G = static_cast< u32 >( 255 * columnRatio );
            rgba[ index ].B = static_cast< u32 >( 255 * 0.2f );
            rgba[ index ].A = static_cast< u32 >( 255 );
        }
    }

    constexpr u32 RGBA_FORMAT = 4;
    int result =  stbi_write_bmp(filename, w, h, RGBA_FORMAT, rgba);

    return 0;
}