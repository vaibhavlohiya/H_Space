#include <iostream>
#include <array>

#include "Scaler.h"
#include "Vector.h"

int main()
{
	Scaler x1(1), x2(2), x3(3), x4(4);
	Scaler y1(5), y2(6), y3(7), y4(8);
	Scaler z1(9), z2(10), z3(11), z4(12);

	// Implicit Conversion

	Scaler sum  = x1 + x2;       // Add
	Scaler diff = x1 - x2;		// Subtract 
	Scaler prod = x1 * x2;		// Multiply
	Scaler quot = x1 / x2;		// Divide

	std::cout << "Sum of x1 and x2: " << sum.Data() << std::endl;
	std::cout << "Difference b/w x1 and x2: " << diff.Data() << std::endl;
	std::cout << "Product of x1 and x2: " << prod.Data() << std::endl;
	std::cout << "Quotient of x1 and x2: " << quot.Data() << std::endl;

	std::cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << "\n";

	std::array<Scaler, 3> x_axis = { x1, x2, x3 };
	std::array<Scaler, 3> y_axis = { y1, y2, y3 };
	std::array<Scaler, 3> z_axis = { z1, z2, z3 };
 
	Vector v1(x_axis), v2(y_axis), v3(z_axis);

	Vector vec_sum = v1 + v2 + v3; // Adding two vectors
	std::cout << "The sum of three vectors v1, v2 and v3 is " << vec_sum << std::endl;

	std::cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << "\n";

	Vector vec_diff = v1 - v2 - v3; // Subtracting two vectors
	std::cout << "The difference b/w vectors v1, v2 and v3 is " << vec_diff << std::endl;

	std::cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << "\n";

	Scaler vec_dot = v1.DotProduct(v2); // Scaler Dot product of two vectors
	std::cout << "The dot product two vectors v1 and v2 is " << vec_dot.Data() << "\n"; // 81.97

	std::cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << std::endl;

	Vector vec_cross = v1 * v2 ; // Vector Cross product two vectors
	std::cout << "The cross product b/w two vectors v1 and v2 is " << vec_cross << std::endl; // -41.19, 210.006, -69.992

	std::cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << "\n";

	std::cin.get();
}