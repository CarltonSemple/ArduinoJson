// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2019
// MIT License

#pragma once

#include "../Polyfills/type_traits.hpp"

namespace ARDUINOJSON_NAMESPACE {

// Differs from standard because we can't use the symbols "min" and "max"
template <typename T, typename Enable = void>
struct numeric_limits;

template <typename T>
struct numeric_limits<T, typename enable_if<is_unsigned<T>::value>::type> {
  const static T min_value = 0;
  const static T max_value = T(~min_value);
};

template <typename T>
struct numeric_limits<T, typename enable_if<is_signed<T>::value>::type> {
  const static T min_value = T(T(1) << (sizeof(T) * 8 - 1));
  const static T max_value = ~min_value;
};

}  // namespace ARDUINOJSON_NAMESPACE
