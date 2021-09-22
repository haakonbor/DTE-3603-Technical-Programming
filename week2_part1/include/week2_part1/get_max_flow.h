#ifndef DTE3603_WEEK2_PART1_H
#define DTE3603_WEEK2_PART1_H

// boost
#include <boost/graph/adjacency_list.hpp>

// concepts
#include <predef_shared/concepts/graphs.h>
#include <predef_shared/concepts/operators.h>

// graph traversal library
#include "breadth_first_search.h"

// stl
#include <vector>
#include <queue>
#include <set>
#include <map>

namespace dte3603::week2::algorithms
{
  template <predef::concepts::graph::DirectionalGraph Graph_T>
  int getMaxFlow([[maybe_unused]] Graph_T const& graph,
                 [[maybe_unused]]
                 typename Graph_T::vertex_descriptor const& source,
                 [[maybe_unused]]
                 typename Graph_T::vertex_descriptor const& sink)
  {
      auto residual_graph = graph;

      typename boost::graph_traits<Graph_T>::edge_iterator edge_it, edge_end;
      std::tie(edge_it, edge_end) = boost::edges(residual_graph);

      int count = 0;

      for (; edge_it != edge_end; edge_it++) {
          auto source_vertex = (*edge_it).m_source;
          auto target_vertex = (*edge_it).m_target;

          std::cout << residual_graph[source_vertex].name << " to " << residual_graph[target_vertex].name << std::endl;

          //boost::add_edge(target_vertex, source_vertex,
          //                {0,0,0,1},
          //                residual_graph);
          if (residual_graph[*edge_it].flow == residual_graph[*edge_it].capacity) {

          }
          count++;
      }

      count = 0;

      std::tie(edge_it, edge_end) = boost::edges(residual_graph);

      for (; edge_it != edge_end; edge_it++) {
          count++;
      }

      return 4;
  }


}   // namespace dte3603::week2::algorithms


#endif   // DTE3603_WEEK2_PART1_H
