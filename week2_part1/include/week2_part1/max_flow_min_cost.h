#ifndef MAX_FLOW_MIN_COST_H
#define MAX_FLOW_MIN_COST_H

#include "get_max_flow.h"
#include "max_flow_utils.h"
#include "min_cost_utils.h"

namespace dte3603::week2::algorithms
{
  template <predef::concepts::graph::DirectionalGraph Graph_T>
  std::pair<double, double> getMinCostMaxFlow(
    [[maybe_unused]] Graph_T&                                   graph,
    [[maybe_unused]] typename Graph_T::vertex_descriptor const& source,
    [[maybe_unused]] typename Graph_T::vertex_descriptor const& sink)
  {
    double max_flow  = getMaxFlow(graph, source, sink);
    auto   res_graph = getResidualGraph(graph);

    while (getCyclesFromGraph(res_graph, source).size() != 0) {
      // reduce cost (flow) along cycle with smallest average cost along cycle
      // update residual cost graph
      // repeat
      break;
    }

    std::pair<double, double> result;

    result.first  = 0;
    result.second = max_flow;

    return result;
  }
}   // namespace dte3603::week2::algorithms



#endif   // MAX_FLOW_MIN_COST_H
