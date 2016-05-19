/////////////////////////////////////////////////////////////////////////
// Game Engine
/////////////////////////////////////////////////////////////////////////
#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

#include <AvniInterfaces.h>
#include <SingletonTemplate.h>
namespace Avni
{
    enum EngineState
    {
        ENG_Init,
        ENG_Update,
        ENG_Uninit,
        ENG_Quit,
    };
    class HPTimer;
	class Scene;
    class GameEngine : public AvniEngine, public SingletonTemplate<GameEngine>
    {
        public: 
            GameEngine();
            ~GameEngine();

            // Interface Methods
            virtual bool    Init();
            virtual bool    Uninit();
            virtual bool    Update();

        private:
            // Internal Methods
            bool            UpdateInternal();

            // Variables and References
            AvniRenderer*   m_gameRenderer;
            EngineState     m_State;
            HPTimer*        m_Timer;
            f32             m_fDelta;
            Scene*          m_scene;
    };
}

#endif