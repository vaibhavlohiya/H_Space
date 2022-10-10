# H_Space

A mathematical API for tensors till rank 2 (Matrix) which takes user input for typenames and number of dimesions.

# How it works

### 1. Include the necessary header file.

       #include "Matrix.h"
       
### SCALER (RANK 0 TENSOR)   
       
### 2. Create a scaler by creating an object of class scaler as given below.

       Scaler<double> x(5.2), y(1.9), z(2.1);   
       
### 3. Some Scaler functions.
       
       x.Data();             // This will give you the data inside the scaler object, in this case "5.2" .
       x1.addition(x2);      // addition of two scalers.
       x1.subtract(x2);      // subtraction of two scalers.
       x1.multiply(x2);      // multiplication of two scalers.
       x1.divide(x2);        // division of two scalers.
  
### 4. Some Scaler operations.

       x1 + x2;             // same as addition.
       x1 - x2;             // same as subtraction
       x1 * x2;             // same as multiply
       x1 / x2;             // same as division
       
       x1 += x2;            // x1 = x1 + x2
       x1 -= x2;            // x1 = x1 - x2
       x1 *= x2;            // x1 = x1 * x2
       x1 /= x2;            // x1 = x1 / x2
       x1 == x2;            // binary comparison
       
### VECTOR  (RANK 1 TENSOR) 
       
### 5. After that, you can create a vector by 2 methods which are given as

#### a). Method 1 (by using scalers)

       Vector<double, 3> v({x, y, z});
       
#### b). Method 2 (by directly putting values in it)

       Vector<double, 3> v({3.1, 6.7, 5.2});

### 6. Vector functions.
 
       v.size();              // returns the size if the vector.
       v.Data();              // return a pointer to the first element of the vector array.
       
       v1.add(v2);            // returns a vector which is a sum of v1 and v2.
       v.addScaler(x);        // returns a vector which adds a scaler x into v. 
       
       v1.subtract(v2);       // returns a vector which is the difference of v1 and v2.
       v.subtractScaler(x);   // returns a vector which subtracts scaler x from v.
       
       v1.dotProduct(v2);     // returns a scaler which is the result of the dot product of v1 and v2.
       v1.crossProduct(v2);   // returns a vector which is the cross product of v1 and v2.
       v.prodScaler(x);       // returns a vector which multiplies a scaler x into v.

### 7. Vector operations.

       v[index];              // returns an element or a scaler at given index
       v_add = v1 + v2;       // same as Add
       v_sub = v1 - v2;       // same as Subtract
       v_dot = v1 * v2;       // same as DotProduct

### MATRIX (RANK 2 TENSOR)

### 8. Create a Matrix by creating an object using two methods.

#### a). Method 1 (by a linear array of scalers with n_Rows x m_Columns length)

       Matrix<int, 3, 3> matrix({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
       
#### b). Method 2 (by an array of either row vectors of column vectors)

       Matrix<double, 3, 3> matrixR({ v1, v2, v3 },  'R') //  For Row Vectors
       Matrix<double, 3, 3> matrixC({ v1, v2, v3 },  'C') //  For Column Vectors
       
### 9. Basic functions. 

       matrix.GetRows();     // returns the number of rows
       matrix.GetColumns();  // returns the number of columns
       matrix.GetLimit();    // returns the number of elements or scalers you can add in this matrix (n_Rows x m_Columns)
       
       matrix.GetLinearIndex(5));   // returns the index of the element 5 in the linear  matrixarray
       matrix.Data();               // returns a pointer to the first element of the linear matrix array.
       
       matrix.GetRowVector(1);     // returns a row vector of the matrix of index 1.
       matrix.GetColumnVector(2);  // returns a column vector of the matrix of index 2.
       
       matrix.GetScaler(0,1);      // returns the element or scaler of row index 0 and column index 1.
       
### 10. Mathematical functions.

       matrix.Transpose();            // This will transpose the matrix. (NOTE: This will change the matrix into its transpose)
       
       matrix1.add_Matrix(matrix2);    // returns a matrix which is a sum of matrix 1 and matrix 2.
       matrix.add_Scaler(scaler);      // returns a matrix which is a sum of a matrix and a scaler.
       
       matrix1.sub_Matrix(matrix2);    // returns a matrix which is a difference of matrix 1 and matrix 2.
       matrix.sub_Scaler(scaler);      // returns a matrix which is a difference of a matrix and a scaler.
       
       matrix1.prod_Matrix(matrix2);   // returns a matrix which is a product of matrix 1 and matrix 2.
       matrix.prod_Scaler(scaler);     // returns a matrix which is a product of matrix and a scaler.
       
### 11. Matrix operations.

       matrix[1];     // returns a row vector of index 1 by default.
       matrix[1][1]   // returns an element of index (1,1). 
       
       matrix_add_matrix = matrix1 + matrix2;   // same as add_Matrix.
       matrix_add_scaler = matrix + scaler;     // same as add_Scaler.
       
       matrix_sub_matrix = matrix1 - matrix2;   // same as sub_Matrix.
       matrix_sub_scaler = matrix - scaler;     // same as sub_Scaler.
       
       matrix_prod_matrix = matrix1 * matrix2;  // same as prod_Matrix.
       matrix_prod_scaler = matrix * scaler;    // same as prod_Scaler.
       
 NOTE: The library is still in development stage and new functions will be added to make it more useful for complex mathematical problems.
