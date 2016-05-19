////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ShaderConstant Buffer Manager
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "ShaderConstBufferManager.h"

namespace Avni
{
	ShaderConstantBufferManager::ShaderConstantBufferManager()
		: m_bConstantDirty(false)
	{
		for (int i = 0; i < CONSTANTBUFFERTYPE_MAX; ++i)
		{
			m_pConstantBuffers[i] = NULL;
			memset(&m_vContantBufferCPU[i][0],0,sizeof(float)*80);
		}
	}

	ShaderConstantBufferManager::~ShaderConstantBufferManager()
	{
		for (int i = 0; i < CONSTANTBUFFERTYPE_MAX; ++i)
		{
			SAFE_RELEASE(m_pConstantBuffers[i]);
		}
	}

	void ShaderConstantBufferManager::InitBuffer()
	{
		D3D11_BUFFER_DESC desc;
		desc.BindFlags		= D3D11_BIND_CONSTANT_BUFFER;
		desc.ByteWidth		= sizeof(float)*80;
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		desc.Usage			= D3D11_USAGE_DYNAMIC;
		desc.MiscFlags		= 0;
		desc.StructureByteStride = 0;
		RENDERERD3D11->GetDevice()->CreateBuffer(&desc,NULL,&m_pConstantBuffers[CONSTANTBUFFERTYPE_VERTEX_COMMON]);

		desc.BindFlags		= D3D11_BIND_CONSTANT_BUFFER;
		desc.ByteWidth		= sizeof(float)*80;
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		desc.Usage			= D3D11_USAGE_DYNAMIC;
		desc.MiscFlags		= 0;
		RENDERERD3D11->GetDevice()->CreateBuffer(&desc,NULL,&m_pConstantBuffers[CONSTANTBUFFERTYPE_PIXEL_COMMON]);

	}

	void ShaderConstantBufferManager::SetVertexShaderConstantF(i32 _startindex,Matrix4x4 _const)
	{
		if(_startindex >= 0 && _startindex <= 16 && memcmp(&m_vContantBufferCPU[CONSTANTBUFFERTYPE_VERTEX_COMMON][_startindex].X,_const.mat.m,sizeof(float)*16))
		{
			memcpy(&m_vContantBufferCPU[CONSTANTBUFFERTYPE_VERTEX_COMMON][_startindex].X,_const.mat.m,sizeof(float)*16);
			m_bConstantDirty = true;
		}
	}

	void ShaderConstantBufferManager::SetVertexShaderConstantF(i32 _startindex,Vector4D _const)
	{
		if(_startindex >= 0 && _startindex <= 16 && memcmp(&m_vContantBufferCPU[CONSTANTBUFFERTYPE_VERTEX_COMMON][_startindex].X,&_const.X,sizeof(float)*4))
		{
			memcpy(&m_vContantBufferCPU[CONSTANTBUFFERTYPE_VERTEX_COMMON][_startindex].X,&_const.X,sizeof(float)*4);
			m_bConstantDirty = true;
		}
	}

	void ShaderConstantBufferManager::SetPixelShaderConstantF(i32 _startindex,Matrix4x4 _const)
	{
		if(_startindex >= 0 && _startindex <= 16 && memcmp(&m_vContantBufferCPU[CONSTANTBUFFERTYPE_PIXEL_COMMON][_startindex].X,_const.mat.m,sizeof(float)*16))
		{
			memcpy(&m_vContantBufferCPU[CONSTANTBUFFERTYPE_PIXEL_COMMON][_startindex].X,_const.mat.m,sizeof(float)*16);
			m_bConstantDirty = true;
		}
	}

	void ShaderConstantBufferManager::SetPixelShaderConstantF(i32 _startindex,Vector4D _const)
	{
		if(_startindex >= 0 && _startindex <= 16 && memcmp(&m_vContantBufferCPU[CONSTANTBUFFERTYPE_PIXEL_COMMON][_startindex].X,&_const.X,sizeof(float)*4))
		{
			memcpy(&m_vContantBufferCPU[CONSTANTBUFFERTYPE_PIXEL_COMMON][_startindex].X,&_const.X,sizeof(float)*4);
			m_bConstantDirty = true;
		}
	}

	void ShaderConstantBufferManager::SetVertexShaderConstantI(i32 _startindex,Vector4D _const)
	{

	}

	void ShaderConstantBufferManager::SetPixelShaderConstantI(i32 _startindex,Vector4D _const)
	{

	}

	void ShaderConstantBufferManager::SetShaderConstant(ShaderConstBufferType _type)
	{
		switch (_type)
		{
		case CONSTANTBUFFERTYPE_VERTEX_COMMON:
			{
				if(m_bConstantDirty)
				{
					D3D11_MAPPED_SUBRESOURCE res;
					HRESULT hr = RENDERERD3D11->GetImmediateContext()->Map(m_pConstantBuffers[CONSTANTBUFFERTYPE_VERTEX_COMMON],0,D3D11_MAP_WRITE_DISCARD,0,&res);
					if(!FAILED(hr))
					{
						memcpy(res.pData,m_vContantBufferCPU[CONSTANTBUFFERTYPE_VERTEX_COMMON],sizeof(float)*80);
						RENDERERD3D11->GetImmediateContext()->Unmap(m_pConstantBuffers[CONSTANTBUFFERTYPE_VERTEX_COMMON],0);
					}

				}
				ID3D11Buffer*const *buff = &m_pConstantBuffers[CONSTANTBUFFERTYPE_VERTEX_COMMON];
				RENDERERD3D11->GetImmediateContext()->VSSetConstantBuffers(0,1,buff);
			}
			break;
		case CONSTANTBUFFERTYPE_PIXEL_COMMON:
			{
				if(m_bConstantDirty)
				{
					D3D11_MAPPED_SUBRESOURCE res;
					RENDERERD3D11->GetImmediateContext()->Map(m_pConstantBuffers[CONSTANTBUFFERTYPE_PIXEL_COMMON],0,D3D11_MAP_WRITE_DISCARD,0,&res);
					memcpy(res.pData,m_vContantBufferCPU[CONSTANTBUFFERTYPE_PIXEL_COMMON],sizeof(float)*80);
					RENDERERD3D11->GetImmediateContext()->Unmap(m_pConstantBuffers[CONSTANTBUFFERTYPE_PIXEL_COMMON],0);
				}
				ID3D11Buffer*const *buff = &m_pConstantBuffers[CONSTANTBUFFERTYPE_PIXEL_COMMON];
				RENDERERD3D11->GetImmediateContext()->PSSetConstantBuffers(0,1,buff);
			}
			break;
		default:
			break;
		}
	}
}