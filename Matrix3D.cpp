//
// Created by kareem on 12/12/18.
//
#include "Matrix3D.h"

/**
 * Default constructor.
 */
Matrix3D::Matrix3D()
{
    Vector3D v1 = Vector3D(0, 0, 0);
    Vector3D v2 = Vector3D(0, 0, 0);
    Vector3D v3 = Vector3D(0, 0, 0);

    this->arrayVectors[0] = v1;
    this->arrayVectors[1] = v2;
    this->arrayVectors[2] = v3;
}

/**
 *Ceates a new Matrix where all of its values are the given num.
 * @param num The given num.
 */
Matrix3D::Matrix3D(double num)
{
    Vector3D v1 = Vector3D(num, 0, 0);
    Vector3D v2 = Vector3D(0, num, 0);
    Vector3D v3 = Vector3D(0, 0, num);

    this->arrayVectors[0] = v1;
    this->arrayVectors[1] = v2;
    this->arrayVectors[2] = v3;
}

/**
 * Creates a new Matrix with the values of 9 given numbers.
 * @param n1
 * @param n2
 * @param n3
 * @param n4
 * @param n5
 * @param n6
 * @param n7
 * @param n8
 * @param n9
 */
Matrix3D::Matrix3D(double n1, double n2, double n3, double n4, double n5, double n6, double n7, double n8, double n9)
{
    Vector3D v1 = Vector3D(n1, n2, n3);
    Vector3D v2 = Vector3D(n4, n5, n6);
    Vector3D v3 = Vector3D(n7, n8, n9);

    this->arrayVectors[0] = v1;
    this->arrayVectors[1] = v2;
    this->arrayVectors[2] = v3;
}

/**
 * Creates a new matrix from the values of a given array of size 9.
 * @param nums The given array.
 */
Matrix3D::Matrix3D(double *nums)
{
    unsigned int i = 0;
    for (i = 0; i < 3; ++i)
    {
        double tempNums[3];
        for (int j = 0; j < 3; ++j)
        {
            tempNums[j] = nums[i*3 + j];
        }

        auto tempVec = Vector3D(tempNums);

        this->arrayVectors[i] = tempVec;
    }
}

/**
 * Creates a new matrix from the values of a given 2d array of size 3x3.
 * @param nums the given array
 */
Matrix3D::Matrix3D(double nums[3][3])
{
    unsigned int i = 0;
    for (i = 0; i < 3; ++ i)
    {
        auto newVec = Vector3D(nums[i]);
        arrayVectors[i] = newVec;
    }
}

/**
 * Creates a new martix from the values of three given vectors where each vector is a
 * row in the matrix.
 * @param v1 First vector.
 * @param v2 second vector.
 * @param v3 third vector.
 */
Matrix3D::Matrix3D(Vector3D v1, Vector3D v2, Vector3D v3)
{
    this->arrayVectors[0] = v1;
    this->arrayVectors[1] = v2;
    this->arrayVectors[2] = v3;
}

/**
 * Copy constructor, creates a new matrix from the values of a given array.
 * @param matrix3D the given array.
 */
Matrix3D::Matrix3D(const Matrix3D &matrix3D)
{
    for (int i = 0; i < 3; ++i)
    {
        this->arrayVectors[i] = matrix3D.arrayVectors[i];
    }
}

/**
 * Adds a given array to the current array.
 * @param m2 the given array.
 * @return The result of the addition.
 */
Matrix3D& Matrix3D::operator+=(const Matrix3D m2)
{
    for (int i = 0; i < 3; ++i)
    {
        this->arrayVectors[i] += m2.arrayVectors[i];
    }

    return *this;
}

/**
 * subtracts a given array from the current array.
 * @param m2 the given array.
 * @return The result of the subtraction.
 */
Matrix3D& Matrix3D::operator-=(const Matrix3D m2)
{
    for (int i = 0; i < 3; ++i)
    {
        this->arrayVectors[i] -= m2.arrayVectors[i];
    }

    return *this;
}

/**
 * multiplies the current array with a given array
 * @param m2 the given array
 * @return the result
 */
Matrix3D& Matrix3D::operator*=(Matrix3D m2)
{
    Matrix3D m2Transpose = findTranspose(m2);

    for (int i = 0; i < 3; ++i)
    {
        Vector3D newRow;
        for (int j = 0; j < 3; ++j)
        {
            double newVal = this->arrayVectors[i]* m2Transpose.arrayVectors[j];
            newRow[j] = newVal;
        }
        this->arrayVectors[i] = newRow;
    }
    return *this;
}

/**
 * Multiplies two given matrices.
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return The new matrix which is the result.
 */
Matrix3D operator*(const Matrix3D m1, const Matrix3D m2)
{
    Matrix3D newMat;
    Matrix3D m2Transpose = findTranspose(m2);

    for (int i = 0; i < 3; ++i)
    {
        Vector3D newRow;
        for (int j = 0; j < 3; ++j)
        {
            double newVal = m1.arrayVectors[i]* m2Transpose.arrayVectors[j];
            newRow[j] = newVal;
        }
        newMat.arrayVectors[i] = newRow;
    }
    return newMat;
}

/**
 * Adds two given array together.
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return A new matrix which is the result.
 */
