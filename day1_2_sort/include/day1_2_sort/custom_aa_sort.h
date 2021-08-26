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
    std::make_heap(begin, end, comp);
    std::sort(begin, end, comp);
  }


}   // namespace dte3603::sort::algorithms

#endif   // DTE3603_WEEK1_CUSTOM_AA_SORT_H
