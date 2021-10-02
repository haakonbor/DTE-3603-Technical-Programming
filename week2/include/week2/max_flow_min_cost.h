#ifndef MAX_FLOW_MIN_COST_H
#define MAX_FLOW_MIN_COST_H

#include "get_max_flow.h"
#include "max_flow_utils.h"
#include "min_cost_utils.h"

namespace dte3603::week2::algorithms
{
  template <predef::concepts::graph::DirectionalGraph Graph_T>
  std::pair<int, int> getMinCostMaxFlow(
    [[maybe_unused]] Graph_T&                                   graph,
    [[maybe_unused]] typename Graph_T::vertex_descriptor const& source,
    [[maybe_unused]] typename Graph_T::vertex_descriptor const& sink)
  {
    int  max_flow  = getMaxFlow(graph, source, sink);
    auto res_graph = getResidualGraph(graph);

    auto cycles = getCyclesFromGraph(res_graph, source);

    while (cycles.size() != 0) {
      // find cycle with smallest average cost along its path
      int index = getIndexOfCycleWithSmallestAVGCost(res_graph, cycles);
      // increase flow along negative cost cycle, and update residual graph
      updateCycleCost(res_graph, cycles[index]);
      // repeat
    }

    std::pair<int, int> result;

    result.first  = 0;
    result.second = max_flow;

    return result;
  }
}   // namespace dte3603::week2::algorithms



#endif   // MAX_FLOW_MIN_COST_H
