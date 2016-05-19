////////////////////////////////////////////////////////////////////////////////////////////
// Box class
////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _BOX_H_
#define _BOX_H

#include <AvniInterfaces.h>
#include <GameEngine/Actor/Actor.h>

namespace Avni
{
	class Box : public Actor
	{
	public:
		Box(Vector3D Pos, i32 _width, i32 height, i32 length);
		~Box();

		virtual void Init();
		virtual void Update(float _dt);
		virtual void Uninit();

	private:
		i32			        m_iWidth;
		i32			        m_iHeigth;
		i32			        m_iLength;
		Vector3D	        m_vOrientation;	// Rotation in radians on each axis

		char*		        m_MeshData;
        AvniMaterial*       m_Material;
        AvniMesh*           m_Mesh;
	};
}
#endif //_BOX_H