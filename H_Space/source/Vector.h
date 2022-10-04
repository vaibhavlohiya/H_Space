#pragma once

#include <array>

#include "Scaler.h"


class Vector
{
public:
	static const size_t m_Size = 3;

	// Class Constructors

	Vector() = default;
	Vector(const std::array<Scaler, m_Size>& Components); 

	// Class Methods

	const size_t size() const;
	Vector Add(const Vector& other);
	Vector Subtract(const Vector& other);
	Scaler DotProduct(const Vector& other);
	Vector CrossProduct(const Vector& other);

	// Class Operator Overloads

	Vector operator+(const Vector& other);  // Addition operator 
	Vector operator-(const Vector& other);  // Subtraction operator
	Scaler operator*(const Vector& other);  // Multiplication operator for cross product

	Scaler& operator[](size_t& index);
	const Scaler& operator[](size_t& index) const;

	// Class Friend functions

	friend std::ostream& operator<<(std::ostream& stream, const Vector& V_out);

	// Class Destructor

	virtual ~Vector() {}

private:

	// Class Members
	std::array<Scaler, m_Size> m_VectorArray;
	
};

