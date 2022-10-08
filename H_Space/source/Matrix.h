#pragma once

#include "Scaler.h"
#include "Vector.h"

template<typename T, size_t N, size_t M>
class Matrix
{
public:

	// Class Members

	static const size_t n_Rows = N;			// Number of rows for a matrix (now fixed, will change it by using templates)
	static const size_t m_Columns = M;		// Number of columns for a matrix.

	// Class Constructors

	Matrix() = default;
	Matrix(const std::array<Scaler<T>, n_Rows* m_Columns>& linear_Scalers);	                 // A constructor which takes linear array as an input.
	Matrix(const std::array<Vector<T,N>, n_Rows>& row_or_column_Vectors, const char& flag);		// A constructor which takes an array of vectors as an input.
	Matrix(const Matrix& matrix);											               // A constructor which takes in another matrix as an input.

	// Class Methods

	const size_t GetRows() const;
	const size_t GetColumns() const;
	const size_t GetLimit() const;
	const size_t GetLinearIndex(const Scaler<T>& scaler_value) const;

	Scaler<T>* Data();          // This would return a scaler pointer to the first element of the linear array.
	const Scaler<T>* Data() const;

	const Vector<T,N> GetRowVector(const size_t& vector_index) const;
	const Vector<T,M> GetColumnVector(const size_t& vector_index) const;

	const Scaler<T> GetScaler(const size_t& row_index, const size_t& column_index) const;

	Matrix Transpose();
	Matrix add_Matrix(const Matrix& other);
	Matrix add_Scaler(const Scaler<T>& other);

	Matrix sub_Matrix(const Matrix& other);
	Matrix sub_Scaler(const Scaler<T>& other);

	Matrix prod_Matrix(const Matrix& other);
	Matrix prod_Scaler(const Scaler<T>& other);

	// Class Operator Overloads

	Matrix operator+(const Matrix& other);  // Addition with another Matrix
	Matrix operator+(const Scaler<T>& other);	// Addition with a Scaler

	Matrix operator-(const Matrix& other);	// Subtraction with another Matrix
	Matrix operator-(const Scaler<T>& other);	// Subtraction with a Scaler

	Matrix operator*(const Matrix& other);  // Multiplication between two Matrices 
	Matrix operator*(const Scaler<T>& other);	// Multiplication with a Scaler

	Vector<T,M>& operator[](size_t index);              // These operators will return row vectors of given index by default.
	const Vector<T,M>& operator[](size_t index) const;

	// Class Friend function

	friend std::ostream& operator<<(std::ostream& stream, const Matrix<T,N,M>& M_out)
	{
		for (size_t i = 0; i < M_out.n_Rows; i++)
			stream << M_out.m_RowVectorArray.at(i) << "\n";

		return stream;
	};

	// Class Destructor

	virtual ~Matrix() {}

private:

	// Private Member variables

	std::array<Vector<T,M>, n_Rows> m_RowVectorArray = {};			// An array to store row vectors of the Matrix
	std::array<Vector<T,N>, m_Columns> m_ColumnVectorArray = {};		// An array to store column vectors of the Matrix
	std::array<Scaler<T>, n_Rows* m_Columns> m_LinearArray = {};	// An array to store all the elements of the Matrix linearly.

	//Private Member function

	const size_t GetLinearIndex(const size_t& row_index, const size_t& column_index) const;

};

// Class Constructors


template<typename T, size_t N, size_t M>
Matrix<T,N,M>::Matrix(const std::array<Scaler<T>, n_Rows* m_Columns>& linear_Scalers)
	: m_LinearArray(linear_Scalers)
{
	for (size_t i = 0; i < n_Rows; i++)
	{
		for (size_t j = 0; j < m_Columns; j++)
		{
			m_RowVectorArray[i][j] = linear_Scalers[GetLinearIndex(i, j)];

			m_ColumnVectorArray[j][i] = linear_Scalers[GetLinearIndex(i, j)];  // ColumnArray is just a transpose of RowArray.
		}
	}

}

