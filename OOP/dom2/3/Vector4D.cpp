#include"Vector4D.hpp"

Vector4D::Vector4D()
{
	for (int i = 0; i < 4; i++) {
		vector[i] = 0;
	}
}
Vector4D::Vector4D(double a, double b, double c, double d)
{
	vector[0] = a;
	vector[1] = b;
	vector[2] = c;
	vector[3] = d;
}

double& Vector4D::operator[](int ind)
{
	return vector[ind];
}
const double& Vector4D::operator[](int ind) const
{
	return vector[ind];
}

Vector4D Vector4D::operator+(const Vector4D& other) const
{
	Vector4D tmp = *this;
	tmp += other;
	return tmp;
}
Vector4D& Vector4D::operator+=(const Vector4D& other)
{
	for (int i = 0; i < 4; i++) {
		vector[i] += other[i];
	}
	return *this;
}

Vector4D Vector4D::operator-(const Vector4D& other) const
{
	Vector4D tmp = *this;
	tmp -= other;
	return tmp;
}
Vector4D& Vector4D::operator-=(const Vector4D& other)
{
	for (int i = 0; i < 4; i++) {
		vector[i] -= other[i];
	}
	return *this;
}

Vector4D Vector4D::operator*(const Vector4D& other) const
{
	Vector4D tmp = *this;
	tmp *= other;
	return tmp;
}
Vector4D Vector4D::operator*(const double& num) const
{
	Vector4D tmp = *this;
	for (int i = 0; i < 4; i++) {
		tmp[i] *= num;
	}
	return tmp;
}
Vector4D& Vector4D::operator*=(const Vector4D& other)
{
	for (int i = 0; i < 4; i++) {
		vector[i] *= other[i];
	}
	return *this;
}
Vector4D& Vector4D::operator*=(const double& num)
{
	for (int i = 0; i < 4; i++) {
		vector[i] *= num;
	}
	return *this;
}

Vector4D Vector4D::operator/(const Vector4D& other) const
{
	Vector4D tmp = *this;
	tmp /= other;
	return tmp;
}
Vector4D& Vector4D::operator/=(const Vector4D& other)
{
	for (int i = 0; i < 4; i++) {
		vector[i] /= other[i];
	}
	return *this;
}

bool Vector4D::operator==(const Vector4D& other) const
{
	for (int i = 0; i < 4; i++) {
		if (vector[i] != other[i]) {
			return false;
		}
	}
	return true;
}
bool Vector4D::operator!=(const Vector4D& other) const
{
	bool check = true;
	for (int i = 0; i < 4; i++) {
		if (vector[i] == other[i]) {
			check = false;
		}
		else {
			check = true;
		}
		
	}
	return check;
}

bool Vector4D::operator<(const Vector4D& other) const
{
	for (int i = 0; i < 4; i++) {
		if (vector[i] != other[i] && vector[i] < other[i]) {
			return true;
		}
	}
	return false;
}
bool Vector4D::operator>(const Vector4D& other) const
{
	for (int i = 0; i < 4; i++) {
		if (vector[i] != other[i] && vector[i] > other[i]) {
			return true;
		}
	}
	return false;
}
bool Vector4D::operator<=(const Vector4D& other) const
{
	for (int i = 0; i < 4; i++) {
		if (vector[i] != other[i] && vector[i] > other[i]) {
			return false;
		}
	}
	return true;
}
bool Vector4D::operator>=(const Vector4D& other) const
{
	for (int i = 0; i < 4; i++) {
		if (vector[i] != other[i] && vector[i] < other[i]) {
			return false;
		}
	}
	return true;
}

bool Vector4D::operator!() const
{
	for (int i = 0; i < 4; i++) {
		if (vector[i] != 0) {
			return false;
		}
	}
	return true;
}

Vector4D Vector4D::operator-() const
{
	Vector4D tmp = *this;
	for (int i = 0; i < 4; i++) {
		tmp[i] *= -1;
	}
	return tmp;
}
