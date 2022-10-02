#include <gtest/gtest.h>

#include <sstream>

#include <numbers_counter.hpp>

TEST(NumbersCounter, BaseTest) {
    std::stringstream ss = []{
        std::stringstream ss;
        ss << "5" << std::endl;
        ss << "1 2 3 2 1" << std::endl;
        return ss;
    }();
    auto data = NumbersCounter::ReadNumbers(ss);
    auto expected_data = std::vector<int>{1, 2, 3, 2, 1};
    EXPECT_EQ(data, expected_data);
}
