// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2019
// MIT License

#include <ArduinoJson.h>
#include <catch.hpp>

template <typename TOut, typename TIn>
TOut setAndGet(TIn value) {
  StaticJsonDocument<1> doc;
  JsonVariant var = doc.to<JsonVariant>();
  var.set(value);
  return var.as<TOut>();
}

TEST_CASE("Handle integer overflow in stored integer") {
  SECTION("int8_t") {
    // ok
    CHECK(setAndGet<int8_t>(-128) == -128);
    CHECK(setAndGet<int8_t>(42.0) == 42);
    CHECK(setAndGet<int8_t>(127) == 127);

    // too low
    CHECK(setAndGet<int8_t>(-128.1) == 0);
    CHECK(setAndGet<int8_t>(-129) == 0);

    // too high
    CHECK(setAndGet<int8_t>(128) == 0);
    CHECK(setAndGet<int8_t>(127.1) == 0);
  }

  SECTION("int16_t") {
    // ok
    CHECK(setAndGet<int16_t>(-32768) == -32768);
    CHECK(setAndGet<int16_t>(-32767.9) == -32767);
    CHECK(setAndGet<int16_t>(32766.9) == 32766);
    CHECK(setAndGet<int16_t>(32767) == 32767);

    // too low
    CHECK(setAndGet<int16_t>(-32768.1) == 0);
    CHECK(setAndGet<int16_t>(-32769) == 0);

    // too high
    CHECK(setAndGet<int16_t>(32767.1) == 0);
    CHECK(setAndGet<int16_t>(32768) == 0);
  }

  SECTION("uint8_t") {
    // ok
    CHECK(setAndGet<uint8_t>(1) == 1);
    CHECK(setAndGet<uint8_t>(42.0) == 42);
    CHECK(setAndGet<uint8_t>(255) == 255);

    // too low
    CHECK(setAndGet<uint8_t>(-1) == 0);
    CHECK(setAndGet<uint8_t>(-0.1) == 0);

    // to high
    CHECK(setAndGet<uint8_t>(255.1) == 0);
    CHECK(setAndGet<uint8_t>(256) == 0);
    CHECK(setAndGet<uint8_t>(257) == 0);
  }
}
