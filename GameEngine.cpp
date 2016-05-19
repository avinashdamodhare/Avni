#include "GameEngine.h"
#include "AvniInterfaces.h"
#include "HPTimer.h"
#include "Scene/Scene.h"
#include "Scene/Box.h"
#include "Scene/Rectangle.h"
#include "Scene/Camera.h"

namespace Avni
{
    GameEngine::GameEngine()
        : m_State(ENG_Init)
    {
    }

    GameEngine::~GameEngine()
    {
    }
   
    bool GameEngine::Init()
    {
        AvniResult result = Success;
        result = SINGLETONMANAGER->GetRenderer()->InitRenderer();
        m_State = ENG_Update;

        m_Timer = new HPTimer();

        // Enumerate Shaders
        SINGLETONMANAGER->GetMaterialManager()->EnumerateMaterials();

		m_scene = new Scene();
		m_scene->AddActor(new Camera());
		m_scene->AddActor(new Box(Vector3D(0.0f,0.0f,0.0f),2,2,2));
		m_scene->Init();

        return result != Success;
    }

    bool GameEngine::Uninit()
    {
        AvniResult result = Success;
        
        delete m_Timer;
        return false;
    }

    bool GameEngine::Update()
    {
        bool quit = false;
        switch (m_State)
        {
            case ENG_Init: 
            {
                quit = Init();
                break;
            }
            case ENG_Update:
            {
                quit = UpdateInternal();
                break;
            }
            case ENG_Uninit:
            {
                quit = Uninit();
                break;
            }
            case ENG_Quit:
            {
                quit = true;
                break;
            }
            default:
            {
                LOG("\nInvalid State", 0);
                break;
            }
        }

        return quit;
    }

    bool GameEngine::UpdateInternal()
    {
        m_fDelta = m_Timer->Update();

		m_scene->Update(m_fDelta);
        SINGLETONMANAGER->GetRenderer()->Render();
        SINGLETONMANAGER->GetRenderer()->Present();
        return false;
    }
}
