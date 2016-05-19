/////////////////////////////////////////////////////////////////////////////////////////////////
// AvniRenderable
/////////////////////////////////////////////////////////////////////////////////////////////////

#include "AvniRenderable.h"

namespace Avni
{
    AvniRenderable::AvniRenderable()
        : m_Material(NULL)
        , m_Mesh(NULL)
        , m_Texture(NULL)
    {

    }

    AvniRenderable::~AvniRenderable()
    {

    }

    void AvniRenderable::ApplyMaterial()
    {
        if(m_Material)
            m_Material->ApplyMaterial();
    }

    void AvniRenderable::ApplyTexture()
    {

    }

    void AvniRenderable::StartMesh()
    {
        if(m_Mesh)
            m_Mesh->SetVertexBuffer();
    }

    void AvniRenderable::DrawMesh()
    {
        if (m_Mesh)
            m_Mesh->DrawMesh();
    }
}