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
  bool ok = (value & ~numeric_limits<T>::mask) == 0;
  return ok ? T(value) : 0;
}

template <typename T>
typename enable_if<sizeof(UInt) < sizeof(T), T>::type convertPositiveInteger(
    UInt value) {
  return T(value);
}

template <typename T>
typename enable_if<is_signed<T>::value, T>::type convertNegativeInteger(
    UInt value) {
  value = ~value + 1;
  bool ok = T(value | numeric_limits<T>::mask) == T(-1);
  return ok ? T(value) : 0;
}

template <typename T>
typename enable_if<is_unsigned<T>::value, T>::type convertNegativeInteger(
    UInt) {
  return 0;
}

template <typename T>
T convertFloat(Float value) {
  return T(value);
}
}  // namespace ARDUINOJSON_NAMESPACE
