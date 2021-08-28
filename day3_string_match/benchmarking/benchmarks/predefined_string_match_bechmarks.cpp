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
  for (auto const& _ : st)
    std::search(m_string.begin(), m_string.end(), m_sequence.begin(),
                m_sequence.end());
}

BENCHMARK_DEFINE_F(HelloWorldF, naiveSearch)
(benchmark::State& st)
{
  for (auto const & _ : st)
    alg::naive_search(m_string.begin(), m_string.end(), m_sequence.begin(),
                      m_sequence.end());
}

BENCHMARK_DEFINE_F(HelloWorldF, kmpSearch)
(benchmark::State& st)
{
  for (auto const & _ : st)
    alg::kmp_search(m_string.begin(), m_string.end(), m_sequence.begin(),
                      m_sequence.end());
}


// Register Benchmark
BENCHMARK_REGISTER_F(HelloWorldF, stlSearch);
    //->RangeMultiplier(10)
    //->Range(1e1, 1e6);

BENCHMARK_REGISTER_F(HelloWorldF, naiveSearch);
    //->RangeMultiplier(10)
    //->Range(1e1, 1e6);

BENCHMARK_REGISTER_F(HelloWorldF, kmpSearch);
    //->RangeMultiplier(10)
    //->Range(1e1, 1e6);

BENCHMARK_MAIN();
