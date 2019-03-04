// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2019
// MIT License

#pragma once

#include "convertNumber.hpp"
#include "parseNumber.hpp"

namespace ARDUINOJSON_NAMESPACE {

template <typename TFloat>
inline TFloat parseFloat(const char* s) {
  typedef typename FloatTraits<TFloat>::mantissa_type TUInt;

  ParsedNumber<Float, TUInt> num = parseNumber<Float, TUInt>(s);

  switch (num.type()) {
    case VALUE_IS_NEGATIVE_INTEGER:
      return convertNegativeInteger<TFloat>(num.uintValue);

    case VALUE_IS_POSITIVE_INTEGER:
      return convertPositiveInteger<TFloat>(num.uintValue);

    case VALUE_IS_FLOAT:
      return TFloat(num.floatValue);

    default:
      return 0;
  }
}
}  // namespace ARDUINOJSON_NAMESPACE
