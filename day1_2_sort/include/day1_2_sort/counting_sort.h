#ifndef DTE3603_WEEK1_COUNTING_SORT_H
#define DTE3603_WEEK1_COUNTING_SORT_H

// stl
#include <iterator>
#include <algorithm>
#include <vector>
#include <map>

namespace dte3603::sort::algorithms
{
  template <std::random_access_iterator Iterator_T,
            std::random_access_iterator Sentinel_T,
            typename Compare_T = std::less<> >
  void counting_sort(Iterator_T begin, Sentinel_T end,
                     Compare_T comp = Compare_T())
  {
      using type = typename std::iterator_traits<Iterator_T>::value_type;
      std::map<type, size_t, Compare_T> map(comp);

      for (auto it = begin; it != end; ++it) {
          if (map.contains(*it)) {
              map[*it]++;
          }
          else {
              map[*it] = 1;
          }
      }

      for(auto const& [key, val]: map) {
          for (auto i = 0ul; i < val; i++)
              *begin++ = key;
      }
  }

}   // namespace dte3603::sort::algorithms

#endif   // DTE3603_WEEK1_COUNTING_SORT_H
