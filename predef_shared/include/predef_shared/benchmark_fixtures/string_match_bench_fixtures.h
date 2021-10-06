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
  size_t BENCHMARK_SIZE = 10;

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
            m_string = "Hello world !_!";
            m_sequence = "!_!";
          }
  };

  struct ShortPatternF : detail::StringMatchBenchmarkFixtureTemplate {
      using Base = detail::StringMatchBenchmarkFixtureTemplate;

      using Base::Base;
      ~ShortPatternF() override {}

        void SetUp(const benchmark::State& st) final
        {
            for (int i = 0; i < BENCHMARK_SIZE; i++) {
                m_string += "aabcaaab";
            }

            m_string += "aabcaaaacaaacaab";
            m_sequence = "aabcaaaacaaacaab";
        }
  };

  struct LongPatternF : detail::StringMatchBenchmarkFixtureTemplate {
      using Base = detail::StringMatchBenchmarkFixtureTemplate;

      using Base::Base;
      ~LongPatternF() override {}

        void SetUp(const benchmark::State& st) final
        {
            for (int i = 0; i < BENCHMARK_SIZE; i++) {
                m_string += "aabcaaab";
            }

            for (int i = 0; i < 5; i++) {
                m_string += "aabcaaaacaaacaab";
                m_sequence += "aabcaaaacaaacaab";
            }

        }
  };

}   // namespace dte3603::predef::benchmarking::string_match::fixtures

#endif   // DTE3603_PREDEF_BENCHMARKING_STRING_MATCH_FIXTURES_H
