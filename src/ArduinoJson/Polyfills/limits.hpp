// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2019
// MIT License

#pragma once

#include <float.h>
#include "../Polyfills/type_traits.hpp"

namespace ARDUINOJSON_NAMESPACE {

// Differs from standard because we can't use the symbols "min" and "max"
template <typename T, typename Enable = void>
struct numeric_limits;

template <typename T>
struct numeric_limits<T, typename enable_if<is_integral<T>::value &&
                                            is_unsigned<T>::value>::type> {
  static T lowest() {
    return 0;
  }
  static T largest() {
    return T(-1);
  }
};

template <typename T>
struct numeric_limits<
    T, typename enable_if<is_integral<T>::value && is_signed<T>::value>::type> {
  static T lowest() {
    return T(T(1) << (sizeof(T) * 8 - 1));
  }
  static T largest() {
    return T(~lowest());
  }
};

template <>
struct numeric_limits<float, void> {
  static float lowest() {
    return -FLT_MAX;
  }
  static float largest() {
    return FLT_MAX;
  }
};

template <>
struct numeric_limits<double, void> {
  static double lowest() {
    return -DBL_MAX;
  }
  static double largest() {
    return DBL_MAX;
  }
};

}  // namespace ARDUINOJSON_NAMESPACE
