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
  getCyclesFromGraph([[maybe_unused]] Graph_T const& res_graph,
                     [[maybe_unused]]
                     typename Graph_T::vertex_descriptor const& start)
  {
    using VertexDescriptor = typename Graph_T::vertex_descriptor;
    using EdgeDescriptor   = typename Graph_T::edge_descriptor;

    std::unordered_map<VertexDescriptor, VertexDescriptor> previous;
    std::unordered_map<VertexDescriptor, int>              distance;
    std::unordered_map<VertexDescriptor, bool>             visited;
    int                                                    num_vertices = 0;

    typename boost::graph_traits<Graph_T>::vertex_iterator vertex_it,
      vertex_end;
    boost::tie(vertex_it, vertex_end) = boost::vertices(res_graph);

    for (; vertex_it != vertex_end; vertex_it++) {
      num_vertices++;
      previous.insert({*vertex_it, NULL});
      distance.insert({*vertex_it, 1000});
      visited.insert({*vertex_it, false});
    }

    distance[start] = 0;
    typename boost::graph_traits<Graph_T>::edge_iterator edge_it, edge_end;
    for (int i = 1; i < num_vertices - 1; i++) {
      boost::tie(edge_it, edge_end) = boost::edges(res_graph);
      for (; edge_it != edge_end; edge_it++) {
        VertexDescriptor source_vertex = boost::source(*edge_it, res_graph);
        VertexDescriptor target_vertex = boost::target(*edge_it, res_graph);
        EdgeDescriptor   edge          = *edge_it;

        if (distance[source_vertex] + res_graph[edge].cost
            < distance[target_vertex]) {
          distance[target_vertex]
            = distance[source_vertex] + res_graph[edge].cost;
          previous[target_vertex] = source_vertex;
        }
      }
    }

    boost::tie(edge_it, edge_end) = boost::edges(res_graph);
    std::vector<std::vector<VertexDescriptor>> cycles;
    for (; edge_it != edge_end; edge_it++) {
      VertexDescriptor source_vertex = boost::source(*edge_it, res_graph);
      VertexDescriptor target_vertex = boost::target(*edge_it, res_graph);

      int source_distance = distance[source_vertex];
      int edge_cost       = res_graph[(*edge_it)].cost;
      int target_distance = distance[target_vertex];

      if (source_distance + edge_cost < target_distance
          && previous[source_vertex] != target_vertex) {

        VertexDescriptor old_previous = previous[target_vertex];
        previous[target_vertex]       = source_vertex;
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

        previous[target_vertex] = old_previous;
      }
    }

    return cycles;
  }

  template <predef::concepts::graph::DirectionalGraph Graph_T>
  int getIndexOfCycleWithSmallestAVGCost(
    [[maybe_unused]] Graph_T const& res_graph,
    [[maybe_unused]] std::vector<
      std::vector<typename Graph_T::vertex_descriptor>>
      cycles)
  {
    double smallest_avg = 0;
    int    cycle_index  = 0;

    for (int i = 0; i < cycles.size(); i++) {
      auto cycle          = cycles[i];
      int  cycle_cost_sum = 0;
      for (int j = 0; j < cycle.size() - 1; j++) {
        auto current_edge = boost::edge(cycle[j], cycle[j + 1], res_graph);
        cycle_cost_sum += res_graph[current_edge.first].cost;
      }

      auto current_edge
        = boost::edge(cycle[cycle.size() - 1], cycle[0], res_graph);
      cycle_cost_sum += res_graph[current_edge.first].cost;

      if (cycle_cost_sum / cycle.size() < smallest_avg) {
        smallest_avg = static_cast<double>(cycle_cost_sum) / cycle.size();
        cycle_index  = i;
      }
    }

    return cycle_index;
  }

  template <predef::concepts::graph::DirectionalGraph Graph_T>
  void updateCycleFlow(
    [[maybe_unused]] Graph_T&                                         graph,
    [[maybe_unused]] std::vector<typename Graph_T::vertex_descriptor> cycle)
  {
    using EdgeDescriptor = typename Graph_T::edge_descriptor;
    std::vector<std::pair<EdgeDescriptor, bool>> edges;
    int min_residual = std::numeric_limits<int>::max();
    for (int i = 0; i < cycle.size() - 1; i++) {
      bool                            add_flow = true;
      std::pair<EdgeDescriptor, bool> edge_flow_sign_pair;
      auto current_edge = boost::edge(cycle[i], cycle[i + 1], graph);
      if (!current_edge.second) {
        current_edge = boost::edge(cycle[i + 1], cycle[i], graph);
        add_flow     = false;
      }
      edge_flow_sign_pair.first  = current_edge.first;
      edge_flow_sign_pair.second = add_flow;

      int current_edge_residual = 0;
      if (add_flow) {
        current_edge_residual
          = graph[current_edge.first].capacity - graph[current_edge.first].flow;
      }
      else {
        current_edge_residual = graph[current_edge.first].flow;
      }

      if (current_edge_residual < min_residual) {
        min_residual = current_edge_residual;
      }

      edges.push_back(edge_flow_sign_pair);
    }

    std::pair<EdgeDescriptor, bool> edge_flow_sign_pair;

    bool add_flow     = true;
    auto current_edge = boost::edge(cycle[cycle.size() - 1], cycle[0], graph);
    if (!current_edge.second) {
      current_edge = boost::edge(cycle[0], cycle[cycle.size() - 1], graph);
      add_flow     = false;
    }

    edge_flow_sign_pair.first  = current_edge.first;
    edge_flow_sign_pair.second = add_flow;

    int current_edge_residual = 0;
    if (add_flow) {
      current_edge_residual
        = graph[current_edge.first].capacity - graph[current_edge.first].flow;
    }
    else {
      current_edge_residual = graph[current_edge.first].flow;
    }

    if (current_edge_residual < min_residual) {
      min_residual = current_edge_residual;
    }

    edges.push_back(edge_flow_sign_pair);

    for (auto pair : edges) {
      if (pair.second) {
        graph[pair.first].flow += min_residual;
      }
      else {
        graph[pair.first].flow -= min_residual;
      }
    }
  }

  template <predef::concepts::graph::DirectionalGraph Graph_T>
  int getTotalFlowCost([[maybe_unused]] Graph_T& graph)
  {
    typename boost::graph_traits<Graph_T>::edge_iterator edge_it, edge_end;
    boost::tie(edge_it, edge_end) = boost::edges(graph);

    int current_cost = 0;

    for (; edge_it != edge_end; edge_it++) {
      current_cost += graph[*edge_it].flow * graph[*edge_it].cost;
    }

    return current_cost;
  }
}   // namespace dte3603::week2::algorithms


#endif   // MIN_COST_UTILS_H
