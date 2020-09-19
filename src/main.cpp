#include "Vector3.h"
#include <iostream>
int main() {
	Vector3<int> vec1(1, 0, 0);
	Vector3<int> vec2(0, 1, 0);
	Vector3<int> vec3(0, 0, 1);

	Vector3<int> vec = vec1 + vec2 + vec3;

	/**
	* Console Output: X: 1, Y: 1, Z: 1
	*/
	std::cout << vec.to_string() << std::endl;

}