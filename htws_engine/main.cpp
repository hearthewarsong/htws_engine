#include "basics/basics_all.h"

int main()
{
	TextFileReader reader("replaces.txt");
	vector<wstring> lines;
	if (reader.GetContent(lines))
	{
		for (unsigned i = 0; i < lines.size(); ++i)
		{
			std::cout << StringHelper::UTF16to8(lines[i].c_str()) << std::endl;
		}

	}
	else
	{
		std::cout << "fail" << std::endl;
	}
	return 0;
}

