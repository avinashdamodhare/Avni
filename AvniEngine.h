//////////////////////////////////////////////////////////////////////////////////////////
//                      AVNI ENGINE
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef AVNIENGINE_H
#define AVNIENGINE_H

namespace Avni
{
    class AvniEngine
    {
    public :
        // Initialization
        virtual bool Init() { return false; }
        virtual bool Uninit(){ return false; }

        // Engine Update
        virtual bool Update() = 0;
    };
}

#endif
