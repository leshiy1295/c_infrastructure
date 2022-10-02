#include <iostream>

#include <numbers_counter.hpp>

int main() {
    auto numbers = NumbersCounter::ReadNumbers(std::cin);
    auto counts = NumbersCounter::CountNumbers(numbers);
    NumbersCounter::PrintCounts(counts, std::cout);
    return 0;
}
