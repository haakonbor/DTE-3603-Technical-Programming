// Unit test utils
#include <predef_shared/testing_gold/graph_testing_fixtures.h>

// Day 5 graph path finding library
#include <day5_graph_path_finding/astar_search.h>

// gtest
#include <gtest/gtest.h>   // googletest header file

// stl
#include <vector>

// Qualify predefined fixtures
using namespace dte3603::predef::testing::graph::fixtures;

namespace alg = dte3603::graph::algorithms;


// A heuristic predicate
const auto unit_heuristic_fn
  = []([[maybe_unused]] auto const& u, [[maybe_unused]] auto const& v,
       [[maybe_unused]] auto const& graph) { return 1.; };


// DAGOneF
TEST_F(DAGOneF, aStarSearch_FromAToE_UnitHeur)
{
  auto paths
    = alg::aStarSearch(gold->graph(), gold->a(), gold->e(), unit_heuristic_fn);
  auto gold_paths = gold->shortestPathsAEGold();
  std::sort(std::begin(paths), std::end(paths));
  std::sort(std::begin(gold_paths), std::end(gold_paths));
  EXPECT_EQ(paths, gold_paths);
}

// DAGTwoF
TEST_F(DAGTwoF, aStarSearch_FromAToE_UnitHeur)
{
  auto paths
    = alg::aStarSearch(gold->graph(), gold->a(), gold->e(), unit_heuristic_fn);
  auto gold_paths = gold->shortestPathsAEGold();
  std::sort(std::begin(paths), std::end(paths));
  std::sort(std::begin(gold_paths), std::end(gold_paths));
  EXPECT_EQ(paths, gold_paths);
}

// DAGThreeF
TEST_F(DAGThreeF, aStarSearch_FromAToE_UnitHeur)
{
  auto paths
    = alg::aStarSearch(gold->graph(), gold->a(), gold->e(), unit_heuristic_fn);
  auto gold_paths = gold->shortestPathsAEGold();
  std::sort(std::begin(paths), std::end(paths));
  std::sort(std::begin(gold_paths), std::end(gold_paths));
  EXPECT_EQ(paths, gold_paths);
}
