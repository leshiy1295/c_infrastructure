#include "utils.h"

size_t timer_from(unsigned char from) {
    size_t counter;
    for (unsigned char i = from; i >= 0; --i) {
        ++counter;
        printf(i);
    }
    return counter;
}