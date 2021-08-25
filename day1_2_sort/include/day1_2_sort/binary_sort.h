#ifndef DTE3603_WEEK1_BINARY_SORT_H
#define DTE3603_WEEK1_BINARY_SORT_H

// stl
#include <iterator>
#include <algorithm>
#include <set>

namespace dte3603::sort::algorithms
{

  template <std::random_access_iterator Iterator_T,
            std::random_access_iterator Sentinel_T,
            typename Compare_T = std::less<> >
  void binary_sort(Iterator_T begin, Sentinel_T end,
                   Compare_T comp = Compare_T())
  {
      using type = typename std::iterator_traits<Iterator_T>::value_type;
      std::multiset<type, Compare_T> set(comp);

      for (auto it = begin; it != end; ++it) {
          set.insert(*it);
      }

      std::copy(set.begin(), set.end(), begin);
  }


}   // namespace dte3603::sort::algorithms

#endif   // DTE3603_WEEK1_BINARY_SORT_H
