#ifndef WEEK2_PART1_TESTING_FIXTURES_H
#define WEEK2_PART1_TESTING_FIXTURES_H

#include "week2_part1_testing_gold.h"

#include <gtest/gtest.h>

namespace dte3603::predef::testing::week2::fixtures {
    template <typename GoldWeek2Part1_T>
    struct GoldWeek2_Part1_TestF : ::testing::Test {
        using GoldWeek2Part1 = GoldWeek2Part1_T;

        using ::testing::Test::Test;
        ~GoldWeek2_Part1_TestF() override {}

        std::unique_ptr<GoldWeek2Part1> gold;

        void SetUp() final { gold = std::make_unique<GoldWeek2Part1>(); }
        void TearDown() final { gold.release(); }
    };

    using DGOneF = GoldWeek2_Part1_TestF<gold::DGOne>;

} // namespace dte::3603::predef::testing::week2::fixtures

#endif // WEEK2_PART1_TESTING_FIXTURES_H
