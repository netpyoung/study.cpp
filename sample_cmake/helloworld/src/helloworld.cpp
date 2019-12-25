#pragma warning(push, 0)
#include <iostream>
#pragma warning(pop)

#include "hello.hpp"

using namespace hello;

int main()
{
	SampleLib1* l = new SampleLib1();
	std::string name = l->getFullName();
	std::cout << name << std::endl;
}