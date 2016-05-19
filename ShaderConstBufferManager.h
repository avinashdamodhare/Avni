//////////////////////////////////////////////////////////////////////////////////////////////////////////
// ShaderConstantBuffer manager
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _SHADERCONSTBUFFMANAGER_H_
#define _SHADERCONSTBUFFMANAGER_H_

#include <AvniInterfaces.h>
#include "Renderer_D3D11.h"

namespace Avni
{
	class ShaderConstantBufferManager : public SingletonTemplate<ShaderConstantBufferManager>
	{
	public:
		ShaderConstantBufferManager();
		~ShaderConstantBufferManager();

		void InitBuffer();

		void SetVertexShaderConstantF(i32 _startindex,Vector4D _const);
		void SetVertexShaderConstantF(i32 _startindex,Matrix4x4 _const);
		void SetVertexShaderConstantI(i32 _startindex,Vector4D _const);
		void SetPixelShaderConstantF(i32 _startindex,Vector4D _const);
		void SetPixelShaderConstantF(i32 _startindex,Matrix4x4 _const);
		void SetPixelShaderConstantI(i32 _startindex,Vector4D _const);

		void SetShaderConstant(ShaderConstBufferType _type);

	private:
		ID3D11Buffer*	m_pConstantBuffers[CONSTANTBUFFERTYPE_MAX];
		Vector4D		m_vContantBufferCPU[CONSTANTBUFFERTYPE_MAX][20];
		bool			m_bConstantDirty;
	};
}
#endif