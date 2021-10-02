#ifndef WEEK2_TESTING_FIXTURES_H
#define WEEK2_TESTING_FIXTURES_H

#include "week2_testing_gold.h"

#include <gtest/gtest.h>

namespace dte3603::predef::testing::week2::fixtures
{
  template <typename GoldWeek2_T>
  struct GoldWeek2_TestF : ::testing::Test {
    using GoldWeek2 = GoldWeek2_T;

    using ::testing::Test::Test;
    ~GoldWeek2_TestF() override {}

    std::unique_ptr<GoldWeek2> gold;

    void SetUp() final { gold = std::make_unique<GoldWeek2>(); }
    void TearDown() final { gold.release(); }
  };

  using DGOneF   = GoldWeek2_TestF<gold::DGOne>;
  using DGTwoF   = GoldWeek2_TestF<gold::DGTwo>;
  using DGThreeF = GoldWeek2_TestF<gold::DGThree>;

}   // namespace dte3603::predef::testing::week2::fixtures

#endif   // WEEK2_TESTING_FIXTURES_H
