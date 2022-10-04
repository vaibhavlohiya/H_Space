// A .cpp file for all the member functions of class Matrix.h

#include "Scaler.h"
#include "Vector.h"
#include "Matrix.h"

// Class Constructors

Matrix::Matrix(const std::array<Scaler, n_Rows * m_Columns>& linear_Scalers)
	: m_LinearArray(linear_Scalers)
{
	for (size_t i = 0; i < n_Rows; i++)
	{
		for (size_t j = 0; j < m_Columns; j++)
		{
			m_RowVectorArray[i][j] = linear_Scalers[(i * m_Columns) + j]; 

			m_ColumnVectorArray[j][i] = linear_Scalers[(i * m_Columns) + j];  // ColumnArray is just a transpose of RowArray.
		}
	}

}

Matrix::Matrix(const std::array<Vector, n_Rows>& row_or_column_Vectors, const char& flag) 
{
	if (flag == 'C')
	{
		m_ColumnVectorArray = row_or_column_Vectors;

		for (size_t i = 0; i < n_Rows; i++)
		{
			for (size_t j = 0; j < m_Columns; j++)
			{
				m_RowVectorArray[i][j] = row_or_column_Vectors[j][i];

				m_LinearArray[(i * m_Columns) + j] = row_or_column_Vectors[j][i];
			}
		}
	}

	else if (flag == 'R')
	{
		m_RowVectorArray = row_or_column_Vectors;

		for (size_t i = 0; i < n_Rows; i++)
		{
			for (size_t j = 0; j < m_Columns; j++)
			{
				m_ColumnVectorArray[i][j] = row_or_column_Vectors[j][i];

				m_LinearArray[(i * m_Columns) + j] = row_or_column_Vectors[i][j];
			}
		}
	}

}

Matrix::Matrix(const Matrix& matrix)
	: m_LinearArray(matrix.m_LinearArray), 
	  m_RowVectorArray(matrix.m_RowVectorArray), 
	  m_ColumnVectorArray(matrix.m_ColumnVectorArray)
{}

// Class Methods

const size_t Matrix::GetRows() const { return n_Rows; }
const size_t Matrix::GetColumns() const { return m_Columns; }
const size_t Matrix::GetLimit() const { return n_Rows * m_Columns; }

const size_t Matrix::GetLinearIndex(const Scaler& scaler_value) const
{
	for (size_t index = 0; index < GetLimit(); index++)
	{
		if (m_LinearArray[index].Data() == scaler_value.Data())
			return index;
	}
}

Scaler* Matrix::GetLinearData() { return &m_LinearArray[0]; }

const Vector Matrix::GetRowVector(const size_t& vector_index) const
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


const Vector Matrix::GetColumnVector(const size_t& vector_index) const 
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
		std::cout << "[ERROR]: The given index " << index <<" is out of bounds" << std::endl;

		return this->m_ColumnVectorArray[0];
	}
}

const Scaler Matrix::GetScaler(const size_t& row_index, const size_t& column_index) const
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

		return Scaler(0);
	}
}

Matrix Matrix::Transpose()
{
	this->m_RowVectorArray = this->m_ColumnVectorArray;

	return *this;
}

Matrix Matrix::add_Matrix(const Matrix& other)
{
	Matrix M = {};

	for (size_t i = 0; i < m_LinearArray.size(); i++)
		M.m_LinearArray[i] = m_LinearArray[i] + other.m_LinearArray[i];

	return Matrix(M.m_LinearArray);
}

Matrix Matrix::add_Scaler(const Scaler& other)
{
	Matrix M = {};

	for (size_t i = 0; i < m_LinearArray.size(); i++)
		M.m_LinearArray[i] = m_LinearArray[i] + other;

	return Matrix(M.m_LinearArray);
}

Matrix Matrix::sub_Matrix(const Matrix& other)
{
	Matrix M = {};

	for (size_t i = 0; i < m_LinearArray.size(); i++)
		M.m_LinearArray[i] = m_LinearArray[i] - other.m_LinearArray[i];

	return Matrix(M.m_LinearArray);
}

Matrix Matrix::sub_Scaler(const Scaler& other)
{
	Matrix M = {};

	for (size_t i = 0; i < m_LinearArray.size(); i++)
		M.m_LinearArray[i] = m_LinearArray[i] - other;

	return Matrix(M.m_LinearArray);
}

Matrix Matrix::prod_Scaler(const Scaler& other)
{
	Matrix M = {};

	for (size_t i = 0; i < m_LinearArray.size(); i++)
		M.m_LinearArray[i] = m_LinearArray[i] * other;

	return Matrix(M.m_LinearArray);
}

Matrix Matrix::prod_Matrix(const Matrix& other)
{
	Matrix M = {};

	// To check if Matrix Multiplication is possible or not

	try
	{
		if (m_Columns != other.n_Rows)
			throw M;
		else
		{
			for (size_t i = 0; i < n_Rows; i++)
			{
				for (size_t j = 0; j < other.m_Columns; j++)
					M.m_LinearArray[(i * other.m_Columns) + j] = m_RowVectorArray[i] * other.m_ColumnVectorArray[j];
			}

			return Matrix(M.m_LinearArray);
		}
	}

	catch (Matrix& m)
	{
		std::cout << "The matrix multiplication is not possible as the dimesions are not compatible" << std::endl;
		return m;
	}
}

// Class Operator Overloads

Matrix Matrix::operator+(const Matrix& other) { return add_Matrix(other); }
Matrix Matrix::operator+(const Scaler& other) { return add_Scaler(other); }

Matrix Matrix::operator-(const Matrix& other) { return sub_Matrix(other); }
Matrix Matrix::operator-(const Scaler& other) { return sub_Scaler(other); }

Matrix Matrix::operator*(const Matrix& other) { return prod_Matrix(other); }
Matrix Matrix::operator*(const Scaler& other) { return prod_Scaler(other); }

Vector& Matrix::operator[](size_t& index) { return m_ColumnVectorArray[index]; }
const Vector& Matrix::operator[](size_t& index) const { return m_ColumnVectorArray[index]; }

std::ostream& operator<<(std::ostream& stream, const Matrix& M_out)
{
	for (size_t i = 0; i < M_out.n_Rows; i++)
		stream << M_out.m_RowVectorArray.at(i) << "\n";

	return stream;
}

void Matrix::ExpCheck(const size_t& index, const size_t& limit)
{
	try
	{
		if (index >= limit)
			throw index;
	}
	catch (size_t& index)
	{
		std::cout << "[ERROR]: The index " << index << " is out of bounds" << std::endl;
 	}
}

const size_t Matrix::GetLinearIndex(const size_t& row_index, const size_t& column_index) const
{
	return (row_index * m_Columns) + column_index;
}




