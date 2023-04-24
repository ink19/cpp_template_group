#include "tnum.hpp"
#include "tnum_logic.hpp"
#include "tnum_adv_compute.hpp"
#include "tnum_compare.hpp"
#include <gtest/gtest.h>


class TNumAdvComputeTest : public ::testing::Test{};

typedef ink19::num_to_tnum<123>::type tnum_123;
typedef ink19::num_to_tnum<321>::type tnum_321;
typedef ink19::num_to_tnum<39483>::type tnum_39483;
typedef ink19::num_to_tnum<142524>::type tnum_142524;
typedef ink19::num_to_tnum<-142524>::type tnum_neg_142524;

typedef ink19::num_to_tnum<-321>::type tnum_neg_321;
typedef ink19::num_to_tnum<0>::type tnum_0;
typedef ink19::num_to_tnum<444>::type tnum_444;
typedef ink19::num_to_tnum<-444>::type tnum_neg_444;

typedef ink19::num_to_tnum<198>::type tnum_198;
typedef ink19::num_to_tnum<-198>::type tnum_neg_198;
typedef ink19::num_to_tnum<765>::type tnum_765;
typedef ink19::num_to_tnum<-765>::type tnum_neg_765;
typedef ink19::num_to_tnum<642>::type tnum_642;

TEST_F(TNumAdvComputeTest, mult) {
  EXPECT_TRUE((std::is_same<tnum_39483, typename ink19::compute_mult<tnum_321, tnum_123>::type>::value));
  EXPECT_TRUE((std::is_same<tnum_39483, typename ink19::compute_mult<tnum_123, tnum_321>::type>::value));
  EXPECT_TRUE((std::is_same<tnum_142524, typename ink19::compute_mult<tnum_444, tnum_321>::type>::value));
  EXPECT_TRUE((std::is_same<tnum_neg_142524, typename ink19::compute_mult<tnum_444, tnum_neg_321>::type>::value));
  EXPECT_TRUE((std::is_same<tnum_neg_142524, typename ink19::compute_mult<tnum_neg_321, tnum_444>::type>::value));
  EXPECT_TRUE((std::is_same<tnum_0, typename ink19::compute_mult<tnum_321, tnum_0>::type>::value));
  EXPECT_TRUE((std::is_same<tnum_0, typename ink19::compute_mult<tnum_neg_321, tnum_0>::type>::value));
  EXPECT_TRUE((std::is_same<tnum_142524, typename ink19::compute_mult<tnum_neg_444, tnum_neg_321>::type>::value));
}

typedef ink19::num_to_tnum<438798>::type tnum_438798;
typedef typename ink19::compute_div<tnum_438798, tnum_123>::type t_438798_123_div;
typedef ink19::num_to_tnum<3567>::type tnum_3567;
typedef ink19::num_to_tnum<57>::type tnum_57;

typedef ink19::num_to_tnum<-438798>::type tnum_neg_438798;
typedef typename ink19::compute_div<tnum_neg_438798, tnum_123>::type t_neg_438798_123_div;
typedef ink19::num_to_tnum<-3567>::type tnum_neg_3567;
typedef ink19::num_to_tnum<-57>::type tnum_neg_57;

typedef typename ink19::compute_div<tnum_0, tnum_123>::type t_neg_0_123_div;



TEST_F(TNumAdvComputeTest, div) {
  EXPECT_TRUE((std::is_same<tnum_3567, typename t_438798_123_div::div_type>::value));
  EXPECT_TRUE((std::is_same<tnum_57, typename t_438798_123_div::mod_type>::value));
  EXPECT_TRUE((std::is_same<tnum_neg_3567, typename t_neg_438798_123_div::div_type>::value));
  EXPECT_TRUE((std::is_same<tnum_neg_57, typename t_neg_438798_123_div::mod_type>::value));
  
  EXPECT_TRUE((std::is_same<tnum_0, typename t_neg_0_123_div::div_type>::value));
  EXPECT_TRUE((std::is_same<tnum_0, typename t_neg_0_123_div::mod_type>::value));
  
}