template<typename T, size_t N, size_t M>
Matrix<T,N,M>::Matrix(const std::array<Vector<T,N>, n_Rows>& row_or_column_Vectors, const char& flag)
{
	if (flag == 'C' || flag == 'c')
	{
		m_ColumnVectorArray = row_or_column_Vectors;

		for (size_t i = 0; i < n_Rows; i++)
		{
			for (size_t j = 0; j < m_Columns; j++)
			{
				m_RowVectorArray[i][j] = row_or_column_Vectors[j][i];

				m_LinearArray[GetLinearIndex(i, j)] = row_or_column_Vectors[j][i];
			}
		}
	}

	else if (flag == 'R' || flag == 'r')
	{
		m_RowVectorArray = row_or_column_Vectors;

		for (size_t i = 0; i < n_Rows; i++)
		{
			for (size_t j = 0; j < m_Columns; j++)
			{
				m_ColumnVectorArray[i][j] = row_or_column_Vectors[j][i];

				m_LinearArray[GetLinearIndex(i, j)] = row_or_column_Vectors[i][j];
			}
		}
	}

}

template<typename T, size_t N, size_t M>
Matrix<T,N,M>::Matrix(const Matrix& matrix)
			: m_LinearArray(matrix.m_LinearArray),
			  m_RowVectorArray(matrix.m_RowVectorArray),
			  m_ColumnVectorArray(matrix.m_ColumnVectorArray)
{}

// Class Methods

template<typename T, size_t N, size_t M> const size_t Matrix<T,N,M>::GetRows() const { return n_Rows; }
template<typename T, size_t N, size_t M> const size_t Matrix<T,N,M>::GetColumns() const { return m_Columns; }
template<typename T, size_t N, size_t M> const size_t Matrix<T,N,M>::GetLimit() const { return n_Rows * m_Columns; }

template<typename T, size_t N, size_t M>
const size_t Matrix<T,N,M>::GetLinearIndex(const Scaler<T>& scaler_value) const
{
	for (size_t index = 0; index < GetLimit(); index++)
	{
		if (m_LinearArray[index].Data() == scaler_value.Data())
			return index;
	}

	return -1;
}


template<typename T, size_t N, size_t M> Scaler<T>* Matrix<T,N,M>::Data() { return &m_LinearArray[0]; }
template<typename T, size_t N, size_t M> const Scaler<T>* Matrix<T,N,M>::Data() const { return &m_LinearArray[0]; }

template<typename T, size_t N, size_t M>
const Vector<T,N> Matrix<T,N,M>::GetRowVector(const size_t& vector_index) const
{
	try
	{
		if (vector_index >= n_Rows || vector_index < 0)
			throw vector_index;
		else
			return m_RowVectorArray[vector_index];
	}
	catch (size_t& index)
	{
		std::cout << "[ERROR]: The given index " << index << " is out of bounds" << std::endl;

		return this->m_ColumnVectorArray[0];
	}
}


template<typename T, size_t N, size_t M>
const Vector<T,M> Matrix<T,N,M>::GetColumnVector(const size_t& vector_index) const
{
	try
	{
		if (vector_index >= m_Columns || vector_index < 0)
			throw vector_index;
		else
			return m_ColumnVectorArray[vector_index];
	}
	catch (size_t& index)
	{
		std::cout << "[ERROR]: The given index " << index << " is out of bounds" << std::endl;

		return this->m_ColumnVectorArray[0];
	}
}

template<typename T, size_t N, size_t M>
const Scaler<T> Matrix<T,N,M>::GetScaler(const size_t& row_index, const size_t& column_index) const
{
	try
	{
		if (row_index >= n_Rows || column_index >= m_Columns || row_index < 0 || column_index < 0)
			throw (row_index * column_index);
		else
			return m_LinearArray[GetLinearIndex(row_index, column_index)];
	}
	catch (size_t& index)
	{
		std::cout << "[ERROR]: The given linear index " << index << " are out of bounds" << std::endl;

		return Scaler<T>(NULL);
	}
}

template<typename T, size_t N, size_t M>
Matrix<T,N,M> Matrix<T,N,M>::Transpose()
{
	this->m_RowVectorArray = this->m_ColumnVectorArray;

	return *this;
}

