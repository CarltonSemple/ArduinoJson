// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2019
// MIT License

#pragma once

#include "../Polyfills/type_traits.hpp"
#include "convertNumber.hpp"
#include "parseNumber.hpp"

namespace ARDUINOJSON_NAMESPACE {
template <typename T>
T parseInteger(const char *s) {
  typedef typename make_unsigned<T>::type TUInt;

  ParsedNumber<Float, TUInt> num = parseNumber<Float, TUInt>(s);

  switch (num.type()) {
    case VALUE_IS_NEGATIVE_INTEGER:
      return convertNegativeInteger<T>(num.uintValue);

    case VALUE_IS_POSITIVE_INTEGER:
      return convertPositiveInteger<T>(num.uintValue);

    default:
      return 0;
  }
}
}  // namespace ARDUINOJSON_NAMESPACE
