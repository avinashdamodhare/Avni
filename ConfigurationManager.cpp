///////////////////////////////////////////////////////////////////////
//      Config Manager
///////////////////////////////////////////////////////////////////////
#include "ConfigurationManager.h"
#include "Engine\GameEngine\GameEngine.h"
#include "Singletons.h"
#include "Engine\GameEngine\Materials\MaterialManager.h"
#ifdef WIN32
#include "Engine\Core\FileManager\FileManager_Win32.h"
#include "Engine\Renderers\Renderer_D3D11\Renderer_D3D11.h"
#elif ORBIS
#include "Engine\Core\FileManager\FileManager_Orbis.h"
#include "Engine\Renderers\Renderer_Orbis\Renderer_Orbis.h"
#include "Engine\Core\MemoryManager\MemoryManager_Orbis.h"
#endif
namespace Avni
{
    

    ConfigurationManager::ConfigurationManager()
		: m_ShouldQuit(false)
    {
        
    }

    ConfigurationManager::~ConfigurationManager()
    {

    }

    void ConfigurationManager::Initialize(Run_Configurations _config)
    {
#ifdef WIN32
        if (_config == Config_WIN32_Directx11)
        {
            SINGLETONMANAGER->SetRenderer(Renderer_D3D11::Instance());
        }
        else
        {
            // Implement the Config
        }
		SINGLETONMANAGER->SetFileManager(FileManager_Win32::Instance());
#elif ORBIS
		SINGLETONMANAGER->SetRenderer(Renderer_Orbis::Instance());
		SINGLETONMANAGER->SetMemoryManager(MemoryManager_Orbis::Instance());
        SINGLETONMANAGER->SetFileManager(FileManager_Orbis::Instance());
#endif

        SINGLETONMANAGER->SetEngine(GameEngine::Instance());
        SINGLETONMANAGER->SetMaterialManager(MaterialManager::Instance());
    }

    bool ConfigurationManager::Update()
    {
        return SINGLETONMANAGER->GetEngine()->Update();
    }

    void ConfigurationManager::Uninitialize()
    {

    }
}
