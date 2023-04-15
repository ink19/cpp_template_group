#ifndef __INK19_TNUM
#define __INK19_TNUM

#include <type_traits>

#ifndef __TNUM_0
#define __TNUM_0 ink19::_tnum_default_0
#endif

#ifndef __TNUM_1
#define __TNUM_1 ink19::_tnum_default_1
#endif

namespace ink19 {

template<typename T, typename S>
class __get_base_impl {
public:
  typedef typename __get_base_impl<S, typename S::type>::type type;
};

template<typename T>
class __get_base : public __get_base_impl<T, typename T::type> {};

template<typename T>
class __get_base_impl<T, T> {
public:
  typedef T type;
};


class _tnum_default_0 {};
class _tnum_default_1 {};

class _tnum_0 : public ::__TNUM_0 {
public:
  typedef _tnum_0 type;
};

class _tnum_1 : public ::__TNUM_1 {
public:
  typedef _tnum_1 type;
};


template<typename T>
class __remove_first_zero;

// 有符号型
template<typename Neg, typename ...T>
class tnum {
public:
  typedef tnum<Neg, T...> self_type;
  typedef typename __remove_first_zero<self_type>::type type;
};

template<>
class tnum<_tnum_0> {
public:
  typedef tnum<_tnum_0> self_type;
  typedef _tnum_0 type;
};

template<>
class tnum<_tnum_1>: public tnum<_tnum_0> {};

// 无符号型
template<typename ...T>
class __tnum_unsigned {
public:
  typedef __tnum_unsigned<T...> type;
  typedef tnum<__TNUM_0, T...> signed_type;
};

// 删除符号型的符号，转为无符号型
template<typename T>
class __remove_signed;

template<typename Neg, typename ...T>
class __remove_signed<tnum<Neg, T...>> {
public:
  typedef __tnum_unsigned<T...> type;
};


// 为无符号型添加符号
template<typename Neg, typename T>
class __add_signed;

template<typename Neg, typename ...T>
class __add_signed<Neg, __tnum_unsigned<T...>> {
public:
  typedef tnum<Neg, T...> type;
};

template<typename Neg>
class __remove_first_zero<tnum<Neg>> {
public:
  typedef typename tnum<Neg>::type type;
};

template<typename Neg, typename First, typename ...To>
class __remove_first_zero<tnum<Neg, First, To...>> {
public:
  typedef typename std::conditional<
    std::is_same<First, _tnum_0>::value,
    typename __remove_first_zero<tnum<Neg, To...>>::type,
    tnum<Neg, First, To...>
  >::type type;
};

// 相反数
template<typename Tnum>
class opposite;

template<typename ...T>
class opposite<tnum<_tnum_0, T...>> {
public:
  typedef typename tnum<_tnum_1, T...>::type type;
};

template<typename ...T>
class opposite<tnum<_tnum_1, T...>> {
public:
  typedef typename tnum<_tnum_0, T...>::type type;
};

// 保证num为正数
template<unsigned int num, typename ...T>
class __num_to_tnum_bin {
public:
  static const unsigned int final_bin = num & 0x1;
  static const unsigned int last_bin = num >> 1;
  typedef typename __num_to_tnum_bin<
    last_bin,
    typename std::conditional<
      final_bin == 0,
      _tnum_0,
      _tnum_1
    >::type, 
    T...
  >::type type;
};

template <typename ...T>
class __num_to_tnum_bin<0, T...> {
public:
  typedef tnum<_tnum_0, T...> type;
};

template<int num>
class num_to_tnum {
public:
  typedef typename std::conditional<
    (num < 0),
    opposite<typename __num_to_tnum_bin<(unsigned int) -num>::type>,
    __num_to_tnum_bin<(unsigned int) num>
  >::type::type __type;
  typedef typename __get_base<__type>::type type;
};
}

#endif