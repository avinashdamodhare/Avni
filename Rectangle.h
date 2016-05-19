////////////////////////////////////////////////////////////////////////////////////////////////////////
// Basic Rectangle
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <AvniInterfaces.h>
#include "GameEngine/Actor/Actor.h"

namespace Avni
{
	class Rectangle : public Actor
	{
	public:
		Rectangle(Vector3D firstPoint, Vector3D secondPoint, Vector3D thirdPoint);
		~Rectangle();

		virtual void Init();
		virtual void Update(float _dt);
		virtual void Uninit();

	private:
		Vector3D	        m_vFirstPoint;
		Vector3D	        m_vSecondPoint;
		Vector3D	        m_vThirdPoint;

		char*		        m_MeshData;
		AvniMaterial*       m_Material;
		AvniMesh*           m_Mesh;
	};
}