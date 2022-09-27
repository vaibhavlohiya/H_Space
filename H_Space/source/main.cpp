#include <iostream>
#include <array>

#include "Scaler.h"
#include "Vector.h"

int main()
{
	Scaler x1(5.1f), x2(3.1f), x3(6.3f);
	Scaler y1(1.3f), y2(6.4f), y3(5.2f);

	Scaler sum = x1 + x2;       // Add
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

	Vector v1(x_axis), v2(y_axis);

	Vector vec_sum = v1.Add(v2); // Adding two vectors
	std::cout << "The sum of two vectors v1 and v2 is " << vec_sum << std::endl;

	std::cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << "\n";

	Vector vec_diff = v1.Subtract(v2); // Subtracting two vectors
	std::cout << "The difference b/w two vectors v1 and v2 is " << vec_diff << std::endl;

	std::cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << "\n";

	Scaler vec_dot = v1.DotProduct(v2); // Dot product of two vectors
	std::cout << "The dot product two vectors v1 and v2 is " << vec_dot.Data() << "\n";

	std::cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << std::endl;

	Vector vec_cross = v1.CrossProduct(v2); // Cross product two vectors
	std::cout << "The difference b/w two vectors v1 and v2 is " << vec_cross << std::endl;

	std::cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << "\n";

	std::cin.get();
}