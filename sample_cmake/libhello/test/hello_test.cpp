#include "gtest/gtest.h"
#include "hello.hpp"

double square_root (double num)
{
	if (num < 0.0) {
		std::cerr << "Error: Negative Input\n";
		exit(255);
	}
    return 0;
}

TEST (SquareRootTest, ZeroAndNegativeNos)
{
	hello::SampleLib1* a = new hello::SampleLib1();
	a->getFullName();
    ASSERT_EQ (0.1, square_root(0.0));
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}