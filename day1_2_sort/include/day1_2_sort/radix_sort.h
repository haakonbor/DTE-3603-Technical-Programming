#ifndef DTE3603_WEEK1_RADIX_SORT_H
#define DTE3603_WEEK1_RADIX_SORT_H

// stl
#include <iterator>
#include <algorithm>

namespace dte3603::sort::algorithms
{

  template <std::random_access_iterator Iterator_T,
            std::random_access_iterator Sentinel_T,
            typename Compare_T = std::less<> >
  void radix_sort(Iterator_T begin, Sentinel_T end,
                  Compare_T comp = Compare_T())
  {
      using type = typename std::iterator_traits<Iterator_T>::value_type;
      int n = std::distance(begin, end);
      auto max = *(std::max_element(begin, end, comp));
      queue<type> queues[n];

      for (int i = 1; (max/i) > 0; i*= n) {
          for (auto iter = begin; iter != end; iter++) {

          }
      }
  }

}   // namespace dte3603::sort::algorithms

#endif   // DTE3603_WEEK1_RADIX_SORT_H
