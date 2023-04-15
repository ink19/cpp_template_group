#ifndef __INK19_TNUM_NUMERIC
#define __INK19_TNUM_NUMERIC

#include "tnum.hpp"
#include <type_traits>

namespace ink19 {

template<typename S>
class is_negative{};

template<typename Neg, typename ...T>
class is_negative<tnum<Neg, T...>> {
public:
  typedef Neg type;
};

}
#endif