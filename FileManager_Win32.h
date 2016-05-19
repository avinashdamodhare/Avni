////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FileManager 
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _FILEMANAGER_H_
#define _FILEMANAGER_H_

#include <AvniInterfaces.h>

namespace Avni
{
	class FileManager_Win32 : public SingletonTemplate<FileManager_Win32>, public AvniFileManager
	{
	public:
		FileManager_Win32();
		~FileManager_Win32();

		virtual AvniFile* ReadFile(char* _filename);
		virtual void  CloseFile(AvniFile* file);
		virtual void  WriteToFile(AvniFile* File,char* _filePath);

	private:
		std::list<AvniFile*>	m_openFiles;
	};
}
#endif //_FILEMANAGER_H_