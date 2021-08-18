#ifndef DTE3603_WEEK1_COUNTING_SORT_H
#define DTE3603_WEEK1_COUNTING_SORT_H

// stl
#include <iterator>
#include <algorithm>

namespace dte3603::sort::algorithms
{


  template <std::random_access_iterator Iterator_T,
            std::random_access_iterator Sentinel_T,
            typename Compare_T = std::less<> >
  void counting_sort(Iterator_T /*begin*/, Sentinel_T /*end*/,
                     Compare_T /*comp*/ = Compare_T())
  {
  }



}   // namespace dte3603::sort::algorithms

#endif   // DTE3603_WEEK1_COUNTING_SORT_H
