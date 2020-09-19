#include <cmath>
#include <string>
template<typename T>
class Vector3
{
public:
	//XYZ fields
	T x, y, z;

	/**
	* Default constructor for the Vector3 class.
	* All fields are set to 0.
	*/
	Vector3() : x(0), y(0), z(0)
	{}

	/**
	* Constructor for the Vector3 class.
	*/
	Vector3(T x, T y, T z) : x(x), y(y), z(z)
	{}

	/**
	* Constructor for the Vector3 class.
	*/
	Vector3(T arr[]) {
		this->x = arr[0];
		this->y = arr[1];
		this->z = arr[2];
	}

	/**
	* Getter for the x field.
	* @return x
	*/
	T get_x() const
	{
		return x;
	}

	/**
	* Getter for the y field.
	* @return y 
	*/
	T get_y() const
	{
		return y;
	}

	/**
	* Getter for the z field.
	* @return z
	*/
	T get_z() const
	{
		return z;
	}

	//BASIC MATH OPERATIONS

	/**
	* Add a vector to this vector.
	* 
	* @param Second addend vector.
	*/
	void add(Vector3<T> target)
	{
		this->x += target.x;
		this->y += target.y;
		this->z += target.z;
	}

	/**
	* Subtract a vector from this vector.
	* 
	* @param Subtrahend vector.
	*/
	void subtract(Vector3<T> target)
	{
		this->x -= target.x;
		this->y -= target.y;
		this->z -= target.z;
	}

	/**
	* Multiply this vector by another vector.
	* 
	* @param Multiplier vector.
	*/
	void multiply(Vector3<T> target)
	{
		this->x *= target.x;
		this->y *= target.y;
		this->z *= target.z;
	}
	/**
	* Divide this vector by another vector.
	*
	* @param Divisor vector.
	*/
	void divide(Vector3<T> target)
	{
		this->x /= target.x;
		this->y /= target.y;
		this->z /= target.z;
	}

	//OPERATOR OVERLOADING

	/**
	* '+' Operator overloaded
	*/
	Vector3<T> operator+(Vector3<T> target)
	{
		return Vector3<T>(this->x + target.x, this->y + target.y, this->z + target.z);
	}

	/**
	* '=' Operator overloaded
	*/
	Vector3<T> operator-(Vector3<T> target)
	{
		return Vector3<T>(this->x - target.x, this->y - target.y, this->z - target.z);
	}

	/**
	* '*' Operator overloaded
	*/
	Vector3<T> operator*(Vector3<T> target)
	{
		return Vector3<T>(this->x * target.x, this->y * target.y, this->z * target.z);
	}

	/**
	* '/' Operator overloaded
	*/
	Vector3<T> operator/(Vector3<T> target)
	{
		return Vector3<T>(this->x / target.x, this->y / target.y, this->z / target.z);
	}

	/**
	* '+=' Operator overloaded
	*/
	Vector3<T> operator+=(Vector3<T> target)
	{
		this->x += target.x;
		this->y += target.y;
		this->z += target.z;
		return *this;
	}

	/**
	* '-=' Operator overloaded
	*/
	Vector3<T> operator-=(Vector3<T> target)
	{
		this->x -= target.x;
		this->y -= target.y;
		this->z -= target.z;
		return *this;
	}

	/**
	* '*=' Operator overloaded
	*/
	Vector3<T> operator*=(Vector3<T> target)
	{
		this->x *= target.x;
		this->y *= target.y;
		this->z *= target.z;
		return *this;
	}
	/**
	* '/=' Operator overloaded
	*/
	Vector3<T> operator/=(Vector3<T> target)
	{
		this->x /= target.x;
		this->y /= target.y;
		this->z /= target.z;
		return *this;
	}

	//UTILITY FUNCTIONS

	/**
	* Reverse this vector.
	* 
	* Reverse all values in this vector.
	* 
	* If x was 1, it will now be -1.
	*/
	void reverse() {
		this->x *= -1;
		this->y *= -1;
		this->z *= -1;
	}

	/**
	* Check if two vectors are the same.
	* 
	* Compare the values of both vectors.
	* 
	* @param A vector to compare to this vector.
	* 
	* @return Whether this vector's XYZ values are equal to the other vector's XYZ values.
	*/
	bool equals(Vector3<T> target) const {
		return this->x == target.x && this->x == target.y && this->z == target.z;
	}

	//VECTOR MATH

    /**
	* Magnitude of the vector.
	*
	* @return Magnitude or length of this vector.
	*/
	T magnitude() const
	{
		return (T)sqrt(dot(*this));
	}

	/**
	* Distance between this vector and the vector passed in as an argument.
	* It is recommended to call the 'distance_squared(Vector3)' function if possible, 
	* it is much cheaper to call.
	* 
	* @param The subtrahend which is used calculate the distance.
	* 
	* @return Distance between both vectors.
	*/
	T distance(Vector3<T> target) const
	{
		return (T)sqrt(distance_squared(target));
	}

	/**
	* Squared Distance between this vector and the vector passed in as an argument.
	*
	* @param The subtrahend which is used calculate the distance.
	* 
	* @return Squared distance between both vectors.
	*/
	T distance_squared(Vector3<T> target) const
	{
		T vecX = this->x - target.x;
		T vecY = this->y - target.y;
		T vecZ = this->z - target.z;
		return (T)(vecX * vecX + vecY * vecY + vecZ * vecZ);
	}
	
	/**
	* Normalize the vector.
	*/
	void normalize()
	{
		T mag = magnitude();
		this->x /= mag;
		this->y /= mag;
		this->z /= mag;
	}

	/**
	* Dot product of the vector.
	* 
	* @return The dot product.
	*/
	T dot(Vector3<T> target) const
	{
		return this->x * target.x + this->y * target.y + this->z * target.z;
	}

	/**
	* Angle between two vectors.
	* 
	* @param Second vector needed to calculate the angle.
	* 
	* @return Angle between this vector and the vector passed in as an argument.
	*/
	T angle(Vector3 target) const 
	{
		T value = dot(target) / magnitude() * target.magnitude();
		if (value < -1) value = -1;
		if (value > 1) value = 1;
		return(T)(acos(value));
	}

	/**
	* A nice string representation of this vector.
	* 
	* @return A string representation of the vector values.
	*/
	std::string to_string() {
		return  "X: " + std::to_string(x) + ", Y: " + std::to_string(y) + ", Z: " + std::to_string(z);
	}
};
