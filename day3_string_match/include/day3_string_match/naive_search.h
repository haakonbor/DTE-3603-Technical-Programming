#ifndef DTE3603_WEEK1_STRING_MATCH_NAIVE_SEARCH_H
#define DTE3603_WEEK1_STRING_MATCH_NAIVE_SEARCH_H

// stl
#include <iterator>
#include <algorithm>

namespace dte3603::string_match::algorithms
{

  template <std::forward_iterator Iterator_T, std::forward_iterator Sentinel_T,
            std::forward_iterator S_Iterator_T,
            std::forward_iterator S_Sentinel_T,
            typename BinaryPredicate_T = std::equal_to<>>
  Iterator_T naive_search(Iterator_T begin, Sentinel_T end,
                          S_Iterator_T s_begin, S_Sentinel_T s_end,
                          BinaryPredicate_T pred = BinaryPredicate_T())
  {   
      size_t match_len = std::distance(s_begin, s_end);

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

      return end;
  }

}   // namespace dte3603::string_match::algorithms

#endif   // DTE3603_WEEK1_STRING_MATCH_NAIVE_SEARCH_H
