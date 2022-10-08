#pragma once


// Scaler class is used to store scaler quantities in the system. It is also used as base class 
// for class vector hence we call it a rank = 0 tensor.

#include <iostream>

template<typename T>
class Scaler
{
public:

	// Class Constructors

	Scaler() = default;
	Scaler(const T& Data);

	// Class Methods

	T Data();
	const T Data() const;

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

	friend std::ostream& operator<<(std::ostream& stream, const Scaler& S_out)
	{
		stream << S_out.Data();

		return stream;
	};

	// Class Destructor

	virtual ~Scaler() {}

private:

	T m_Value = 0;

};

// Class Constructors

template<typename T>
Scaler<T>::Scaler(const T& DataPoint) : m_Value(DataPoint) {}

// Class Methods

template<typename T> T Scaler<T>::Data() { return m_Value; }
template<typename T> const T Scaler<T>::Data() const { return m_Value; }

template<typename T> Scaler<T> Scaler<T>::addition(const Scaler& other) { return Scaler(m_Value + other.m_Value); }
template<typename T> Scaler<T> Scaler<T>::subtract(const Scaler& other) { return Scaler(m_Value - other.m_Value); }
template<typename T> Scaler<T> Scaler<T>::multiply(const Scaler& other) { return Scaler(m_Value * other.m_Value); }
template<typename T> Scaler<T> Scaler<T>::divide(const Scaler& other) { return Scaler(m_Value / other.m_Value); }

// Class Operator Overloads

template<typename T> Scaler<T> Scaler<T>::operator+(const Scaler& other) { return addition(other); }
template<typename T> Scaler<T> Scaler<T>::operator-(const Scaler& other) { return subtract(other); }
template<typename T> Scaler<T> Scaler<T>::operator*(const Scaler& other) { return multiply(other); }
template<typename T> Scaler<T> Scaler<T>::operator/(const Scaler& other) { return divide(other); }

template<typename T>
bool Scaler<T>::operator==(const Scaler& other)
{
	if (m_Value == other.Data())
		return true;
	else
		return false;

	//m_Value == other.Data() ? true : false;
}

template<typename T> Scaler<T> Scaler<T>::operator+=(const Scaler& other) { return Scaler(m_Value += other.m_Value); }
template<typename T> Scaler<T> Scaler<T>::operator-=(const Scaler& other) { return Scaler(m_Value -= other.m_Value); }
template<typename T> Scaler<T> Scaler<T>::operator*=(const Scaler& other) { return Scaler(m_Value *= other.m_Value); }


