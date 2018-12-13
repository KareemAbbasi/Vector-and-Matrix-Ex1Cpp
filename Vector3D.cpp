//
// Created by kareem on 12/12/18.
//

#include "Vector3D.h"
#include <iostream>

Vector3D::Vector3D()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3D::Vector3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3D::Vector3D(double *d)
{
    this->x = d[0];
    this->y = d[1];
    this->z = d[2];
}

Vector3D::Vector3D(const Vector3D &vector3D)
{
    x = vector3D.x;
    y = vector3D.y;
    z = vector3D.z;
}

double Vector3D::getX() { return x; }

double Vector3D::getY() { return y; }

double Vector3D::getZ() { return z; }

Vector3D Vector3D::operator+(const Vector3D v2)
{
    double newX, newY, newZ;
    newX = x + v2.x;
    newY = y + v2.y;
    newZ = z + v2.z;

    return Vector3D(newX, newY, newZ);
}

Vector3D Vector3D::operator-(const Vector3D v2)
{
    double newX, newY, newZ;
    newX = x - v2.x;
    newY = y - v2.y;
    newZ = z - v2.z;

    return Vector3D(newX, newY, newZ);
}

Vector3D& Vector3D::operator+=(const Vector3D v2)
{
    this->x += v2.x;
    this->y += v2.y;
    this->z += v2.z;

    return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D v2)
{
    this->x -= v2.x;
    this->y -= v2.y;
    this->z -= v2.z;

    return *this;
}

Vector3D& Vector3D::operator+=(const double num)
{
    this->x += num;
    this->y += num;
    this->z += num;

    return *this;
}

Vector3D& Vector3D::operator-=(const double num)
{
    this->x -= num;
    this->y -= num;
    this->z -= num;

    return *this;
}

Vector3D& Vector3D::operator-()
{
    this->x *= -1;
    this->y *= -1;
    this->z *= -1;

    return *this;
}

Vector3D Vector3D::operator*(const double num)
{
    double newX, newY, newZ;
    newX = x * num;
    newY = y * num;
    newZ = z * num;

    return Vector3D(newX, newY, newZ);
}

Vector3D Vector3D::operator/(const double num)
{
    double newX, newY, newZ;
    newX = x / num;
    newY = y / num;
    newZ = z / num;

    return Vector3D(newX, newY, newZ);
}



int main()
{
    Vector3D v1 = Vector3D(1,2,3);
    std::cout << v1.getX() << " " << v1.getY() << " " << v1.getZ() << std::endl;
    Vector3D v2 = Vector3D(1,0,3);
    std::cout << v2.getX() << " " << v2.getY() << " " << v2.getZ() << std::endl;

    v1 += v2;
    std::cout << v1.getX() << " " << v1.getY() << " " << v1.getZ() << std::endl;

    Vector3D newVec = v1 + v2;

    std::cout << newVec.getX() << " " << newVec.getY() << " " << newVec.getZ() << std::endl;
    return 0;
}

