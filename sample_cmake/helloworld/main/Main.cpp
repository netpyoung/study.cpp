#pragma warning(push, 0)
#include <iostream>
#pragma warning(pop)

#include "hello.hpp"
#include "helloworld/Simple.hpp"

using namespace hello;

int main()
{
	std::cout << helloworld::Add(1, 2) << std::endl;

	SampleLib1* l = new SampleLib1();
	std::string name = l->getFullName();
	std::cout << name << std::endl;
}