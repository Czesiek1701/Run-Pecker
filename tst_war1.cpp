
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

using namespace testing;

TEST(test1, war1)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}
