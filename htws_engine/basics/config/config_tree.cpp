/*
 * config_tree.cpp
 *
 *  Created on: Dec 24, 2014
 *      Author: hearthewarsong
 */

#include "../basics_all.h"

CREATE_STATIC_INSTANCE(ConfigTree);

ConfigTree::ConfigTree()
{
	// TODO Auto-generated constructor stub

}

ConfigTree::~ConfigTree()
{
	// TODO Auto-generated destructor stub
}

bool ConfigTree::HasElement(const string& path, const string& key) const
{
	if (ConstantConfig::GetInstance()->HasConfig(path,key)) return true;
	return false;
}


ConfigElement& ConfigTree::GetElementOrDefault(const string& path,
		const string& key, const string& default_value)
{

	if (ConstantConfig::GetInstance()->HasConfig(path,key)) return ConstantConfig::GetInstance()->GetElement(path,key);
	default_elements.push_back(new ConfigElement(default_value));
	return default_elements.back();
}

