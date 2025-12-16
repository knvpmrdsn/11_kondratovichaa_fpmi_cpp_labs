#include <gtest/gtest.h>

bool all_digits_are_unique(int number);

TEST(DigitsTest, Basic) {
    EXPECT_TRUE(all_digits_are_unique(12345));
    EXPECT_TRUE(all_digits_are_unique(7));
    EXPECT_TRUE(all_digits_are_unique(0));
    EXPECT_TRUE(all_digits_are_unique(102));
    EXPECT_TRUE(all_digits_are_unique(987654321));
    
    EXPECT_FALSE(all_digits_are_unique(112345));
    EXPECT_FALSE(all_digits_are_unique(1223));
    EXPECT_FALSE(all_digits_are_unique(111));
    EXPECT_FALSE(all_digits_are_unique(121));
    EXPECT_FALSE(all_digits_are_unique(100));
}

TEST(DigitsTest, Negative) {
    EXPECT_TRUE(all_digits_are_unique(-12345));
    EXPECT_FALSE(all_digits_are_unique(-112233));
    EXPECT_TRUE(all_digits_are_unique(-7));
    EXPECT_FALSE(all_digits_are_unique(-100));
}

TEST(DigitsTest, EdgeCases) {
    EXPECT_TRUE(all_digits_are_unique(10));
    EXPECT_TRUE(all_digits_are_unique(98));
    EXPECT_FALSE(all_digits_are_unique(99));
    EXPECT_FALSE(all_digits_are_unique(101));
}
