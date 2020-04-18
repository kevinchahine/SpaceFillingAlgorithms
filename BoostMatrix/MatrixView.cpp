#include "MatrixView.h"

MatrixView::MatrixView(
	MyMatrix& myMatrix,
	size_t upperLeftRow, 
	size_t upperLeftCol,
	size_t lowerRightRow, 
	size_t lowerRightCol) :
	view(myMatrix),
	upperLeftRow(upperLeftRow), 
	upperLeftCol(upperLeftCol),
	lowerRightRow(lowerRightRow), 
	lowerRightCol(lowerRightCol)
{
}

MatrixView::MatrixView(
	MatrixView& view, 
	size_t upperLeftRow, 
	size_t upperLeftCol, 
	size_t lowerRightRow, 
	size_t lowerRightCol) :
	view(view.view),
	upperLeftRow(view.upperLeftRow + upperLeftRow), 
	upperLeftCol(view.upperLeftCol + upperLeftCol),
	lowerRightRow(view.upperLeftRow + lowerRightRow),
	lowerRightCol(view.upperLeftCol + lowerRightCol)
{
}

void MatrixView::print(std::ostream& os) const
{
	auto flags = cout.flags();
	cout << std::left;

	for (size_t row = upperLeftRow; row < lowerRightRow; row++) {
		os << "[ ";
		for (size_t col = upperLeftCol; col < lowerRightCol; col++) {
			os << std::setw(4) << view(row, col);
		}
		os << ']' << '\n';
	}
	os << '\n';

	cout.flags(flags);
}

size_t MatrixView::rows() const
{
	return lowerRightRow - upperLeftRow;
}

size_t MatrixView::cols() const
{
	return lowerRightCol - upperLeftCol;
}

int & MatrixView::operator()(size_t row, size_t col)
{
	return view(row + upperLeftRow, col + upperLeftCol);
}

MatrixView& MatrixView::operator*=(const int scalar)
{
	for (size_t r = 0; r < rows(); r++) {
		for (size_t c = 0; c < cols(); c++) {
			(*this)(r, c) *= scalar;
		}
	}

	return *this;
}

MatrixView& MatrixView::operator+=(const int scalar)
{
	for (size_t r = 0; r < rows(); r++) {
		for (size_t c = 0; c < cols(); c++) {
			(*this)(r, c) += scalar;
		}
	}

	return *this;
}

MatrixView& MatrixView::operator-=(const int scalar)
{
	for (size_t r = 0; r < rows(); r++) {
		for (size_t c = 0; c < cols(); c++) {
			(*this)(r, c) -= scalar;
		}
	}

	return *this;
}

void MatrixView::transpose()
{
	for (size_t r = 0; r < rows(); r++) {
		for (size_t c = r + 1; c < cols(); c++) {
			std::swap((*this)(r, c), (*this)(c, r));
		}
	}
}

void MatrixView::transposeOffDiagonal()
{
	for (size_t r = 0; r < rows() - 1; r++) {
		for (size_t c = 0; c < cols() - r - 1; c++) {
			std::swap((*this)(r, c), (*this)(cols() - c - 1, rows() - r - 1));
		}
	}
}

void MatrixView::fill(int value)
{
	for (size_t r = 0; r < rows(); r++) {
		for (size_t c = 0; c < cols(); c++) {
			(*this)(r, c) = value;
		}
	}
}
