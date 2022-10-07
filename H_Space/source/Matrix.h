#pragma once

#include "Scaler.h"
#include "Vector.h"


class Matrix
{
public:

	// Class Members

	static const size_t n_Rows = 3;			// Number of rows for a matrix (now fixed, will change it by using templates)
	static const size_t m_Columns = 3;		// Number of columns for a matrix.

	// Class Constructors

	Matrix() = default;
	Matrix(const std::array<Scaler, n_Rows* m_Columns>& linear_Scalers);	                 // A constructor which takes linear array as an input.
	Matrix(const std::array<Vector, n_Rows>& row_or_column_Vectors, const char& flag);		// A constructor which takes an array of vectors as an input.
	Matrix(const Matrix& matrix);											               // A constructor which takes in another matrix as an input.

	// Class Methods

	const size_t GetRows() const;
	const size_t GetColumns() const;
	const size_t GetLimit() const;
	const size_t GetLinearIndex(const Scaler& scaler_value) const;

	Scaler* Data();          // This would return a scaler pointer to the first element of the linear array.
	const Scaler* Data() const;

	const Vector GetRowVector(const size_t& vector_index) const;
	const Vector GetColumnVector(const size_t& vector_index) const;

	const Scaler GetScaler(const size_t& row_index, const size_t& column_index) const;

	Matrix Transpose();
	Matrix add_Matrix(const Matrix& other);
	Matrix add_Scaler(const Scaler& other);

	Matrix sub_Matrix(const Matrix& other);
	Matrix sub_Scaler(const Scaler& other);

	Matrix prod_Matrix(const Matrix& other);
	Matrix prod_Scaler(const Scaler& other);

	// Class Operator Overloads

	Matrix operator+(const Matrix& other);  // Addition with another Matrix
	Matrix operator+(const Scaler& other);	// Addition with a Scaler

	Matrix operator-(const Matrix& other);	// Subtraction with another Matrix
	Matrix operator-(const Scaler& other);	// Subtraction with a Scaler

	Matrix operator*(const Matrix& other);  // Multiplication between two Matrices 
	Matrix operator*(const Scaler& other);	// Multiplication with a Scaler

	Vector& operator[](size_t index);             // These operators will return row vectors of given index by default.
	const Vector& operator[](size_t index) const;


	// Class Friend function

	friend std::ostream& operator<<(std::ostream& stream, const Matrix& M_out);

	// Class Destructor

	virtual ~Matrix() {}

private:

	// Private Member variables

	std::array<Vector, n_Rows> m_RowVectorArray;			// An array to store row vectors of the Matrix
	std::array<Vector, m_Columns> m_ColumnVectorArray;		// An array to store column vectors of the Matrix
	std::array<Scaler, n_Rows* m_Columns> m_LinearArray;	// An array to store all the elements of the Matrix linearly.

	// Private Member function

	void ExpCheck(const size_t& index, const size_t& limit);
	const size_t GetLinearIndex(const size_t& row_index, const size_t& column_index) const;

};