#pragma once

#include "MyMatrix.h"

class MatrixView
{
public:
	MatrixView(MyMatrix& myMatrix,
		size_t upperLeftRow, size_t upperLeftCol,
		size_t lowerRightRow, size_t lowerRightCol);

	MatrixView(MatrixView& view,
		size_t upperLeftRow, size_t upperLeftCol,
		size_t lowerRightRow, size_t lowerRightCol);

	void print(std::ostream& os = cout) const;

	size_t rows() const;
	size_t cols() const;

	int & operator()(size_t row, size_t col);
	
	MatrixView& operator*=(const int scalar);
	MatrixView& operator+=(const int scalar);
	MatrixView& operator-=(const int scalar);

	void transpose();
	void transposeOffDiagonal();

	void fill(int value);
	friend std::ostream& operator<<(std::ostream& os, MyMatrix& m);

private:
	MyMatrix& view;

	size_t upperLeftRow;
	size_t upperLeftCol;
	size_t lowerRightRow;
	size_t lowerRightCol;
};