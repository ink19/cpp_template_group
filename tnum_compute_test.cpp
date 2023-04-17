#include "tnum.hpp"
#include "tnum_logic.hpp"
#include "tnum_compute.hpp"
#include "tnum_compare.hpp"
#include <gtest/gtest.h>

class TNumComputeTest : public ::testing::Test{};

typedef ink19::num_to_tnum<123>::type tnum_123;
typedef ink19::num_to_tnum<321>::type tnum_321;
typedef ink19::num_to_tnum<444>::type tnum_444;

typedef ink19::num_to_tnum<-321>::type tnum_neg_321;
typedef ink19::num_to_tnum<0>::type tnum_0;


TEST_F(TNumComputeTest, add) {
  EXPECT_TRUE((std::is_same<tnum_444, typename ink19::compute_add<tnum_321, tnum_123>::type>::value));
  EXPECT_TRUE((std::is_same<tnum_444, typename ink19::compute_add<tnum_123, tnum_321>::type>::value));

  EXPECT_TRUE((std::is_same<tnum_123, typename ink19::compute_add<tnum_444, tnum_neg_321>::type>::value));
  EXPECT_TRUE((std::is_same<tnum_123, typename ink19::compute_add<tnum_neg_321, tnum_444>::type>::value));
  EXPECT_TRUE((std::is_same<tnum_0, typename ink19::compute_add<tnum_321, tnum_neg_321>::type>::value));
  EXPECT_TRUE((std::is_same<tnum_0, typename ink19::compute_add<tnum_neg_321, tnum_321>::type>::value));
  EXPECT_TRUE((std::is_same<tnum_123, typename ink19::compute_add<tnum_444, tnum_neg_321>::type>::value));
}
