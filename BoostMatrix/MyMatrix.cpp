#include "MyMatrix.h"

MyMatrix::MyMatrix(size_t nRows, size_t nCols, int value) :
	matrix<int>(nRows, nCols, value)
{
}

void MyMatrix::print(std::ostream& os) const
{
	auto flags = cout.flags();
	cout << std::left;

	for (size_t row = 0; row < this->size1(); row++) {
		os << "[ ";
		for (size_t col = 0; col < this->size2(); col++) {
			os << std::setw(4) << (*this)(row, col);
		}
		os << ']' << '\n';
	}
	os << '\n';

	cout.flags(flags);
}

size_t MyMatrix::rows() const
{
	return this->size1();
}

size_t MyMatrix::cols() const
{
	return this->size2();
}

void MyMatrix::flipPositiveDiagonal(
	size_t upperLeftRow, size_t upperLeftCol, 
	size_t lowerRightRow, size_t lowerRightCol)
{
	const size_t WIDTH = lowerRightCol - upperLeftRow;
	const size_t HEIGHT = lowerRightRow - upperLeftRow;

	size_t row1 = 0, col1 = 0;
	size_t row2 = 0, col2 = 0;

	//for (size_t r = 0; r < rows(); r++) {
	//	for (size_t c = 0; c < cols(); c++) {

	//	}
	//}
}

void MyMatrix::flipNegativeDiagonal(
	size_t upperLeftRow, size_t upperLeftCol, 
	size_t lowerRightRow, size_t lowerRightCol)
{
	const size_t WIDTH = lowerRightCol - upperLeftRow;
	const size_t HEIGHT = lowerRightRow - upperLeftRow;

}

std::ostream& operator<<(std::ostream& os, MyMatrix& m)
{
	os << static_cast<boost::numeric::ublas::matrix<int>>(m);

	return os;
}
