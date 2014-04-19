#ifndef CONSTANT_CONFIG_H_
#define CONSTANT_CONFIG_H_

#include "../basics_all.h"

class ConstantConfig : public Singleton<ConstantConfig>
{
protected:
	ConstantConfig();
	~ConstantConfig();
	map<string,map<string,wstring> > values;
public:
	bool HasConfig(const string& group, const string& key);
	int GetInt(const string& group, const string& key,int defaultValue);
	bool GetBool(const string& group, const string& key,bool defaultValue);
	const string GetString(const string& group, const string& key, const string& defaultValue);
	const wstring GetWString(const string& group, const string& key, const wstring& defaultValue);

};

#endif /* CONSTANT_CONFIG_H_ */
