/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Vertex Buffer D3D11
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Renderer_D3D11.h"
#include "VertexBuffer_D3D11.h"

namespace Avni
{

	VertexBuffer_D3D11::VertexBuffer_D3D11(AvniVertexType _type, i32 totalVertices, void* _meshdata, void* _indexdata, i32 totalindices)
		: m_pIndexBuffer(NULL)
		, m_pVertexBuffer(NULL)
		, m_iVertexType(VERTEXTYPE_MAX)
		, m_iVertexTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST)
        , m_iTotalIndices(totalindices)
        , m_iStartIndice(0)
        , m_iBaseVertexLocation(0)
        , m_iTotalVertices(totalVertices)
        , m_iStartVertex(0)
	{
		m_iVertexType = _type;

		D3D11_BUFFER_DESC bufferdesc;
		ZeroMemory(&bufferdesc, sizeof(bufferdesc));
		bufferdesc.Usage                = D3D11_USAGE_DEFAULT;
		bufferdesc.BindFlags            = D3D11_BIND_VERTEX_BUFFER;
		bufferdesc.CPUAccessFlags       = 0;

		D3D11_SUBRESOURCE_DATA InitData;
		ZeroMemory(&InitData, sizeof(InitData));

		if(m_iVertexType == VERTEXTYPE_POS_DIFFUSE)
		{
			m_iVertexStride					= 1* sizeof(Avni_Vertex_pos_diffuse);
			bufferdesc.ByteWidth            = m_iVertexStride * totalVertices;
			InitData.pSysMem				= _meshdata;
			RENDERERD3D11->GetDevice()->CreateBuffer(&bufferdesc, &InitData, &m_pVertexBuffer);

			if(_indexdata)
			{
				CreateIndexBuffer(_indexdata, totalindices);
			}
		}
	}

	VertexBuffer_D3D11::~VertexBuffer_D3D11()
	{
		SAFE_RELEASE(m_pVertexBuffer);
		SAFE_RELEASE(m_pIndexBuffer);
	}

	void VertexBuffer_D3D11::CreateIndexBuffer(void* _indexdata,i32 totalindices)
	{
		D3D11_BUFFER_DESC bufferdesc;
		ZeroMemory(&bufferdesc, sizeof(bufferdesc));
		bufferdesc.Usage                = D3D11_USAGE_DEFAULT;
		bufferdesc.BindFlags            = D3D11_BIND_INDEX_BUFFER;
		bufferdesc.CPUAccessFlags       = 0;

		D3D11_SUBRESOURCE_DATA InitData;
		ZeroMemory(&InitData, sizeof(InitData));

		bufferdesc.ByteWidth            = sizeof(u32) * totalindices;
		InitData.pSysMem				= _indexdata;

		RENDERERD3D11->GetDevice()->CreateBuffer(&bufferdesc, &InitData, &m_pIndexBuffer);
	}

    void VertexBuffer_D3D11::DrawMesh()
    {
        if (m_pIndexBuffer)
            RENDERERD3D11->GetImmediateContext()->DrawIndexed(m_iTotalIndices, m_iStartIndice, m_iBaseVertexLocation);
        else
            RENDERERD3D11->GetImmediateContext()->Draw(m_iTotalVertices,m_iStartVertex);

    }

	void VertexBuffer_D3D11::SetVertexBuffer()
	{
        RENDERERD3D11->SetVertexLayout(VERTEXTYPE_POS_DIFFUSE);
		if(m_pIndexBuffer)
			RENDERERD3D11->GetImmediateContext()->IASetIndexBuffer(m_pIndexBuffer,DXGI_FORMAT_R32_UINT,0);
		if(m_pVertexBuffer)
		{
			u32 offset = 0;
			RENDERERD3D11->GetImmediateContext()->IASetVertexBuffers(0,1,&m_pVertexBuffer,&m_iVertexStride,&offset);
		}

		// Topology
		RENDERERD3D11->GetImmediateContext()->IASetPrimitiveTopology(m_iVertexTopology);
	}
}