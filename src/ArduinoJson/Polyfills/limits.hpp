// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2019
// MIT License

#pragma once

#include <stdint.h>

namespace ARDUINOJSON_NAMESPACE {

template <typename T>
struct numeric_limits;

template <>
struct numeric_limits<uint32_t> {
  static uint32_t max() {
    return uint32_t(-1);
  }
};

template <>
struct numeric_limits<uint64_t> {
  static uint64_t max() {
    return uint64_t(-1);
  }
};
}  // namespace ARDUINOJSON_NAMESPACE
