/////////////////////////////////////////////////////////////////////////////////////////////////////////
// FileManager
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "FileManager.h"
#include "File_win32.h"

namespace Avni
{
	FileManager::FileManager()
	{
	}

	FileManager::~FileManager()
	{
		for (std::list<AvniFile*>::iterator itr = m_openFiles.begin(); itr != m_openFiles.end(); itr++)
		{
			(*itr)->Close();
		}
	}

	AvniFile* FileManager::ReadFile(char* _filename)
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

	void FileManager::CloseFile(AvniFile* file)
	{
		m_openFiles.remove(file);
		file->Close();
		SAFE_DELETE(file);
	}

	void FileManager::WriteToFile(AvniFile* File,char* _filePath)
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