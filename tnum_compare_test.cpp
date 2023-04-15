#include "tnum.hpp"
#include "tnum_compare.hpp"
#include <gtest/gtest.h>


class TNumCompareTest : public ::testing::Test{};

typedef ink19::num_to_tnum<100>::type test_num_100;
typedef ink19::num_to_tnum<100>::type test_num_equal_100;
typedef ink19::num_to_tnum<124>::type test_num_124;
typedef ink19::num_to_tnum<97>::type test_num_97;
typedef ink19::num_to_tnum<-100>::type test_num_neg_100;
typedef ink19::num_to_tnum<-122>::type test_num_neg_122;
typedef ink19::num_to_tnum<-82>::type test_num_neg_82;

TEST_F(TNumCompareTest, compare_gt) {
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, ink19::compare_gt<test_num_100, test_num_equal_100>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, ink19::compare_gt<test_num_100, test_num_124>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, ink19::compare_gt<test_num_100, test_num_97>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, ink19::compare_gt<test_num_100, test_num_neg_100>::type>::value));

  EXPECT_TRUE((std::is_same<ink19::_tnum_1, ink19::compare_gt<test_num_neg_100, test_num_neg_122>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, ink19::compare_gt<test_num_neg_100, test_num_neg_82>::type>::value));
}

TEST_F(TNumCompareTest, compare_equal) {
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, ink19::compare_equal<test_num_100, test_num_equal_100>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, ink19::compare_equal<test_num_100, test_num_124>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, ink19::compare_equal<test_num_100, test_num_97>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, ink19::compare_equal<test_num_100, test_num_neg_100>::type>::value));

  EXPECT_TRUE((std::is_same<ink19::_tnum_0, ink19::compare_equal<test_num_neg_100, test_num_neg_122>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_0, ink19::compare_equal<test_num_neg_100, test_num_neg_82>::type>::value));
  EXPECT_TRUE((std::is_same<ink19::_tnum_1, ink19::compare_equal<test_num_neg_100, test_num_neg_100>::type>::value));
}
