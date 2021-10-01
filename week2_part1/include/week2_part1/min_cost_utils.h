#ifndef MIN_COST_UTILS_H
#define MIN_COST_UTILS_H

// concepts
#include <predef_shared/concepts/graphs.h>

#include <boost/graph/adjacency_list.hpp>

#include <vector>
#include <limits>
#include <unordered_map>
#include <unordered_set>

namespace dte3603::week2::algorithms
{

  template <predef::concepts::graph::DirectionalGraph Graph_T>
  std::vector<std::vector<typename Graph_T::vertex_descriptor>>
  getCyclesFromGraph([[maybe_unused]] Graph_T const& graph,
                     [[maybe_unused]]
                     typename Graph_T::vertex_descriptor const& start)
  {
    using VertexDescriptor = typename Graph_T::vertex_descriptor;
    using EdgeDescriptor   = typename Graph_T::edge_descriptor;

    std::unordered_map<VertexDescriptor, VertexDescriptor> previous;
    std::unordered_map<VertexDescriptor, double>           distance;
    std::unordered_map<VertexDescriptor, bool>             visited;
    int                                                    num_vertices = 0;

    typename boost::graph_traits<Graph_T>::vertex_iterator vertex_it,
      vertex_end;
    boost::tie(vertex_it, vertex_end) = boost::vertices(graph);

    for (; vertex_it != vertex_end; vertex_it++) {
      num_vertices++;
      previous.insert({*vertex_it, NULL});
      distance.insert({*vertex_it, 1000});
      visited.insert({*vertex_it, false});
    }

    distance[start] = 0;
    typename boost::graph_traits<Graph_T>::edge_iterator edge_it, edge_end;
    for (int i = 1; i < num_vertices - 1; i++) {
      boost::tie(edge_it, edge_end) = boost::edges(graph);
      for (; edge_it != edge_end; edge_it++) {
        VertexDescriptor source_vertex = boost::source(*edge_it, graph);
        VertexDescriptor target_vertex = boost::target(*edge_it, graph);
        EdgeDescriptor   edge          = *edge_it;

        if (distance[source_vertex] + graph[edge].cost
            < distance[target_vertex]) {
          distance[target_vertex] = distance[source_vertex] + graph[edge].cost;
          previous[target_vertex] = source_vertex;
        }
      }
    }

    boost::tie(edge_it, edge_end) = boost::edges(graph);
    std::vector<std::vector<VertexDescriptor>> cycles;
    for (; edge_it != edge_end; edge_it++) {
      VertexDescriptor source_vertex = boost::source(*edge_it, graph);
      VertexDescriptor target_vertex = boost::target(*edge_it, graph);

      double source_distance = distance[source_vertex];
      double edge_cost       = graph[(*edge_it)].cost;
      double target_distance = distance[target_vertex];

      if (source_distance + edge_cost < target_distance
          && previous[source_vertex] != target_vertex) {

        previous[target_vertex] = source_vertex;
        std::vector<VertexDescriptor>        current_cycle;
        std::unordered_set<VertexDescriptor> in_cycle;
        VertexDescriptor                     current_vertex = source_vertex;
        while (1) {
          current_vertex = previous[current_vertex];
          if (!in_cycle.contains(current_vertex)) {
            current_cycle.push_back(current_vertex);
            in_cycle.insert(current_vertex);
          }
          else {
            break;
          }
        }

        if (current_cycle.size() > 2) {
          bool permutation = true;
          for (auto v : current_cycle) {
            if (!visited[v]) {
              permutation = false;
            }
          }
          if (!permutation) {
            std::reverse(current_cycle.begin(), current_cycle.end());
            cycles.push_back(current_cycle);

            for (auto v : current_cycle) {
              visited[v] = true;
            }
          }
        }
      }
    }

    return cycles;
  }
}   // namespace dte3603::week2::algorithms


#endif   // MIN_COST_UTILS_H
