//////////////////////////////////////////////////////////////////////////////////////////////////////////
// VertexBuffer_D3D11
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _VERTEXBUFFER_D3D11_H_
#define _VERTEXBUFFER_D3D11_H_

#include <AvniInterfaces.h>
#include <d3d11.h>

namespace Avni
{
	class VertexBuffer_D3D11 : public AvniMesh
	{
	public:
		VertexBuffer_D3D11(AvniVertexType _type, i32 totalVertices, void* _meshdata, void* _indexdata, i32 totalindices);
		~VertexBuffer_D3D11();

		virtual void CreateIndexBuffer(void* _indexdata,i32 totalindices);
		virtual void SetVertexBuffer();
        virtual void DrawMesh();
	private:
		ID3D11Buffer*				m_pVertexBuffer;
		ID3D11Buffer*				m_pIndexBuffer;
		D3D_PRIMITIVE_TOPOLOGY		m_iVertexTopology;
		AvniVertexType				m_iVertexType;
		u32							m_iVertexStride;
        u32							m_iTotalIndices;
        u32							m_iStartIndice;
        u32							m_iBaseVertexLocation;
        u32                         m_iTotalVertices;
        u32                         m_iStartVertex;
	};
}
#endif