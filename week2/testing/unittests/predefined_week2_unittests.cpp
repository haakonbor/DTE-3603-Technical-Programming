// Unit test utils
#include <predef_shared/testing_gold/week2_testing_fixtures.h>

#include <week2/get_max_flow.h>
#include <week2/max_flow_min_cost.h>

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
  int flow      = alg::getMaxFlow(gold->graph(), gold->s(), gold->t());
  int gold_flow = gold->flowFromStoTGold();

  EXPECT_EQ(flow, gold_flow);
}


// DGTwoF - Flow
TEST_F(DGTwoF, getMaxFlowTest)
{
  int flow      = alg::getMaxFlow(gold->graph(), gold->s(), gold->t());
  int gold_flow = gold->flowFromStoTGold();

  EXPECT_EQ(flow, gold_flow);
}

// DGTwoF - Cycles
TEST_F(DGTwoF, getCyclesTest)
{
  auto graph = gold->graph();

  int  max_flow  = alg::getMaxFlow(graph, gold->s(), gold->t());
  auto res_graph = alg::getResidualGraph(graph);

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

TEST_F(DGTwoF, minCostMaxFlowTest)
{
  std::pair<int, int> result
    = alg::getMinCostMaxFlow(gold->graph(), gold->s(), gold->t());
  std::pair<int, int> gold_result;
  gold_result.first  = gold->minCostGold();
  gold_result.second = gold->flowFromStoTGold();

  EXPECT_EQ(result, gold_result);
}

// DGThreeF
TEST_F(DGThreeF, getMaxFlowTest)
{
  int flow      = alg::getMaxFlow(gold->graph(), gold->s(), gold->t());
  int gold_flow = gold->flowFromStoTGold();

  EXPECT_EQ(flow, gold_flow);
}

TEST_F(DGFourF, getMaxFlowTest)
{
  int flow      = alg::getMaxFlow(gold->graph(), gold->s(), gold->t());
  int gold_flow = gold->flowFromStoTGold();

  EXPECT_EQ(flow, gold_flow);
}

TEST_F(DGFourF, minCostMaxFlowTest)
{
  std::pair<int, int> result
    = alg::getMinCostMaxFlow(gold->graph(), gold->s(), gold->t());
  std::pair<int, int> gold_result;
  gold_result.first  = gold->minCostGold();
  gold_result.second = gold->flowFromStoTGold();

  EXPECT_EQ(result, gold_result);
}
