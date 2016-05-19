////////////////////////////////////////////////////////////////////////////////////////////////////////
// Basic Shading
////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Material_Basic.h"

namespace Avni
{
    Material_Basic::Material_Basic()
	{
	}

    Material_Basic::~Material_Basic()
	{

	}

    void Material_Basic::Init()
    {
        m_pVertexShader = SINGLETONMANAGER->GetRenderer()->CreateShader("BasicShader_vs",SHADERTYPE_VERTEX);
        m_pPixelShader  = SINGLETONMANAGER->GetRenderer()->CreateShader("BasicShader_ps",SHADERTYPE_PIXEL);
    }
    
    void Material_Basic::Uninit()
    {

    }

	void Material_Basic::ApplyMaterial()
	{
        m_pVertexShader->SetShader();
        m_pPixelShader->SetShader();
		SetObjectOrientation();
	}

	void Material_Basic::SetObjectOrientation()
	{

	}
}