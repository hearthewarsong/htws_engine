#ifndef CONSTANT_CONFIG_H_
#define CONSTANT_CONFIG_H_

#include "../basics_all.h"

class ConstantConfig : public Singleton<ConstantConfig>
{
protected:
	~ConstantConfig();
	map<string,boost::ptr_map<string,ConfigElement> > values;
public:
	bool HasConfig(const string& group, const string& key) const;
	ConfigElement& GetElement(const string& path, const string& key);
	ConstantConfig();
};

#endif /* CONSTANT_CONFIG_H_ */
