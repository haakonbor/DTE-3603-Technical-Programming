#ifndef DTE3603_DAY4_DEPTH_FIRST_SEARCH_H
#define DTE3603_DAY4_DEPTH_FIRST_SEARCH_H

// concepts
#include <predef_shared/concepts/graphs.h>

// stl
#include <vector>
#include <stack>

namespace dte3603::graph::algorithms
{

  template <predef::concepts::graph::BidirectionalGraph Graph_T>
  std::vector<typename Graph_T::vertex_descriptor>
  depthFirstSearch([[maybe_unused]] Graph_T const& graph,
                   [[maybe_unused]]
                   typename Graph_T::vertex_descriptor const& start)
  {
      using VertexDescriptor = typename Graph_T::vertex_descriptor;
      using EdgeDescriptor = typename Graph_T::edge_descriptor;

      std::stack<VertexDescriptor> stack;
      std::vector<VertexDescriptor> result;
      std::set<VertexDescriptor> is_visited;

      stack.push(start);
      is_visited.insert(start);

      // While there are vertices in the stack
      while (!stack.empty()) {
          // Put the current vertex in the result, and mark it as visited
          VertexDescriptor current_vertex_desc = stack.top();
          stack.pop();

          if (!is_visited.contains(current_vertex_desc)) {
              result.push_back(current_vertex_desc);
              is_visited.insert(current_vertex_desc);
          }

          typename boost::graph_traits<Graph_T>::out_edge_iterator edge_it, edge_end;

          // Put every vertex from the out edges in the stack
          for (boost::tie(edge_it, edge_end) = boost::out_edges(current_vertex_desc, graph); edge_it != edge_end; edge_it++) {
              VertexDescriptor target_vertex = boost::target(*edge_it, graph);
              stack.push(target_vertex);
          }
      }

      return result;
  }


}   // namespace dte3603::graph::algorithms


#endif   // DTE3603_DAY4_DEPTH_FIRST_SEARCH_H
