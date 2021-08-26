#ifndef DTE3603_WEEK1_STRING_MATCH_KNUTH_MORRIS_PRATT_SEARCH_H
#define DTE3603_WEEK1_STRING_MATCH_KNUTH_MORRIS_PRATT_SEARCH_H

// stl
#include <iterator>
#include <algorithm>

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
    return {end};
  }

}   // namespace dte3603::string_match::algorithms

#endif   // DTE3603_WEEK1_STRING_MATCH_KNUTH_MORRIS_PRATT_SEARCH_H
