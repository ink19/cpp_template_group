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
  typedef __pair<T1, T2> type;
};

template<typename S>
class __pair_swap{
public:
  typedef typename S::type2 type1;
  typedef typename S::type1 type2;
  typedef __pair_swap<S> type;
};

template<typename T1, typename T2, bool is_bit_len_equal>
class __zero_padding_impl;

template<typename T1, typename T2>
class __zero_padding : public std::conditional<
  std::is_same<
    _tnum_1,
    typename __compare_gt_bit<T1, T2>::is_equal_type
  >::value,
  __pair<T1, T2>,
  typename std::conditional<
    std::is_same<_tnum_1, typename __compare_gt_bit<T1, T2>::type>::value,
    __zero_padding_impl<T1, T2, false>,
    __pair_swap<__zero_padding_impl<T2, T1, false>>
  >::type
>::type {};


template<typename T1, typename T2>
class __zero_padding_impl<T1, T2, true> : public __pair<T1, T2> {};

template<typename T1, typename T2>
class __zero_padding_impl<T1, T2, false> : public __zero_padding_impl<
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

// 对齐后的无符号加法，保证T1 > T2
template<typename T1, typename T2>
class __unsigned_padding_add;

// 对齐后无符号的减法，保证T1 > T2
template<typename T1, typename T2>
class __unsigned_padding_sub;

// 无符号的加法
template<typename T1, typename T2>
class __unsigned_add : public __get_base<__unsigned_padding_add<
  typename __zero_padding<
    typename __concat_left<_tnum_0, T1>::type, // 前面加0，防止进位
    typename __concat_left<_tnum_0, T2>::type
  >::type1,
  typename __zero_padding<
    typename __concat_left<_tnum_0, T1>::type, 
    typename __concat_left<_tnum_0, T2>::type
  >::type2
>>::type {};

// 无符号的减法，保证T1 > T2
template<typename T1, typename T2>
class __unsigned_sub : public __get_base<__unsigned_padding_sub<
  typename __zero_padding<
    typename __concat_left<_tnum_0, T1>::type, // 前面加0，防止进位
    T2
  >::type1,
  typename __zero_padding<
    typename __concat_left<_tnum_0, T1>::type, 
    T2
  >::type2
>>::type {};

template<typename Tf1, typename ...T1, typename Tf2, typename ...T2>
class __unsigned_padding_add<__tnum_unsigned<Tf1, T1...>, __tnum_unsigned<Tf2, T2...>> {
public:
  typedef __unsigned_padding_add<__tnum_unsigned<T1...>, __tnum_unsigned<T2...>> left_type;

  /*
   * bit_type
   * 0 0 0 = 0
   * 1 0 0 = 1
   * 1 1 0 = 0
   * 1 1 1 = 1
   * (Tf1 | Tf2 | carry) & (Tf1 ^ Tf2 ^ carry)
   */
  typedef typename logic_and<
    typename logic_or_n<Tf1, Tf2, typename left_type::carry_type>::type, 
    typename logic_xor_n<Tf1, Tf2, typename left_type::carry_type>::type
  >::type bit_type;

  /*
   * carry_type
   * 0 0 0 = 0
   * 0 0 1 = 0
   * 0 1 1 = 1
   * 1 1 1 = 1
   * (Tf1 & Tf2 & carry) | !(Tf1 ^ Tf2 ^ carry)
   */
  typedef typename logic_or_n<
    typename logic_and<Tf1, Tf2>::type,
    typename logic_and<Tf1, typename left_type::carry_type>::type,
    typename logic_and<Tf2, typename left_type::carry_type>::type
  >::type carry_type;
  typedef typename __concat_left<bit_type, typename left_type::type>::type type;
};

template<>
class __unsigned_padding_add<__tnum_unsigned<>, __tnum_unsigned<>> {
public:
  typedef __tnum_unsigned<> type;
  typedef _tnum_0 carry_type;
};

