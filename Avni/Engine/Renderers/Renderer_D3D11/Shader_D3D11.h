/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Shader D3D11
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _VERTEXSHADERD3D11_H_
#define _VERTEXSHADERD3D11_H_

#include <AvniInterfaces.h>
#include <d3d11.h>

namespace Avni
{
	typedef union Shader
	{
		ID3D11VertexShader*		m_pVertexShader;
		ID3D11PixelShader*		m_pPixelShader;
	} AvniShaderUnion;

	class Shader_D3D11 : public AvniShader
	{
	public:
		Shader_D3D11(char* _Shadername, AvniShaderType _type);
		~Shader_D3D11();

		// Interface 
		virtual AvniShaderType	GetShaderType()	{ return m_iShaderType; }
		virtual void			SetShader();
		virtual void			SetShaderConstantf(i32 shaderregisterno, Vector4D _constant);
		virtual void			SetShaderConstanti(i32 shaderregisterno, Vector4D _constant);
	private:
		AvniShaderType			m_iShaderType;
		AvniShaderUnion			m_pShader;
	};
}

#endif