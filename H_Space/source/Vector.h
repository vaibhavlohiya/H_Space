#pragma once

#include <iostream>
#include <array>

#include "Scaler.h"


class Vector
{
public:
	static const size_t m_Size = 3;
	std::array<Scaler, m_Size> m_Data;
	
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
	Vector operator*(const Vector& other);  // Multiplication operator for cross product

	Scaler& operator[](size_t index);
	const Scaler& operator[](size_t index) const;

	// Friend functions

	friend std::ostream& operator<<(std::ostream& stream, const Vector& V_out);

private:
	
};

inline std::ostream& operator<<(std::ostream& stream, const Vector& V_out)
{
	for (size_t i = 0; i < V_out.size(); i++)
		stream << V_out[i].Data() << " ";

	return stream;
}