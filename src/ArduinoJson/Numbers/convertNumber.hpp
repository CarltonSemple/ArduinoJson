// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2019
// MIT License

#pragma once

#include "../Polyfills/limits.hpp"
#include "Float.hpp"
#include "Integer.hpp"

namespace ARDUINOJSON_NAMESPACE {

template <typename T>
typename enable_if<sizeof(T) <= sizeof(UInt), T>::type convertPositiveInteger(
    UInt value) {
  return value <= T(numeric_limits<T>::max_value) ? T(value) : 0;
}

template <typename T>
typename enable_if<sizeof(UInt) < sizeof(T), T>::type convertPositiveInteger(
    UInt value) {
  return T(value);
}

template <typename T>
typename enable_if<is_signed<T>::value, T>::type convertNegativeInteger(
    UInt value) {
  return value <= UInt(-numeric_limits<T>::min_value) ? T(~value + 1) : 0;
}

template <typename T>
typename enable_if<is_unsigned<T>::value, T>::type convertNegativeInteger(
    UInt) {
  return 0;
}

template <typename T>
T convertFloat(Float value) {
  return value >= numeric_limits<T>::min_value &&
                 value <= numeric_limits<T>::max_value
             ? T(value)
             : 0;
}
}  // namespace ARDUINOJSON_NAMESPACE
