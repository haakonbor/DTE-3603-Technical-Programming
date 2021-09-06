#ifndef DTE3603_PREDEF_BENCHMARKING_STRING_MATCH_FIXTURES_H
#define DTE3603_PREDEF_BENCHMARKING_STRING_MATCH_FIXTURES_H

// google benchmark
#include <benchmark/benchmark.h>

// stl
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

namespace dte3603::predef::benchmarking::string_match::fixtures
{

  namespace detail
  {

    struct StringMatchBenchmarkFixtureTemplate : benchmark::Fixture {

      using benchmark::Fixture::Fixture;
      ~StringMatchBenchmarkFixtureTemplate() override {}

      std::string m_string;
      std::string m_sequence;

      void TearDown(const benchmark::State&) override {}
    };
  }   // namespace detail

  struct HelloWorldF : detail::StringMatchBenchmarkFixtureTemplate {
    using Base = detail::StringMatchBenchmarkFixtureTemplate;

    using Base::Base;
    ~HelloWorldF() override {}

      void SetUp(const benchmark::State& st) final
          {
            for (int i = 0; i < 10000000; ++i) {
                m_string+=("aabcaaaab");
            }
            m_string += "aabcaaaacaaacaab";
            m_sequence = "aabcaaaacaaacaab";
          }
  };

}   // namespace dte3603::predef::benchmarking::string_match::fixtures

#endif   // DTE3603_PREDEF_BENCHMARKING_STRING_MATCH_FIXTURES_H
