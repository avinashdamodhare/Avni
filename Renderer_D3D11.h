///////////////////////////////////////////////////////////////////////////////////////////////////
// Renderer implementation for D3D11 
///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef RENDERD3D12_H_
#define RENDERD3D12_H_

#include <AvniInterfaces.h>
#include <SingletonTemplate.h>
#include <D3D11.h>

#define CHECK_DEVICE_ERRORS(X) if(HRESULT(X) != 0) { __debugbreak(); }

typedef enum 
{
	CONSTANTBUFFERTYPE_VERTEX_COMMON,
	CONSTANTBUFFERTYPE_PIXEL_COMMON,
	CONSTANTBUFFERTYPE_MAX
}ShaderConstBufferType;

namespace Avni
{
	class VertexLayout_D3D11;

    class Renderer_D3D11 : public SingletonTemplate<Renderer_D3D11>, public AvniRenderer
    {
    public:
        Renderer_D3D11();
        ~Renderer_D3D11();

        virtual AvniResult          InitRenderer();
        virtual void                Render();
        virtual void                Present();
        virtual u32                 GetRenderWidth();
        virtual u32                 GetRenderHeight();
        virtual float               GetRenderAspectRatio();

        virtual void                AddObjectrenderList(AvniRenderable& _object);

		virtual	AvniShader*			CreateShader(char* _Shadername, AvniShaderType _type);
		virtual	AvniMesh*	        CreateMesh(AvniVertexType _type, i32 totalVertices, void* _meshdata, void* _indexdata, i32 totalindices);
		virtual void				SetVertexLayout(AvniVertexType _type);
		virtual void                SetViewMat(Matrix4x4 _ViewMatrix);
		virtual void                SetViewProjMat(Matrix4x4 _ViewProjectionMatrix);

		ID3D11Device*				GetDevice()											{ return m_pDevice; }
		ID3D11DeviceContext*		GetImmediateContext()								{ return m_pImmediateContext; }

    private:
        void                        RenderObjectList();
        
        AvniResult                  CreateDevice();

        ID3D11Device*               m_pDevice;
        IDXGISwapChain*             m_pSwapChain;
        ID3D11DeviceContext*        m_pImmediateContext;
        ID3D11RenderTargetView*     m_pRenderTargetView;
        D3D_FEATURE_LEVEL           m_iFeatureLevel;
        UINT                        m_iSDKVersion;

		VertexLayout_D3D11*			m_pVertexlayout;
		std::list<AvniShader*>		m_ShaderList;
        std::list<AvniRenderable>	m_RenderList;

		Matrix4x4					m_ViewMatrix;
		Matrix4x4					m_ViewProjMatrix;
    };

#define RENDERERD3D11 ((Renderer_D3D11*)SINGLETONMANAGER->GetRenderer())
}
#endif