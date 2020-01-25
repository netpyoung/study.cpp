#include "gtest/gtest.h"
#include "helloworld/Simple.hpp"

TEST (SquareRootTest, ZeroAndNegativeNos)
{
    ASSERT_EQ (3, helloworld::Add(1, 2));
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}