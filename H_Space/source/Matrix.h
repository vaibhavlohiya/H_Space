#pragma once

#include "Scaler.h"
#include "Vector.h"


class Matrix
{
public:

	// Class Members

	static const size_t n_Rows = 3;
	static const size_t m_Columns = 3;

	// Class Constructors

	Matrix() = default;
	Matrix(const std::array<Scaler, n_Rows * m_Columns>& linear_Scalers);
	Matrix(const std::array<Vector, m_Columns>& row_or_column_Vectors);
	Matrix(const Matrix& matrix);

	// Class Methods

	inline const size_t GetRows() const;
	inline const size_t GetColumns() const;

	inline const size_t GetLinearIndex(const Scaler& scaler_value) const;

	inline const Vector GetRowVector(const size_t& vector_index) const;
	inline const Vector GetColumnVector(const size_t& vector_index) const;

	inline const Scaler GetScaler(const size_t& column_index, const size_t& row_index) const;

	Matrix add_Matrix(const Matrix& other);
	Matrix add_Scaler(const Scaler& other);

	Matrix sub_Matrix(const Matrix& other);
	Matrix sub_Scaler(const Scaler& other);

	Matrix prod_Matrix(const Matrix& other);
	Matrix prod_Scaler(const Scaler& other);

	// Class Operator Overloads`

	Matrix operator+(const Matrix& other);
	Matrix operator+(const Scaler& other);

	Matrix operator-(const Matrix& other);
	Matrix operator-(const Scaler& other);

	Matrix operator*(const Matrix& other);
	Matrix operator*(const Scaler& other);


private:
	std::array<Vector, n_Rows> m_RowVectorArray;
	std::array<Vector, m_Columns> m_ColumnVectorArray;
	std::array<Scaler, n_Rows* m_Columns> m_LinearArray;
};