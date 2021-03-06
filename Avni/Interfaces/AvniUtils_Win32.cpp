////////////////////////////////////////////////////////////////////////
// Avni Utility functions
////////////////////////////////////////////////////////////////////////

// Includes
#include "AvniInterfaces.h"
#include <stdio.h>
#include <stdarg.h>
#include <Windows.h>

namespace Avni
{ 
    void Log(char* str, int numarg , ... ) // supports only float and integer, maximum 10 nos
    {
        static char string[512];
        if(numarg)
        {
            va_list arglist;
            va_start(arglist, numarg);
            sprintf_s(str, strlen(str), string, arglist);
            va_end(arglist);
        }
        else
        {
            strcpy_s(string,(const char*)str);
        }

        // Write to the console
        OutputDebugStringA(string);
    }
}