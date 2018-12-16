//
// Created by kareem on 12/12/18.
//

#include "Vector3D.h"
//TODO remove this include
#include "Matrix3D.h"
#include <iostream>
#include <cmath>

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
    this->x = vector3D.x;
    this->y = vector3D.y;
    this->z = vector3D.z;
}

double Vector3D::getX() { return x; }

double Vector3D::getY() { return y; }

double Vector3D::getZ() { return z; }

Vector3D operator+(const Vector3D v1, const Vector3D v2)
{
    return Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector3D operator-(const Vector3D v1, const Vector3D v2)
{
    return Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
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

Vector3D operator*(const Vector3D v2, const double num)
{
    return Vector3D(v2.x * num, v2.y * num, v2.z * num);
}

Vector3D operator/(const Vector3D v2, const double num)
{
    return Vector3D(v2.x / num, v2.y / num, v2.z / num);;
}

Vector3D operator*(const double num, const Vector3D v2)
{
    return Vector3D(v2.x * num, v2.y * num, v2.z * num);
}

Vector3D& Vector3D::operator*=(const double num)
{
    this->x *= num;
    this->y *= num;
    this->z *= num;

    return *this;
}

Vector3D& Vector3D::operator/=(const double num)
{
    this->x /= num;
    this->y /= num;
    this->z /= num;

    return *this;
}

double operator|(const Vector3D v1, const Vector3D v2)
{
    return sqrt(pow((v1.x - v2.x), 2) + pow((v1.y - v2.y), 2) + pow((v1.z - v2.z), 2));
}

double operator*(const Vector3D v1, const Vector3D v2) {
    return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

double operator^(Vector3D v1, Vector3D v2)
{
    double cosineTheta = (v1 * v2) / (v1.norm() * v2.norm());
    return acos(cosineTheta);
}

double Vector3D::norm()
{
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

double Vector3D::dist(const Vector3D v2)
{
    return sqrt(pow((x - v2.x), 2) + pow((y - v2.y), 2) + pow((z - v2.z), 2));
}

std::istream& operator>>(std::istream &in, Vector3D& v1)
{
    in >> v1.x >> v1.y >> v1.z;
    return in;
}

//TODO check school output.
std::ostream& operator<<(std::ostream &out, const Vector3D vec)
{
    out << vec.x << " " << vec.y << " " << vec.z << std::endl;
    return out;
}

Vector3D& Vector3D::operator=(const Vector3D v2)
{
    this->x = v2.x;
    this->y = v2.y;
    this->z = v2.z;

    return *this;
}


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
            throw std::out_of_range("Index out of range");
    }
}


int main(){
    Vector3D a(3.0, 2.0, 5.0);
    std::cout << "a.norm = " << a.norm() << std::endl;
    Vector3D b(7.0, 1.0, 5);
    std::cout << "a.dist(b) = " << a.dist(b) << std::endl;

    Vector3D c(1, 1, 1);

    Matrix3D m(a,b,c);
    Matrix3D m1(1,2,3,4,1,0,0,8,1);

//    m*=m1;
    Matrix3D nm = m *m1;

    std::cout << nm;

    Vector3D vec = m * a;
    std::cout << "..." << std::endl;
    std::cout << m << std::endl;

//    m[1] = a + b;
    std::cout << "..." << std::endl;
    std::cout << m.column(-1) << std::endl;

    return 0;

}

