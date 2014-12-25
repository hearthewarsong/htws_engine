/*
 * config_tree.h
 *
 *  Created on: Dec 24, 2014
 *      Author: hearthewarsong
 */

#ifndef CONFIG_TREE_H_
#define CONFIG_TREE_H_


class ConfigTree : public Singleton<ConfigTree>
{
protected:
	boost::ptr_vector<ConfigElement> default_elements;
public:
	ConfigTree();
	virtual ~ConfigTree();
	bool HasElement(const string& path, const string& key) const;
	ConfigElement& GetElementOrDefault(const string& path, const string& key, const string& default_value);
	//ConfigElement& GetElementOrCreate(const string& path, const string& key, const string& default_value) const;
};

#endif /* CONFIG_TREE_H_ */
