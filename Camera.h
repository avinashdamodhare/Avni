////////////////////////////////////////////////////////////////////////////////
// Camera Class
////////////////////////////////////////////////////////////////////////////////
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <AvniInterfaces.h>
#include <GameEngine\Actor\Actor.h>

namespace Avni
{
    class Camera : public Actor
    {
    public:
        Camera();
        ~Camera();

		void GetViewProjectionMatrix(Matrix4x4 & mat)	{ mat = m_ViewProjectionMatrix; }
		void GetProjectionMatrix(Matrix4x4 & mat)		{ mat = m_ProjectionMatrix;		}
		void GetViewMatrix(Matrix4x4 & mat)				{ mat = m_ViewMatrix;			}

		virtual void Init();
		virtual void Update(float _dt);
		virtual void Uninit();

    private:

        float           m_fFov;
        float           m_fAspectRatio;
        float           m_fZnear;
        float           m_fZfar;
        Vector3D        m_lookAtPos;
        Vector3D        m_UpDir;

        // We will not have World Matrix as we will consider the world having the origin always at (0,0,0).
        Matrix4x4       m_ViewMatrix;
        Matrix4x4       m_ProjectionMatrix;
        Matrix4x4       m_ViewProjectionMatrix;
    };
}

#endif
