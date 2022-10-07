#pragma once


// Scaler class is used to store scaler quantities in the system. It is also used as base class 
// for class vector hence we call it a rank = 0 tensor.

#include <iostream>

class Scaler
{
public:

	// Class Constructors

	Scaler() = default;
	Scaler(const double& Data);

	// Class Methods

	double Data();
	const double Data() const;

	Scaler addition(const Scaler& other);
	Scaler subtract(const Scaler& other);
	Scaler multiply(const Scaler& other);
	Scaler divide(const Scaler& other);


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

	double m_Value = 0;

};
