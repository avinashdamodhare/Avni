/////////////////////////////////////////////////////////////////////////////////
//          Avni Renderer
/////////////////////////////////////////////////////////////////////////////////
#include "AvniInterfaces.h"


namespace Avni
{

    class GLRenderer : public AvniRenderer
	{

    private:
        GLRenderer();
        ~GLRenderer();
        AvniRenderer* Create();

        static AvniRenderer* m_instance;

    public:
        static AvniRenderer*   Instance() { return m_instance; }
        AvniResult      InitRenderer();
        void            Register();
	};
}