// Unit test utils
#include <predef_shared/benchmark_fixtures/string_match_bench_fixtures.h>

// Day 3 string match library
#include <day3_string_match/naive_search.h>
#include <day3_string_match/kmp_search.h>

// google benchmark
#include <benchmark/benchmark.h>

// stl
#include <memory>
#include <algorithm>

// Qualify predefined fixtures
using namespace dte3603::predef::benchmarking::string_match::fixtures;

namespace alg = dte3603::string_match::algorithms;

// Define benchmark fixtures for sorting of a sorted collection
BENCHMARK_DEFINE_F(HelloWorldF, stlSearch)
(benchmark::State& st)
{
  for (auto const& _ : st) {
    auto it = std::search(m_string.begin(), m_string.end(), m_sequence.begin(),
                m_sequence.end());
    benchmark::DoNotOptimize(it);
  }

}

BENCHMARK_DEFINE_F(HelloWorldF, naiveSearch)
(benchmark::State& st)
{
  for (auto const & _ : st) {
    auto it = alg::naive_search(m_string.begin(), m_string.end(), m_sequence.begin(),
                      m_sequence.end());
    benchmark::DoNotOptimize(it);
  }

}

BENCHMARK_DEFINE_F(HelloWorldF, kmpSearch)
(benchmark::State& st)
{
  for (auto const & _ : st) {
    auto it = alg::kmp_search(m_string.begin(), m_string.end(), m_sequence.begin(),
                      m_sequence.end());
    benchmark::DoNotOptimize(it);
  }
}

BENCHMARK_DEFINE_F(LongPatternF, stlSearch)
(benchmark::State& st)
{
  for (auto const& _ : st) {
    auto it = std::search(m_string.begin(), m_string.end(), m_sequence.begin(),
                m_sequence.end());
    benchmark::DoNotOptimize(it);
  }

}

BENCHMARK_DEFINE_F(LongPatternF, naiveSearch)
(benchmark::State& st)
{
  for (auto const & _ : st) {
    auto it = alg::naive_search(m_string.begin(), m_string.end(), m_sequence.begin(),
                      m_sequence.end());
    benchmark::DoNotOptimize(it);
  }

}

BENCHMARK_DEFINE_F(LongPatternF, kmpSearch)
(benchmark::State& st)
{
  for (auto const & _ : st) {
    auto it = alg::kmp_search(m_string.begin(), m_string.end(), m_sequence.begin(),
                      m_sequence.end());
    benchmark::DoNotOptimize(it);
  }
}


BENCHMARK_DEFINE_F(ShortPatternF, stlSearch)
(benchmark::State& st)
{
  for (auto const& _ : st) {
    auto it = std::search(m_string.begin(), m_string.end(), m_sequence.begin(),
                m_sequence.end());
    benchmark::DoNotOptimize(it);
  }

}

BENCHMARK_DEFINE_F(ShortPatternF, naiveSearch)
(benchmark::State& st)
{
  for (auto const & _ : st) {
    auto it = alg::naive_search(m_string.begin(), m_string.end(), m_sequence.begin(),
                      m_sequence.end());
    benchmark::DoNotOptimize(it);
  }

}

BENCHMARK_DEFINE_F(ShortPatternF, kmpSearch)
(benchmark::State& st)
{
  for (auto const & _ : st) {
    auto it = alg::kmp_search(m_string.begin(), m_string.end(), m_sequence.begin(),
                      m_sequence.end());
    benchmark::DoNotOptimize(it);
  }
}

// Register Benchmark
BENCHMARK_REGISTER_F(HelloWorldF, stlSearch);

BENCHMARK_REGISTER_F(HelloWorldF, naiveSearch);

BENCHMARK_REGISTER_F(HelloWorldF, kmpSearch);



BENCHMARK_REGISTER_F(LongPatternF, stlSearch);

BENCHMARK_REGISTER_F(LongPatternF, naiveSearch);

BENCHMARK_REGISTER_F(LongPatternF, kmpSearch);


BENCHMARK_REGISTER_F(ShortPatternF, stlSearch);

BENCHMARK_REGISTER_F(ShortPatternF, naiveSearch);

BENCHMARK_REGISTER_F(ShortPatternF, kmpSearch);



BENCHMARK_MAIN();
