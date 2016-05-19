////////////////////////////////////////////////////////////////////////////////////////
// Singletons Manager
////////////////////////////////////////////////////////////////////////////////////////

#ifndef SINGLETON_MANAGER
#define SINGLETON_MANAGER

namespace Avni
{
    //  Forwards
    class AvniRenderer;
    class AvniEngine;

    class SingletonsManager
    {
        SingletonsManager();
        ~SingletonsManager();

        static SingletonsManager* m_Instance;

    public:
        // Getters
        static SingletonsManager&       Get();
        static SingletonsManager*       Instance();
        static void                     Destroy();

        //Getters
        AvniEngine*                     GetEngine()											{ return m_Engine;                  }
        AvniRenderer*                   GetRenderer()										{ return m_Renderer;                }
		AvniFileManager*                GetFileManager()									{ return m_FileManager;             }
        AvniMaterialManager*              GetMaterialManager()                                  { return m_MaterialManager;           }

        // Setters
        void                            SetEngine(AvniEngine* _engine)						{ m_Engine = _engine;               }
        void                            SetRenderer(AvniRenderer* _renderer)				{ m_Renderer = _renderer;           }
		void                            SetFileManager(AvniFileManager* _filemanager)       { m_FileManager = _filemanager;     }
        void                            SetMaterialManager(AvniMaterialManager* _MaterialManager) { m_MaterialManager = _MaterialManager; }

    private:
        AvniRenderer*					m_Renderer;
        AvniEngine*						m_Engine;
		AvniFileManager*				m_FileManager;
        AvniMaterialManager*              m_MaterialManager;
    };

#define SINGLETONMANAGER SingletonsManager::Instance()
}
#endif