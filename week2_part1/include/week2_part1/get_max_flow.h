#ifndef DTE3603_WEEK2_PART1_H
#define DTE3603_WEEK2_PART1_H

// boost
#include <boost/graph/adjacency_list.hpp>

// concepts
#include <predef_shared/concepts/graphs.h>
#include <predef_shared/concepts/operators.h>

// graph traversal library
#include "breadth_first_search.h"
#include "max_flow_utils.h"

// stl
#include <vector>
#include <queue>
#include <set>
#include <map>

namespace dte3603::week2::algorithms
{
  template <predef::concepts::graph::DirectionalGraph Graph_T>
  double
  getMaxFlow([[maybe_unused]] Graph_T const&                             g,
             [[maybe_unused]] typename Graph_T::vertex_descriptor const& source,
             [[maybe_unused]] typename Graph_T::vertex_descriptor const& sink)
  {
    using VertexDescriptor            = typename Graph_T::vertex_descriptor;
    using EdgeDescriptor              = typename Graph_T::edge_descriptor;
    auto                        graph = g;
    auto                        residual_graph = getResidualGraph(graph);
    std::vector<EdgeDescriptor> shortest_path
      = bfsUnweightedShortestPath(residual_graph, source, sink);
    double flow_increase = 0.;

    while (shortest_path.size() != 0) {
      flow_increase += increaseFlow(shortest_path, graph);
      residual_graph = getResidualGraph(graph);
      shortest_path  = bfsUnweightedShortestPath(residual_graph, source, sink);
    }

    // find flow of max flow graph

    return flow_increase;
  }


}   // namespace dte3603::week2::algorithms


#endif   // DTE3603_WEEK2_PART1_H
