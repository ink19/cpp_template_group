#ifndef __INK19_TNUM_ADV_COMPUTE
#define __INK19_TNUM_ADV_COMPUTE

#include "tnum.hpp"
#include "tnum_compare.hpp"
#include "tnum_logic.hpp"
#include "tnum_compute.hpp"
#include "tnum_numeric.hpp"

namespace ink19 {

template<typename T1, typename T2>
class __mult_unsigned;

// mult zero
template<typename ...To1>
class __mult_unsigned<__tnum_unsigned<To1...>, __tnum_unsigned<>> {
public:
  typedef __tnum_unsigned<_tnum_0> __multiplier_type; // 乘子
  typedef __tnum_unsigned<_tnum_0> type;
  typedef __tnum_unsigned<_tnum_0> __term_type;
};

template<typename ...To1, typename To2>
class __mult_unsigned<__tnum_unsigned<To1...>, __tnum_unsigned<To2>> {
public:
  typedef __tnum_unsigned<To1...> __multiplier_type; // 乘子
  typedef typename std::conditional<std::is_same<To2, _tnum_1>::value, __multiplier_type, __tnum_unsigned<_tnum_0>>::type __term_type;
  typedef __term_type type;
};

template<typename ...To1, typename Tf2, typename ...To2>
class __mult_unsigned<__tnum_unsigned<To1...>, __tnum_unsigned<Tf2, To2...>> {
public:
  typedef __mult_unsigned<__tnum_unsigned<To1...>, __tnum_unsigned<To2...>> __next_step;
  typedef typename logic_left_shift<typename __next_step::__multiplier_type>::type __multiplier_type; // 乘子
  typedef typename std::conditional<std::is_same<Tf2, _tnum_1>::value, __multiplier_type, __tnum_unsigned<_tnum_0>>::type __term_type;
  typedef typename __unsigned_add<
    __term_type,
    typename __next_step::type
  >::type type;
};

template<typename T1, typename T2>
class compute_mult : public __add_signed<
  typename std::conditional_t<
    std::is_same<
      typename is_negative<T1>::type,
      typename is_negative<T2>::type
    >::value,
    _tnum_0,
    _tnum_1
  >::type,
  typename __mult_unsigned<typename __remove_signed<T1>::type, typename __remove_signed<T2>::type
  >::type
>::type {};

template<typename T1, typename T2, typename judge>
class __div_unsigned_impl;

template<typename T1, typename T2>
class __div_unsigned : public __div_unsigned_impl<T1, T2, typename compare_ge<typename __add_signed<_tnum_0, T1>::type, typename __add_signed<_tnum_0, T2>::type>::type>{};

// div 0
template<typename ...To1>
class __div_unsigned<__tnum_unsigned<To1...>, __tnum_unsigned<>>{};

template<typename T1, typename T2>
class __div_unsigned_impl<T1, T2, _tnum_0> {
public:
  typedef T1 mod_type;
  typedef __tnum_unsigned<_tnum_0> div_type;
  typedef __div_unsigned_impl<T1, T2, _tnum_0> type;
  typedef __tnum_unsigned<_tnum_0> __term_type;
};

template<typename T1, typename T2>
class __div_unsigned_impl<T1, T2, _tnum_1> {
public:
  typedef __div_unsigned_impl<T1, T2, _tnum_1> type;
  typedef __div_unsigned<T1, typename logic_left_shift<T2>::type> __next_step;
  typedef typename __next_step::mod_type __left_type;
  typedef typename compare_ge<typename __add_signed<_tnum_0, __left_type>::type, typename __add_signed<_tnum_0, T2>::type>::type __term_type;
  typedef typename std::conditional<std::is_same<__term_type, _tnum_0>::value, __left_type, __unsigned_sub<__left_type, T2>>::type::type mod_type;
  typedef typename __unsigned_add<
    typename logic_left_shift<typename __next_step::div_type>::type,
    __tnum_unsigned<__term_type>
  >::type div_type;
};

template<typename T1, typename T2>
class compute_div {
public:
  typedef typename std::conditional_t<
    std::is_same<
      typename is_negative<T1>::type,
      typename is_negative<T2>::type
    >::value,
    _tnum_0,
    _tnum_1
  >::type __signed_type;
  typedef typename __div_unsigned<typename __remove_signed<T1>::type, typename __remove_signed<T2>::type>::type __unsigned_type;
  typedef typename __get_base<typename __add_signed<__signed_type, typename __unsigned_type::div_type>::type>::type div_type;
  typedef typename __get_base<typename __add_signed<__signed_type, typename __unsigned_type::mod_type>::type>::type mod_type;
  typedef compute_div<T1, T2> type; 
};


} // namespace end

#endif