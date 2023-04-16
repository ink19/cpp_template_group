#include "tnum.hpp"
#include "tnum_logic.hpp"
#include <gtest/gtest.h>

class TNumLogicTest : public ::testing::Test{};

TEST_F(TNumLogicTest, logic_and) {
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_and<ink19::_tnum_0, ink19::_tnum_0>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_and<ink19::_tnum_1, ink19::_tnum_0>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_and<ink19::_tnum_0, ink19::_tnum_1>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_and<ink19::_tnum_1, ink19::_tnum_1>::type>::value));
};

TEST_F(TNumLogicTest, logic_or) {
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_or<ink19::_tnum_0, ink19::_tnum_0>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_or<ink19::_tnum_1, ink19::_tnum_0>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_or<ink19::_tnum_0, ink19::_tnum_1>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_or<ink19::_tnum_1, ink19::_tnum_1>::type>::value));
};

TEST_F(TNumLogicTest, logic_xor) {
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_xor<ink19::_tnum_0, ink19::_tnum_0>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_xor<ink19::_tnum_1, ink19::_tnum_0>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_xor<ink19::_tnum_0, ink19::_tnum_1>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_xor<ink19::_tnum_1, ink19::_tnum_1>::type>::value));
};

TEST_F(TNumLogicTest, logic_and_n) {
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_and_n<ink19::_tnum_0, ink19::_tnum_0>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_and_n<ink19::_tnum_1, ink19::_tnum_0>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_and_n<ink19::_tnum_0, ink19::_tnum_1>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_and_n<ink19::_tnum_1, ink19::_tnum_1>::type>::value));

  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_and_n<ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_and_n<ink19::_tnum_1, ink19::_tnum_0, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_and_n<ink19::_tnum_1, ink19::_tnum_0, ink19::_tnum_1, ink19::_tnum_0, ink19::_tnum_1, ink19::_tnum_1>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_and_n<ink19::_tnum_0, ink19::_tnum_0, ink19::_tnum_0, ink19::_tnum_0, ink19::_tnum_0, ink19::_tnum_0>::type>::value));
};

TEST_F(TNumLogicTest, logic_or_n) {
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_or_n<ink19::_tnum_0, ink19::_tnum_0>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_or_n<ink19::_tnum_1, ink19::_tnum_0>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_or_n<ink19::_tnum_0, ink19::_tnum_1>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_or_n<ink19::_tnum_1, ink19::_tnum_1>::type>::value));

  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_or_n<ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_or_n<ink19::_tnum_1, ink19::_tnum_0, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_or_n<ink19::_tnum_1, ink19::_tnum_0, ink19::_tnum_1, ink19::_tnum_0, ink19::_tnum_1, ink19::_tnum_1>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_or_n<ink19::_tnum_0, ink19::_tnum_0, ink19::_tnum_0, ink19::_tnum_0, ink19::_tnum_0, ink19::_tnum_0>::type>::value));
};

TEST_F(TNumLogicTest, logic_xor_n) {
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_xor_n<ink19::_tnum_0, ink19::_tnum_0>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_xor_n<ink19::_tnum_1, ink19::_tnum_0>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_xor_n<ink19::_tnum_0, ink19::_tnum_1>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_xor_n<ink19::_tnum_1, ink19::_tnum_1>::type>::value));

  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_xor_n<ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_xor_n<ink19::_tnum_1, ink19::_tnum_0, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_xor_n<ink19::_tnum_1, ink19::_tnum_0, ink19::_tnum_1, ink19::_tnum_0, ink19::_tnum_1, ink19::_tnum_1>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_xor_n<ink19::_tnum_0, ink19::_tnum_0, ink19::_tnum_0, ink19::_tnum_0, ink19::_tnum_0, ink19::_tnum_0>::type>::value));
};

TEST_F(TNumLogicTest, logic_not) {
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, typename ink19::logic_not<ink19::_tnum_1>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, typename ink19::logic_not<ink19::_tnum_0>::type>::value));
};


typedef ink19::__remove_signed<ink19::num_to_tnum<12231>::type>::type unsigned_tnum_12231;
typedef ink19::__remove_signed<ink19::num_to_tnum<24462>::type>::type unsigned_tnum_24462;

TEST_F(TNumLogicTest, logic_shift) {
  EXPECT_TRUE((std::is_same<unsigned_tnum_12231, typename ink19::logic_right_shift<unsigned_tnum_24462>::type>::value));
  EXPECT_TRUE((std::is_same<unsigned_tnum_24462, typename ink19::logic_left_shift<unsigned_tnum_12231>::type>::value));
};