Matrix3D operator+(Matrix3D m1, Matrix3D m2)
{
    Matrix3D newMat;
    for (int i = 0; i < 3; ++i)
    {
        Vector3D newVec = Vector3D(m1.arrayVectors[i].getX() + m2.arrayVectors[i].getX(),
                                   m1.arrayVectors[i].getY() + m2.arrayVectors[i].getY(),
                                   m1.arrayVectors[i].getZ() + m2.arrayVectors[i].getZ());

        newMat.arrayVectors[i] = newVec;
    }

    return newMat;
}

/**
 * Subtracts two given matrices.
 * @param m1 The first array.
 * @param m2 The second array.
 * @return A new matrix which is the result.
 */
Matrix3D operator-(Matrix3D m1, Matrix3D m2)
{
    Matrix3D newMat;
    for (int i = 0; i < 3; ++i)
    {
        Vector3D newVec = Vector3D(m1.arrayVectors[i].getX() - m2.arrayVectors[i].getX(),
                                   m1.arrayVectors[i].getY() - m2.arrayVectors[i].getY(),
                                   m1.arrayVectors[i].getZ() - m2.arrayVectors[i].getZ());

        newMat.arrayVectors[i] = newVec;
    }

    return newMat;
}

/**
 * Multiplies the current matrix with a given number.
 * @param num The given number.
 * @return The result.
 */
Matrix3D& Matrix3D::operator*=(double num)
{
    for (Vector3D v : this->arrayVectors)
    {
        v = Vector3D(v.getX()*num, v.getY()*num, v.getZ()*num);
    }

    return *this;
}

/**
 * Divides the current matrix with a given number.
 * @param num the given number.
 * @return the result.
 */
Matrix3D& Matrix3D::operator/=(double num)
{
    for (Vector3D v : this->arrayVectors)
    {
        v = Vector3D(v.getX()/num, v.getY()/num, v.getZ()/num);
    }

    return *this;
}


/**
 * Multiplies a given matrix with a given vector.
 * @param m1 the given matrix.
 * @param v the given vector.
 * @return a new matrix which is the result.
 */
Vector3D operator*(Matrix3D m1, Vector3D v)
{
    Vector3D newVec;

    for (int i = 0; i < 3; ++i)
    {
        newVec[i] = m1.arrayVectors[i] * v;
    }

    return newVec;
}

/**
 * Creates a new Matrix with the values from the stdin.
 * @param in
 * @param m1
 * @return
 */
std::istream& operator>>(std::istream &in,  Matrix3D &m1)
{

    in >> m1.arrayVectors[0] >> m1.arrayVectors[1] >> m1.arrayVectors[2];

    return in;
}

/**
 * Prints a given array to the stdout
 * @param out
 * @param m1
 * @return
 */
std::ostream& operator<<(std::ostream &out, const Matrix3D &m1)
{
    for (Vector3D v : m1.arrayVectors)
    {
        out << v;
    }
    return out;
}

/**
 * Find the transposed matrix of a given matrix.
 * @param m the given matrix
 * @return the transposed matrix.
 */
Matrix3D findTranspose(Matrix3D m)
{
    Matrix3D m2Transpose;

    for (int i = 0; i < 3; ++i)
    {
        Vector3D colVec;
        for (int j = 0; j < 3; ++j)
        {
            colVec[j] = m.arrayVectors[j][i];
        }

        m2Transpose.arrayVectors[i] = colVec;
    }

    return m2Transpose;
}

/**
 * returns the vector which is in the given index of the matrix.
 * @param index the given index.
 * @return The vector.
 */
Vector3D& Matrix3D::operator[](int index)
{
    switch(index)
    {
        case 0:
            return this->arrayVectors[0];
        case 1:
            return this->arrayVectors[1];
        case 2:
            return this->arrayVectors[2];
        default:
            std::cerr << "Index out of range" << std::endl;
            return this->arrayVectors[0];
    }

}

/**
 * finds the Vector which is in the given index.
 * @param index the given index.
 * @return the vector in the index.
 */
Vector3D Matrix3D::row(short index)
{
    if (index > 2 || index < 0)
    {
        std::cerr << "Index out of range" << std::endl;
        return this->arrayVectors[0];
    }
    return this->arrayVectors[index];
}

/**
 * @param index The given index.
 * @return returns the column of the matrix in the given index.
 */
Vector3D Matrix3D::column(short index)
{
    if (index > 2 || index < 0)
    {
        std::cerr << "Index out of range" << std::endl;
        return this->arrayVectors[0];
    }
    Matrix3D transposed = findTranspose(*this);

    return transposed.arrayVectors[index];

}

/**
 * @return returns the sum of the elements in the diagonal of the current matrix.
 */
double Matrix3D::trace()
{
    double sum = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j =0; j < 3; ++j)
        {
            if (i==j)
            {
                sum += this->arrayVectors[i][j];
            }
        }
    }

    return sum;
}

/**
 * @return returns the determinant of the current array.
 */
double Matrix3D::determinant()
{

    auto arr = this->arrayVectors;
    double det = arr[0][0]*(arr[1][1]*arr[2][2] - arr[1][2]*arr[2][1]) -
            arr[0][1]*(arr[1][0]*arr[2][2] - arr[1][2]*arr[2][0]) +
            arr[0][2]*(arr[1][0]*arr[2][1] - arr[1][1]*arr[2][0]);

    return det;
}