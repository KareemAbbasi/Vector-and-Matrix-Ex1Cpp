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

Matrix3D& Matrix3D::operator*=(double num)
{
    for (Vector3D v : this->arrayVectors)
    {
        v = Vector3D(v.getX()*num, v.getY()*num, v.getZ()*num);
    }

    return *this;
}

Matrix3D& Matrix3D::operator/=(double num)
{
    for (Vector3D v : this->arrayVectors)
    {
        v = Vector3D(v.getX()/num, v.getY()/num, v.getZ()/num);
    }

    return *this;
}


//TODO wrong, need to return vector
Vector3D operator*(Matrix3D m1, Vector3D v)
{
    Vector3D newVec;

    for (int i = 0; i < 3; ++i)
    {
        newVec[i] = m1.arrayVectors[i] * v;
    }

    return newVec;
}

std::istream& operator>>(std::istream &in, Matrix3D &m1)
{
    for (Vector3D v : m1.arrayVectors)
    {
        in >> v;
    }

    return in;
}

std::ostream& operator<<(std::ostream &out, Matrix3D &m1)
{
    for (Vector3D v : m1.arrayVectors)
    {
        out << v;
    }
    return out;
}

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
            throw std::out_of_range("Index out of range");
    }
}

Vector3D Matrix3D::row(short index)
{
    if (index > 2 || index < 0)
        throw std::out_of_range("Index out of range");
    return this->arrayVectors[index];
}

Vector3D Matrix3D::column(short index)
{
    if (index > 2 || index < 0)
        throw std::out_of_range("Index out of range");

    Matrix3D transposed = findTranspose(*this);

    return transposed.arrayVectors[index];

}

double Matrix3D::trace()
{
    double sum;
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

double Matrix3D::determinant()
{

}