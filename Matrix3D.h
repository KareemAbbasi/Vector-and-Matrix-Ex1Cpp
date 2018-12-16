//
// Created by kareem on 12/12/18.
//
#include <vector>
#include "Vector3D.h"

#ifndef UNTITLED_MATRIX3D_H
#define UNTITLED_MATRIX3D_H

class Matrix3D
{
public:

    Matrix3D();
    Matrix3D(double num);
    Matrix3D(double n1, double n2, double n3, double n4, double n5, double n6,
             double n7, double n8, double n9);
    Matrix3D(double nums[9]);
    Matrix3D(double nums[3][3]);
    Matrix3D(Vector3D v1, Vector3D v2, Vector3D v3);
    Matrix3D(const Matrix3D& matrix3D);

    Matrix3D& operator+=(const Matrix3D m2);
    Matrix3D& operator-=(const Matrix3D m2);

    Matrix3D& operator*=(Matrix3D m2);



private:
    Vector3D arrayVectors[3];
};

#endif //UNTITLED_MATRIX3D_H
