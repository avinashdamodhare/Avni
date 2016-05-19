/////////////////////////////////////////////////////////////////////////////////////////////////////
// Shader Implemetation
/////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _SHADER_H_
#define _SHADER_H_

#include <AvniInterfaces.h>

namespace Avni
{
	class AvniShader
	{
	public:
		virtual AvniShaderType	GetShaderType()					= 0;
		virtual void			SetShader()						= 0;
		virtual void			SetShaderConstantf(i32 shaderregisterno, Vector4D _constant) = 0;
		virtual void			SetShaderConstanti(i32 shaderregisterno, Vector4D _constant) = 0;
	};
}

#endif