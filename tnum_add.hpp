#ifndef __INK19_TNUM_ADD
#define __INK19_TNUM_ADD

#include "tnum.hpp"
#include "tnum_compare.hpp"
#include "tnum_logic.hpp"

namespace ink19 {

template<typename T1, typename T2>
class __pair {
public:
  typedef T1 type1;
  typedef T2 type2;
};

template<typename S>
class __pair_swap;

template<typename T1, typename T2>
class __pair_swap<__pair<T1, T2>> : __pair<T2, T1> {};

template<typename T1, typename T2, bool is_bit_len_equal>
class __zero_padding_impl;

template<typename T1, typename T2>
class __zero_padding :  std::conditional<
  std::is_same<
    _tnum_1,
    typename __compare_gt_bit<T1, T2>::is_equal_type
  >::value,
  __pair<T1, T2>,
  typename std::conditional<
    std::is_same<_tnum_1, typename __compare_gt_bit<T1, T2>::type>::value,
    __zero_padding_impl<T1, T2, false>,
    __pair_swap<__zero_padding_impl<T1, T2, false>>
  >::type
>::type {};


template<typename T1, typename T2>
class __zero_padding_impl<T1, T2, true> : __pair<T1, T2> {};

template<typename T1, typename T2>
class __zero_padding_impl<T1, T2, false> : __zero_padding_impl<
  T1, 
  typename __concat_left<_tnum_0, T2>::type, 
  std::is_same<
    _tnum_1, 
    typename __compare_gt_bit<
      T1,
      typename __concat_left<_tnum_0, T2>::type
    >::is_equal_type
  >::value
> {};

} // namespace ink19 end
#endif