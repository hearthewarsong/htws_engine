#ifndef CONTAINER_HPP_
#define CONTAINER_HPP_


template<class T>
class SContainer: public T
{
protected:
	typedef vector<SContainer<T>*> ChildList;
	ChildList children;
public:
	virtual vector<SContainer<T>*>& GetCildren()
	{
		return children;
	}
	virtual bool HasChildren() const
	{
		return children.size() != 0;
	}
	virtual bool AddChildren(OWNERSHIP SContainer<T>* child)
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
	virtual void SortChildren() { std::sort(children.begin(), children.end());}
	virtual ~SContainer()
	{
		for(int i = 0; i<children.size(); ++i)
		{
			delete children[i];
		}
	}
};

#endif /* CONTAINER_HPP_ */
