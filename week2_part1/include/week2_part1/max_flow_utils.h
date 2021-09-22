#ifndef MAX_FLOW_UTILS_H
#define MAX_FLOW_UTILS_H

// concepts
#include <predef_shared/concepts/graphs.h>

#include <boost/graph/adjacency_list.hpp>

// stl
#include <vector>
#include <queue>
#include <map>

namespace dte3603::week2::algorithms
{
  template <predef::concepts::graph::DirectionalGraph Graph_T>
  std::vector<typename Graph_T::edge_descriptor> bfsUnweightedShortestPath(
    [[maybe_unused]] Graph_T const&                             graph,
    [[maybe_unused]] typename Graph_T::vertex_descriptor const& start,
    [[maybe_unused]] typename Graph_T::vertex_descriptor const& goal)
  {
    using VertexDescriptor = typename Graph_T::vertex_descriptor;
    using EdgeDescriptor   = typename Graph_T::edge_descriptor;

    std::set<VertexDescriptor>                   is_visited;
    std::map<VertexDescriptor, VertexDescriptor> previous;
    std::queue<VertexDescriptor>                 queue;
    std::vector<EdgeDescriptor>                  edge_path;


    queue.push(start);
    is_visited.insert(start);
    previous.insert({start, NULL});

    while (!queue.empty()) {
      VertexDescriptor current_vertex = queue.front();
      queue.pop();

      typename boost::graph_traits<Graph_T>::out_edge_iterator edge_it,
        edge_end;
      boost::tie(edge_it, edge_end) = boost::out_edges(current_vertex, graph);

      for (; edge_it != edge_end; edge_it++) {
        VertexDescriptor adjacent_vertex = boost::target(*edge_it, graph);
        if (!is_visited.contains(adjacent_vertex)) {
          is_visited.insert(adjacent_vertex);
          previous.insert({adjacent_vertex, current_vertex});
          queue.push(adjacent_vertex);

          if (adjacent_vertex == goal) {
            current_vertex = goal;

            while (current_vertex != start) {
              EdgeDescriptor current_edge
                = boost::edge(previous[current_vertex], current_vertex, graph)
                    .first;
              edge_path.push_back(current_edge);
              current_vertex = previous[current_vertex];
            }

            return edge_path;
          }
        }
      }
    }

    return edge_path;
  }

  template <predef::concepts::graph::DirectionalGraph Graph_T>
  std::string addResidualEdges([[maybe_unused]] Graph_T const& graph,
                               [[maybe_unused]] Graph_T&       residual_graph,
                               [[maybe_unused]]
                               typename Graph_T::edge_descriptor const& edge)
  {
    auto        source_vertex   = edge.m_source;
    auto        target_vertex   = edge.m_target;
    std::string edge_type_added = "";

    if (graph[edge].flow == graph[edge].capacity) {
      boost::add_edge(target_vertex, source_vertex, {0, 0, 0, 1},
                      residual_graph);
      edge_type_added = "Backwards";
    }
    else if (graph[edge].flow == 0) {
      boost::add_edge(source_vertex, target_vertex, {0, 0, 0, 1},
                      residual_graph);
      edge_type_added = "Forward";
    }
    else {
      boost::add_edge(target_vertex, source_vertex, {0, 0, 0, 1},
                      residual_graph);
      boost::add_edge(source_vertex, target_vertex, {0, 0, 0, 1},
                      residual_graph);

      edge_type_added = "Both";
    }

    return edge_type_added;
  }

  template <predef::concepts::graph::DirectionalGraph Graph_T>
  Graph_T getResidualGraph([[maybe_unused]] Graph_T const& graph)
  {
    typename boost::graph_traits<Graph_T>::vertex_iterator residual_it,
      residual_end;
    typename boost::graph_traits<Graph_T>::edge_iterator edge_it, edge_end;

    auto residual_graph = graph;

    std::tie(residual_it, residual_end) = boost::vertices(residual_graph);

    for (; residual_it != residual_end; residual_it++) {
      boost::clear_vertex(*residual_it, residual_graph);
    }

    std::tie(edge_it, edge_end) = boost::edges(graph);

    for (; edge_it != edge_end; edge_it++) {
      // Save return value for debug purposes
      std::string residual_edge_type
        = addResidualEdges(graph, residual_graph, *edge_it);
    }

    return residual_graph;
  }

  template <predef::concepts::graph::DirectionalGraph Graph_T>
  double increaseFlow(std::vector<typename Graph_T::edge_descriptor> path,
                      [[maybe_unused]] Graph_T&                      graph)
  {
    double min_residue = std::numeric_limits<double>::max();

    for (auto edge = path.begin() + 1; edge != path.end() - 1; edge++) {
      auto current_edge
        = boost::edge((*edge).m_source, (*edge).m_target, graph).first;
      double current_edge_residue
        = graph[current_edge].capacity - graph[current_edge].flow;
      if (current_edge_residue < min_residue) {
        min_residue = current_edge_residue;
      }
    }

    for (auto& edge : path) {
      auto current_edge
        = boost::edge(edge.m_source, edge.m_target, graph).first;
      graph[current_edge].flow += min_residue;
    }

    return min_residue;
  }




}   // namespace dte3603::week2::algorithms



#endif   // MAX_FLOW_UTILS_H
