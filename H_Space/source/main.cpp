#include <iostream>
#include <array>

#include "Scaler.h"
#include "Vector.h"
#include "Matrix.h"

int main()
{
	//std::cout << "x-x-x-x-x-x-x-x-x-x-x-x- [SCALERS] -x-x-x-x-x-x-x-x-x-x-x-x-x-x" << "\n";

	Scaler x1(1), x2(2), x3(3), x4(4);
	Scaler y1(5), y2(6), y3(7), y4(8);
	Scaler z1(9), z2(10), z3(11), z4(12);

	// Implicit Conversion

	Scaler sum  = x1 + x2;       // Add
	Scaler diff = x1 - x2;		// Subtract 
	Scaler prod = x1 * x2;		// Multiply
	Scaler quot = x1 / x2;		// Divide

	std::cout << "Sum of x1 and x2: " << sum << std::endl;
	std::cout << "Difference b/w x1 and x2: " << diff << std::endl;
	std::cout << "Product of x1 and x2: " << prod << std::endl;
	std::cout << "Quotient of x1 and x2: " << quot << std::endl;

	std::cout << "x-x-x-x-x-x-x-x-x-x-x- [VECTORS] -x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << "\n";

	std::array<Scaler, 4> x_axis = { x1, x2, x3, x4 };
	std::array<Scaler, 4> y_axis = { y1, y2, y3, y4 };
	std::array<Scaler, 4> z_axis = { z1, z2, z3, y4 };
 
	Vector v1(x_axis), v2(y_axis), v3(z_axis);

	Vector vec_sum = v1 + v2; // Adding two vectors
	std::cout << "The sum of two vectors v1, v2 and v3 is " << vec_sum << std::endl;

	Vector vec_diff = v1 - v2; // Subtracting two vectors
	std::cout << "The difference b/w vectors v1 and v2 is " << vec_diff << std::endl;

	Scaler vec_dot = v1.DotProduct(v2); // Scaler Dot product of two vectors
	std::cout << "The dot product two vectors v1 and v2 is " << vec_dot << std::endl; // 81.97

	Vector vec_cross = v1 * v2 ; // Vector Cross product two vectors
	std::cout << "The cross product b/w two vectors v1 and v2 is " << vec_cross << std::endl; // -41.19, 210.006, -69.992

	std::cout << "x-x-x-x-x-x-x-x-x-x-x-x-x- [MATRIX] -x-x-x-x-x-x-x-x-x-x-x-x-x" << std::endl;

	Matrix matrix({ x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4 });
	Scaler Ten(10);

	std::cout << "The matrix after multiplying with a scaler: " << "\n" << matrix.prod_Scaler(Ten);

	Matrix Prod = matrix + Ten;

	std::cout << "The prod array is " << "\n" << Prod;
	std::cout << "The matrix array is " << "\n" << matrix;
	std::cout << "Column vector is " << matrix.GetColumnVector(0) << "\n";
	std::cout << "Column vector of prod is " << "\n" << Prod.GetColumnVector(0) << "\n";

	std::cin.get();
}