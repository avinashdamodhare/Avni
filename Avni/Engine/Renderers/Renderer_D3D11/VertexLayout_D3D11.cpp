/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Vertex Layout D3D11
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Renderer_D3D11.h"
#include "VertexLayout_D3D11.h"

namespace Avni
{
	VertexLayout_D3D11::VertexLayout_D3D11()
	{

	}

	VertexLayout_D3D11::~VertexLayout_D3D11()
	{

	}

	void VertexLayout_D3D11::InitializeVertexLayouts()
	{
		// Vertex the input layout
		D3D11_INPUT_ELEMENT_DESC layout[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "COLOR"	, 0, DXGI_FORMAT_R32G32B32_FLOAT   , 0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		};

		AvniFile* File = SINGLETONMANAGER->GetFileManager()->ReadFile("Shaders\\BasicShader_vs.cso");
		HRESULT res = RENDERERD3D11->GetDevice()->CreateInputLayout(layout, 2, File->GetFileData(), File->GetFileSize(), &m_pInputLayot[VERTEXTYPE_POS_DIFFUSE]);
		SINGLETONMANAGER->GetFileManager()->CloseFile(File);
	}

	void VertexLayout_D3D11::SetVertexLayout(AvniVertexType _type)
	{
		switch(_type)
		{
			case VERTEXTYPE_POS_DIFFUSE:
			{
				RENDERERD3D11->GetImmediateContext()->IASetInputLayout(m_pInputLayot[VERTEXTYPE_POS_DIFFUSE]);
			}
		}
	}
}
