//
// Created by kareem on 12/12/18.
//
#include <iostream>

#ifndef UNTITLED_VECTOR3D_H
#define UNTITLED_VECTOR3D_H

class Vector3D
{
public:
    Vector3D();
    Vector3D(double x, double y, double z);
    Vector3D(double d[3]);
    Vector3D(const Vector3D& vector3D);

    double getX();
    double getY();
    double getZ();


    friend Vector3D operator+(const Vector3D v1, const Vector3D v2);
    friend Vector3D operator-(const Vector3D v1, const Vector3D v2);

    Vector3D& operator+=(const Vector3D v2);
    Vector3D& operator-=(const Vector3D v2);

    Vector3D& operator+=(const double num);
    Vector3D& operator-=(const double num);

    Vector3D& operator-();

    friend Vector3D operator*(const Vector3D v2, const double num);
    friend Vector3D operator/(const Vector3D v2, const double num);

    friend Vector3D operator*(const double num, const Vector3D v2);

    Vector3D& operator*=(const double num);
    Vector3D& operator/=(const double num);

    friend double operator|(const Vector3D v1, const Vector3D v2);
    friend double operator*(const Vector3D v1, const Vector3D v2);
    friend double operator^(const Vector3D v1, const Vector3D v2);

    double norm();
    double dist(const Vector3D v2);


    friend std::ostream& operator<<(std::ostream &out, const Vector3D vec);

    Vector3D&operator=(const Vector3D v2);



private:
    double x, y, z;


};


#endif //UNTITLED_VECTOR3D_H
