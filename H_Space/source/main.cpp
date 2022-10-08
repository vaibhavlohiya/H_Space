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

	Matrix<int, 10, 10> big1(exp1);
	std::cout << "Big matrix1 : " << "\n" << big1 << "\n";

	for (int i = 0; i < exp2.size(); i++)
		if (i % 2 != 0) exp2[i] = 1;

	Matrix<int, 10, 10> big2(exp2);
	std::cout << "Big matrix2 : " << "\n" << big2 << "\n";
	
	std::cout << "Big matrix 1 + Big matrix 2 : " << "\n" << big1 + big2 << "\n";

	std::cin.get();

}