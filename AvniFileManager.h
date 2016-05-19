///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Avni File Manager
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _AVNIFILEMANAGER_H_
#define _AVNIFILEMANAGER_H_

namespace Avni
{
	class AvniFile;
	class AvniFileManager
	{
	public:
		virtual AvniFile*	ReadFile(char* _filename) = 0;
		virtual void		CloseFile(AvniFile* file) = 0;
		virtual void		WriteToFile(AvniFile* File,char* _filePath) = 0;
	};
}

#endif
