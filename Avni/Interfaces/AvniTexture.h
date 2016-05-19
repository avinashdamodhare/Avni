/////////////////////////////////////////////////////////////////////////////////////////////
// Avni Texture
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _AVNITEXTURE_H_
#define _AVNITEXTURE_H_

#include "AvniDefines.h"

namespace Avni
{
    class AvniTexture
    {
    public:
        virtual char*               GetTexturePath()          = 0;
        virtual AvniTextureFormat   GetTexturePixelFormat()   = 0;
        virtual i32                 GetTextureWidth()         = 0;
        virtual i32                 GetTextureHeight()        = 0;
    };
}
#endif
