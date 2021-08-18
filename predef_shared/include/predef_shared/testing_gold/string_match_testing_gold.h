#ifndef DTE3603_PREDEF_TESTING_STRING_MATCH_GOLD_H
#define DTE3603_PREDEF_TESTING_STRING_MATCH_GOLD_H

// gtest
#include <gtest/gtest.h>

// stl
#include <concepts>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>

namespace dte3603::predef::testing::string_match
{

  namespace detail
  {

    namespace generators
    {

      template <typename Generator_T>
      concept CollectionGenerator = requires(Generator_T g, std::string s)
      {
        typename Generator_T::GoldPairSeqs;

        {
          g(s)
          } -> std::convertible_to<typename Generator_T::GoldPairSeqs>;
      };

      struct EmptySMColGenerator {
        using GoldPairSeqs
          = std::vector<std::pair<std::string, std::string::const_iterator>>;

        GoldPairSeqs operator()(std::string& the_empty_string) const
        {
          the_empty_string = std::string{};
          GoldPairSeqs sgps;
          sgps.emplace_back("hello", the_empty_string.end());
          sgps.emplace_back("world", the_empty_string.end());
          sgps.emplace_back("", the_empty_string.begin());
          return sgps;
        }
      };

      struct HelloWorldSMColGenerator {
        using GoldPairSeqs
          = std::vector<std::pair<std::string, std::string::const_iterator>>;

        GoldPairSeqs operator()(std::string& the_string) const
        {
          the_string = "Hello world !_!";
          GoldPairSeqs sgps;
          sgps.emplace_back("hello", the_string.end());
          sgps.emplace_back("world", the_string.begin() + 6);
          sgps.emplace_back("", the_string.begin());
          sgps.emplace_back("_!", the_string.begin() + 13);
          return sgps;
        }
      };

    }   // namespace generators

    template <generators::CollectionGenerator Generator_T>
    class CollectionTemplate {
    public:
      using SeqGoldPairs
        = std::vector<std::pair<std::string, std::string::const_iterator>>;
      using Generator = Generator_T;

      CollectionTemplate()  = default;
      ~CollectionTemplate() = default;

      void init() { m_sg_pairs = m_gen(m_string); }

      std::string const&  string() const { return m_string; }
      SeqGoldPairs const& sequenceGoldPairs() const { return m_sg_pairs; }

    private:
      Generator    m_gen;
      std::string  m_string;
      SeqGoldPairs m_sg_pairs;
    };

  }   // namespace detail

  namespace gold
  {

    struct Empty
      : detail::CollectionTemplate<detail::generators::EmptySMColGenerator> {

      Empty() { init(); }
    };

    struct HelloWorld : detail::CollectionTemplate<
                          detail::generators::HelloWorldSMColGenerator> {

      HelloWorld() { init(); }
    };

  }   // namespace gold

}   // namespace dte3603::predef::testing::string_match

#endif   // DTE3603_PREDEF_TESTING_STRING_MATCH_GOLD_H
