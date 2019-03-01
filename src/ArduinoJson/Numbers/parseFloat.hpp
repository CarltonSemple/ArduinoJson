// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2019
// MIT License

#pragma once

#include "parseNumber.hpp"

namespace ARDUINOJSON_NAMESPACE {

template <typename TFloat>
inline TFloat parseFloat(const char* s) {
  typedef typename FloatTraits<TFloat>::mantissa_type TUInt;
  return parseNumber<TFloat, TUInt>(s).template as<TFloat>();
}
}  // namespace ARDUINOJSON_NAMESPACE
