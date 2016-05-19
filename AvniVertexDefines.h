//////////////////////////////////////////////////////////////////////////////////////////////////
// VertexType Defines
//////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _VERTEXBUFFERDEFINES_H_
#define _VERTEXBUFFERDEFINES_H_

namespace Avni
{
    typedef enum 
    {
        VertexPos,
        VertexColor
    } AvniVertexAttribute;

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

        virtual i32  GetVertexSize(AvniVertexType _type)
        {
            switch (_type)
            {
            case VERTEXTYPE_POS_DIFFUSE:
                {
                    return sizeof(Avni_Vertex_pos_diffuse);
                }
                break;
            default:
                return 0;
                break;
            }
        }

        virtual i32  GetTotalVertexAttr(AvniVertexType _type)
        {
            switch (_type)
            {
            case VERTEXTYPE_POS_DIFFUSE:
                {
                    return 2;
                }
                break;
            default:
                return 0;
                break;
            }
        }
	};

	class AvniVertexLayoutManager
	{
	public:
		virtual void InitializeVertexLayouts() = 0;
		virtual void SetVertexLayout(AvniVertexType _type) = 0;
	};
}

#endif //_RENDERDEFINES_H_