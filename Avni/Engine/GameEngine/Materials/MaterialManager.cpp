/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MaterialManager
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "MaterialManager.h"
#include "Material_Basic.h"

namespace Avni
{
	MaterialManager::MaterialManager()
	{
	}

	MaterialManager::~MaterialManager()
	{
	}

	void MaterialManager::EnumerateMaterials()
	{
        m_pMaterials[MATERIALNAME_BASIC] = new Material_Basic();

		for (int i = 0; i < MATERIALNAME_MAX; i++)
		{
			m_pMaterials[i]->Init();
		}
	}

    AvniMaterial* MaterialManager::GetMaterial(AvniMaterialName _MaterialName)
	{
        switch (_MaterialName)
        {
            case MATERIALNAME_BASIC:
            {
                return m_pMaterials[_MaterialName];
            }
            default:
                LOG("UnRecognised Material",0);
        }
        return NULL;
	}

    void MaterialManager::ReleaseAllMaterials()
    {
        for (int i = 0; i < MATERIALNAME_MAX; i++)
        {
            SAFE_DELETE(m_pMaterials[i]);
        }
    }
}