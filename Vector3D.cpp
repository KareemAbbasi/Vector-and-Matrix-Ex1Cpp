//
// Created by kareem on 12/12/18.
//

#include "Vector3D.h"

Vector3D::Vector3D()
{
    x = 0;
    y = 0;
    z = 0;
}

Vector3D::Vector3D(double x, double y, double z)
{
    x = x;
    y = y;
    z = z;
}

Vector3D::Vector3D(double *d)
{
    x = d[0];
    y = d[1];
    z = d[2];
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

Vector3D Vector3D::operator+=(const Vector3D v2)
{
    return operator+(v2);
}

Vector3D Vector3D::operator-=(const Vector3D v2)
{
    return operator-(v2);
}

Vector3D Vector3D::operator+=(const double num)
{

}