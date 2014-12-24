#ifndef HTWS_MATH_MATRIX_HPP_
#define HTWS_MATH_MATRIX_HPP_


template<typename FieldData>
class Matrix
{
protected:
	FieldData* fields;
	int rowCount;
	int columnCount;
public:
	// rows and columns are fuckedd up
	Matrix(int rowCount, int columnCount) :rowCount(rowCount), columnCount(columnCount)
	{
		fields = new FieldData[rowCount*columnCount];
	}


	FieldData* operator[](int row) { return &fields[row*columnCount]; }
	const FieldData* operator[](int row) const { return &fields[row*columnCount]; }
};

class IntMatrix : public Matrix<int>
{
public:
	IntMatrix(int rowCount, int columnCount) :Matrix<int>(rowCount,columnCount) {}
};

#endif /* HTWS_MATH_MATRIX_HPP_ */
