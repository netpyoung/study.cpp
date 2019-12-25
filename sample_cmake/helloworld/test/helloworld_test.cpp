#include "gtest/gtest.h"

double square_root (double num)
{
	if (num < 0.0)
	{
		std::cerr << "Error: Negative Input\n";
		exit(255);
	}
    return 0;
}

TEST (SquareRootTest, ZeroAndNegativeNos)
{
    ASSERT_EQ (0.0, square_root(0.0));
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}