#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(TestCastTest, Test01)
{
    ASSERT_TRUE(true);
}

int main(int argc, char **argv)
{
   ::testing::GTEST_FLAG(print_time) = true;

	testing::InitGoogleMock(&argc, argv);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
