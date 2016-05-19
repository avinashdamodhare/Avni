//////////////////////////////////////////////////////////////////////////////////////
// Camera Implemetation
//////////////////////////////////////////////////////////////////////////////////////

#include "Camera.h"

namespace Avni
{
    Camera::Camera()
        : m_fAspectRatio(0.0f)
        , m_fFov(0.0f)
        , m_fZfar(1000.0f)
        , m_fZnear(1.0f)
    {
        m_WorldPos              = Vector3D(0.0f, 0.0f, -10.0f);
        m_lookAtPos             = Vector3D(0.0f, 0.0f, 0.0f);
        m_UpDir                 = Vector3D(0.0f, 1.0f, 0.0f);
    }

    Camera::~Camera()
    {

    }

    void Camera::Init()
    {
        m_fFov					= 0.75f;
        m_fAspectRatio			= SINGLETONMANAGER->GetRenderer()->GetRenderAspectRatio();
        MatrixGetCameraMatrix(m_ViewMatrix,m_WorldPos, m_lookAtPos, m_UpDir);
		MatrixGetProjectionMatrix(m_ProjectionMatrix,m_fFov,m_fAspectRatio,m_fZfar,m_fZnear);
        MatrixMul(m_ViewProjectionMatrix,m_ViewMatrix, m_ProjectionMatrix);
    }

	void Camera::Uninit()
	{

	}

	void Camera::Update(float _dt)
	{
		SINGLETONMANAGER->GetRenderer()->SetViewMat(m_ViewMatrix);
		SINGLETONMANAGER->GetRenderer()->SetViewProjMat(m_ViewProjectionMatrix);
	}
}