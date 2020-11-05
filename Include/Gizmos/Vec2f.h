#pragma once

#ifndef __VEC2F_H__
#define __VEC2F_H__
#include <cmath>

namespace ge
{

	template<class T>
	class vec2f
	{
	public:
		// Constructors
		vec2f();
		vec2f(T x, T y) : x(x), y(y) { }
		vec2f(const vec2f& v) : x(v.x), y(v.y) { }
		~vec2f() {}

		// Operators
		vec2f operator=(vec2f v) { x = v.x; y = v.y; return this; }

		vec2f operator+(vec2f v) { return vec2f(x + v.x, y + v.y); }
		vec2f operator+=(vec2f v) { x += v.x; y += v.y; return this; }

		vec2f operator-(vec2f v) { return vec2f(x - v.x, y - v.y); }
		vec2f operator-=(vec2f v) { x -= v.x; y -= v.y; return this; }

		vec2f operator*(T scale) { return vec2f(x * scale, y * scale); }
		vec2f operator*=(T scale) { x *= scale; y *= scale; return this; }

		vec2f operator/(T divisor)
		{
			if (x == 0 || divisor == 0 || y == 0)
			{
				return *this;
			}
			return vec2f(x / divisor, y / divisor);
		}

		vec2f operator/=(T divisor)
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
		bool operator==(vec2f v) { return (x == v.x && y == v.y); }
		bool operator!=(vec2f v) { return (x != v.x || y != v.y); }

		// Getters
		T getX() { return x; }
		T getY() { return y; }
		T get() { return this; }


		vec2f normalized() { vec2f v = vec2f(x, y); v.normalise(); return v; }

		float magnitude() { return std::sqrt(x * x + y * y); }

		float squareMagnitude() { return x * x + y * y; }

		float length() { return std::sqrt(x * x + y * y); }

		float lengthSquared() { return x * x + y * y; }

		float distance(vec2f v) { vec2f d = vec2f(v.x - x, v.y - y); return d.length(); }

		// Setters
		void setX(T x) { this->x = x; }
		void setY(T y) { this->y = y; }
		void set(T x, T y) { this->x = x; this->y = y; }
		void set(vec2f v) { x = v.x; y = v.y; }


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

		static float distance(vec2f v1, vec2f v2)
		{
			v2 -= v1;
			return v2.length();
		}

		static vec2f zero() { return vec2f(0, 0); }

	private:
		T x, y;
	};


	typedef vec2f<float> Vector2f;
	typedef vec2f<double> Vector2d;

#endif

	template<class T>
	inline vec2f<T>::vec2f() : x(0), y(0)
	{
	}
}