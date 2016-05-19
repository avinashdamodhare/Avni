//////////////////////////////////////////////////////////////////////////////////////////////////////
// BasicShading
//////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _BASICSHADING_H_
#define _BASICSHADING_H_

#include <AvniInterfaces.h>

namespace Avni
{
	class Material_Basic : public AvniMaterial
	{
	public :
        Material_Basic();
		~Material_Basic();

		virtual void ApplyMaterial();
		virtual void SetObjectOrientation();
        virtual void Init();
        virtual void Uninit();

	private:
		Matrix4x4		m_pOrientation;
		AvniShader*		m_pVertexShader;
		AvniShader*		m_pPixelShader;
	};
}
#endif // _BASICSHADING_H_