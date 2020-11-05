#pragma once

#ifndef __VEC2I_H__
#define __VEC2I_H__

#include <cmath>

template<class T>
class vec2i
{
public:
	// Constructors
	vec2i();
	vec2i(T x, T y) : x(x), y(y) { }
	vec2i(const vec2i& v) : x(v.x), y(v.y) { }
	~vec2i() {}

	// Operators
	vec2i operator=(vec2i v) { x = v.x; y = v.y; return this; }

	vec2i operator+(vec2i v) { return vec2i(x + v.x, y + v.y); }
	vec2i operator+=(vec2i v) { x += v.x; y += v.y; return this; }

	vec2i operator-(vec2i v) { return vec2i(x - v.x, y - v.y); }
	vec2i operator-=(vec2i v) { x -= v.x; y -= v.y; return this; }

	vec2i operator*(T scale) { return vec2i(x * scale, y * scale); }
	vec2i operator*=(T scale) { x *= scale; y *= scale; return this; }

	vec2i operator/(T divisor)
	{
		if (x == 0 || divisor == 0 || y == 0)
		{
			return *this;
		}
		return vec2i(x / divisor, y / divisor);
	}

	vec2i operator/=(T divisor)
	{
		if (x == 0 || divisor == 0 || y == 0)
		{
			return *this;
		}
		x /= divisor;
		y /= divisor;
		return *this;
	}

	// Comparison Operators
	bool operator==(vec2i v) { return (x == v.x && y == v.y); }
	bool operator!=(vec2i v) { return (x != v.x || y != v.y); }

	// Getters
	T getX() { return x; }
	T getY() { return y; }
	T get() { return this; }


	vec2i normalized() { vec2i v = vec2i(x, y); v.normalise(); return v; }

	float magnitude() { return std::sqrt(x * x + y * y); }

	float squareMagnitude() { return x * x + y * y; }

	float length() { return std::sqrt(x * x + y * y); }

	float lengthSquared() { return x * x + y * y; }

	float distance(vec2i v) { vec2i d = vec2i(v.x - x, v.y - y); return d.length(); }

	// Setters
	void setX(T x) { this->x = x; }
	void setY(T y) { this->y = y; }
	void set(T x, T y) { this->x = x; this->y = y; }
	void set(vec2i v) { x = v.x; y = v.y; }


	// Static functions
	static void normalise()
	{
		float m = magnitude();

		if (m == 0)
		{
			this = zero();
			return;
		}
		this /= m;
	}

	static float distance(vec2i v1, vec2i v2)
	{
		v2 -= v1;
		return v2.length();
	}

	static vec2i zero() { return vec2i(0, 0); }

private:
	T x, y;
};


typedef vec2i<int> Vector2i;
typedef vec2i<unsigned int> Vector2u;

#endif

template<class T>
inline vec2i<T>::vec2i() : x(0), y(0)
{
}
