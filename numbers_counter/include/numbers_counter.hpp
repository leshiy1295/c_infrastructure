#ifndef NUMBERS_COUNTER_LIB_HPP
#define NUMBERS_COUNTER_LIB_HPP

#include <iostream>
#include <unordered_map>
#include <vector>

namespace NumbersCounter {
    std::vector<int> ReadNumbers(std::istream &is);
    std::unordered_map<int, size_t> CountNumbers(const std::vector<int> &numbers);
    void PrintCounts(const std::unordered_map<int, size_t> &counts, std::ostream &os);
}

#endif // NUMBERS_COUNTER_LIB_HPP
