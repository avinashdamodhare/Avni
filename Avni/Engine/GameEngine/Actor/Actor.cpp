/////////////////////////////////////////////////////////////////////////////////////
// Actor Implementation
/////////////////////////////////////////////////////////////////////////////////////

#include "Actor.h"

namespace Avni
{
    u32 Actor::m_sActorCount = 0;

    Actor::Actor()
        : m_iActorId(++m_sActorCount)
    {
    }

    Actor::~Actor()
    {
    }

	void Actor::Init()
	{

	}

	void Actor::Uninit()
	{

	}

	void Actor::Update(float _dt)
	{
		// currently doing nothing
	}
}