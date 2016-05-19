//////////////////////////////////////////////////////////////////////////////////////////////////
// Renderer D3D11 implemetation
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "Renderer_D3D11.h"
#include <ConfigurationManager.h>
#include "Shader_D3D11.h"
#include "VertexLayout_D3D11.h"
#include "VertexBuffer_D3D11.h"
#include "ShaderConstBufferManager.h"

namespace Avni
{
    Renderer_D3D11::Renderer_D3D11()
        : m_pDevice(0)
        , m_pSwapChain(0)
        , m_pRenderTargetView(0)
    {
		m_pVertexlayout = new VertexLayout_D3D11();
    }

    Renderer_D3D11::~Renderer_D3D11()
    {
		SAFE_DELETE(m_pVertexlayout);
    }
    
    AvniResult Renderer_D3D11::CreateDevice()
    {
        if (m_pDevice)
            return Success;

        DXGI_SWAP_CHAIN_DESC swapChaindesc;
        memset(&swapChaindesc,0,sizeof(DXGI_SWAP_CHAIN_DESC));
        swapChaindesc.BufferCount                           = 1;
        swapChaindesc.BufferDesc.Format                     = DXGI_FORMAT_R8G8B8A8_UNORM;
        swapChaindesc.BufferDesc.Width                      = 854;
        swapChaindesc.BufferDesc.Height                     = 480;
        swapChaindesc.BufferDesc.RefreshRate.Numerator      = 60;
        swapChaindesc.BufferDesc.RefreshRate.Denominator    = 1;
        swapChaindesc.BufferUsage                           = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        swapChaindesc.OutputWindow                          = (HWND)CONFIGURATIONMANAGER->GetHWND();
        swapChaindesc.SampleDesc.Count                      = 1;
        swapChaindesc.SampleDesc.Quality                    = 0;
        swapChaindesc.Windowed                              = CONFIGURATIONMANAGER->GetIsWindowed();

        D3D_FEATURE_LEVEL Featurelevel = D3D_FEATURE_LEVEL_11_0;

        HRESULT hr = D3D11CreateDeviceAndSwapChain(
                                                    NULL,
                                                    D3D_DRIVER_TYPE_HARDWARE,
                                                    NULL,
                                                    0,
                                                    &Featurelevel,
                                                    1,
                                                    D3D11_SDK_VERSION,
                                                    &swapChaindesc,
                                                    &m_pSwapChain,
                                                    &m_pDevice,
                                                    &m_iFeatureLevel,
                                                    &m_pImmediateContext
                                                    );

        if (FAILED(hr))
            return Failed;

        ID3D11Texture2D* rendertarget;
        hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D),(void**) &rendertarget);
        if (FAILED(hr))
            return Failed;

        hr = m_pDevice->CreateRenderTargetView(rendertarget,NULL,&m_pRenderTargetView);
        if (FAILED(hr))
            return Failed;

        m_pImmediateContext->OMSetRenderTargets(1, &m_pRenderTargetView, NULL);
        
        D3D11_VIEWPORT viewport;
        viewport.Width      = 854;
        viewport.Height     = 480;
        viewport.TopLeftX   = 0;
        viewport.TopLeftY   = 0;
        viewport.MaxDepth   = 0;
        viewport.MinDepth   = 0;

        m_pImmediateContext->RSSetViewports(1,&viewport);

		m_pVertexlayout->InitializeVertexLayouts();

		ShaderConstantBufferManager::Instance()->InitBuffer();

        return Success;
    }

    AvniResult Renderer_D3D11::InitRenderer()
    {
        AvniResult result;
        result      = CreateDevice();
        return result;
    }

    void Renderer_D3D11::Render()
    {
        float rgba[4];
        rgba[0] = 0;
        rgba[1] = 0;
        rgba[2] = 0;
        rgba[3] = 255;
        m_pImmediateContext->ClearRenderTargetView(m_pRenderTargetView,rgba);
        RenderObjectList();        
    }

    void Renderer_D3D11::Present()
    {
        CHECK_DEVICE_ERRORS(m_pSwapChain->Present(0, 0));
    }

    void Renderer_D3D11::AddObjectrenderList(AvniRenderable& _object)
    {
        m_RenderList.push_back(_object);
    }

    u32 Renderer_D3D11::GetRenderWidth()
    {
        return 854;
    }

    u32 Renderer_D3D11::GetRenderHeight()
    {
        return 480;
    }

    float Renderer_D3D11::GetRenderAspectRatio()
    {
        return 854.0f / 480.0f;
    }

	AvniShader* Renderer_D3D11::CreateShader(char* _Shadername, AvniShaderType _type)
	{
		for(std::list<AvniShader*>::iterator itr = m_ShaderList.begin(); itr != m_ShaderList.end(); itr++) 
		{
			if((*itr)->GetShaderType() == _type)
				return *itr;
		}

        char shadername[64];
        strcpy_s(shadername, "Shaders\\");
        strcat_s(shadername,_Shadername);
        strcat_s(shadername, ".cso");

		AvniShader* shader = new Shader_D3D11(shadername,_type);
		m_ShaderList.push_back(shader);

		return shader;
	}

	AvniMesh* Renderer_D3D11::CreateMesh(AvniVertexType _type, i32 totalVertices, void* _meshdata, void* _indexdata, i32 totalindices)
	{
		return new VertexBuffer_D3D11(_type, totalVertices, _meshdata, _indexdata, totalindices);
	}

	void Renderer_D3D11::SetVertexLayout(AvniVertexType _type)
	{
		m_pVertexlayout->SetVertexLayout(_type);
	}

    void Renderer_D3D11::RenderObjectList()
    {
        for (std::list<AvniRenderable>::iterator itr = m_RenderList.begin(); itr != m_RenderList.end(); itr++)
        {
            (*itr).StartMesh();
            (*itr).ApplyMaterial();
            (*itr).DrawMesh();
        }
        m_RenderList.clear();
    }

	void Renderer_D3D11::SetViewMat(Matrix4x4 _ViewMatrix)
	{
		m_ViewMatrix = _ViewMatrix;
	}

	void Renderer_D3D11::SetViewProjMat(Matrix4x4 _ViewProjectionMatrix)
	{
		m_ViewProjMatrix = _ViewProjectionMatrix;
		ShaderConstantBufferManager::Instance()->SetVertexShaderConstantF(0,_ViewProjectionMatrix);
	}
}