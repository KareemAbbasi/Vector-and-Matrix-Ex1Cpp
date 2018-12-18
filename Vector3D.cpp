//
// Created by kareem on 12/12/18.
//

#include "Vector3D.h"

#include <iostream>
#include <cmath>

/**
     * Default Constructor.
     */
Vector3D::Vector3D()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

/**
 * Constructor that receives 3 values and creates a new vector from them.
 * @param x
 * @param y
 * @param z
 */
Vector3D::Vector3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

/**
 * Vector3D constructor that receives an array of three values and creates a vector from
 * these values.
 * @param d the array
 */
Vector3D::Vector3D(double *d)
{
    this->x = d[0];
    this->y = d[1];
    this->z = d[2];
}

/**
 * Copy constructor, creates a new vector3D that has the same values as a given vector.
 * @param vector3D
 */
Vector3D::Vector3D(const Vector3D &vector3D)
{
    this->x = vector3D.x;
    this->y = vector3D.y;
    this->z = vector3D.z;
}

/**
 * @return Returns the x value of the vector.
 */
double Vector3D::getX() { return x; }

/**
 * @return Returns the y value of the vector.
 */
double Vector3D::getY() { return y; }

/**
 * @return Returns the z value of the vector.
 */
double Vector3D::getZ() { return z; }

/**
 * Adds two given vectors together and returns their sum.
 * @param v1 first vector.
 * @param v2 second vector.
 * @return a new vector that is the sum of the two vectors.
 */
Vector3D operator+(const Vector3D v1, const Vector3D v2)
{
    return Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

/**
 * Subtracts two given vectors from one another.
 * @param v1 First vector.
 * @param v2 Second vector.
 * @return a new vector that is the result of the subtraction.
 */
Vector3D operator-(const Vector3D v1, const Vector3D v2)
{
    return Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

/**
 * Adds a given vector to the current vector.
 * @param v2 the given vector.
 * @return The sum of the two vectors.
 */
Vector3D& Vector3D::operator+=(const Vector3D v2)
{
    this->x += v2.x;
    this->y += v2.y;
    this->z += v2.z;

    return *this;
}

/**
 * Subtracts a given vector from the current vector.
 * @param v2 the given vector.
 * @return The result.
 */
Vector3D& Vector3D::operator-=(const Vector3D v2)
{
    this->x -= v2.x;
    this->y -= v2.y;
    this->z -= v2.z;

    return *this;
}

/**
 * Adds a number to the current vector.
 * @param num The number to add to the vector.
 * @return The result.
 */
Vector3D& Vector3D::operator+=(const double num)
{
    this->x += num;
    this->y += num;
    this->z += num;

    return *this;
}

/**
 * Subtracts a number from the current vector.
 * @param num The number to subtract from the vector.
 * @return The result.
 */
Vector3D& Vector3D::operator-=(const double num)
{
    this->x -= num;
    this->y -= num;
    this->z -= num;

    return *this;
}

/**
 * @return returns the minus of the vector.
 */
Vector3D& Vector3D::operator-()
{
    this->x *= -1;
    this->y *= -1;
    this->z *= -1;

    return *this;
}

/**
 * Multiplies a vector with a number.
 * @param v2 The given vector.
 * @param num The given number.
 * @return a new vector that is the result.
 */
Vector3D operator*(const Vector3D v2, const double num)
{
    return Vector3D(v2.x * num, v2.y * num, v2.z * num);
}

/**
 * Devides a vector with a number.
 * @param v2 The given vector.
 * @param num The given number.
 * @return a new vector that is the result.
 */
Vector3D operator/(const Vector3D v2, const double num)
{
    return Vector3D(v2.x / num, v2.y / num, v2.z / num);
}

/**
 * Multiplies a number with a vector.
 * @param num The given number.
 * @param v2 The given vector.
 * @return a new vector that is the result.
 */
Vector3D operator*(const double num, const Vector3D v2)
{
    return Vector3D(v2.x * num, v2.y * num, v2.z * num);
}

/**
 * Multiplies the current vector with a given number.
 * @param num The given number.
 * @return The result.
 */
Vector3D& Vector3D::operator*=(const double num)
{
    this->x *= num;
    this->y *= num;
    this->z *= num;

    return *this;
}

/**
 * Divides the current vector with a given number.
 * @param num The given number.
 * @return The result.
 */
Vector3D& Vector3D::operator/=(const double num)
{
    this->x /= num;
    this->y /= num;
    this->z /= num;

    return *this;
}

/**
 * Calculates the distance between two given vectors.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return The distance between them.
 */
double operator|(const Vector3D v1, const Vector3D v2)
{
    return sqrt(pow((v1.x - v2.x), 2) + pow((v1.y - v2.y), 2) + pow((v1.z - v2.z), 2));
}

/**
 * Calculates the Dot product of two given vectors.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return The result.
 */
double operator*(const Vector3D v1, const Vector3D v2)
{
    return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

/**
 * Calculates the angle between two given vectors.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return The angle between them.
 */
double operator^(Vector3D v1, Vector3D v2)
{
    double cosineTheta = (v1 * v2) / (v1.norm() * v2.norm());
    return acos(cosineTheta);
}

/**
 * @return The length of the current vector.
 */
double Vector3D::norm()
{
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

/**
 * Find the distance between the current vector and a given vector.
 * @param v2 The given vector.
 * @return The distance.
 */
double Vector3D::dist(const Vector3D v2)
{
    return sqrt(pow((x - v2.x), 2) + pow((y - v2.y), 2) + pow((z - v2.z), 2));
}

/**
 * Reads a vector from stdin.
 * @param in
 * @param v1
 * @return
 */
std::istream& operator>>(std::istream &in, Vector3D& v1)
{
    in >> v1.x >> v1.y >> v1.z;
    return in;
}

/**
 * prints a vector to stdout.
 * @param out
 * @param vec
 * @return
 */
std::ostream& operator<<(std::ostream &out, const Vector3D vec)
{
    out << vec.x << " " << vec.y << " " << vec.z ;
    return out;
}

/**
 * copy constructor.
 * @param v2
 * @return
 */
//Vector3D& Vector3D::operator=(const Vector3D v2)
//{
//    this->x = v2.x;
//    this->y = v2.y;
//    this->z = v2.z;
//
//    return *this;
//}

/**
 * Reads and writes to an index in the vector.
 * @param index The given index.
 * @return a reference to the value at that index.
 */
double& Vector3D::operator[](int index)
{
    switch(index)
    {
        case 0:
            return this->x;
        case 1:
            return this->y;
        case 2:
            return this->z;
        default:
            std::cerr << "Index out of range" << std::endl;
            return this->x;
    }
}