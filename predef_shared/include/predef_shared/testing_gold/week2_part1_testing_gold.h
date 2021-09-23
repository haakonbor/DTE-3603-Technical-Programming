#ifndef WEEK2_PART1_TESTING_GOLD_H
#define WEEK2_PART1_TESTING_GOLD_H


// boost
#include <boost/graph/adjacency_list.hpp>

// gtest
#include <gtest/gtest.h>

// stl
#include <concepts>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
#include <string>
#include <vector>

namespace dte3603::predef::testing::week2
{

  namespace detail
  {

    namespace types
    {

      namespace properties
      {

        struct NodeProperties {
          std::string name;
        };

        struct EdgeProperties {
          double flow;
          double capacity;
          double cost;
          double distance;
        };

        using GraphProperties = boost::no_property;

      }   // namespace properties

      using DirectionalGraph = boost::adjacency_list<
        boost::vecS, boost::vecS, boost::directedS, properties::NodeProperties,
        properties::EdgeProperties, properties::GraphProperties>;

    }   // namespace types


    template <typename GraphType_T>
    struct GoldGraphTemplate {

      using Graph       = GraphType_T;
      using VP          = typename Graph::vertex_property_type;
      using EP          = typename Graph::edge_property_type;
      using VD          = typename Graph::vertex_descriptor;
      using ED          = typename Graph::edge_descriptor;
      using VDVector    = std::vector<VD>;
      using VDVecVector = std::vector<VDVector>;

      GoldGraphTemplate()          = default;
      virtual ~GoldGraphTemplate() = default;

      Graph const& graph() const { return m_graph; }

      Graph m_graph;
    };

  }   // namespace detail

  namespace gold
  {
    class DGOne
      : public detail::GoldGraphTemplate<detail::types::DirectionalGraph> {

      using Base = detail::GoldGraphTemplate<detail::types::DirectionalGraph>;

      std::vector<std::vector<VD>> vertices;
      VD                           S;
      VD                           T;

    public:
      DGOne()
      {
        std::ifstream infile(
          "C:/dev/dte-3603_template_source_base/predef_shared/include/"
          "predef_shared/testing_gold/data/DGOne_test.txt");
        std::string current_line;
        int         count  = 0;
        int         floors = 0;

        while (std::getline(infile, current_line)) {
          if (count < 2) {
            if (count == 0) {
              floors = std::stoi(current_line);

              std::vector<VD> floor_vector;
              for (int i = 0; i < floors; i++) {
                vertices.push_back(floor_vector);
              }
            }
            else if (count == 1) {
              std::stringstream current_stream(current_line);
              std::string       vertices_in_floor;

              for (int i = 1;
                   i <= floors && current_stream >> vertices_in_floor; i++) {
                for (int n = 1; n <= std::stoi(vertices_in_floor); n++) {
                  auto v = boost::add_vertex(
                    VP{.name = std::to_string(i) + "." + std::to_string(n)},
                    m_graph);
                  vertices[i - 1].push_back(v);
                }
              }

              S = boost::add_vertex(VP{.name = "S"}, m_graph);
              T = boost::add_vertex(VP{.name = "T"}, m_graph);
            }
            count++;
            continue;
          }

          else {
            std::stringstream current_stream(current_line);
            std::string       source;
            current_stream >> source;
            std::string target;
            current_stream >> target;
            std::string capacity = "";
            current_stream >> capacity;
            std::string cost = "";
            current_stream >> cost;

            std::string temp;

            int source_floor  = 0;
            int source_vertex = 0;
            int target_floor  = 0;
            int target_vertex = 0;

            VD source_vertex_desc = NULL;

            if (source[0] == 'S') {
              source_vertex_desc = S;
            }

            else {
              for (int i = 0; i < source.size(); i++) {
                if (source[i] != ',') {
                  temp += source[i];
                }
                else {
                  source_floor  = std::stoi(temp);
                  source_vertex = std::stoi(source.substr(i + 1));
                  source_vertex_desc
                    = vertices[source_floor - 1][source_vertex - 1];
                }
              }
            }

            temp = "";

            VD target_vertex_desc = NULL;

            if (target[0] == 'T') {
              target_vertex_desc = T;
            }

            else {
              for (int i = 0; i < target.size(); i++) {
                if (target[i] != ',') {
                  temp += target[i];
                }
                else {
                  target_floor  = std::stoi(temp);
                  target_vertex = std::stoi(target.substr(i + 1));
                  target_vertex_desc
                    = vertices[target_floor - 1][target_vertex - 1];
                }
              }
            }

            boost::add_edge(source_vertex_desc, target_vertex_desc,
                            EP{.flow     = 0.,
                               .capacity = std::stod(capacity),
                               .cost     = std::stod(cost),
                               .distance = 0},
                            m_graph);
          }
        }
      }

      ~DGOne() override {}

      VD const& s() const { return S; }
      VD const& t() const { return T; }

      double flowFromStoTGold() const { return 3.; }
    };


