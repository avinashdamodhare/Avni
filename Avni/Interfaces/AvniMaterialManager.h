//////////////////////////////////////////////////////////////////////////////////////////////
// AvniShader Manager
//////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _AVNIMaterialManager_H_
#define _AVNIMaterialManager_H_

#include "AvniDefines.h"

namespace Avni
{
    class AvniShader;
    class AvniMaterialManager
    {
    public:
        virtual void            EnumerateMaterials() = 0;
        virtual AvniMaterial*   GetMaterial(AvniMaterialName _MaterialName) = 0;
        virtual void	        ReleaseAllMaterials() = 0;
    };
}
#endif // _AVNIMaterialManager_H_
