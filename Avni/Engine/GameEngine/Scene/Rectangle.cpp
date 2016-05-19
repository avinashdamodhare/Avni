//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Rectangle
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Rectangle.h"

namespace Avni
{
	Rectangle::Rectangle(Vector3D firstPoint, Vector3D secondPoint, Vector3D thirdPoint)
	{
		m_vFirstPoint = firstPoint; m_vSecondPoint = secondPoint; m_vThirdPoint = thirdPoint;
	}

	Rectangle::~Rectangle()
	{
	}

	void Rectangle::Init()
	{
		Avni_Vertex_pos_diffuse vert[4];
		vert[0].vertex = Vector4D(-1.0f, 1.0f, 0.0f,1.0f);
		vert[1].vertex = Vector4D( 1.0f, 1.0f, 0.0f,1.0f);
		vert[2].vertex = Vector4D( 1.0f,-1.0f, 0.0f,1.0f);
		vert[3].vertex = Vector4D(-1.0f, -1.0f, 0.0f,1.0f);

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

	void Rectangle::Uninit()
	{

	}

	void Rectangle::Update(float _dt)
	{
		AvniRenderable render;
		render.SetMesh(m_Mesh);
		render.SetMaterial(m_Material);
		SINGLETONMANAGER->GetRenderer()->AddObjectrenderList(render);
	}
}