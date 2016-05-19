/////////////////////////////////////////////////////////////////////////////////////////
// Box implementation
/////////////////////////////////////////////////////////////////////////////////////////

#include "Box.h"
#include "GameEngine\Materials\Material_Basic.h"

namespace Avni
{
	Box::Box(Vector3D Pos, i32 _width, i32 height, i32 length)
	{
	}

	Box::~Box()
	{
	}

	void Box::Init()
	{
		m_MeshData = (char*)malloc(sizeof(Avni_Vertex_pos_diffuse)*4);
		Avni_Vertex_pos_diffuse* mesh = (Avni_Vertex_pos_diffuse*)(m_MeshData);

		Avni_Vertex_pos_diffuse vert[4];
		vert[0].vertex		= Vector4D(-1.0f, 1.0f, 0.0f,1.0f);
		vert[1].vertex		= Vector4D( 1.0f, 1.0f, 0.0f,1.0f);
		vert[2].vertex		= Vector4D( 1.0f,-1.0f, 0.0f,1.0f);
		vert[3].vertex		= Vector4D(-1.0f,-1.0f, 0.0f,1.0f);

		vert[0].diffuseColor = Vector3D(1.0f,0.0f,0.0f);
		vert[1].diffuseColor = Vector3D(0.0f,1.0f,0.0f);
		vert[2].diffuseColor = Vector3D(0.0f,0.0f,1.0f);
		vert[3].diffuseColor = Vector3D(1.0f,0.0f,1.0f);
		
		u32 indices[] =
		{
			0, 1, 3,
			3, 1, 2,
		};

        m_Mesh      = SINGLETONMANAGER->GetRenderer()->CreateMesh(VERTEXTYPE_POS_DIFFUSE, 4, vert,indices, 6);
        m_Material  = SINGLETONMANAGER->GetMaterialManager()->GetMaterial(MATERIALNAME_BASIC);
	}

	void Box::Update(float _dt)
	{
        AvniRenderable renderobj;
        renderobj.SetMaterial(m_Material);
        renderobj.SetMesh(m_Mesh);
        SINGLETONMANAGER->GetRenderer()->AddObjectrenderList(renderobj);
	}

	void Box::Uninit()
	{
		free(m_MeshData);
	}
}