#ifndef DTE3603_DAY5_DIJKSTRA_SHORTEST_PATHS_H
#define DTE3603_DAY5_DIJKSTRA_SHORTEST_PATHS_H

#include "operators.h"

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

namespace dte3603::graph::algorithms
{

  template <predef::concepts::graph::BidirectionalGraph            Graph_T,
            predef::concepts::graph::EdgeDistanceOperator<Graph_T> EdOp_T
            = operators::DefaultEdgeDistanceOperator<>>
  std::vector<std::vector<typename Graph_T::vertex_descriptor>>
  dijkstraShortestPaths([[maybe_unused]] Graph_T const& graph,
                        [[maybe_unused]]
                        typename Graph_T::vertex_descriptor const& start,
                        [[maybe_unused]]
                        typename Graph_T::vertex_descriptor const& goal,
                        [[maybe_unused]] EdOp_T distance_op = EdOp_T())
  {
      namespace alg = dte3603::graph::algorithms;
      using VertexDescriptor = typename Graph_T::vertex_descriptor;

      std::vector<VertexDescriptor> vertices = breadthFirstSearch(graph, start);
      std::set<std::pair<double,VertexDescriptor>> q;
      //std::priority_queue<VertexDescriptor, std::vector<VertexDescriptor>,
      std::map<VertexDescriptor, std::set<VertexDescriptor>> prev;
      std::map<VertexDescriptor, bool> visited;
      std::map<VertexDescriptor, double> distance;

      // Initialize queue by inserting vertices with their distance from start
      q.insert(std::pair<double, VertexDescriptor> (0, start));
      distance.emplace(start, 0);
      std::set<VertexDescriptor> v;
      prev.emplace(start, v);

      for (auto it = vertices.begin(); it != vertices.end(); it++) {
          //q.insert(std::pair<double,VertexDescriptor> (std::numeric_limits<double>::max(), *it));
          visited.emplace(*it, nullptr);
          distance.emplace(*it, std::numeric_limits<double>::max());
          //prev.emplace(*it, std::vector<VertexDescriptor>);
      }


      while (!q.empty()) {
          // Extract vertex with shortest length from the queue
          auto current_vertex = q.begin()->second;
          q.erase(q.begin());

          typename boost::graph_traits<Graph_T>::out_edge_iterator edge_it, edge_end;
          boost::tie(edge_it, edge_end) = boost::out_edges(current_vertex, graph);

          // Check every adjacent vertex
          for (; edge_it != edge_end; edge_it++) {
              VertexDescriptor adjacent_vertex = boost::target(*edge_it, graph);
              auto alt_distance = distance[current_vertex] + distance_op(*edge_it, graph);
              if (alt_distance <= distance[adjacent_vertex]) {
                  if (alt_distance < distance[adjacent_vertex]) {
                      prev[adjacent_vertex].clear();
                  }
                  prev[adjacent_vertex].insert(current_vertex);

                  distance[adjacent_vertex] = alt_distance;

                  if (!visited[adjacent_vertex]) {
                      q.insert(std::pair<double, VertexDescriptor> (distance[adjacent_vertex], adjacent_vertex));
                  }
              }

          }
          visited[current_vertex] = true;
      }

      std::vector<std::vector<VertexDescriptor>> paths;
      std::queue<std::vector<VertexDescriptor>> path_queue;
      std::vector<VertexDescriptor> path;

      path.push_back(goal);
      path_queue.push(path);

      // BFS (sort of) of new graph made from Dijkstra, but bottoms-up instead (goal to start)
      while (!path_queue.empty()) {
          path = path_queue.front();
          path_queue.pop();

          VertexDescriptor path_end = path[path.size() - 1];
          if (path_end == start) {
              std::vector<VertexDescriptor> completed_path(path.begin(), path.end() - 1);
              std::reverse(completed_path.begin(), completed_path.end());
              paths.push_back(completed_path);
          }

          for (auto vertex : prev[path_end]) {
              std::vector<VertexDescriptor> new_path(path);
              new_path.push_back(vertex);
              path_queue.push(new_path);
          }

      }


      /*
      std::stack<VertexDescriptor> s;
      _insert_path(goal, s, prev);
      std::vector<VertexDescriptor> path;

      while (!s.empty()) {
          auto current = s.pop();
          if (current == start) {
              path.clear();
          }
          else if (current == goal) {
              paths.push_back(path);
          }
          else {
              path.push_back(current);
          }
      }
      */


      /*
      if (prev[goal].size() != 0){
          bool more_paths = true;
          VertexDescriptor current_branch = NULL;

          while (more_paths) {
              current_branch = NULL;
              more_paths = false;
              auto current_vertex = goal;
              std::vector<VertexDescriptor> current_path;

              // While there are predecessors
              while (current_vertex != start && prev[current_vertex].size() != 0) {

                  // If there is more than one branch to take
                  if (prev[current_vertex].size() > 1) {
                      // Set this branch as the current branch checked
                      current_branch = current_vertex;
                      more_paths = true;
                  }

                  current_path.push_back(current_vertex);

                  current_vertex = *(prev[current_vertex].begin());
              }

              // Remove the current branch so we don't traverse it again
              if (current_branch != NULL) {
                  prev[current_branch].erase(prev[current_branch].begin());
              }

              std::reverse(current_path.begin(), current_path.end());

              paths.push_back(current_path);
          }
      }
      */

      return paths;
  }


}   // namespace dte3603::graph::algorithms


#endif   // DTE3603_DAY5_DIJKSTRA_SHORTEST_PATHS_H
