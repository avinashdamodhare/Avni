/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// VertexLayout Manager
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _VERTEXLAYOUT_H_
#define _VERTEXLAYOUT_H_

#include <AvniInterfaces.h>
#include <d3d11.h>

namespace Avni
{
	class VertexLayout_D3D11 : public AvniVertexLayoutManager
	{
	public:
		VertexLayout_D3D11();
		~VertexLayout_D3D11();

		// Interface
		virtual void InitializeVertexLayouts();
		virtual void SetVertexLayout(AvniVertexType _type);

	private:
		ID3D11InputLayout* m_pInputLayot[VERTEXTYPE_MAX];
	};
}
#endif