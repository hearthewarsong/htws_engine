#ifndef PROPERTY_HPP_
#define PROPERTY_HPP_


#include "../basics_all.h"

template<class ValueType>
class Property
{
protected:
	ValueType _value;
	FunctionGroup<ValueType> _listeners;
	void notify()
	{
		_listeners(_value);
	}
public:
	Property(const ValueType& value)
	{
		_value = value;
	}
	Property(const Property<ValueType>& p)
	{
		_value = p._value;
	}
	//getters
	operator ValueType()
	{
		return _value;
	}
	const ValueType& Get()
	{
		return _value;
	}
	//setters
	const ValueType& operator=(const ValueType& value)
	{
		return this->Set(value);
	}
	const ValueType& operator=(const Property<ValueType>& p)
	{
		return this->Set(p._value);
	}
	const ValueType& Set(const ValueType& value)
	{
		_value = value;
		notify();
		return _value;
	}
	//compare
	bool operator==(ValueType& value)
	{
		return _value == value;
	}
	bool operator==(const Property<ValueType>& p)
	{
		return _value == p._value;
	}
	bool operator!=(ValueType& value)
	{
		return _value != value;
	}
	bool operator!=(const Property<ValueType>& p)
	{
		return _value != p._value;
	}
	//listeners:

	~Property()
	{
	}
};



template<typename ValueType>
class PropertyList
{
	std::map<std::string, Property<ValueType> * > properties;
public:
	bool AddProperty(const std::string& key, OWNERSHIP Property<ValueType>* prop)
	{
		if (properties.find(key) != properties.end())
		{
			properties.insert(std::pair<std::string,Property<ValueType> * >(key,prop));
			return true;
		}
		return false;
	}
	void RemoveProperty(const std::string& key)
	{
		properties.erease(key);
	}
	Property<ValueType>& operator[](const std::string& key)
	{
		return properties[key];
	}
	bool hasProperty(const std::string& key)
	{
		if (properties.find(key) != properties.end())
		{
			return true;
		}
		return false;
	}
};



#endif /* PROPERTY_HPP_ */
