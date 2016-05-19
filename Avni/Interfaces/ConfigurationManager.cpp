///////////////////////////////////////////////////////////////////////
//      Config Manager
///////////////////////////////////////////////////////////////////////
#include "ConfigurationManager.h"
#include "Engine\GameEngine\GameEngine.h"
#include "Singletons.h"
#include "Engine\Core\FileManager\FileManager.h"
#include "Engine\GameEngine\Materials\MaterialManager.h"
#ifdef WIN32
#include "Engine\Renderers\Renderer_D3D11\Renderer_D3D11.h"
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
        if (_config == Config_WIN32_Directx11)
        {
            SINGLETONMANAGER->SetRenderer(Renderer_D3D11::Instance());
        }
        else
        {
            // Implement the Config
        }

        SINGLETONMANAGER->SetEngine(GameEngine::Instance());
		SINGLETONMANAGER->SetFileManager(FileManager::Instance());
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
