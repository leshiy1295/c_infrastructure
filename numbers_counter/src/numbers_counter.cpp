#include <numbers_counter.hpp>

namespace NumbersCounter {
    std::vector<int> ReadNumbers(std::istream &is) {
        std::size_t size = 0;
        is >> size;
        std::vector<int> numbers;
        numbers.reserve(size);
        for (size_t idx = 0; idx < size; ++idx) {
            int number = 0;
            is >> number;
            numbers.push_back(number);
        }
        return numbers;
    }

    std::unordered_map<int, size_t> CountNumbers(const std::vector<int> &numbers) {
        std::unordered_map<int, size_t> counts;
        for (const auto &number : numbers) {
            ++counts[number];
        }
        return counts;
    }

    void PrintCounts(const std::unordered_map<int, size_t> &counts, std::ostream &os) {
        os << "Counts: " << std::endl;
        for (const auto &[number, count] : counts) {
            os << number << " -> " << count << std::endl;
        }
    }
}
