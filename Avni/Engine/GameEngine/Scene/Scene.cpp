////////////////////////////////////////////////////////////////////////////////////////////////////////
// Scene implementation
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Scene.h"
#include "Camera.h"
#include "GameEngine/Actor/Actor.h"

namespace Avni
{
	Scene::Scene()
		: m_SceneCamera(NULL)
	{
		m_SceneCamera = new Camera();
	}

	Scene::~Scene()
	{

	}

	void Scene::AddActor(Actor* _actor)
	{
		m_ActorList.push_back(_actor);
	}

	void Scene::Init()
	{
		for (std::vector<Actor*>::iterator itr = m_ActorList.begin(); itr != m_ActorList.end(); itr++)
		{
			(*itr)->Init();
		}
	}

    void Scene::Uninit()
    {
        for (std::vector<Actor*>::iterator itr = m_ActorList.begin(); itr != m_ActorList.end(); itr++)
        {
            (*itr)->Uninit();
        }
    }

	void Scene::Update(float _dt)
	{
		for (std::vector<Actor*>::iterator itr = m_ActorList.begin(); itr != m_ActorList.end(); itr++)
		{
			(*itr)->Update(_dt);
		}
	}
}