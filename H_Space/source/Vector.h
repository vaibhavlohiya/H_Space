#pragma once

#include <array>

#include "Scaler.h"

template<typename T, size_t N>
class Vector
{
public:
	static const size_t m_Size = N;

	// Class Constructors

	Vector() = default;
	Vector(const std::array<Scaler<T>, m_Size>& Components);

	// Class Methods

	Scaler<T>* Data();
	const Scaler<T>* Data() const;

	const size_t size() const;

	Vector add(const Vector& other);
	Vector subtract(const Vector& other);
	Scaler<T> dotProduct(const Vector& other);
	Vector crossProduct(const Vector& other);

	Vector addScaler(const Scaler<T>& other);
	Vector subtractScaler(const Scaler<T>& other);
	Vector prodScaler(const Scaler<T>& other);

	// Class Operator Overloads

	Vector operator+(const Vector& other);  // Addition operator 
	Vector operator-(const Vector& other);  // Subtraction operator
	Scaler<T> operator*(const Vector& other);  // Multiplication operator for dot product

	Vector operator+(const Scaler<T>& other);  // Addition operator for scaler
	Vector operator-(const Scaler<T>& other);	// Subtraction operator for scaler
	Vector operator*(const Scaler<T>& other);	// Multiplication operator for scaler

	Scaler<T>& operator[](size_t index);
	const Scaler<T>& operator[](size_t index) const;

	// Class Friend functions

	friend std::ostream& operator<<(std::ostream& stream, const Vector& V_out)
	{
		for (size_t i = 0; i < V_out.size(); i++)
			stream << V_out[i].Data() << " ";

		return stream;
	};

	// Class Destructor

	virtual ~Vector() {}

private:

	// Class Members

	std::array<Scaler<T>, m_Size> m_VectorArray;

};


// Class Constructors

template<typename T, size_t N>
Vector<T,N>::Vector(const std::array<Scaler<T>, m_Size>& Components)
	: m_VectorArray(Components)
{}

// Class Methods 

template<typename T, size_t N> Scaler<T>* Vector<T,N>::Data() { return &m_VectorArray[0]; }
template<typename T, size_t N> const Scaler<T>* Vector<T,N>::Data() const { return &m_VectorArray[0]; }

template<typename T, size_t N> const size_t Vector<T,N>::size() const { return m_Size; }

template<typename T, size_t N>
Vector<T,N> Vector<T,N>::add(const Vector& other)
{
	Vector vector = {};

	for (size_t i = 0; i < m_Size; i++)
		vector.m_VectorArray[i] = m_VectorArray[i] + other.m_VectorArray[i];

	return Vector(vector.m_VectorArray);
}

template<typename T, size_t N>
Vector<T,N> Vector<T,N>::subtract(const Vector& other)
{
	Vector vector = {};

	for (size_t i = 0; i < m_Size; i++)
		vector.m_VectorArray[i] = m_VectorArray[i] - other.m_VectorArray[i];

	return Vector(vector.m_VectorArray);
}

template<typename T, size_t N>
Scaler<T> Vector<T,N>::dotProduct(const Vector& other)
{
	Scaler<T> scaler = {};

	for (size_t i = 0; i < m_Size; i++)
		scaler += m_VectorArray[i] * other.m_VectorArray[i];

	return Scaler<T>(scaler.Data());
}

template<typename T, size_t N>
Vector<T,N> Vector<T,N>::crossProduct(const Vector& other)
{
	Vector vector = {};

	if (m_Size == 3)
	{
		vector.m_VectorArray[0] = m_VectorArray[1] * other.m_VectorArray[2] - m_VectorArray[2] * other.m_VectorArray[1];
		vector.m_VectorArray[1] = m_VectorArray[2] * other.m_VectorArray[0] - m_VectorArray[0] * other.m_VectorArray[2];
		vector.m_VectorArray[2] = m_VectorArray[0] * other.m_VectorArray[1] - m_VectorArray[1] * other.m_VectorArray[0];
	}

	return Vector(vector.m_VectorArray);
}

template<typename T, size_t N>
Vector<T,N> Vector<T,N>::addScaler(const Scaler<T>& other)
{
	Vector vector = {};

	for (size_t i = 0; i < m_Size; i++)
		vector.m_VectorArray[i] = m_VectorArray[i] + other;

	return Vector(vector.m_VectorArray);
}

template<typename T, size_t N>
Vector<T,N> Vector<T,N>::subtractScaler(const Scaler<T>& other)
{
	Vector vector = {};

	for (size_t i = 0; i < m_Size; i++)
		vector.m_VectorArray[i] = m_VectorArray[i] - other;

	return Vector(vector.m_VectorArray);
}

template<typename T, size_t N>
Vector<T,N> Vector<T,N>::prodScaler(const Scaler<T>& other)
{
	Vector vector = {};

	for (size_t i = 0; i < m_Size; i++)
		vector.m_VectorArray[i] = m_VectorArray[i] * other;

	return Vector(vector.m_VectorArray);
}

// Class Operator Overloads

template<typename T, size_t N> Vector<T,N> Vector<T,N>::operator+(const Vector& other) { return add(other); }
template<typename T, size_t N> Vector<T,N> Vector<T,N>::operator-(const Vector& other) { return subtract(other); }
template<typename T, size_t N> Scaler<T> Vector<T,N>::operator*(const Vector& other) { return dotProduct(other); }

template<typename T, size_t N> Vector<T,N> Vector<T,N>::operator+(const Scaler<T>& other) { return addScaler(other); }
template<typename T, size_t N> Vector<T,N> Vector<T,N>::operator-(const Scaler<T>& other) { return subtractScaler(other); }
template<typename T, size_t N> Vector<T,N> Vector<T,N>::operator*(const Scaler<T>& other) { return prodScaler(other); }

template<typename T, size_t N> Scaler<T>& Vector<T,N>::operator[](size_t index) { return m_VectorArray[index]; }
template<typename T, size_t N> const Scaler<T>& Vector<T,N>::operator[](size_t index) const { return m_VectorArray[index]; }



