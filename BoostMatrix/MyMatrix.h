#pragma once

#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

class MyMatrix : public boost::numeric::ublas::matrix<int>
{
public:
	MyMatrix() = default;
	MyMatrix(size_t nRows, size_t nCols, int value = 0);
	MyMatrix(const MyMatrix&) = default;
	MyMatrix(MyMatrix&&) noexcept = default;
	~MyMatrix() noexcept = default;

	MyMatrix& operator=(const MyMatrix&) = default;
	MyMatrix& operator=(MyMatrix&&) noexcept = default;

	void print(std::ostream& os = cout) const;

	size_t rows() const;
	size_t cols() const;

	void flipPositiveDiagonal(
		size_t upperLeftRow, size_t upperLeftCol,
		size_t lowerRightRow, size_t lowerRightCol);
	
	void flipNegativeDiagonal(
		size_t upperLeftRow, size_t upperLeftCol,
		size_t lowerRightRow, size_t lowerRightCol);

	friend std::ostream& operator<<(std::ostream & os, MyMatrix& m);
};
