#include "gtest/gtest.h"
#include "world/World.hpp"

using namespace world;

TEST (WorldTest, ZeroAndNegativeNos)
{
	World world;
	world.A = 1;
    ASSERT_EQ (1, world.A);
}