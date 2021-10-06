#ifndef DTE3603_DAY5_ASTAR_SEARCH_H
#define DTE3603_DAY5_ASTAR_SEARCH_H

#include "operators.h"

// concepts
#include <predef_shared/concepts/graphs.h>
#include <predef_shared/concepts/operators.h>

// stl
#include <vector>

namespace dte3603::graph::algorithms
{

  template <
    predef::concepts::graph::BidirectionalGraph                     Graph_T,
    predef::concepts::graph::ShortestPathHeuristicOperator<Graph_T> HOp_T,
    predef::concepts::graph::EdgeDistanceOperator<Graph_T>          EdOp_T
    = operators::DefaultEdgeDistanceOperator<>>
  std::vector<std::vector<typename Graph_T::vertex_descriptor>>
  aStarSearch([[maybe_unused]] Graph_T const&                             graph,
              [[maybe_unused]] typename Graph_T::vertex_descriptor const& start,
              [[maybe_unused]] typename Graph_T::vertex_descriptor const& goal,
              [[maybe_unused]] HOp_T                                      h_op,
              [[maybe_unused]] EdOp_T distance_op = EdOp_T())
  {
    return {};
  }


}   // namespace dte3603::graph::algorithms


#endif   // DTE3603_DAY5_ASTAR_SEARCH_H
