#ifndef STRING_MATCH_UTILS_H
#define STRING_MATCH_UTILS_H

#include <iterator>
#include <vector>
#include <span>

namespace dte3603::string_match::algorithms {
    //template <std::forward_iterator Iterator_T,
    //          std::forward_iterator Sentinel_T>
    std::vector<int> get_table(auto pattern) {
        std::vector<int> T;
        T.assign(pattern.size(), 0);

        // Code based on Joachims implementation
        for (int i = 1, j = 0; i < T.size(); i++) {
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

        return T;
    }

}

#endif // STRING_MATCH_UTILS_H
