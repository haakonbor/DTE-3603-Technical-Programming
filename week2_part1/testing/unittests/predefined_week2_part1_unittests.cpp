// Unit test utils
#include <predef_shared/testing_gold/week2_part1_testing_fixtures.h>

#include <week2_part1/get_max_flow.h>
#include <week2_part1/max_flow_min_cost.h>

// gtest
#include <gtest/gtest.h>   // googletest header file

// stl
#include <vector>

// Qualify predefined fixtures
using namespace dte3603::predef::testing::week2::fixtures;

namespace alg = dte3603::week2::algorithms;


// DGOneF
TEST_F(DGOneF, getMaxFlowTest)
{
  double flow      = alg::getMaxFlow(gold->graph(), gold->s(), gold->t());
  double gold_flow = gold->flowFromStoTGold();

  EXPECT_EQ(flow, gold_flow);
}


// DGTwoF - Flow
TEST_F(DGTwoF, getMaxFlowTest)
{
  double flow      = alg::getMaxFlow(gold->graph(), gold->s(), gold->t());
  double gold_flow = gold->flowFromStoTGold();

  EXPECT_EQ(flow, gold_flow);
}

// DGThreeF
TEST_F(DGThreeF, getMaxFlowTest)
{
  double flow      = alg::getMaxFlow(gold->graph(), gold->s(), gold->t());
  double gold_flow = gold->flowFromStoTGold();

  EXPECT_EQ(flow, gold_flow);
}

// DGTwoF - Cycles
TEST_F(DGTwoF, getCyclesTest)
{
  auto graph = gold->graph();

  double max_flow  = alg::getMaxFlow(graph, gold->s(), gold->t());
  auto   res_graph = alg::getResidualGraph(graph);

  auto cycles = alg::getCyclesFromGraph(res_graph, gold->s());
  for (auto c : cycles) {
    std::sort(c.begin(), c.end());
  }
  std::sort(cycles.begin(), cycles.end());

  auto cycles_gold = gold->cycleAtStartGold();
  for (auto c : cycles_gold) {
    std::sort(c.begin(), c.end());
  }
  std::sort(cycles_gold.begin(), cycles_gold.end());

  EXPECT_EQ(max_flow, gold->flowFromStoTGold());
  EXPECT_EQ(cycles, cycles_gold);
}
