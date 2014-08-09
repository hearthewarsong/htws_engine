#ifndef MATH_CLASSES_HPP_
#define MATH_CLASSES_HPP_

template<class T>
class NumVector
{
public:
	T x;
	T y;
	T z;
	NumVector(double x, double y, double z = 0) :
			x(x), y(y), z(z)
	{
	}

};

#endif /* MATH_CLASSES_HPP_ */