template<typename Tf1, typename ...T1, typename Tf2, typename ...T2>
class __unsigned_padding_sub<__tnum_unsigned<Tf1, T1...>, __tnum_unsigned<Tf2, T2...>> {
public:
  typedef __unsigned_padding_sub<__tnum_unsigned<T1...>, __tnum_unsigned<T2...>> left_type;

  /*
   * bit_type
   * 0 0 0 = 0
   * 1 0 0 = 1
   * 1 1 0 = 0
   * 1 1 1 = 1
   * (Tf1 | Tf2 | carry) & (Tf1 ^ Tf2 ^ carry)
   */
  typedef typename logic_and<
    typename logic_or_n<Tf1, Tf2, typename left_type::carry_type>::type, 
    typename logic_xor_n<Tf1, Tf2, typename left_type::carry_type>::type
  >::type bit_type;

  /*
   * carry_type
   * 0 0 0 = 0
   * 1 0 0 = 0
   * 1 0 1 = 0
   * 0 0 1 = 1
   * 0 1 1 = 1
   * 1 1 1 = 1
   * (carry & Tf2) | ((carry | Tf2) & (!Tf1))
   */
  typedef typename logic_or<
    typename logic_and<Tf2, typename left_type::carry_type>::type, 
    typename logic_and<typename logic_or<Tf2, typename left_type::carry_type>::type, typename logic_not<Tf1>::type>::type
  >::type carry_type;
  typedef typename __concat_left<bit_type, typename left_type::type>::type type;
};

template<>
class __unsigned_padding_sub<__tnum_unsigned<>, __tnum_unsigned<>> {
public:
  typedef __tnum_unsigned<> type;
  typedef _tnum_0 carry_type;
};

template<typename T, typename S>
class compute_sub;

template<typename T, typename S>
class compute_add : public compute_sub<T, typename opposite<S>::type>::type {};

template<typename ...T1, typename ...T2>
class compute_add<tnum<_tnum_0, T1...>, tnum<_tnum_0, T2...>> : public __add_signed<_tnum_0, typename __unsigned_add<__tnum_unsigned<T1...>, __tnum_unsigned<T2...>>::type>::type {};

template<typename ...T1, typename ...T2>
class compute_add<tnum<_tnum_1, T1...>, tnum<_tnum_1, T2...>> : public __add_signed<_tnum_1, typename __unsigned_add<__tnum_unsigned<T1...>, __tnum_unsigned<T2...>>::type>::type {};

template<typename ...T1, typename ...T2>
class compute_sub<tnum<_tnum_0, T1...>, tnum<_tnum_0, T2...>> : public __add_signed<
  typename compare_gt<tnum<_tnum_0, T2...>, tnum<_tnum_0, T1...>>::type,
  typename std::conditional<
    std::is_same<_tnum_0, typename compare_gt<tnum<_tnum_0, T2...>, tnum<_tnum_0, T1...>>::type>::value,
    __unsigned_sub<__tnum_unsigned<T1...>, __tnum_unsigned<T2...>>,
    __unsigned_sub<__tnum_unsigned<T2...>, __tnum_unsigned<T1...>>
  >::type::type
>::type {};

template<typename ...T1, typename ...T2>
class compute_sub<tnum<_tnum_1, T1...>, tnum<_tnum_1, T2...>> : public opposite<
  typename compute_sub<tnum<_tnum_0, T1...>, tnum<_tnum_0, T2...>>::type
>::type {};

template<typename ...T1, typename ...T2>
class compute_sub<tnum<_tnum_0, T1...>, tnum<_tnum_1, T2...>> : public compute_add<tnum<_tnum_0, T1...>, tnum<_tnum_0, T1...>>::type {};

template<typename ...T1, typename ...T2>
class compute_sub<tnum<_tnum_1, T1...>, tnum<_tnum_0, T2...>> : public compute_add<tnum<_tnum_1, T1...>, tnum<_tnum_1, T1...>>::type {};

} // namespace ink19 end
#endif