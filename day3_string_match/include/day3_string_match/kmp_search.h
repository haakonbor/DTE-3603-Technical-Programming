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
      /*
      size_t match_len = std::distance(s_begin, s_end);
      std::string pattern = static_cast<std::string>(std::span(s_begin, s_end));

      size_t table [match_len] = get_table(pattern);
      auto preprocess_curr_it = s_begin;
      auto preprocess_check_it = s_begin;

      preprocess_curr_it++;
      table[0] = 0;
      int i = 0;
      int j = 1;

      while (preprocess_curr_it != s_end) {
          if (!pred(*preprocess_curr_it, *preprocess_check_it)) {
              table[j] = i;
              j++;
              i = 0;
          }
          else {
              i++;
          }
      }

      for (auto text_it = begin; text_it != end; text_it++) {
          size_t current_match_len = 0;
          auto current_it = text_it;

          for (auto pattern_it = s_begin; pattern_it != s_end; pattern_it++) {
              if (pred(*pattern_it, *current_it)) {
                  current_it++;
                  current_match_len++;
              }
              else {
                  break;
              }
          }

          if (current_match_len == match_len) {
              return text_it;
          }
      }


      */
      return end;
  }

}   // namespace dte3603::string_match::algorithms

#endif   // DTE3603_WEEK1_STRING_MATCH_KNUTH_MORRIS_PRATT_SEARCH_H
