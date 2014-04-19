#include "../basics_all.h"

TextFileReader::~TextFileReader()
{
}

bool TextFileReader::GetContent(vector<string>& lines)
{
	std::ifstream ifile((path + fileName).c_str());
	if (ifile.is_open())
	{
		string line("");
		while (std::getline(ifile,line))
		{
			if (skipComments)
			{
				if (considerQuestionMarks)
				{
					bool inQuestionMark = false;
					for (int i = 0; i< ((int)line.size()) - 1; ++i)
					{
						if (line[i] == '"')
						{
							inQuestionMark = !inQuestionMark;
						}
						if (!inQuestionMark && line[i] == '/' && line[i+1] == '/')
						{
							line = line.substr(0,i);
							break;
						}
					}
				}
				else
				{
					line = line.substr(0, line.find("//"));
				}
			}
			if (trim)
			{
				line = StringHelper::trim(line);
			}
			if (line.size())
			{
				lines.push_back(line);
			}
		}
		ifile.close();
		return true;
	}
	else
	{
		return false;
	}
}

bool TextFileReader::GetContent(vector<wstring>& lines)
{
	std::ifstream ifile((path + fileName).c_str());
	if (ifile.is_open())
	{
		string rawline("");
		while (std::getline(ifile,rawline))
		{
			wstring line = StringHelper::UTF8to16(rawline.c_str());
			if (skipComments)
			{
				if (considerQuestionMarks)
				{
					bool inQuestionMark = false;
					for (int i = 0; i< ((int)line.size()) - 1; ++i)
					{
						if (line[i] == '"')
						{
							inQuestionMark = !inQuestionMark;
						}
						if (!inQuestionMark && line[i] == '/' && line[i+1] == '/')
						{
							line = line.substr(0,i);
							break;
						}
					}
				}
				else
				{
					line = line.substr(0, line.find(L"//"));
				}
			}
			if (trim)
			{
				line = StringHelper::trim(line);
			}
			if (line.size())
			{
				lines.push_back(line);
			}
		}
		ifile.close();
		return true;
	}
	else
	{
		return false;
	}
}

bool TextFileReader::GetContent(map<string, string>& lines)
{
}

TextFileReader::TextFileReader(const string& fileName,
		bool skipComments /* =true*/, bool trim /* =true*/,
		bool considerQuestionMarks /* =true*/) :
		fileName(fileName), trim(trim), skipComments(skipComments), considerQuestionMarks(
				considerQuestionMarks)
{
	path = htws_globals::BasicPath;
}

bool TextFileReader::GetContent(vector<wstring, wstring>& lines)
{
}

void TextFileReader::SetPath(string path)
{
	this->path = path;
}
