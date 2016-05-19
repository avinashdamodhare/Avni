////////////////////////////////////////////////////////////////////////
// Avni Utility functions
////////////////////////////////////////////////////////////////////////

// Includes
#include "AvniInterfaces.h"
#include <stdio.h>
#include <stdarg.h>
#ifdef WIN32
#include <Windows.h>
#endif

namespace Avni
{ 
    void Log(char* str, int numarg , ... ) // supports only float and integer, maximum 10 nos
    {
        /*static char string[512];
        if(numarg)
        {
            va_list arglist;
            va_start(arglist, numarg);
            sprintf(str, string, arglist);
            va_end(arglist);
        }
        else
        {
            strcpy(string,(const char*)str);
        }*/

        // Write to the console
#ifdef WIN32
        OutputDebugStringA(str);
#else
		printf("%s",str);
#endif // WIN32


    }
}