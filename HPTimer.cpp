///////////////////////////////////////////////////////////////////////////
// Timer impletation
///////////////////////////////////////////////////////////////////////////

#include "HPTimer.h"
#ifdef WIN32
#include <windows.h>
#endif
namespace Avni
{
    HPTimer::HPTimer()
        : m_lLastTickCount(0)
        , m_lCurrentCount(0)
        , m_fCurrentDelta(0.0f)
        , m_fSecPerCount(0.0f)
        , m_fFixedFrameDelta(100 / 6.0f)
    {
        int64 count;
        QueryPerformanceFrequency((LARGE_INTEGER*)&count);
        m_fSecPerCount = (float)(1.0f / count);
    }

    HPTimer::~HPTimer()
    {

    }

    float HPTimer::GetDeltaTime()
    {
        return m_fCurrentDelta;
    }

    float HPTimer::Update()
    {
        QueryPerformanceCounter((LARGE_INTEGER*)&m_lCurrentCount);

        int64 deltacount = (m_lCurrentCount - m_lLastTickCount);

        m_fCurrentDelta = deltacount * m_fSecPerCount;
        m_lLastTickCount = m_lCurrentCount;

        if (m_fCurrentDelta < m_fFixedFrameDelta && m_lLastTickCount)
        {
            u32 sleeptime = (u32)(m_fFixedFrameDelta - m_fCurrentDelta);
            Sleep(sleeptime);
            m_fCurrentDelta = m_fFixedFrameDelta;
			//printf("\n controlled delta %d",sleeptime);
        }

        return m_fCurrentDelta;
    }
}