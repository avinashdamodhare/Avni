//////////////////////////////////////////////////////////////////////////////////////
//      Config manager  
//////////////////////////////////////////////////////////////////////////////////////

#ifndef CONFIGURATIONMANAGER_H_
#define CONFIGURATIONMANAGER_H_

#include <AvniInterfaces.h>
#include <SingletonTemplate.h>

namespace Avni
{
    class ConfigurationManager : public SingletonTemplate<ConfigurationManager>
    {
    public:
        ConfigurationManager();
        ~ConfigurationManager();

        void Initialize(Run_Configurations _config);
        bool Update();
        void Uninitialize();

        // Getters
        Run_Configurations  GetCurrentConfig()  {   return m_CurrentConfig;     }
        bool                GetIsWindowed()     {   return m_IsWindowed;        }
        void*               GetHWND()           {   return m_pHWND;				}
		bool                GetShouldQuit()     {   return m_ShouldQuit;		}

        // setters
        void                SetCurrentConfig(Run_Configurations _config){ m_CurrentConfig   = _config;  }
        void                SetWindowed(bool _windowed)                 {   m_IsWindowed    = _windowed;}
        void                SetHWND(void* _hwnd)                        {   m_pHWND         = _hwnd;    }
		void                SetShouldQuit(bool _quit)                   {   m_ShouldQuit    = _quit;    }

    private:
        Run_Configurations  m_CurrentConfig;
        void*               m_pHWND;
        bool                m_IsWindowed;
		bool				m_ShouldQuit;
    };
}

#define CONFIGURATIONMANAGER ConfigurationManager::Instance()
#endif