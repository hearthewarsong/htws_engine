#ifndef VECTOR_HANDLING_HPP_
#define VECTOR_HANDLING_HPP_


namespace htws_math
{

template<typename T>
bool allElementsEqualTo(const vector<T>& vec, const T& value)
{
	for (unsigned i = 0; i<vec.size(); ++i)
	{
		if (vec[i]!=value) return false;
	}
	return true;
}

template<typename T>
bool HasSmallerElementThan(const vector<T>& vec, const T& value)
{
	for (unsigned i = 0; i<vec.size(); ++i)
	{
		if (vec[i]<value) return true;
	}
	return false;
}

template<typename T>
bool HasGraterElementThan(const vector<T>& vec, const T& value)
{
	for (unsigned i = 0; i<vec.size(); ++i)
	{
		if (vec[i]>value) return true;
	}
	return false;
}

template<typename T>
bool LessThanOrEqualTo(const vector<T>& vec1, const vector<T>& vec2)
{
	if (vec1.size() != vec2.size())
	{
		LLF("algorithm",Format("Different size vectors in %s. vec1.size()=%d, vec2.size() = %d", __PRETTY_FUNCTION__ % vec1.size() % vec2.size()));
		return false;
	}
	for (unsigned i = 0; i<vec1.size(); ++i)
	{
		if (vec1[i]>vec2[i]) return false;
	}
	return true;
}

template<typename T>
bool LessThan(const vector<T>& vec1, const vector<T>& vec2)
{
	if (vec1.size() != vec2.size())
	{
		LLF("algorithm",Format("Different size vectors in %s. vec1.size()=%d, vec2.size() = %d", __PRETTY_FUNCTION__ % vec1.size() % vec2.size()));
		return false;
	}
	for (unsigned i = 0; i<vec1.size(); ++i)
	{
		if (vec1[i]>=vec2[i]) return false;
	}
	return true;
}


template<typename T>
vector<T> SubtractVector(const vector<T>& vec1, const vector<T>& vec2)
{
	if (vec1.size() != vec2.size())
	{
		LLF("algorithm",Format("Different size vectors in %s. vec1.size()=%d, vec2.size() = %d", __PRETTY_FUNCTION__ % vec1.size() % vec2.size()));
		return vec1;
	}
	vector<T> result = vec1;
	for (unsigned i = 0; i<vec1.size(); ++i)
	{
		result[i]-=vec2[i];
	}
	return result;
}

template<typename T>
vector<T> AddVector(const vector<T>& vec1, const vector<T>& vec2)
{
	if (vec1.size() != vec2.size())
	{
		LLF("algorithm",Format("Different size vectors in %s. vec1.size()=%d, vec2.size() = %d", __PRETTY_FUNCTION__ % vec1.size() % vec2.size()));
		return vec1;
	}
	vector<T> result = vec1;
	for (unsigned i = 0; i<vec1.size(); ++i)
	{
		result[i]+=vec2[i];
	}
	return result;
}


}


#endif /* VECTOR_HANDLING_HPP_ */
