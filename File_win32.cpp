/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File Manager
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "File_win32.h"

namespace Avni
{
	File_win32::File_win32()
		: m_pFiledata(NULL)
		, m_iFilesize(0)
		, m_pFile(NULL)
	{

	}

	File_win32::~File_win32()
	{
		Close();
	}

	void File_win32::Open(char* _filepath)
	{
		fopen_s(&m_pFile,_filepath,"rb");

		if(m_pFile)
		{
			fseek(m_pFile,0,SEEK_END);
			m_iFilesize = ftell(m_pFile);
			fseek(m_pFile,0,SEEK_SET);
			m_pFiledata = new char[m_iFilesize];
			fread(m_pFiledata,1,m_iFilesize,m_pFile);
		}
	}

	void File_win32::Close()
	{
		if(m_pFile)
			fclose(m_pFile);

		SAFE_DELETE(m_pFiledata);
	}

	void* File_win32::GetFileData()
	{
		return (void*)m_pFiledata;
	}

	i32 File_win32::GetFileSize()
	{
		return m_iFilesize;
	}
}