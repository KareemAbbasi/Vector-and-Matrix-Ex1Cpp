//
// Created by kareem on 12/12/18.
//
#include <vector>
#include "Vector3D.h"

#ifndef MATRIX3D_H
#define MATRIX3D_H

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
    Matrix3D& operator-=(const Matrix3D m2);

    Matrix3D& operator*=(Matrix3D m2);

    friend Matrix3D operator*(const Matrix3D m1, const Matrix3D m2);
    friend Matrix3D operator+(const Matrix3D m1, const Matrix3D m2);
    friend Matrix3D operator-(const Matrix3D m1, const Matrix3D m2);

    Matrix3D& operator*=(double num);
    Matrix3D& operator/=(double num);

    friend Vector3D operator*(Matrix3D m1, Vector3D v);

    friend std::istream& operator>>(std::istream &in, Matrix3D& m1);
    friend std::ostream& operator<<(std::ostream &out, const Matrix3D& m1);



    Vector3D& operator[](int index);

    Vector3D row(short index);
    Vector3D column(short index);
    double trace();
    double determinant();

    friend Matrix3D findTranspose(Matrix3D m);


private:
    Vector3D arrayVectors[3];
};

#endif //MATRIX3D_H
