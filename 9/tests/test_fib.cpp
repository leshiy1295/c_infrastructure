#include <gtest/gtest.h>

extern "C" {
    #include "fib.h"
}

TEST(Fib, TestBasics) {
    EXPECT_EQ(1, fib(1));
    EXPECT_EQ(1, fib(2));
}

TEST(Fib, Test10) {
    EXPECT_EQ(55, fib(10));
}
