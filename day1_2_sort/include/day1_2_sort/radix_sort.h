#ifndef DTE3603_WEEK1_RADIX_SORT_H
#define DTE3603_WEEK1_RADIX_SORT_H

// stl
#include <iterator>
#include <algorithm>
#include "sorting_utils.h"

namespace dte3603::sort::algorithms
{

  template <std::random_access_iterator Iterator_T,
            std::random_access_iterator Sentinel_T,
            typename Compare_T = std::less<> >
  void radix_sort(Iterator_T begin, Sentinel_T end,
                  Compare_T comp = Compare_T())
  {
      if (begin == end)
          return;
      using type = typename std::iterator_traits<Iterator_T>::value_type;
      type max = *(std::max_element(begin, end, comp));
      int k = n_digits(max);

      for (int i = 0; i < k; i++) {
          std::stable_sort(begin, end, [i](auto& X, auto& Y) {
              return get_element(X, i) < get_element(Y, i);
          });
      }
  }

}   // namespace dte3603::sort::algorithms

#endif   // DTE3603_WEEK1_RADIX_SORT_H
