//
// Created by kareem on 12/12/18.
//
#include <vector>
#include "Vector3D.h"

#ifndef MATRIX3D_H
#define MATRIX3D_H

/**
 * Matrix3D class
 */
class Matrix3D
{
public:


    /**
     * Default constructor.
     */
    Matrix3D();

    /**
     *Ceates a new Matrix where all of its values are the given num.
     * @param num The given num.
     */
    Matrix3D(double num);

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
    Matrix3D(double n1, double n2, double n3, double n4, double n5, double n6,
             double n7, double n8, double n9);

    /**
     * Creates a new matrix from the values of a given array of size 9.
     * @param nums The given array.
     */
    Matrix3D(double nums[9]);

    /**
     * Creates a new matrix from the values of a given 2d array of size 3x3.
     * @param nums the given array
     */
    Matrix3D(double nums[3][3]);

    /**
     * Creates a new martix from the values of three given vectors where each vector is a
     * row in the matrix.
     * @param v1 First vector.
     * @param v2 second vector.
     * @param v3 third vector.
     */
    Matrix3D(Vector3D v1, Vector3D v2, Vector3D v3);

    /**
     * Copy constructor, creates a new matrix from the values of a given array.
     * @param matrix3D the given array.
     */
    Matrix3D(const Matrix3D& matrix3D);

    /**
     * Adds a given array to the current array.
     * @param m2 the given array.
     * @return The result of the addition.
     */
    Matrix3D& operator+=(const Matrix3D m2);

    /**
     * subtracts a given array from the current array.
     * @param m2 the given array.
     * @return The result of the subtraction.
     */
    Matrix3D& operator-=(const Matrix3D m2);


    /**
     * multiplies the current array with a given array
     * @param m2 the given array
     * @return the result
     */
    Matrix3D& operator*=(Matrix3D m2);

    /**
     * Multiplies two given matrices.
     * @param m1 The first matrix.
     * @param m2 The second matrix.
     * @return The new matrix which is the result.
     */
    friend Matrix3D operator*(const Matrix3D m1, const Matrix3D m2);

    /**
     * Adds two given array together.
     * @param m1 The first matrix.
     * @param m2 The second matrix.
     * @return A new matrix which is the result.
     */
    friend Matrix3D operator+(const Matrix3D m1, const Matrix3D m2);

    /**
     * Subtracts two given matrices.
     * @param m1 The first array.
     * @param m2 The second array.
     * @return A new matrix which is the result.
     */
    friend Matrix3D operator-(const Matrix3D m1, const Matrix3D m2);

    /**
     * Multiplies the current matrix with a given number.
     * @param num The given number.
     * @return The result.
     */
    Matrix3D& operator*=(double num);

    /**
     * Divides the current matrix with a given number.
     * @param num the given number.
     * @return the result.
     */
    Matrix3D& operator/=(double num);

    /**
     * Multiplies a given matrix with a given vector.
     * @param m1 the given matrix.
     * @param v the given vector.
     * @return a new matrix which is the result.
     */
    friend Vector3D operator*(Matrix3D m1, Vector3D v);

    /**
     * Creates a new Matrix with the values from the stdin.
     * @param in
     * @param m1
     * @return
     */
    friend std::istream& operator>>(std::istream &in, Matrix3D& m1);

    /**
     * Prints a given array to the stdout
     * @param out
     * @param m1
     * @return
     */
    friend std::ostream& operator<<(std::ostream &out, Matrix3D m1);


    /**
     * returns the vector which is in the given index of the matrix.
     * @param index the given index.
     * @return The vector.
     */
    Vector3D& operator[](int index);

    /**
     * finds the Vector which is in the given index.
     * @param index the given index.
     * @return the vector in the index.
     */
    Vector3D row(short index);

    /**
     * @param index The given index.
     * @return returns the column of the matrix in the given index.
     */
    Vector3D column(short index);

    /**
     * @return returns the sum of the elements in the diagonal of the current matrix.
     */
    double trace();

    /**
     * @return returns the determinant of the current array.
     */
    double determinant();

    /**
     * Find the transposed matrix of a given matrix.
     * @param m the given matrix
     * @return the transposed matrix.
     */
    friend Matrix3D findTranspose(Matrix3D m);


private:
    /**
     * An array of the vectors of the matrix.
     */
    Vector3D arrayVectors[3];
};

#endif //MATRIX3D_H
