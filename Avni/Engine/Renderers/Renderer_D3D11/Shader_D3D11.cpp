////////////////////////////////////////////////////////////////////////////////////////////////////////
// Shader D3D11
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Renderer_D3D11.h"
#include "Shader_D3D11.h"
#include "ShaderConstBufferManager.h"

namespace Avni
{
	Shader_D3D11::Shader_D3D11(char* _Shadername, AvniShaderType _type)
	{
		m_iShaderType = _type;
		if(m_iShaderType == SHADERTYPE_VERTEX)
		{
			// VertexShader
			AvniFile* File = SINGLETONMANAGER->GetFileManager()->ReadFile(_Shadername);
            if (!File)
                __debugbreak();
            CHECK_DEVICE_ERRORS(RENDERERD3D11->GetDevice()->CreateVertexShader(File->GetFileData(),File->GetFileSize(),NULL,&m_pShader.m_pVertexShader));
			SINGLETONMANAGER->GetFileManager()->CloseFile(File);
		}
		else if(m_iShaderType = SHADERTYPE_PIXEL)
		{
			// PixelShader
			AvniFile* File = SINGLETONMANAGER->GetFileManager()->ReadFile(_Shadername);
            CHECK_DEVICE_ERRORS(RENDERERD3D11->GetDevice()->CreatePixelShader(File->GetFileData(),File->GetFileSize(),NULL,&m_pShader.m_pPixelShader));
			SINGLETONMANAGER->GetFileManager()->CloseFile(File);
		}
	}

	Shader_D3D11::~Shader_D3D11()
	{

	}

	void Shader_D3D11::SetShader()
	{
        if (m_iShaderType == SHADERTYPE_VERTEX)
        {
            RENDERERD3D11->GetImmediateContext()->VSSetShader(m_pShader.m_pVertexShader, NULL, 0);
        }
		else if(m_iShaderType == SHADERTYPE_PIXEL)
        {
            RENDERERD3D11->GetImmediateContext()->PSSetShader(m_pShader.m_pPixelShader, NULL, 0);
        }
		ShaderConstantBufferManager::Instance()->SetShaderConstant(CONSTANTBUFFERTYPE_VERTEX_COMMON);
	}

	void Shader_D3D11::SetShaderConstantf(i32 shaderregisterno, Vector4D _constant)
	{

	}

	void Shader_D3D11::SetShaderConstanti(i32 shaderregisterno, Vector4D _constant)
	{

	}
}