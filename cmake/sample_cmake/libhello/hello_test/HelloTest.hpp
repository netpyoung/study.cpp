#include "gtest/gtest.h"
#include "hello.hpp"

using namespace hello;

TEST(HelloTest, ZeroAndNegativeNos)
{
	Hello hello;
	ASSERT_EQ(3, hello.Add(1, 2));
}
