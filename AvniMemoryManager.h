//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Avni Memory Manager
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _AVNIMEMORY_MANAGER_H_
#define _AVNIMEMORY_MANAGER_H_

namespace Avni
{
	class AvniMemoryManager
	{
	public:
		virtual void Initialize(u32 SystemMemSize, u32 GPUMemSize) = 0;
		virtual void* AllocateSystemMemory(u32 _size, u32 _allign = 16) = 0;
		virtual void* AllocateGPUMemory(u32 _size, u32 _allign = 32) = 0;
		virtual void  ReleaseSystemMemory(void* ptr) = 0;
		virtual void  ReleaseGPUMemory(void* ptr) = 0;
	};
}
#endif