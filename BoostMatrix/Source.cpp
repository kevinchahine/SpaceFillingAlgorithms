#include <iostream>
using std::cout;
using std::cin;

#include "MyMatrix.h"
#include "MatrixView.h"

#include "HilbertsCurve.h"

int main()
{
	//MyMatrix curve(8, 8, 0);
	//curve.print();

	//MatrixView view1(curve, 4, 0, 8, 4);
	//view1.fill(1);

	//MatrixView view2(curve, 0, 0, 4, 4);
	//view2.fill(2);

	//MatrixView view3(curve, 0, 4, 4, 8);
	//view3.fill(3);

	//MatrixView view4(curve, 4, 4, 8, 8);
	//view4.fill(4);

	//
	////view.transposeOffDiagonal();
	////view.transpose();
	//curve.print();

	HilbertsCurve::make2x2();
	HilbertsCurve::make4x4();
	HilbertsCurve::make8x8();
	cout << "Press any key...";
	cin.get();
	return 0;
}