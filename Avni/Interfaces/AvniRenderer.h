//////////////////////////////////////////////////////////////////////////////
//  Renderer interface
//////////////////////////////////////////////////////////////////////////////

#ifndef AVNIRENDERER_H_
#define AVNIRENDERER_H_

namespace Avni
{
    class AvniRenderable;
	class AvniShader;
	class AvniMesh;

    class AvniRenderer
    {
    public:
        virtual             AvniResult          InitRenderer()			= 0;
        virtual             void                Render()				= 0;
        virtual             void                Present()				= 0;

        virtual             u32                 GetRenderWidth()		= 0;
        virtual             u32                 GetRenderHeight()		= 0;
        virtual             float               GetRenderAspectRatio()	= 0;

        virtual             void                AddObjectrenderList(AvniRenderable& _object) = 0;
		virtual             void                SetViewMat(Matrix4x4 _ViewMatrix) = 0;
		virtual             void                SetViewProjMat(Matrix4x4 _ViewProjectionMatrix) = 0;
		virtual				AvniShader*			CreateShader(char* _Shadername, AvniShaderType _type) = 0;
		virtual				AvniMesh*			CreateMesh(AvniVertexType _type, i32 totalVertices, void* _meshdata, void* _indexdata, i32 totalindices) = 0;
		virtual				void				SetVertexLayout(AvniVertexType _type) = 0;
    };
}

#endif // AVNIRENDERER_H_