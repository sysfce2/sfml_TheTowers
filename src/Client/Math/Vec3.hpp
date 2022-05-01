#pragma once
#include <cstdlib>

#include "Vec2.hpp"

namespace math {

	template<typename T>
	struct base_vec3 {
		T x, y, z;
		base_vec3(T value)
		: x(value), y(value), z(value)
		{}
		base_vec3(T x, T y, T z)
		: x(x), y(y), z(z)
		{}

		base_vec3()
		{x = 0; y = 0; z = 0;}

		~base_vec3() {}



		base_vec3<T>operator+=(const base_vec3<T>& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		base_vec3<T>operator-=(const base_vec3<T>& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}

		base_vec3<T>operator*=(const base_vec3<T>& other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}

		base_vec3<T>operator/=(const base_vec3<T>& other) {
			x /= other.x;
			y /= other.y;
			z /= other.z;
			return *this;
		}

		base_vec3<T> operator+(const base_vec3<T>& other) const {
			return base_vec3<T>(x+other.x, y+other.y, z+other.z);
		}

		base_vec3<T> operator+(const T& other) const {
			return base_vec3<T>(x+other, y+other, z+other);
		}

		base_vec3<T> operator-(const base_vec3<T>& other) const {
			return base_vec3<T>(x-other.x, y-other.y, z-other.z);
		}

		base_vec3<T> operator-(const T& other) const {
			return base_vec3<T>(x-other, y-other, z-other);
		}

		base_vec3<T> operator-() const {
			return base_vec3<T>(-x, -y, -z);
		}

		base_vec3<T> operator*(const base_vec3<T>& other) const {
			return base_vec3<T>(x*other.x, y*other.y, z*other.z);
		}

		base_vec3<T> operator*(const T& other) const {
			return base_vec3<T>(x*other, y*other, z*other);
		}

		base_vec3<T> operator/(const base_vec3<T>& other) const {
			return base_vec3<T>(x/other.x, y/other.y, z/other.z);
		}

		base_vec3<T> operator/(const T& other) const {
			return base_vec3<T>(x/other, y/other, z/other);
		}

		bool operator==(const base_vec3<T>& other){
			return x == other.x && y == other.y && z == other.z;
		}

		bool operator!=(const base_vec3<T>& other){
			return x != other.x || y != other.y || z != other.z;
		}
	};


	typedef base_vec3<float> vec3;
	typedef base_vec3<int> ivec3;
	typedef base_vec3<unsigned int> uvec3;

}