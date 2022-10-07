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

	Scaler* Data();
	const Scaler* Data() const;

	const size_t size() const;

	Vector add(const Vector& other);
	Vector subtract(const Vector& other);
	Scaler dotProduct(const Vector& other);
	Vector crossProduct(const Vector& other);

	Vector addScaler(const Scaler& other);
	Vector subtractScaler(const Scaler& other);
	Vector prodScaler(const Scaler& other);

	// Class Operator Overloads

	Vector operator+(const Vector& other);  // Addition operator 
	Vector operator-(const Vector& other);  // Subtraction operator
	Scaler operator*(const Vector& other);  // Multiplication operator for dot product

	Vector operator+(const Scaler& other);  // Addition operator for scaler
	Vector operator-(const Scaler& other);	// Subtraction operator for scaler
	Vector operator*(const Scaler& other);	// Multiplication operator for scaler

	Scaler& operator[](size_t index);
	const Scaler& operator[](size_t index) const;

	// Class Friend functions

	friend std::ostream& operator<<(std::ostream& stream, const Vector& V_out);

	// Class Destructor

	virtual ~Vector() {}

private:

	// Class Members

	std::array<Scaler, m_Size> m_VectorArray;

};
