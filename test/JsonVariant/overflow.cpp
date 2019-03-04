// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2019
// MIT License

#include <ArduinoJson.h>
#include <catch.hpp>

template <typename T>
long setAndGet(long value) {
  StaticJsonDocument<1> doc;
  JsonVariant var = doc.to<JsonVariant>();
  var.set(value);
  return var.as<T>();
}

TEST_CASE("Integer overflow") {
  SECTION("uint8_t") {
    CHECK(setAndGet<uint8_t>(-1) == 0);
    CHECK(setAndGet<uint8_t>(42) == 42);
    CHECK(setAndGet<uint8_t>(256) == 0);
    CHECK(setAndGet<uint8_t>(257) == 0);
  }

  SECTION("uint8_t") {
    CHECK(setAndGet<uint8_t>(-1) == 0);
    CHECK(setAndGet<uint8_t>(42) == 42);
    CHECK(setAndGet<uint8_t>(256) == 0);
    CHECK(setAndGet<uint8_t>(257) == 0);
  }

  SECTION("int8_t") {
    CHECK(setAndGet<int8_t>(-1000) == 0);
    CHECK(setAndGet<int8_t>(-129) == 0);
    CHECK(setAndGet<int8_t>(-128) == -128);
    CHECK(setAndGet<int8_t>(-1) == -1);
    CHECK(setAndGet<int8_t>(42) == 42);
    CHECK(setAndGet<int8_t>(127) == 127);
    CHECK(setAndGet<int8_t>(128) == 0);
  }
}
