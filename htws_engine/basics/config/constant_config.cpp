/*
 * constant_config.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: hearthewarsong
 */

#include "../basics_all.h"

CREATE_STATIC_INSTANCE(ConstantConfig);

ConstantConfig ::ConstantConfig()
{
	vector<string> config_files;
	std::ifstream configList(
			(htws_globals::BasicPath + "config/conffilelist.cfg").c_str());
	if (configList.is_open())
	{
		while (!configList.eof())
		{
			char buffer[256] = "";
			configList.getline(buffer,255);
			std::string line(buffer);
			line = StringHelper::trim(line);
			if (line.size())
			{
				config_files.push_back(line);
			}
		}
	}
	else
	{
		//TODO log
	}
}

ConstantConfig::~ConstantConfig()
{
	// TODO Auto-generated destructor stub
}

bool ConstantConfig::HasConfig(const string& group, const string& key)
{
}

int ConstantConfig::GetInt(const string& group, const string& key,
		int defaultValue)
{
}

bool ConstantConfig::GetBool(const string& group, const string& key,
		bool defaultValue)
{
}

const string ConstantConfig::GetString(const string& group, const string& key,
		const string& defaultValue)
{
}

const wstring ConstantConfig::GetWString(const string& group, const string& key,
		const wstring& defaultValue)
{
}
