////////////////////////////////////////////////////////////////////////////////////////////////////////
// Rencerable Object
////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_

#include "AvniInterfaces.h"

namespace Avni
{
	class AvniRenderable
	{
	public:
        AvniRenderable();
        ~AvniRenderable();

        virtual void SetMaterial(AvniMaterial* _material)           { m_Material    = _material;        }
        virtual void SetTexture(AvniTexture* _texture)              { m_Texture     = _texture;         }
        virtual void SetMesh(AvniMesh* _meshname)                   { m_Mesh        = _meshname;        }

        virtual void ApplyMaterial();
        virtual void ApplyTexture();
        virtual void StartMesh();

        virtual void DrawMesh();
    private:
        AvniMaterial*           m_Material;
        AvniMesh*               m_Mesh;
        AvniTexture*            m_Texture;
	};
}

#endif