#ifndef STRING_MATCH_UTILS_H
#define STRING_MATCH_UTILS_H

#include <iterator>
#include <vector>

namespace dte3603::string_match::algorithms {
    template <std::random_access_iterator Iterator_T,
              std::random_access_iterator Sentinel_T >
    Iterator_T get_table(std::string pattern) {

        std::vector<int> T(pattern.begin(), pattern.end());
        std::fill(T.begin(), T.end(), 0);


         for (int i = 1, j = 0; i < T.size(); ++i) {
                if (pattern[i] == pattern[j]) {
                    T[i] = ++j;
                }
                else {
                    if (j != 0) {
                        j = T[j - 1];
                        i--;
                    }
                }
          }


        /*
        std::vector<int> table(begin, end);

        table[0] = 0;

        for (int i = 1; i < std::distance(begin, end) - 1; i++) {
            if (table[i-1] > 0) {
                if (pattern.substr(i - table[i-1], i) == pattern.substr(0, table[i-1])) {
                    table[i] = table[i-1] + 1;
                }
                else if (pattern.substr(i - (table[i-1] - 1), i) == pattern.substr(0, table[i-1] - 1)) {
                    table[i] = table[i-1];
                }
                else {
                    table[i] = 0;
                }
            }
        }
        */

    }

}

#endif // STRING_MATCH_UTILS_H
