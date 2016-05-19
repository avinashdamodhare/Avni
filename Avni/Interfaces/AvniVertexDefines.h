//////////////////////////////////////////////////////////////////////////////////////////////////
// VertexType Defines
//////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _VERTEXBUFFERDEFINES_H_
#define _VERTEXBUFFERDEFINES_H_

namespace Avni
{
	struct Avni_Vertex_pos_diffuse
	{
		Vector4D vertex;
		Vector3D diffuseColor;
	};

	class AvniMesh
	{
	public:
		virtual void CreateIndexBuffer(void* _indexdata,i32 totalindices) = 0;
		virtual void SetVertexBuffer() = 0;
        virtual void DrawMesh() = 0;
	};

	class AvniVertexLayoutManager
	{
	public:
		virtual void InitializeVertexLayouts() = 0;
		virtual void SetVertexLayout(AvniVertexType _type) = 0;
	};
}

#endif //_RENDERDEFINES_H_