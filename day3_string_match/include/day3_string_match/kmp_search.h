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
      int i = 0;

      for (auto text_it = begin; text_it != end; text_it++) {
          auto current_it = text_it;

          for (i = 0; i < pattern_size;) {
              if (pred(*current_it, pattern[i])) {
                  current_it++;
                  i++;
              }
              else {
                  if (i != 0) {
                      i = table[i-1];
                  }
                  else {
                      break;
                  }
              }
          }

          if (i == pattern_size) {
              return text_it;
          }
      }

      return end;
  }

}   // namespace dte3603::string_match::algorithms

#endif   // DTE3603_WEEK1_STRING_MATCH_KNUTH_MORRIS_PRATT_SEARCH_H
