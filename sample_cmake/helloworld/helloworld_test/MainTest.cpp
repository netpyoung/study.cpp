#include "gtest/gtest.h"
#include "Main.hpp"

TEST (SquareRootTest, ZeroAndNegativeNos)
{
    ASSERT_EQ (3, Add(1, 2));
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}