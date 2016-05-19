/////////////////////////////////////////////////////////////////////////////////
// Singleton Implementation
/////////////////////////////////////////////////////////////////////////////////

#include "AvniInterfaces.h"
#include "Singletons.h"

namespace Avni
{
    SingletonsManager* SingletonsManager::m_Instance = NULL;

    SingletonsManager::SingletonsManager()
    {

    }

    SingletonsManager::~SingletonsManager()
    {

    }

    SingletonsManager & SingletonsManager::Get()
    {
        return *(Instance());
    }

    SingletonsManager* SingletonsManager::Instance()
    {
        if (!m_Instance)
            m_Instance = new SingletonsManager();

        return m_Instance;
    }

    void SingletonsManager::Destroy()
    {
        SAFE_DELETE(m_Instance);
    }
}