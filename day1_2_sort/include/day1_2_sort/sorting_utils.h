#ifndef SORTING_UTILS_H
#define SORTING_UTILS_H

#include <string>

namespace dte3603::sort::algorithms
{
    char get_element(std::string s, int i) {
        return s.at(s.length() - 1 - i);
    }

    int get_element(int n, int i) {
        for (int k = 1, j = 0; (n / k) > 0; k *= 10, j++) {
            if (j == i) {
                return (n/k) % 10;
            }
        }

        return 0;
    }

    size_t n_digits(int n) {
        int digits = 0;
        while (n != 0 ) {
            n /= 10;
            digits++;
        }
        return digits;
    }

    size_t n_digits(std::string s) {
        return s.length();
    }

} // namespace dte3603::sort::algorithms


#endif // SORTING_UTILS_H
