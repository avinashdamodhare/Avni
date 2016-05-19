///////////////////////////////////////////////////////////////////////////////
//   Renderer Implementation
///////////////////////////////////////////////////////////////////////////////
#include "GLRenderer.h"

namespace Avni
{
    AvniRenderer* GLRenderer::m_instance = NULL;

    GLRenderer::GLRenderer()
    {
    }

    GLRenderer::~GLRenderer()
    {
    }

    AvniRenderer* GLRenderer::Create()
    {
        if (!m_instance)
        {
            m_instance = new GLRenderer();
        }

        return m_instance;
    }

    void GLRenderer::Register()
    {

    }

    AvniResult GLRenderer::InitRenderer()
	{
        return AvniResult::Success;
	}

}

