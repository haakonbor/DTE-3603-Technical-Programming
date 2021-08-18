#ifndef DTE3603_PREDEF_TESTING_STRING_MATCH_FIXTURES_H
#define DTE3603_PREDEF_TESTING_STRING_MATCH_FIXTURES_H

#include "string_match_testing_gold.h"

// gtest
#include <gtest/gtest.h>

// stl
#include <variant>
#include <memory>


namespace dte3603::predef::testing::string_match::fixtures
{

  namespace detail
  {

    template <typename GoldStringMatchCollection_T>
    struct GoldStringMatchTestF : ::testing::Test {

      using GoldStringMatchCollection = GoldStringMatchCollection_T;

      using ::testing::Test::Test;
      ~GoldStringMatchTestF() override {}

      std::unique_ptr<GoldStringMatchCollection> data;

      void SetUp() final
      {
        data = std::make_unique<GoldStringMatchCollection>();
      }
      void TearDown() final { data.release(); }
    };


    namespace alphabet
    {

      struct Char {
        virtual char value() const = 0;
      };

      namespace chars
      {
        struct Emerge : Char {
          char value() const final { return 'e'; }
        };
        struct Oneshot : Char {
          char value() const final { return 'o'; }
        };
        struct Life : Char {
          char value() const final { return 'l'; }
        };
      }   // namespace chars

      using CharPtr = std::unique_ptr<Char>;
      using String  = std::vector<CharPtr>;

    }   // namespace alphabet

  }     // namespace detail

  using EmptySMCollF      = detail::GoldStringMatchTestF<gold::Empty>;
  using HelloWorldSMCollF = detail::GoldStringMatchTestF<gold::HelloWorld>;



  struct GoldCustomAlphabetStringMatchTestF : ::testing::Test {

    using ::testing::Test::Test;
    ~GoldCustomAlphabetStringMatchTestF() override {}

    using Char     = detail::alphabet::Char;
    using String   = detail::alphabet::String;
    using Sequence = String;

    using SeqGoldPair  = std::pair<String, String::const_iterator>;
    using SeqGoldPairs = std::vector<std::pair<String, String::const_iterator>>;

    String       m_string;
    SeqGoldPairs m_sg_pairs;

    // Use where auto -> detail::alphabet::CharPtr
    static constexpr auto char_ptr_pred = [](auto const& lhs, auto const& rhs) {
      return lhs->value() == rhs->value();
    };

    void SetUp() final
    {
      using E = detail::alphabet::chars::Emerge;
      using O = detail::alphabet::chars::Oneshot;
      using L = detail::alphabet::chars::Life;

      // The string
      m_string.emplace_back(std::make_unique<E>());
      m_string.emplace_back(std::make_unique<O>());
      m_string.emplace_back(std::make_unique<L>());
      m_string.emplace_back(std::make_unique<E>());
      m_string.emplace_back(std::make_unique<L>());
      m_string.emplace_back(std::make_unique<O>());
      m_string.emplace_back(std::make_unique<E>());
      m_string.emplace_back(std::make_unique<L>());
      m_string.emplace_back(std::make_unique<L>());
      m_string.emplace_back(std::make_unique<L>());
      m_string.emplace_back(std::make_unique<E>());

      // Empty string
      m_sg_pairs.emplace_back(String{}, m_string.begin());

      // No match
      {
        SeqGoldPair p;
        p.first.emplace_back(std::make_unique<L>());
        p.first.emplace_back(std::make_unique<O>());
        p.first.emplace_back(std::make_unique<L>());
        p.second = m_string.end();
        m_sg_pairs.push_back(std::move(p));
      }

      // A match at begin + 2
      {
        SeqGoldPair p;
        p.first.emplace_back(std::make_unique<L>());
        p.first.emplace_back(std::make_unique<E>());
        p.first.emplace_back(std::make_unique<L>());
        p.second = m_string.begin() + 2;
        m_sg_pairs.push_back(std::move(p));
      }
    }

    void TearDown() final
    {
      m_string.clear();
      m_sg_pairs.clear();
    }
  };


}   // namespace dte3603::predef::testing::string_match::fixtures

#endif   // DTE3603_PREDEF_TESTING_STRING_MATCH_FIXTURES_H
