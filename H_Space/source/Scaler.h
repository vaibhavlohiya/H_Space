#pragma once


// Scaler class is used to store scaler quantities in the system. It is also used as base class 
// for class vector hence we call it a rank = 0 tensor.
 
class Scaler
{
public:
	float m_Data;

	// Class Constructors

	Scaler() = default;
	Scaler(const float& Data);

	// Class Methods

	const float Data() const;
	Scaler Addition(const Scaler& other);
	Scaler Subtract(const Scaler& other);
	Scaler Multiply(const Scaler& other);
	Scaler Divide(const Scaler& other);


	// Class Operator Overloads

	Scaler operator+(const Scaler& other);
	Scaler operator-(const Scaler& other);
	Scaler operator*(const Scaler& other);
	Scaler operator/(const Scaler& other);

	// Class Destructor

	virtual ~Scaler();

private:

};