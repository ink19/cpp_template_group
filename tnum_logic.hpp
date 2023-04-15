#ifndef __INK19_TNUM_LOGIC
#define __INK19_TNUM_LOGIC

#include "tnum.hpp"

namespace ink19 {

template<bool b>
class __bool_to_tnum_bit;

template<>
class __bool_to_tnum_bit<false> : public _tnum_0 {};

template<>
class __bool_to_tnum_bit<true> : public _tnum_1 {};

template<typename T, typename S>
class logic_and;

template<typename ...T>
class logic_and_n : public std::conditional<true && std::is_same<_tnum_0, T>::value..., _tnum_1, _tnum_0>::type {};

template<typename T, typename S>
class logic_or;

template<typename ...T>
class logic_or_n : public std::conditional<false || std::is_same<_tnum_0, T>::value..., _tnum_1, _tnum_0>::type {};
;

template<typename T, typename S>
class logic_xor;

template<typename ...T>
class logic_xor_n;

template<>
class logic_and<_tnum_1, _tnum_1> {
public:
  typedef _tnum_1 type;
};

template<typename T, typename S>
class logic_and {
public:
  typedef _tnum_0 type;
};

template<>
class logic_or<_tnum_0, _tnum_0> {
public:
  typedef _tnum_0 type;
};

template<typename T, typename S>
class logic_or {
public:
  typedef _tnum_1 type;
};

template<>
class logic_xor<_tnum_1, _tnum_0> {
public:
  typedef _tnum_1 type;
};

template<>
class logic_xor<_tnum_0, _tnum_1> {
public:
  typedef _tnum_1 type;
};

template<typename T, typename S>
class logic_xor {
public:
  typedef _tnum_1 type;
};

template<typename T1, typename T2>
class logic_xor_n<T1, T2>: public logic_xor<T1, T2> {};

template<typename T1>
class logic_xor_n<T1>: public T1 {};

template<typename ...T, typename Tf>
class logic_xor_n<Tf, T...> : public logic_xor<Tf, typename logic_xor_n<T...>::type>::type {};

template<typename T>
class logic_left_shift;

template<typename ...T>
class logic_left_shift<__tnum_unsigned<T...>> {
public:
  typedef __tnum_unsigned<T..., _tnum_0> type;
};

template<typename T, typename S>
class __concat_left;

template<typename ...T, typename S>
class __concat_left<S, __tnum_unsigned<T...>> {
public:
  typedef __tnum_unsigned<S, T...> type;
};

template<typename T>
class logic_right_shift;

template<typename ...T, typename Tf>
class logic_right_shift<__tnum_unsigned<Tf, T...>> {
public:
  typedef typename __concat_left<Tf, 
    typename logic_right_shift<__tnum_unsigned<T...>>::type
  >::type type;
};

template<typename T>
class logic_right_shift<__tnum_unsigned<T>> {
public:
  typedef __tnum_unsigned<> type;
};

template<>
class logic_right_shift<__tnum_unsigned<>>{
public:
  typedef __tnum_unsigned<> type;
};

}
#endif
