#ifndef DTE3603_DAY5_OPERATORS_H
#define DTE3603_DAY5_OPERATORS_H

namespace dte3603::graph::operators
{

  template <typename = void>
  struct DefaultEdgeDistanceOperator {

    template <typename Graph_T>
    double operator()([[maybe_unused]]
                      typename Graph_T::edge_descriptor const& e,
                      [[maybe_unused]] Graph_T const&          graph)
    {
      return graph[e].distance;
    }
  };

}   // namespace dte3603::graph::operators

#endif   // DTE3603_DAY5_OPERATORS_H
