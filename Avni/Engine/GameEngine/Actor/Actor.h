////////////////////////////////////////////////////////////////////////////////////
// Basic actor
////////////////////////////////////////////////////////////////////////////////////
#ifndef _ACTOR_H_
#define _ACTOR_H_

#include <AvniInterfaces.h>

namespace Avni
{ 
    class Actor
    {
    public:
        Actor();
        ~Actor();

        u32 GetActorId() { return m_iActorId; }

		virtual void Init();
		virtual void Update(float _dt);
		virtual void Uninit();

    protected : 

        Vector3D        m_WorldPos;
    private:
        u32             m_iActorId;

        static u32      m_sActorCount;
    };
}

#endif // _ACTOR_H_
