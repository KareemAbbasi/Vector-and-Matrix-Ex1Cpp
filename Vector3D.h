//
// Created by kareem on 12/12/18.
//

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

    Vector3D operator+(const Vector3D v2);
    Vector3D operator-(const Vector3D v2);

    Vector3D& operator+=(const Vector3D v2);
    Vector3D& operator-=(const Vector3D v2);

    Vector3D& operator+=(const double num);
    Vector3D& operator-=(const double num);

    Vector3D& operator-();

    Vector3D operator*(const double num);
    Vector3D operator/(const double num);

    Vector3D operator*(const Vector3D v2);









private:
    double x, y, z;


};


#endif //UNTITLED_VECTOR3D_H
