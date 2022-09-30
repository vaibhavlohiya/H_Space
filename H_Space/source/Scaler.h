#pragma once


// Scaler class is used to store scaler quantities in the system. It is also used as base class 
// for class vector hence we call it a rank = 0 tensor.

#include <iostream>
 
class Scaler
{
public:

	// Class Constructors

	Scaler() = default;
	Scaler(const int& Data);

	// Class Methods

	const int Data() const;

	Scaler Addition(const Scaler& other);
	Scaler Subtract(const Scaler& other);
	Scaler Multiply(const Scaler& other);
	Scaler Divide(const Scaler& other);


	// Class Operator Overloads

	Scaler operator+(const Scaler& other);
	Scaler operator-(const Scaler& other);
	Scaler operator*(const Scaler& other);
	Scaler operator/(const Scaler& other);

	bool operator==(const Scaler& other);

	Scaler operator+=(const Scaler& other);
	Scaler operator-=(const Scaler& other);
	Scaler operator*=(const Scaler& other);

	friend std::ostream& operator<<(std::ostream& stream, const Scaler& S_out);

	// Class Destructor

	virtual ~Scaler() {}

private:

	int m_Value = 0;

};