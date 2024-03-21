#pragma once
#include "gtest/gtest.h"
#include "helloworld/HelloWorld.hpp"

TEST(HelloworldTest, ZeroAndNegativeNos)
{
	ASSERT_EQ(3, helloworld::Add(1, 2));
}
