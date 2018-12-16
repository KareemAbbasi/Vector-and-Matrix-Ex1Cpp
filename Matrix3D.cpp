//
// Created by kareem on 12/12/18.
//
#include "Matrix3D.h"

Matrix3D::Matrix3D()
{
    Vector3D v1 = Vector3D(0, 0, 0);
    Vector3D v2 = Vector3D(0, 0, 0);
    Vector3D v3 = Vector3D(0, 0, 0);

    this->arrayVectors[0] = v1;
    this->arrayVectors[1] = v2;
    this->arrayVectors[2] = v3;
}

Matrix3D::Matrix3D(double n1, double n2, double n3, double n4, double n5, double n6, double n7, double n8, double n9)
{
    Vector3D v1 = Vector3D(n1, n2, n3);
    Vector3D v2 = Vector3D(n4, n5, n6);
    Vector3D v3 = Vector3D(n7, n8, n9);

    this->arrayVectors[0] = v1;
    this->arrayVectors[1] = v2;
    this->arrayVectors[2] = v3;
}

Matrix3D::Matrix3D(double num)
{
    Vector3D v1 = Vector3D(num, 0, 0);
    Vector3D v2 = Vector3D(0, num, 0);
    Vector3D v3 = Vector3D(0, 0, num);

    this->arrayVectors[0] = v1;
    this->arrayVectors[1] = v2;
    this->arrayVectors[2] = v3;
}

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

Matrix3D::Matrix3D(double nums[3][3])
{
    unsigned int i = 0;
    for (i = 0; i < 3; ++ i)
    {
        auto newVec = Vector3D(nums[i]);
        arrayVectors[i] = newVec;
    }
}

Matrix3D::Matrix3D(Vector3D v1, Vector3D v2, Vector3D v3)
{
    this->arrayVectors[0] = v1;
    this->arrayVectors[1] = v2;
    this->arrayVectors[2] = v3;
}

Matrix3D::Matrix3D(const Matrix3D &matrix3D)
{
    for (int i = 0; i < 3; ++i)
    {
        this->arrayVectors[i] = matrix3D.arrayVectors[i];
    }
}

Matrix3D& Matrix3D::operator+=(const Matrix3D m2)
{
    for (int i = 0; i < 3; ++i)
    {
        this->arrayVectors[i] += m2.arrayVectors[i];
    }

    return *this;
}

Matrix3D& Matrix3D::operator-=(const Matrix3D m2)
{
    for (int i = 0; i < 3; ++i)
    {
        this->arrayVectors[i] -= m2.arrayVectors[i];
    }

    return *this;
}

Matrix3D& Matrix3D::operator*=(Matrix3D m2)
{
    for (int i = 0; i < 3; ++i)
    {
        double vecValues[3];

        for (int j = 0; j < 3; ++j)
        {
            vecValues[j] = this->arrayVectors[i].getX() * m2.arrayVectors[j].getX();
        }

        this->arrayVectors[i] = Vector3D(vecValues);
    }

    return *this;
}