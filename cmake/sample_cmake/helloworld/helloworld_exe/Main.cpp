#pragma warning(push, 0)
#include <iostream>
#pragma warning(pop)

#include "helloworld/Helloworld.hpp"

using namespace hello;
using namespace world;
using namespace helloworld;

int main()
{
	std::cout << helloworld::Add(1, 2) << std::endl;
}