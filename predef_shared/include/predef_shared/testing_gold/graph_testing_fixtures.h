#ifndef DTE3603_PREDEF_TESTING_GRAPH_GOLD_H
#define DTE3603_PREDEF_TESTING_GRAPH_GOLD_H

#include "graph_testing_gold.h"

// gtest
#include <gtest/gtest.h>

namespace dte3603::predef::testing::graph::fixtures
{

  template <typename GoldGraph_T>
  struct GoldGraphTestF : ::testing::Test {

    using GoldGraph = GoldGraph_T;

    using ::testing::Test::Test;
    ~GoldGraphTestF() override {}

    std::unique_ptr<GoldGraph> gold;

    void SetUp() final { gold = std::make_unique<GoldGraph>(); }
    void TearDown() final { gold.release(); }
  };

  // Special purpose fixtures
  using SingleNodeDAGF = GoldGraphTestF<gold::SingleNodeDAG>;
  using TreeDAGF       = GoldGraphTestF<gold::TreeDAG>;

  // Brute force test fixtures
  using DAGOneF   = GoldGraphTestF<gold::DAGOne>;
  using DAGTwoF   = GoldGraphTestF<gold::DAGTwo>;
  using DAGThreeF = GoldGraphTestF<gold::DAGThree>;

}   // namespace dte3603::predef::testing::graph::fixtures

#endif   // DTE3603_PREDEF_TESTING_GRAPH_GOLD_H
