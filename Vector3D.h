//
// Created by kareem on 12/12/18.
//
#include <iostream>

#ifndef VECTOR3D_H
#define VECTOR3D_H

/**
 * Vector3D class
 */
class Vector3D
{
public:
    /**
     * Default Constructor.
     */
    Vector3D();

    /**
     * Constructor that receives 3 values and creates a new vector from them.
     * @param x
     * @param y
     * @param z
     */
    Vector3D(double x, double y, double z);

    /**
     * Vector3D constructor that receives an array of three values and creates a vector from
     * these values.
     * @param d the array
     */
    Vector3D(double d[3]);

    /**
     * Copy constructor, creates a new vector3D that has the same values as a given vector.
     * @param vector3D
     */
    Vector3D(const Vector3D& vector3D);

    /**
     * @return Returns the x value of the vector.
     */
    double getX();

    /**
     * @return Returns the y value of the vector.
     */
    double getY();


    /**
     * @return Returns the z value of the vector.
     */
    double getZ();

    /**
     * Adds two given vectors together and returns their sum.
     * @param v1 first vector.
     * @param v2 second vector.
     * @return a new vector that is the sum of the two vectors.
     */
    friend Vector3D operator+(const Vector3D v1, const Vector3D v2);

    /**
     * Subtracts two given vectors from one another.
     * @param v1 First vector.
     * @param v2 Second vector.
     * @return a new vector that is the result of the subtraction.
     */
    friend Vector3D operator-(const Vector3D v1, const Vector3D v2);


    /**
     * Adds a given vector to the current vector.
     * @param v2 the given vector.
     * @return The sum of the two vectors.
     */
    Vector3D& operator+=(const Vector3D v2);

    /**
     * Subtracts a given vector from the current vector.
     * @param v2 the given vector.
     * @return The result.
     */
    Vector3D& operator-=(const Vector3D v2);


    /**
     * Adds a number to the current vector.
     * @param num The number to add to the vector.
     * @return The result.
     */
    Vector3D& operator+=(const double num);

    /**
     * Subtracts a number from the current vector.
     * @param num The number to subtract from the vector.
     * @return The result.
     */
    Vector3D& operator-=(const double num);

    /**
     * @return returns the minus of the vector.
     */
    Vector3D& operator-();

    /**
     * Multiplies a vector with a number.
     * @param v2 The given vector.
     * @param num The given number.
     * @return a new vector that is the result.
     */
    friend Vector3D operator*(const Vector3D v2, const double num);

    /**
     * Devides a vector with a number.
     * @param v2 The given vector.
     * @param num The given number.
     * @return a new vector that is the result.
     */
    friend Vector3D operator/(const Vector3D v2, const double num);


    /**
     * Multiplies a number with a vector.
     * @param num The given number.
     * @param v2 The given vector.
     * @return a new vector that is the result.
     */
    friend Vector3D operator*(const double num, const Vector3D v2);


    /**
     * Multiplies the current vector with a given number.
     * @param num The given number.
     * @return The result.
     */
    Vector3D& operator*=(const double num);

    /**
     * Divides the current vector with a given number.
     * @param num The given number.
     * @return The result.
     */
    Vector3D& operator/=(const double num);

    /**
     * Calculates the distance between two given vectors.
     * @param v1 The first vector.
     * @param v2 The second vector.
     * @return The distance between them.
     */
    friend double operator|(const Vector3D v1, const Vector3D v2);

    /**
     * Calculates the Dot product of two given vectors.
     * @param v1 The first vector.
     * @param v2 The second vector.
     * @return The result.
     */
    friend double operator*(const Vector3D v1, const Vector3D v2);

    /**
     * Calculates the angle between two given vectors.
     * @param v1 The first vector.
     * @param v2 The second vector.
     * @return The angle between them.
     */
    friend double operator^(const Vector3D v1, const Vector3D v2);


    /**
     * @return The length of the current vector.
     */
    double norm();

    /**
     * Find the distance between the current vector and a given vector.
     * @param v2 The given vector.
     * @return The distance.
     */
    double dist(const Vector3D v2);


    /**
     * Reads a vector from stdin.
     * @param in
     * @param v1
     * @return
     */
    friend std::istream& operator>>(std::istream &in, Vector3D& v1);

    /**
     * prints a vector to stdout.
     * @param out
     * @param vec
     * @return
     */
    friend std::ostream& operator<<(std::ostream &out, const Vector3D vec);


    /**
     * copy constructor.
     * @param v2
     * @return
     */
//    Vector3D&operator=(const Vector3D v2);

    /**
     * Reads and writes to an index in the vector.
     * @param index The given index.
     * @return a reference to the value at that index.
     */
    double& operator[](int index);


private:
    /**
     * The x, y, z values of the vector.
     */
    double x, y, z;


};


#endif //VECTOR3D_H
