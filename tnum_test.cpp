#include "tnum.hpp"
#include <gtest/gtest.h>

class TNumTest : public ::testing::Test{};

typedef ink19::num_to_tnum<100> test_num_100;
typedef ink19::tnum<ink19::_tnum_0, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_0, ink19::_tnum_0, ink19::_tnum_1, ink19::_tnum_0, ink19::_tnum_0> test_tnum_100;
typedef ink19::num_to_tnum<-765> test_num_neg_765;
typedef ink19::tnum<ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_0, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_1, ink19::_tnum_0, ink19::_tnum_1> test_tnum_neg_765;

typedef ink19::num_to_tnum<0> test_num_0;
typedef ink19::tnum<ink19::_tnum_0> test_tnum_0;
typedef ink19::tnum<ink19::_tnum_1> test_tnum_neg_0;

TEST_F(TNumTest, num_create) {
  EXPECT_TRUE((std::is_same<test_num_100::type, test_tnum_100::type>::value));
  EXPECT_TRUE((std::is_same<test_num_neg_765::type, test_tnum_neg_765::type>::value));
  EXPECT_TRUE((std::is_same<test_num_0::type, test_tnum_0::type>::value));
  EXPECT_TRUE((std::is_same<test_num_0::type, test_tnum_neg_0::type>::value));
}

typedef ink19::num_to_tnum<-100>::type test_num_neg_100;

TEST_F(TNumTest, num_opposite) {
  EXPECT_TRUE((std::is_same<test_num_100::type, ink19::opposite<test_num_neg_100>::type>::value));
}
