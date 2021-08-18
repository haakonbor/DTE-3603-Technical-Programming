#ifndef DTE3603_DAY4_DEPTH_FIRST_SEARCH_H
#define DTE3603_DAY4_DEPTH_FIRST_SEARCH_H

// concepts
#include <predef_shared/concepts/graphs.h>

// stl
#include <vector>

namespace dte3603::graph::algorithms
{

  template <predef::concepts::graph::BidirectionalGraph Graph_T>
  std::vector<typename Graph_T::vertex_descriptor>
  depthFirstSearch([[maybe_unused]] Graph_T const& graph,
                   [[maybe_unused]]
                   typename Graph_T::vertex_descriptor const& start)
  {
    return {};
  }


}   // namespace dte3603::graph::algorithms


#endif   // DTE3603_DAY4_DEPTH_FIRST_SEARCH_H
