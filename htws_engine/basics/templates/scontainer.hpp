#ifndef CONTAINER_HPP_
#define CONTAINER_HPP_


template<class T>
class SContainer: public T
{
protected:
	typedef vector<SContainer<T>*> ChildList;
	ChildList children;
public:
	virtual const vector<SContainer<T>*>& GetCildren() const
	{
		return children;
	}
	virtual bool HasChildren() const
	{
		return children.size() != 0;
	}
	virtual bool AddChildren(SContainer<T>* child)
	{
		if (std::find(children.begin(), children.end(), child)
				!= children.end())
		{
			return false;
		}
		children.push_back(child);
		return true;
	}
	virtual bool RemoveChildren(SContainer<T>* child)
	{
		if (std::find(children.begin(), children.end(), child)
				!= children.end())
		{
			children.erase(std::find(children.begin(), children.end(), child));
			return true;
		}
		return false;
	}
	virtual bool CanHaveChildren()
	{
		return true;
	}
	virtual ~SContainer() {}
};

#endif /* CONTAINER_HPP_ */