template<typename T, size_t N, size_t M>
Matrix<T,N,M> Matrix<T,N,M>::add_Matrix(const Matrix& other)
{
	Matrix matrix = {};

	for (size_t i = 0; i < m_LinearArray.size(); i++)
		matrix.m_LinearArray[i] = m_LinearArray[i] + other.m_LinearArray[i];

	return Matrix(matrix.m_LinearArray);
}

template<typename T, size_t N, size_t M>
Matrix<T,N,M> Matrix<T,N,M>::add_Scaler(const Scaler<T>& other)
{
	Matrix matrix = {};

	for (size_t i = 0; i < m_LinearArray.size(); i++)
		matrix.m_LinearArray[i] = m_LinearArray[i] + other;

	return Matrix(matrix.m_LinearArray);
}

template<typename T, size_t N, size_t M>
Matrix<T,N,M> Matrix<T,N,M>::sub_Matrix(const Matrix& other)
{
	Matrix matrix = {};

	for (size_t i = 0; i < m_LinearArray.size(); i++)
		matrix.m_LinearArray[i] = m_LinearArray[i] - other.m_LinearArray[i];

	return Matrix(matrix.m_LinearArray);
}

template<typename T, size_t N, size_t M>
Matrix<T,N,M> Matrix<T,N,M>::sub_Scaler(const Scaler<T>& other)
{
	Matrix matrix = {};

	for (size_t i = 0; i < m_LinearArray.size(); i++)
		matrix.m_LinearArray[i] = m_LinearArray[i] - other;

	return Matrix(matrix.m_LinearArray);
}

template<typename T, size_t N, size_t M>
Matrix<T,N,M> Matrix<T,N,M>::prod_Scaler(const Scaler<T>& other)
{
	Matrix matrix = {};

	for (size_t i = 0; i < m_LinearArray.size(); i++)
		matrix.m_LinearArray[i] = m_LinearArray[i] * other;

	return Matrix(matrix.m_LinearArray);
}

template<typename T, size_t N, size_t M>
Matrix<T,N,M> Matrix<T,N,M>::prod_Matrix(const Matrix& other)
{
	Matrix matrix = {};

	// To check if Matrix Multiplication is possible or not

	try
	{
		if (m_Columns != other.n_Rows)
			throw matrix;
		else
		{
			for (size_t i = 0; i < n_Rows; i++)
			{
				for (size_t j = 0; j < other.m_Columns; j++)
					matrix.m_LinearArray[(i * other.m_Columns) + j] = m_RowVectorArray[i] * other.m_ColumnVectorArray[j];
			}

			return Matrix(matrix.m_LinearArray);
		}
	}

	catch (Matrix& m)
	{
		std::cout << "The matrix multiplication is not possible as the dimesions are not compatible" << std::endl;
		return m;
	}
}

// Class Operator Overloads

template<typename T, size_t N, size_t M> 
Matrix<T,N,M> Matrix<T,N,M>::operator+(const Matrix& other) { return add_Matrix(other); }

template<typename T, size_t N, size_t M>
Matrix<T,N,M> Matrix<T,N,M>::operator+(const Scaler<T>& other) { return add_Scaler(other); }

template<typename T, size_t N, size_t M>
Matrix<T,N,M> Matrix<T,N,M>::operator-(const Matrix& other) { return sub_Matrix(other); }

template<typename T, size_t N, size_t M> 
Matrix<T,N,M> Matrix<T,N,M>::operator-(const Scaler<T>& other) { return sub_Scaler(other); }

template<typename T, size_t N, size_t M>
Matrix<T,N,M> Matrix<T,N,M>::operator*(const Matrix& other) { return prod_Matrix(other); }

template<typename T, size_t N, size_t M>
Matrix<T,N,M> Matrix<T,N,M>::operator*(const Scaler<T>& other) { return prod_Scaler(other); }

template<typename T, size_t N, size_t M>
Vector<T,M>& Matrix<T,N,M>::operator[](size_t index) { return m_RowVectorArray[index]; }

template<typename T, size_t N, size_t M>
const Vector<T,M>& Matrix<T,N,M>::operator[](size_t index) const { return m_RowVectorArray[index]; }

// Private member functions

template<typename T, size_t N, size_t M>
const size_t Matrix<T,N,M>::GetLinearIndex(const size_t& row_index, const size_t& column_index) const
{
	return (row_index * m_Columns) + column_index;
}




