// Unit test utils
#include <predef_shared/testing_gold/string_match_testing_fixtures.h>

// Day3 string match library
#include <day3_string_match/naive_search.h>
#include <day3_string_match/kmp_search.h>
#include <day3_string_match/bmh_search.h>
#include <day3_string_match/kr_search.h>

// gtest
#include <gtest/gtest.h>   // googletest header file

// stl
#include <vector>


// Qualify predefined fixtures
using namespace dte3603::predef::testing::string_match::fixtures;

namespace alg = dte3603::string_match::algorithms;

// Test on empty dataset
TEST_F(EmptySMCollF, naiveSearch)
{
  auto const& string = data->string();
  auto const& sgps   = data->sequenceGoldPairs();

  for (auto const& [sequence, gold] : sgps) {

    auto const res
      = alg::naive_search(std::begin(string), std::end(string),
                          std::begin(sequence), std::end(sequence));
    EXPECT_EQ(res, gold);
  }
}

TEST_F(EmptySMCollF, kmpSearch)
{
  auto const& string = data->string();
  auto const& sgps   = data->sequenceGoldPairs();

  for (auto const& [sequence, gold] : sgps) {

    auto const res = alg::kmp_search(std::begin(string), std::end(string),
                                     std::begin(sequence), std::end(sequence));
    EXPECT_EQ(res, gold);
  }
}

TEST_F(EmptySMCollF, bmhSearch)
{
  auto const& string = data->string();
  auto const& sgps   = data->sequenceGoldPairs();

  for (auto const& [sequence, gold] : sgps) {

    auto const res = alg::bmh_search(std::begin(string), std::end(string),
                                     std::begin(sequence), std::end(sequence));
    EXPECT_EQ(res, gold);
  }
}

TEST_F(EmptySMCollF, krSearch)
{
  auto const& string = data->string();
  auto const& sgps   = data->sequenceGoldPairs();

  for (auto const& [sequence, gold] : sgps) {

    auto const res = alg::kr_search(std::begin(string), std::end(string),
                                    std::begin(sequence), std::end(sequence));
    EXPECT_EQ(res, gold);
  }
}


// Test on HelloWorld dataset
TEST_F(HelloWorldSMCollF, naiveSearch)
{
  auto const& string = data->string();
  auto const& sgps   = data->sequenceGoldPairs();

  for (auto const& [sequence, gold] : sgps) {

    auto const res
      = alg::naive_search(std::begin(string), std::end(string),
                          std::begin(sequence), std::end(sequence));
    EXPECT_EQ(res, gold);
  }
}

TEST_F(HelloWorldSMCollF, kmpSearch)
{
  auto const& string = data->string();
  auto const& sgps   = data->sequenceGoldPairs();

  for (auto const& [sequence, gold] : sgps) {

    auto const res = alg::kmp_search(std::begin(string), std::end(string),
                                     std::begin(sequence), std::end(sequence));
    EXPECT_EQ(res, gold);
  }
}

TEST_F(HelloWorldSMCollF, bmhSearch)
{
  auto const& string = data->string();
  auto const& sgps   = data->sequenceGoldPairs();

  for (auto const& [sequence, gold] : sgps) {

    auto const res = alg::bmh_search(std::begin(string), std::end(string),
                                     std::begin(sequence), std::end(sequence));
    EXPECT_EQ(res, gold);
  }
}

TEST_F(HelloWorldSMCollF, krSearch)
{
  auto const& string = data->string();
  auto const& sgps   = data->sequenceGoldPairs();

  for (auto const& [sequence, gold] : sgps) {

    auto const res = alg::kr_search(std::begin(string), std::end(string),
                                    std::begin(sequence), std::end(sequence));
    EXPECT_EQ(res, gold);
  }
}


// Test on a custom alphabet
TEST_F(GoldCustomAlphabetStringMatchTestF, naiveSearch)
{
  auto const& string = m_string;
  auto const& sgps   = m_sg_pairs;


  for (auto const& [sequence, gold] : sgps) {

    auto const res = alg::naive_search(std::begin(string), std::end(string),
                                       std::begin(sequence), std::end(sequence),
                                       char_ptr_pred);
    EXPECT_EQ(res, gold);
  }
}

TEST_F(GoldCustomAlphabetStringMatchTestF, kmpSearch)
{
  auto const& string = m_string;
  auto const& sgps   = m_sg_pairs;


  for (auto const& [sequence, gold] : sgps) {

    auto const res = alg::kmp_search(std::begin(string), std::end(string),
                                     std::begin(sequence), std::end(sequence),
                                     char_ptr_pred);
    EXPECT_EQ(res, gold);
  }
}

TEST_F(GoldCustomAlphabetStringMatchTestF, bmhSearch)
{
  auto const& string = m_string;
  auto const& sgps   = m_sg_pairs;


  for (auto const& [sequence, gold] : sgps) {

    auto const res = alg::bmh_search(std::begin(string), std::end(string),
                                     std::begin(sequence), std::end(sequence),
                                     char_ptr_pred);
    EXPECT_EQ(res, gold);
  }
}

TEST_F(GoldCustomAlphabetStringMatchTestF, krSearch)
{
  auto const& string = m_string;
  auto const& sgps   = m_sg_pairs;

  for (auto const& [sequence, gold] : sgps) {

    auto const res
      = alg::kr_search(std::begin(string), std::end(string),
                       std::begin(sequence), std::end(sequence), char_ptr_pred);
    EXPECT_EQ(res, gold);
  }
}
