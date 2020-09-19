/*
 * MIT License
 *
 * Copyright (c) 2020 retrooper
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once
#include <cmath>
template<typename T>
class Vector2
{
public:
	T x, y;

	Vector2() : x(0), y(0)
	{}

	Vector2(T x, T y) : x(x), y(y)
	{}

	Vector2(T arr[]) {
		this->x = arr[0];
		this->y = arr[1];
	}

	T get_x() const
	{
		return x;
	}

	T get_y() const
	{
		return y;
	}

	//BASIC MATH OPERATIONS

	void add(Vector2<T> target) 
	{
		this->x += target.x;
		this->y += target.y;
	}

	void subtract(Vector2<T> target) 
	{
		this->x -= target.x;
		this->y -= target.y;
	}

	void multiply(Vector2<T> target) 
	{
		this->x *= target.x;
		this->y *= target.y;
	}

	void divide(Vector2<T> target) 
	{
		this->x /= target.x;
		this->y /= target.y;
	}

	//OPERATOR OVERLOADING
	
	Vector2<T> operator+(Vector2<T> target) 
	{
		return Vector2<T>(this->x + target.x, this->y + target.y);
	}

	Vector2<T> operator-(Vector2<T> target) 
	{
		return Vector2<T>(this->x - target.x, this->y - target.y);
	}

	Vector2<T> operator*(Vector2<T> target) 
	{
		return Vector2<T>(this->x * target.x, this->y * target.y);
	}

	Vector2<T> operator/(Vector2<T> target) 
	{
		return Vector2<T>(this->x / target.x, this->y / target.y);
	}

	Vector2<T> operator+=(Vector2<T> target)
	{
		this->x += target.x;
		this->y += target.y;
		return *this;
	}

	Vector2<T> operator-=(Vector2<T> target)
	{
		this->x -= target.x;
		this->y -= target.y;
		return *this;
	}

	Vector2<T> operator*=(Vector2<T> target) 
	{
		this->x *= target.x;
		this->y *= target.y;
		return *this;
	}

	Vector2<T> operator/=(Vector2<T> target)
	{
		this->x /= target.x;
		this->y /= target.y;
		return *this;
	}

	//UTILITY FUNCTIONS

	void reverse() {
		this->x *= -1;
		this->y *= -1;
	}

	bool equals(Vector2<T> target) const {
		return this->x == target.x && this->x == target.y;
	}

	//VECTOR MATH

	T get_length() const
	{
		return (T) sqrt(get_length_squared());
	}

	T get_length_squared() const
	{
		return (T)(x * x + y * y);
	}

	T distance(Vector2<T> target) const
	{
		return (T)sqrt(distance_squared(target));
	}

	T distance_squared(Vector2<T> target) const
	{
		T vecX = this->x - target.x;
		T vecY = this->y - target.y;
		return (T)(vecX * vecX + vecY * vecY);
	}

	void normalize() 
	{
		T magnitude = get_length();
		this->x /= magnitude;
		this->y /= magnitude;
	}

	T dot(Vector2<T> target) const
	{
		return this->x * target.x + this->y * target.y;
	}
};
