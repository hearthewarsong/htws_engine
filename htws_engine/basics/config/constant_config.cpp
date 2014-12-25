/*
 * constant_config.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: hearthewarsong
 */

#include "../basics_all.h"

CREATE_STATIC_INSTANCE(ConstantConfig);

ConstantConfig::ConstantConfig()
{
	vector<string> config_files;
	std::ifstream configList(
			(htws_globals::BasicPath + "config/conffilelist.cfg").c_str());
	if (configList.is_open())
	{
		while (!configList.eof())
		{
			std::string line;
			std::getline(configList,line);
			line = StringHelper::trim(line);
			if (line.size())
			{
				config_files.push_back(line);
			}
		}
		for (const string & s : config_files)
		{
			std::ifstream configFile(
					(htws_globals::BasicPath + s).c_str());
			if (configFile.is_open())
			{
				string configPath("");
				string line;
				int lnumber = 0;
				while(std::getline(configFile,line))
				{
					++lnumber;
					bool success = false;
					line = StringHelper::trim(line);
					if (line.empty())
					{
						success = true;
					} else if (line[0] == '[')
					{
						configPath = line.substr(1,line.size()-2);
						success = true;
					}
					else if (line.find(".[") == 0)
					{
						configPath.append(".");
						configPath.append(line.substr(2,line.size()-3));
						success = true;
					}
					else if (line.find("-[]") == 0)
					{
						configPath = configPath.substr(0,configPath.rfind("."));
						success = true;
					}
					else if (line.find("=") != string::npos)
					{
						string key = StringHelper::trim(line.substr(0, line.find("=")));
						string value = StringHelper::trim(line.substr(line.find("=") + 1, string::npos));
						if (value.size() > 0)
						{
							values[configPath][key] = ConfigElement(value);
							success = true;
						}
					}
					if (!success)
					{
						LLF(LLA_Config, Format("Unable to parse %s line %d : %s",s.c_str() % lnumber % line.c_str()));
					}
				}
			}
			else
			{
				LLF(LLA_Config, Format("Error: file %s not found", (htws_globals::BasicPath + s).c_str() ));
			}
		}
	}
	else
	{
		LLF(LLA_Config, Format("Error: file %s not found", (htws_globals::BasicPath + "config/conffilelist.cfg")));
	}
}

ConstantConfig::~ConstantConfig()
{
}

bool ConstantConfig::HasConfig(const string& group, const string& key) const
{
	if(values.find(group) == values.end()) return false;
	return values.find(group)->second.find(key) != values.find(group)->second.end();
}

ConfigElement& ConstantConfig::GetElement(const string& path,
		const string& key)
{
	return values[path][key];
}
