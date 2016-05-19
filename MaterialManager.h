/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Shader Manager
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _MATERIALMANAGER_H_
#define _MATERIALMANAGER_H_

#include <AvniInterfaces.h>
#include <SingletonTemplate.h>

namespace Avni
{
	class MaterialManager : public SingletonTemplate<MaterialManager> , public AvniMaterialManager
	{
	public:
		MaterialManager();
		~MaterialManager();

		virtual void	        EnumerateMaterials();
        virtual AvniMaterial*	GetMaterial(AvniMaterialName _MaterialName);
        virtual void	        ReleaseAllMaterials();

	private:
        AvniMaterial*           m_pMaterials[MATERIALNAME_MAX];
	};
}
#endif