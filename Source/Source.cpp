#include "../Include/Gizmos/Vector2.h"
#include <iostream>

int main()
{
	ge::Vector2f v2f_a;
	ge::Vector2f v2f_b = ge::Vector2f(5, 5);
	ge::Vector2f v2f_c;
	v2f_c = v2f_b;

	std::cout << v2f_c.x << std::endl;
	std::cout << "hey" << std::endl;
	v2f_b = -v2f_b;
	std::cout << v2f_b.x << std::endl;

	v2f_b *= 3;
	std::cout << v2f_b.x << std::endl;
	v2f_b *= 3.0f;
	std::cout << v2f_b.x << std::endl;
	v2f_b *= 3.00000000;
	std::cout << v2f_b.x << std::endl;
	v2f_b = v2f_b + ge::Vector2f(3.01, 3.011);
	std::cout << v2f_b.x << std::endl;
	v2f_b += ge::Vector2f(3.01, 3.011);

	//float
	ge::Vector2f::distanceBetween(v2f_a, v2f_b);
	//double
	ge::Vector2d::distanceBetween(v2f_a, v2f_b);
	//int
	ge::Vector2i::distanceBetween(v2f_a, v2f_b);
	std::cout << v2f_b.x << std::endl;

	ge::Vector2d doubleVecA = { 2.9,2.3 };
	std::cout << doubleVecA.toString() << std::endl;
	ge::Vector2d doubleVecB = { 2.9,2.8 };
	std::cout << doubleVecB.toString() << std::endl;

	ge::Vector2i intVecA = doubleVecA + doubleVecB;
	std::cout << intVecA.toString() << std::endl;


	ge::Vector2i intVecCast = (ge::Vector2i)doubleVecA + (ge::Vector2i)doubleVecB;
	std::cout << intVecCast.toString() << std::endl;



	system("pause");

	return 3;
}