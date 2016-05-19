//////////////////////////////////////////////////////////////////////////////////////
// Avni basic defines
//////////////////////////////////////////////////////////////////////////////////////

#ifndef AVNIDEFINES_H_
#define AVNIDEFINES_H_

#include <stdlib.h>

namespace Avni
{
	enum AvniResult
	{
		Success		= 0,
		Failed		= 1,
	};

    enum Run_Configurations
    {
        Config_WIN32_Directx11 = 0,
        Config_WIN32_Directx12,
        Config_WIN32_OpenGL,
        Config_WIN32_OpenGLEX,
		Config_ORBIS_GNM,
        Config_MAX
    };

    typedef unsigned    int			u32;
    typedef unsigned    long		u64;
    typedef             float		f32;
    typedef             int			i32;
    typedef unsigned    short       u16;
#ifdef WIN32
	typedef				__int64		int64;
#elif ORBIS
	typedef				long		int64;
	#define LARGE_INTEGER unsigned long
#endif // WIN32


    void Log(char* str, i32 numarg, ...);


    //////////////////////////////////////////////////////////////////////////////////////////////
    // Renderer defines
    //////////////////////////////////////////////////////////////////////////////////////////////
    typedef enum
    {
        SHADERTYPE_VERTEX,
        SHADERTYPE_PIXEL,
        SHADERTYPE_HULL,
        SHADERTYPE_DOMAIN,
        SHADERTYPE_TESSALATION,
        SHADERTYPE_COMPUTE,
        SHADERTYPE_MAXSHADER
    } AvniShaderType;

    typedef enum
    {
        VERTEXTYPE_POS_DIFFUSE = 0,
        VERTEXTYPE_MAX
    } AvniVertexType;

    typedef enum
    {
        SHADERNAME_BASIC = 0,
        SHADERNAME_MAX
    }AvniShaderName;

    typedef enum
    {
        MATERIALNAME_BASIC = 0,
        MATERIALNAME_MAX
    }AvniMaterialName;

    typedef enum
    {
        TEXTUREFMT_R8G8B8A8 = 0,
        TEXTUREFMT_MAX
    }AvniTextureFormat;
    //////////////////////////////////////////////////////////////////////////////////////////////

    #define LOG Log
}
#ifdef WIN32
#define NULL 0
#endif

#ifdef ORBIS
#include <kernel.h>
void Sleep(Avni::u32 _time);
void QueryPerformanceFrequency(LARGE_INTEGER * count);
void QueryPerformanceCounter(LARGE_INTEGER * count);
#endif

// String Defines

#define SAFE_DELETE(X)  if(X) { delete X;   X = NULL; }
#define SAFE_RELEASE(X) if(X) { X->Release(); X = NULL; }
#endif