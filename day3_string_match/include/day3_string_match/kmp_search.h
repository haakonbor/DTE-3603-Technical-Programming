#ifndef DTE3603_WEEK1_STRING_MATCH_KNUTH_MORRIS_PRATT_SEARCH_H
#define DTE3603_WEEK1_STRING_MATCH_KNUTH_MORRIS_PRATT_SEARCH_H

// stl
#include <algorithm>
#include <span>
#include "string_match_utils.h"

namespace dte3603::string_match::algorithms
{

  template <std::forward_iterator Iterator_T, std::forward_iterator Sentinel_T,
            std::forward_iterator S_Iterator_T,
            std::forward_iterator S_Sentinel_T,
            typename BinaryPredicate_T = std::equal_to<>>
  Iterator_T kmp_search(Iterator_T begin, Sentinel_T end, S_Iterator_T s_begin,
                        S_Sentinel_T      s_end,
                        BinaryPredicate_T pred = BinaryPredicate_T())
  {
      auto const pattern = std::span(s_begin, s_end);
      size_t pattern_size = pattern.size();
      auto const table = get_table(pattern);

      for (auto text_it = begin; text_it != end; text_it++) {
          size_t current_match_len = 0;
          auto current_it = text_it;

          for (int i = 0; i < pattern_size; i++) {
              if (pred(*current_it, pattern[i])) {
                  current_match_len++;
                  current_it++;
              }
              else {
                  if (i != 0) {
                      i = table[i-1];

                      //if (i == 0) {
                      //    break;
                      //}

                      i--;

                  }
                  else {
                      break;
                  }
              }
          }

          if (current_match_len == pattern_size) {
              std::cout << *text_it << *(text_it + 1) << *(text_it + 2) << *(text_it + 3) << *(text_it + 4) << *(text_it + 5) << *(text_it + 6) << *(text_it + 7) << std::endl;
              return text_it;
          }
      }

      return end;



      /*
      auto       string_span  = std::span(begin, end);
      auto       pattern_span = std::span(s_begin, s_end);
      auto const string_size  = string_span.size();
      auto const pattern_size = pattern_span.size();

      auto lookup_table = get_table(pattern_span);

      if (string_size >= pattern_size) {
        for (auto i = 0; i < string_size; i++) {
          auto count       = 0;
          auto current_pos = i;
          for (auto j = 0; j < pattern_size; j++) {
            if (!pred(string_span[current_pos], pattern_span[j])) {
              if (j != 0) {
                j = lookup_table[j - 1];
                break;
              }
              break;
            }
            count++;
            current_pos++;
          }
          if (count == pattern_size) {
            return begin + i;
          }
        }
      }
      return end;
      */
  }

}   // namespace dte3603::string_match::algorithms

#endif   // DTE3603_WEEK1_STRING_MATCH_KNUTH_MORRIS_PRATT_SEARCH_H
