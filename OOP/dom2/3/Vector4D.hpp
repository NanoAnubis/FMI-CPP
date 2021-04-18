#pragma once

// Add all other required methods and fields of the class.

class Vector4D {

public:

    Vector4D();
    Vector4D(double, double, double, double);

    double& operator[](int);
    const double& operator[](int) const;

    Vector4D operator+(const Vector4D&) const;
    Vector4D& operator+=(const Vector4D&);

    Vector4D operator-(const Vector4D&) const;
    Vector4D& operator-=(const Vector4D&);

    Vector4D operator*(const Vector4D&) const;
    Vector4D operator*(const double&) const;
    Vector4D& operator*=(const Vector4D&);
    Vector4D& operator*=(const double&);

    Vector4D operator/(const Vector4D&) const;
    Vector4D& operator/=(const Vector4D&);

    bool operator==(const Vector4D&) const;
    bool operator!=(const Vector4D&) const;

    bool operator<(const Vector4D&) const;
    bool operator>(const Vector4D&) const;
    bool operator<=(const Vector4D&) const;
    bool operator>=(const Vector4D&) const;

    bool operator!()const;
    Vector4D operator-() const;


private:

    double vector[4];
};