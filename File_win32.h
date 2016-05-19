////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File win32
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FILEWIN32_H_
#define _FILEWIN32_H_

#include <AvniInterfaces.h>
#include <stdio.h>

namespace Avni
{
	class File_win32 : public AvniFile
	{
	public :
		File_win32();
		~File_win32();

		virtual void	Open(char* _filepath);
		virtual void	Close();
		virtual void*	GetFileData();
		virtual i32		GetFileSize();

	private:
		char*	m_pFiledata;
		FILE*	m_pFile;
		i32		m_iFilesize;
	};
}
#endif