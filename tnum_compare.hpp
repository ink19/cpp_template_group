#ifndef __INK19_TNUM_COMPARE
#define __INK19_TNUM_COMPARE

#include "tnum.hpp"

namespace ink19 {
template<typename T, typename S>
class compare_gt;

template<typename Neg1, typename Unsign1, typename Neg2, typename Unsign2>
class __compare_gt_impl;

template<typename Neg1, typename ...T1, typename Neg2, typename ...T2>
class compare_gt<tnum<Neg1, T1...>, tnum<Neg2, T2...>> : public __compare_gt_impl<
  Neg1, typename __remove_signed<typename tnum<Neg1, T1...>::type>::type,
  Neg2, typename __remove_signed<typename tnum<Neg2, T2...>::type>::type
> {};

// 情况1
template<typename Unsign1, typename Unsign2>
class __compare_gt_impl<_tnum_0, Unsign1, _tnum_1, Unsign2> {
public:
  typedef _tnum_1 type;
};

// 情况2
template<typename Unsign1, typename Unsign2>
class __compare_gt_impl<_tnum_1, Unsign1, _tnum_0, Unsign2> {
public:
  typedef _tnum_0 type;
};

// 情况3
template<typename Unsign1, typename Unsign2>
class __compare_gt_impl<_tnum_1, Unsign1, _tnum_1, Unsign2> : public __compare_gt_impl<_tnum_0, Unsign2, _tnum_0, Unsign1> {};

// 对比bit长度
template<typename Unsign1, typename Unsign2>
class __compare_gt_bit;

// 逐位对比
template<typename Unsign1, typename Unsign2>
class __compare_gt_by_bit;

// 情况4全为正数，先比较位数
template<typename Unsign1, typename Unsign2>
class __compare_gt_impl<_tnum_0, Unsign1, _tnum_0, Unsign2> {
public:
  typedef __compare_gt_bit<Unsign1, Unsign2> __bit_compare_type;
  typedef typename std::conditional<
    std::is_same<
      typename __bit_compare_type::is_equal_type, _tnum_0
    >::value,
    __bit_compare_type,
    __compare_gt_by_bit<Unsign1, Unsign2>
  >::type::type type;
};


// 对比bit长度，实现
template<typename F1, typename ...T1, typename F2, typename ...T2>
class __compare_gt_bit<__tnum_unsigned<F1, T1...>, __tnum_unsigned<F2, T2...>> : public __compare_gt_bit<__tnum_unsigned<T1...>, __tnum_unsigned<T2...>> {};

template<typename F1, typename ...T1>
class __compare_gt_bit<__tnum_unsigned<F1, T1...>, __tnum_unsigned<>> {
public:
  typedef _tnum_1 type;
  typedef _tnum_0 is_equal_type;
};

template<typename F2, typename ...T2>
class __compare_gt_bit<__tnum_unsigned<>, __tnum_unsigned<F2, T2...>> {
public:
  typedef _tnum_0 type;
  typedef _tnum_0 is_equal_type;
};

template<>
class __compare_gt_bit<__tnum_unsigned<>, __tnum_unsigned<>> {
public:
  typedef _tnum_0 type;
  typedef _tnum_1 is_equal_type;
};

// 逐位对比，实现
template<typename F1, typename ...T1, typename F2, typename ...T2>
class __compare_gt_by_bit<__tnum_unsigned<F1, T1...>, __tnum_unsigned<F2, T2...>> {
public:
  typedef typename std::conditional<
    std::is_same<F1, F2>::value,
    __compare_gt_by_bit<__tnum_unsigned<T1...>, __tnum_unsigned<T2...>>,
    std::conditional<std::is_same<F1, _tnum_1>::value, _tnum_1, _tnum_0>
  >::type::type type;
};

template<>
class __compare_gt_by_bit<__tnum_unsigned<>, __tnum_unsigned<>> {
public:
  typedef _tnum_0 type;
};

template<typename T, typename S>
class compare_equal {
public:
  typedef typename std::conditional<
    std::is_same<typename __get_base<T>::type, typename __get_base<S>::type>::value &&
    std::is_base_of<typename __get_base<T>::type, typename __get_base<S>::type>::value &&
    std::is_base_of<typename __get_base<T>::type, typename __get_base<S>::type>::value
  , _tnum_1, _tnum_0>::type type;
};

}

#endif