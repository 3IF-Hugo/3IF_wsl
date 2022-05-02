#include <gtest/gtest.h>

TEST(ExampleTests, Test1) {
    EXPECT_EQ(1, 2);
    EXPECT_EQ(1, 2);
    //ASSERT_TRUE(false);
    EXPECT_EQ(1, 2) << "This is a message";
}