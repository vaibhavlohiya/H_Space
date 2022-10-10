#include <iostream>
#include <array>

#include "Matrix.h"

int main()
{
	Scaler<std::string> h("hello"), m("my name is"), v("Vaibhav");

	Matrix<const char*, 2, 3> mat_str({ "Hello", "My" , "name",  "is", "Vaibhav", "Nice to meet you" });
	Matrix<double, 2, 3> mat_basic({ 1, 2, 3, 4, 5, 7 });

	std::cout << "Matrix of Strings is given below: " << "\n" << mat_str;

	std::cout << "\n" << mat_str[1][2] << "\n";

	std::array<Scaler<int>, 100> exp1 = {};
	std::array<Scaler<int>, 100> exp2 = {};

	for (int i = 0; i < exp1.size(); i++)
		if (i % 2 == 0) exp1[i] = 1;

	Matrix<int, 5, 20> big1(exp1);
	std::cout << "Big matrix1 : " << "\n" << big1 << "\n";

	for (int i = 0; i < exp2.size(); i++)
		if (i % 2 != 0) exp2[i] = 1;

	Matrix<int, 20, 5> big2(exp2);
	std::cout << "Big matrix2 : " << "\n" << big2 << "\n";

	Matrix<int, 2, 3> m1({ 1, 2, 3, 4, 5, 6});
	Matrix<int, 3, 3> m2({ 7, 8, 9, 10, 11, 12, 13, 14, 15 });

	std::cout << "Result: " << "\n" << m1 * m2; // matrix multiplication of 5x20 and 20x5 matrix.

	std::cout << "\n" << m1.GetColumnVector(2) << "\n" << m2 * 10 << "\n"<< m2[1][2];

	std::cout << "\n The matrix m1 is : \n" << m1;
	std::cout << "\n The transpose of m1 is : \n" << m1.Transpose();

	std::cout << "\n The matrix m2 is : \n" << m2;
	std::cout << "\n The tranpose of matrix m2: \n" << m2.Transpose();

	std::cin.get();
}