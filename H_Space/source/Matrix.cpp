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

Matrix::Matrix(const std::array<Vector, m_Columns>& row_or_column_Vectors) 
{
	if (row_or_column_Vectors.size() == m_Columns)
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

	else if (row_or_column_Vectors.size() == n_Rows)
	{
		m_RowVectorArray = row_or_column_Vectors;

		for (size_t i = 0; i < n_Rows; i++)
		{
			for (size_t j = 0; j < m_Columns; j++)
			{
				m_ColumnVectorArray[i][j] = row_or_column_Vectors[j][i];

				m_LinearArray[(i * m_Columns) + j] = row_or_column_Vectors[j][i];
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

inline const size_t Matrix::GetRows() const { return n_Rows; }
inline const size_t Matrix::GetColumns() const { return m_Columns; }
inline const size_t Matrix::GetLimit() const { return n_Rows * m_Columns; }

const size_t Matrix::GetLinearIndex(const Scaler& scaler_value) const
{
	for (size_t index = 0; index < GetLimit(); index++)
	{
		if (m_LinearArray[index].Data() == scaler_value.Data())
			return index;
	}
}

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
	}
}

const Scaler Matrix::GetScaler(const size_t& column_index, const size_t& row_index) const
{
	size_t linear_index = (row_index * m_Columns) + column_index;

	try
	{
		if (row_index >= n_Rows || column_index >= m_Columns || row_index < 0 || column_index < 0)
			throw (row_index * column_index);
		else
			return m_LinearArray[linear_index];
	}
	catch (size_t& index)
	{
		std::cout << "[ERROR]: The given linear index " << index << " are out of bounds" << std::endl;
	}
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

/*Matrix Matrix::prod_Matrix(const Matrix& other)
{
	// To check if Matrix Multiplication is possible or not

	if (GetColumns() == other.GetRows()) // Columns of the first matrix must be equal to the rows of second matrix
	{
		for (size_t i = 0; i < GetRows() * other.GetColumns(); i++)
		{
		
		}
	}
}*/

// Class Operator Overloads

Matrix Matrix::operator+(const Matrix& other) { return add_Matrix(other); }
Matrix Matrix::operator+(const Scaler& other) { return add_Scaler(other); }

Matrix Matrix::operator-(const Matrix& other) { return sub_Matrix(other); }
Matrix Matrix::operator-(const Scaler& other) { return sub_Scaler(other); }

//Matrix Matrix::operator*(const Matrix& other);  
Matrix Matrix::operator*(const Scaler& other) { return prod_Scaler(other); }


std::ostream& operator<<(std::ostream& stream, const Matrix& M_out)
{
	for (size_t i = 0; i < M_out.GetRows(); i++)
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



