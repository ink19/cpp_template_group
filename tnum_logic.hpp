#ifndef __INK19_TNUM_LOGIC
#define __INK19_TNUM_LOGIC

#include "tnum.hpp"

namespace ink19 {

template<typename T, typename S>
class logic_and;

template<typename T, typename S>
class logic_or;

template<typename T, typename S>
class logic_xor;

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
