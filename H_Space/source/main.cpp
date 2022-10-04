#include <iostream>
#include <array>

#include "Scaler.h"
#include "Vector.h"
#include "Matrix.h"

int main()
{
	std::cout << "x-x-x-x-x-x-x-x-x-x-x-x- [SCALERS] -x-x-x-x-x-x-x-x-x-x-x-x-x-x" << "\n";

	Scaler x1(1), x2(2), x3(3), x4(4);
	Scaler y1(5), y2(6), y3(7), y4(8);
	Scaler z1(9), z2(10), z3(11), z4(12);

	// Implicit Conversion

	Scaler sum = x1 + x2;       // Add
	Scaler diff = x1 - x2;		// Subtract 
	Scaler prod = x1 * x2;		// Multiply
	Scaler quot = x1 / x2;		// Divide

	std::cout << "Sum of x1 and x2: " << sum << std::endl;
	std::cout << "Difference b/w x1 and x2: " << diff << std::endl;
	std::cout << "Product of x1 and x2: " << prod << std::endl;
	std::cout << "Quotient of x1 and x2: " << quot << std::endl;

	std::cout << "x-x-x-x-x-x-x-x-x-x-x- [VECTORS] -x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << "\n";

	std::array<Scaler, 3> x_axis = { x1, x2, x3 };
	std::array<Scaler, 3> y_axis = { y1, y2, y3 };
	std::array<Scaler, 3> z_axis = { z1, z2, z3 };

	Vector v1(x_axis), v2(y_axis), v3(z_axis);

	Vector v4({ -2, -4, -6 }), v5({ -1, -3, -5 }), v6({ -7, -9, -11 }); // implicit conversion

	Vector vec_sum = v4 + v5; // Adding two vectors
	std::cout << "The sum of two vectors v4 and v5 is " << vec_sum << std::endl;

	Vector vec_diff = v1 - v2; // Subtracting two vectors
	std::cout << "The difference b/w vectors v1 and v2 is " << vec_diff << std::endl;

	Scaler vec_dot = v1 * v2; // Scaler Dot product of two vectors
	std::cout << "The dot product two vectors v1 and v2 is " << vec_dot << std::endl; // 81.97

	Vector vec_cross = v1.CrossProduct(v2); // Vector Cross product two vectors
	std::cout << "The cross product b/w two vectors v1 and v2 is " << vec_cross << std::endl; // -41.19, 210.006, -69.992

	std::cout << "x-x-x-x-x-x-x-x-x-x-x-x-x- [MATRIX] -x-x-x-x-x-x-x-x-x-x-x-x-x" << std::endl;

	Matrix matrix1({ v1, v2, v3 }, 'R');
	Matrix matrix2({ v1, v2, v3 }, 'C');
	Scaler Ten(10);

	Scaler* m1_linear = matrix1.GetLinearData();
	Scaler* m2_linear = matrix2.GetLinearData();

	for (size_t i = 0; i < matrix1.GetRows() * matrix1.GetColumns(); i++)
		std::cout << m1_linear[i] << " ";

	std::cout << "\n";

	for (size_t i = 0; i < matrix2.GetRows() * matrix2.GetColumns(); i++)
		std::cout << m2_linear[i] << " ";

	std::cout << "\n";

	std::cout << "Matrix 1 : " << "\n" << matrix1;
	std::cout << "Matrix 2 : " << "\n" << matrix2;

	matrix1.Transpose();
	std::cout << "Transpose of Matrix 1 is " << "\n" << matrix1;

	std::cout << "Matrix 1 + Matrix 2 : " << "\n" << matrix1 + matrix2;

	std::cout << "The matrix1 after multiplying with a scaler: " << "\n" << matrix1.prod_Scaler(Ten);

	Matrix Prod = matrix1 + Ten;

	std::cout << "The prod array is " << "\n" << Prod;
	std::cout << "Column vector of matrix1 is " << matrix1.GetColumnVector(0) << "\n";
	std::cout << "Column vector of prod is " << "\n" << Prod.GetColumnVector(0) << "\n";

	Vector v7({ 1, 1, 1 }), v8({ 2, 2, 2 }), v9({ 3, 3, 3 });

	Matrix matrix3({ v7, v8, v9 }, 'R');
	Matrix matrix4({ v9, v8, v7 }, 'R'); 

	Matrix multiply = matrix3 * matrix4;

	std::cout << "Multiplication of matrix 3 & 4 is " << "\n" << multiply;

	std::cin.get();
}