#include<iostream>
#include "head.h"

int main()
{
	Point A(1, 1);
	Point B(4, 5);
	std::cout << A.distance(B) << std::endl;
	return 0;

}