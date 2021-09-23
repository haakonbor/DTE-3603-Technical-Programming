// Unit test utils
#include <predef_shared/testing_gold/week2_part1_testing_fixtures.h>

#include <week2_part1/get_max_flow.h>

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


// DGTwoF
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