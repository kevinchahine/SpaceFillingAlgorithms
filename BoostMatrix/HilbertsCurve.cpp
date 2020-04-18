#include "HilbertsCurve.h"

void HilbertsCurve::make2x2()
{
	MyMatrix hc(2, 2, 0);

	hc(1, 0) = 1;
	hc(0, 0) = 2;
	hc(0, 1) = 3;
	hc(1, 1) = 4;

	hc.print();
}

void HilbertsCurve::make4x4()
{
	MyMatrix hc(4, 4, 0);

	MatrixView view1(hc, 2, 0, 4, 2);
	MatrixView view2(hc, 0, 0, 2, 2);
	MatrixView view3(hc, 0, 2, 2, 4);
	MatrixView view4(hc, 2, 2, 4, 4);

	view1.fill(4 * 1);
	view2.fill(4 * 2);
	view3.fill(4 * 3);
	view4.fill(4 * 4);

	view1(0, 0) -= 2;
	view1(1, 0) -= 3;
	view1(0, 1) -= 1;
	view1(1, 1) -= 0;

	view2(0, 0) -= 2;
	view2(1, 0) -= 3;
	view2(0, 1) -= 1;
	view2(1, 1) -= 0;

	view3(0, 0) -= 2;
	view3(1, 0) -= 3;
	view3(0, 1) -= 1;
	view3(1, 1) -= 0;

	view4(0, 0) -= 2;
	view4(1, 0) -= 3;
	view4(0, 1) -= 1;
	view4(1, 1) -= 0;

	hc.print();

	// --- transpose matricies ---

	view1.transposeOffDiagonal();
	view4.transpose();

	hc.print();
}

void HilbertsCurve::make8x8()
{
	MyMatrix hc(8, 8, 0);

	// --- 4x4 quarters ---
	MatrixView view1(hc, 4, 0, 8, 4);
	MatrixView view2(hc, 0, 0, 4, 4);
	MatrixView view3(hc, 0, 4, 4, 8);
	MatrixView view4(hc, 4, 4, 8, 8);

	view1.fill(4 * 4 * 1);
	view2.fill(4 * 4 * 2);
	view3.fill(4 * 4 * 3);
	view4.fill(4 * 4 * 4);

	hc.print();
	
	// --- 2x2 16ths ---
	// 1st 1/4
	MatrixView view1_1(view1, 2, 0, 4, 2);
	MatrixView view1_2(view1, 0, 0, 2, 2);
	MatrixView view1_3(view1, 0, 2, 2, 4);
	MatrixView view1_4(view1, 2, 2, 4, 4);

	view1_1 -= 4 * 3;
	view1_2 -= 4 * 2;
	view1_3 -= 4 * 1;
	view1_4 -= 4 * 0;

	// 2nd 1/4
	MatrixView view2_1(view2, 2, 0, 4, 2);
	MatrixView view2_2(view2, 0, 0, 2, 2);
	MatrixView view2_3(view2, 0, 2, 2, 4);
	MatrixView view2_4(view2, 2, 2, 4, 4);

	view2_1 -= 4 * 3;
	view2_2 -= 4 * 2;
	view2_3 -= 4 * 1;
	view2_4 -= 4 * 0;
	
	// 3rd 1/4
	MatrixView view3_1(view3, 2, 0, 4, 2);
	MatrixView view3_2(view3, 0, 0, 2, 2);
	MatrixView view3_3(view3, 0, 2, 2, 4);
	MatrixView view3_4(view3, 2, 2, 4, 4);

	view3_1 -= 4 * 3;
	view3_2 -= 4 * 2;
	view3_3 -= 4 * 1;
	view3_4 -= 4 * 0;

	// 4th 1/4
	MatrixView view4_1(view4, 2, 0, 4, 2);
	MatrixView view4_2(view4, 0, 0, 2, 2);
	MatrixView view4_3(view4, 0, 2, 2, 4);
	MatrixView view4_4(view4, 2, 2, 4, 4);

	view4_1 -= 4 * 3;
	view4_2 -= 4 * 2;
	view4_3 -= 4 * 1;
	view4_4 -= 4 * 0;

	// --- 1x1 64ths ---
	view1_1(1, 0) -= 3;
	view1_1(0, 0) -= 2;
	view1_1(0, 1) -= 1;
	view1_1(1, 1) -= 0;

	view1_2(1, 0) -= 3;
	view1_2(0, 0) -= 2;
	view1_2(0, 1) -= 1;
	view1_2(1, 1) -= 0;

	view1_3(1, 0) -= 3;
	view1_3(0, 0) -= 2;
	view1_3(0, 1) -= 1;
	view1_3(1, 1) -= 0;

	view1_4(1, 0) -= 3;
	view1_4(0, 0) -= 2;
	view1_4(0, 1) -= 1;
	view1_4(1, 1) -= 0;

	view2_1(1, 0) -= 3;
	view2_1(0, 0) -= 2;
	view2_1(0, 1) -= 1;
	view2_1(1, 1) -= 0;

	view2_2(1, 0) -= 3;
	view2_2(0, 0) -= 2;
	view2_2(0, 1) -= 1;
	view2_2(1, 1) -= 0;

	view2_3(1, 0) -= 3;
	view2_3(0, 0) -= 2;
	view2_3(0, 1) -= 1;
	view2_3(1, 1) -= 0;

	view2_4(1, 0) -= 3;
	view2_4(0, 0) -= 2;
	view2_4(0, 1) -= 1;
	view2_4(1, 1) -= 0;

	view3_1(1, 0) -= 3;
	view3_1(0, 0) -= 2;
	view3_1(0, 1) -= 1;
	view3_1(1, 1) -= 0;

	view3_2(1, 0) -= 3;
	view3_2(0, 0) -= 2;
	view3_2(0, 1) -= 1;
	view3_2(1, 1) -= 0;

	view3_3(1, 0) -= 3;
	view3_3(0, 0) -= 2;
	view3_3(0, 1) -= 1;
	view3_3(1, 1) -= 0;

	view3_4(1, 0) -= 3;
	view3_4(0, 0) -= 2;
	view3_4(0, 1) -= 1;
	view3_4(1, 1) -= 0;

	view4_1(1, 0) -= 3;
	view4_1(0, 0) -= 2;
	view4_1(0, 1) -= 1;
	view4_1(1, 1) -= 0;

	view4_2(1, 0) -= 3;
	view4_2(0, 0) -= 2;
	view4_2(0, 1) -= 1;
	view4_2(1, 1) -= 0;

	view4_3(1, 0) -= 3;
	view4_3(0, 0) -= 2;
	view4_3(0, 1) -= 1;
	view4_3(1, 1) -= 0;

	view4_4(1, 0) -= 3;
	view4_4(0, 0) -= 2;
	view4_4(0, 1) -= 1;
	view4_4(1, 1) -= 0;

	hc.print();

	// --- transpose ---
	// 2x2
	view1_1.transposeOffDiagonal();
	view1_4.transpose();

	view2_1.transposeOffDiagonal();
	view2_4.transpose();

	view3_1.transposeOffDiagonal();
	view3_4.transpose();

	view4_1.transposeOffDiagonal();
	view4_4.transpose();

	// 4x4
	view1.transposeOffDiagonal();
	view4.transpose();

	hc.print();
}
