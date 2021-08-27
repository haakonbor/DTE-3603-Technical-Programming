#ifndef DTE3603_WEEK1_CUSTOM_AA_SORT_H
#define DTE3603_WEEK1_CUSTOM_AA_SORT_H

// stl
#include <iterator>
#include <algorithm>

namespace dte3603::sort::algorithms
{

  template <std::random_access_iterator Iterator_T,
            std::random_access_iterator Sentinel_T,
            typename Compare_T = std::less<> >
  void custom_aa_sort(Iterator_T begin, Sentinel_T end,
                      Compare_T comp = Compare_T())
  {
      std::make_heap(begin, end, [comp](const auto& arg1, const auto& arg2) {
          return comp(arg2, arg1);
      });

      // Insertion sort
      // reference implementation: https://www.geeksforgeeks.org/insertion-sort-using-c-stl/
      for (auto iter = begin; iter != end; iter++) {
          auto const insert_point = std::upper_bound(begin, iter, *iter, comp);

          std::rotate(insert_point, iter, iter+1);
      }

  }


}   // namespace dte3603::sort::algorithms

#endif   // DTE3603_WEEK1_CUSTOM_AA_SORT_H