    class DGTwo
      : public detail::GoldGraphTemplate<detail::types::DirectionalGraph> {

      using Base = detail::GoldGraphTemplate<detail::types::DirectionalGraph>;

      std::vector<std::vector<VD>> vertices;
      VD                           S;
      VD                           T;

    public:
      DGTwo()
      {
        std::ifstream infile(
          "C:/dev/dte-3603_template_source_base/predef_shared/include/"
          "predef_shared/testing_gold/data/DGTwo_test.txt");
        if (infile.fail()) {
          throw "FILE DOES NOT EXIST";
        }
        std::string current_line;
        int         count  = 0;
        int         floors = 0;

        while (std::getline(infile, current_line)) {
          if (count < 2) {
            if (count == 0) {
              floors = std::stoi(current_line);

              std::vector<VD> floor_vector;
              for (int i = 0; i < floors; i++) {
                vertices.push_back(floor_vector);
              }
            }
            else if (count == 1) {
              std::stringstream current_stream(current_line);
              std::string       vertices_in_floor;

              for (int i = 1;
                   i <= floors && current_stream >> vertices_in_floor; i++) {
                for (int n = 1; n <= std::stoi(vertices_in_floor); n++) {
                  auto v = boost::add_vertex(
                    VP{.name = std::to_string(i) + "." + std::to_string(n)},
                    m_graph);
                  vertices[i - 1].push_back(v);
                }
              }

              S = boost::add_vertex(VP{.name = "S"}, m_graph);
              T = boost::add_vertex(VP{.name = "T"}, m_graph);
            }
            count++;
            continue;
          }

          else {
            std::stringstream current_stream(current_line);
            std::string       source;
            current_stream >> source;
            std::string target;
            current_stream >> target;
            std::string capacity = "";
            current_stream >> capacity;
            std::string cost = "";
            current_stream >> cost;

            std::string temp;

            int source_floor  = 0;
            int source_vertex = 0;
            int target_floor  = 0;
            int target_vertex = 0;

            VD source_vertex_desc = NULL;

            if (source[0] == 'S') {
              source_vertex_desc = S;
            }

            else {
              for (int i = 0; i < source.size(); i++) {
                if (source[i] != ',') {
                  temp += source[i];
                }
                else {
                  source_floor  = std::stoi(temp);
                  source_vertex = std::stoi(source.substr(i + 1));
                  source_vertex_desc
                    = vertices[source_floor - 1][source_vertex - 1];
                }
              }
            }

            temp = "";

            VD target_vertex_desc = NULL;

            if (target[0] == 'T') {
              target_vertex_desc = T;
            }

            else {
              for (int i = 0; i < target.size(); i++) {
                if (target[i] != ',') {
                  temp += target[i];
                }
                else {
                  target_floor  = std::stoi(temp);
                  target_vertex = std::stoi(target.substr(i + 1));
                  target_vertex_desc
                    = vertices[target_floor - 1][target_vertex - 1];
                }
              }
            }

            if (source_vertex_desc == S || target_vertex_desc == T) {
              boost::add_edge(source_vertex_desc, target_vertex_desc,
                              EP{.flow     = 3.,
                                 .capacity = std::stod(capacity),
                                 .cost     = std::stod(cost),
                                 .distance = 0},
                              m_graph);
            }

            else {
              boost::add_edge(source_vertex_desc, target_vertex_desc,
                              EP{.flow     = 0.,
                                 .capacity = std::stod(capacity),
                                 .cost     = std::stod(cost),
                                 .distance = 0},
                              m_graph);
            }
          }
        }

        // Flow from MIT example
        m_graph[boost::edge(vertices[0][0], vertices[0][1], m_graph).first].flow
          = 1;
        m_graph[boost::edge(vertices[0][0], vertices[0][2], m_graph).first].flow
          = 2;
        m_graph[boost::edge(vertices[0][1], vertices[1][0], m_graph).first].flow
          = 2;
        m_graph[boost::edge(vertices[0][2], vertices[0][1], m_graph).first].flow
          = 1;
        m_graph[boost::edge(vertices[0][2], vertices[1][1], m_graph).first].flow
          = 2;
        m_graph[boost::edge(vertices[1][0], vertices[0][2], m_graph).first].flow
          = 1;
        m_graph[boost::edge(vertices[1][1], vertices[1][0], m_graph).first].flow
          = 1;
        m_graph[boost::edge(vertices[1][0], vertices[1][2], m_graph).first].flow
          = 2;
        m_graph[boost::edge(vertices[1][1], vertices[1][2], m_graph).first].flow
          = 1;
      }

      ~DGTwo() override {}

      VD const& s() const { return S; }
      VD const& t() const { return T; }

      double flowFromStoTGold() const { return 4.; }
    };

