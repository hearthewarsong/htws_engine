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
		while (std::getline(ifile, line))
		{
			if (skipComments)
			{
				if (considerQuotationMarks)
				{
					bool inQuestionMark = false;
					for (int i = 0; i < ((int) line.size()) - 1; ++i)
					{
						if (line[i] == '"')
						{
							inQuestionMark = !inQuestionMark;
						}
						if (!inQuestionMark && line[i] == '/'
								&& line[i + 1] == '/')
						{
							line = line.substr(0, i);
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
		while (std::getline(ifile, rawline))
		{
			wstring line = StringHelper::UTF8to16(rawline.c_str());
			if (skipComments)
			{
				if (considerQuotationMarks)
				{
					bool inQuestionMark = false;
					for (int i = 0; i < ((int) line.size()) - 1; ++i)
					{
						if (line[i] == '"')
						{
							inQuestionMark = !inQuestionMark;
						}
						if (!inQuestionMark && line[i] == '/'
								&& line[i + 1] == '/')
						{
							line = line.substr(0, i);
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

bool TextFileReader::GetContent(map<string, string>& dictionary)
{
	trim = true;
	considerQuotationMarks = true;
	skipComments = true;
	vector<string> rawLines;
	if (!GetContent(rawLines))
		return false;
	foreach(vector<string>,rawLines,it){
	string& line = *it;
	string key = "";
	string value = "";
	bool inQuotationMarks = false;
	if (!line.size()) continue;
	for(unsigned i = 0; i< line.size()-1; ++i)
	{
		if (line[i] == '"')
		{
			inQuotationMarks = !inQuotationMarks;
		}
		else
		{
			if (line[i] == '=')
			{
				key = line.substr(0,i);
				key = StringHelper::trim(key);
				if (key.size() == 0)
				{
					break;
				}
				if (key[0] == '"') key = key.substr(1, string::npos);
				if (key.size() == 0)
				{
					break;
				}
				if (*key.rbegin() == '"') key = key.substr(0, key.size()-1);
				if (key.size() == 0)
				{
					break;
				}
				value = line.substr(i+1,string::npos);
				value = StringHelper::trim(value);
				if (value.size() > 0 && value[0]=='"')
				{
					value = value.substr(1, string::npos);
				}
				if (value.size() > 0 && *value.rbegin() =='"')
				{
					value = value.substr(0, value.size()-1);
				}
				break;
			}
		}
	}
	if (key == "")
	{
		//TODO Log Error
		continue;
	}
	dictionary[key] = value;
}
	return true;
}

TextFileReader::TextFileReader(const string& fileName,
		bool skipComments /* =true*/, bool trim /* =true*/,
		bool considerQuotationMarks /* =true*/) :
		fileName(fileName), trim(trim), skipComments(skipComments), considerQuotationMarks(
				considerQuotationMarks)
{
	path = htws_globals::BasicPath;
}

bool TextFileReader::GetContent(map<wstring, wstring>& dictionary)
{
	trim = true;
	considerQuotationMarks = true;
	skipComments = true;
	vector<wstring> rawLines;
	if (!GetContent(rawLines))
		return false;
	foreach(vector<wstring>,rawLines,it){
	wstring& line = *it;
	wstring key = L"";
	wstring value = L"";
	bool inQuotationMarks = false;
	if (!line.size()) continue;
	for(unsigned i = 0; i< line.size()-1; ++i)
	{
		if (line[i] == L'"')
		{
			inQuotationMarks = !inQuotationMarks;
		}
		else
		{
			if (line[i] == L'=')
			{
				key = line.substr(0,i);
				key = StringHelper::trim(key);
				if (key.size() == 0)
				{
					break;
				}
				if (key[0] == L'"') key = key.substr(1, string::npos);
				if (key.size() == 0)
				{
					break;
				}
				if (*key.rbegin() == L'"') key = key.substr(0, key.size()-1);
				if (key.size() == 0)
				{
					break;
				}
				value = line.substr(i+1,string::npos);
				value = StringHelper::trim(value);
				if (value.size() > 0 && value[0]==L'"')
				{
					value = value.substr(1, string::npos);
				}
				if (value.size() > 0 && *value.rbegin() == L'"')
				{
					value = value.substr(0, value.size()-1);
				}
				break;
			}
		}
	}
	if (key == L"")
	{
		//TODO Log Error
		continue;
	}
	dictionary[key] = value;
}
	return true;
}

void TextFileReader::SetPath(string path)
{
	this->path = path;
}
