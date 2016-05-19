//////////////////////////////////////////////////////////////////////////////////////////
// High Performance timer
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef _HPITMER_H_
#define _HPITMER_H_

#include <AvniInterfaces.h>

// All timings are in milliseconds
namespace Avni
{
    class HPTimer
    {
    public:
        HPTimer();
        ~HPTimer();

        float GetDeltaTime();
        float Update();

    private:
        float   m_fSecPerCount;
        float   m_fCurrentDelta;
        float   m_fFixedFrameDelta;
        __int64 m_lCurrentCount;
        __int64 m_lLastTickCount;
    };
}


#endif //_HTITMER_H_