    class DGThree
      : public detail::GoldGraphTemplate<detail::types::DirectionalGraph> {

      using Base = detail::GoldGraphTemplate<detail::types::DirectionalGraph>;

      std::vector<std::vector<VD>> vertices;
      VD                           S;
      VD                           T;

    public:
      DGThree()
      {
        std::ifstream infile(
          "C:/dev/dte-3603_template_source_base/predef_shared/include/"
          "predef_shared/testing_gold/data/DGThree_test.txt");
        std::string current_line;
        int         count  = 0;
        int         floors = 0;

        while (std::getline(infile, current_line)) {
          if (count < 2) {
            if (count == 0) {
              floors = std::stoi(current_line);

              std::vector<VD> floor_vector;
              for (int i = 0; i < floors; i++) {
                vertices.push_back(floor_vector);
              }
            }
            else if (count == 1) {
              std::stringstream current_stream(current_line);
              std::string       vertices_in_floor;

              for (int i = 1;
                   i <= floors && current_stream >> vertices_in_floor; i++) {
                for (int n = 1; n <= std::stoi(vertices_in_floor); n++) {
                  auto v = boost::add_vertex(
                    VP{.name = std::to_string(i) + "." + std::to_string(n)},
                    m_graph);
                  vertices[i - 1].push_back(v);
                }
              }

              S = boost::add_vertex(VP{.name = "S"}, m_graph);
              T = boost::add_vertex(VP{.name = "T"}, m_graph);
            }
            count++;
            continue;
          }

          else {
            std::stringstream current_stream(current_line);
            std::string       source;
            current_stream >> source;
            std::string target;
            current_stream >> target;
            std::string capacity = "";
            current_stream >> capacity;
            std::string cost = "";
            current_stream >> cost;

            std::string temp;

            int source_floor  = 0;
            int source_vertex = 0;
            int target_floor  = 0;
            int target_vertex = 0;

            VD source_vertex_desc = NULL;

            if (source[0] == 'S') {
              source_vertex_desc = S;
            }

            else {
              for (int i = 0; i < source.size(); i++) {
                if (source[i] != ',') {
                  temp += source[i];
                }
                else {
                  source_floor  = std::stoi(temp);
                  source_vertex = std::stoi(source.substr(i + 1));
                  source_vertex_desc
                    = vertices[source_floor - 1][source_vertex - 1];
                }
              }
            }

            temp = "";

            VD target_vertex_desc = NULL;

            if (target[0] == 'T') {
              target_vertex_desc = T;
            }

            else {
              for (int i = 0; i < target.size(); i++) {
                if (target[i] != ',') {
                  temp += target[i];
                }
                else {
                  target_floor  = std::stoi(temp);
                  target_vertex = std::stoi(target.substr(i + 1));
                  target_vertex_desc
                    = vertices[target_floor - 1][target_vertex - 1];
                }
              }
            }

            boost::add_edge(source_vertex_desc, target_vertex_desc,
                            EP{.flow     = 0.,
                               .capacity = std::stod(capacity),
                               .cost     = std::stod(cost),
                               .distance = 0},
                            m_graph);
          }
        }
      }

      ~DGThree() override {}

      VD const& s() const { return S; }
      VD const& t() const { return T; }

      double flowFromStoTGold() const { return 2000.; }
    };

  }   // namespace gold

}   // namespace dte3603::predef::testing::week2


#endif   // WEEK2_PART1_TESTING_GOLD_H
