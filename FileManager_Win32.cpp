/////////////////////////////////////////////////////////////////////////////////////////////////////////
// FileManager_Win32
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "FileManager_Win32.h"
#include "File_win32.h"

namespace Avni
{
	FileManager_Win32::FileManager_Win32()
	{
	}

	FileManager_Win32::~FileManager_Win32()
	{
		for (std::list<AvniFile*>::iterator itr = m_openFiles.begin(); itr != m_openFiles.end(); itr++)
		{
			(*itr)->Close();
		}
	}

	AvniFile* FileManager_Win32::ReadFile(char* _filename)
	{
		AvniFile* file = new File_win32();
		
		file->Open(_filename);

        if(file->GetFileData() != NULL)
        {
            m_openFiles.emplace_back(file);
        }
        else
        {
            SAFE_DELETE(file);
        }
		return file;
	}

	void FileManager_Win32::CloseFile(AvniFile* file)
	{
		m_openFiles.remove(file);
		file->Close();
		SAFE_DELETE(file);
	}

	void FileManager_Win32::WriteToFile(AvniFile* File,char* _filePath)
	{
		FILE* fp;
		fopen_s(&fp,_filePath,"wb");
		if(fp)
		{
			fwrite(File->GetFileData(),File->GetFileSize(),1,fp);
		}
		fclose(fp);
	}
}