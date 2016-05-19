////////////////////////////////////////////////////////////////////////////////////////////////
// Scene File
////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _SCENE_H_
#define _SCENE_H_

#include <AvniInterfaces.h>

namespace Avni
{
	class Camera;
	class Actor;
	class Scene
	{
	public:
		Scene();
		~Scene();

		void Update(float _dt);
		void AddActor(Actor* _actor);
		void Init();
        void Uninit();

	private:

		Camera				*m_SceneCamera;
		std::vector<Actor*>  m_ActorList;
	};

}
#endif  // _SCENE_H_