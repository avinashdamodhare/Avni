/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Material
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _MATERIAL_H_
#define _MATERIAL_H_

namespace Avni
{
	class AvniMaterial
	{
	public:
		virtual void ApplyMaterial() = 0;
        virtual void SetObjectOrientation() = 0;
        virtual void Init() = 0;
        virtual void Uninit() = 0;
	};
}
#endif