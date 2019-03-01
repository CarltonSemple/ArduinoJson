// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2019
// MIT License

#define ARDUINOJSON_USE_LONG_LONG 0

#include <ArduinoJson.h>
#include <catch.hpp>

namespace my {
using ARDUINOJSON_NAMESPACE::isinf;
using ARDUINOJSON_NAMESPACE::isnan;
}  // namespace my

TEST_CASE("deserialize an integer") {
  DynamicJsonDocument doc(4096);

  SECTION("0") {
    DeserializationError err = deserializeJson(doc, "0");
    REQUIRE(err == DeserializationError::Ok);
    REQUIRE(doc.is<int>() == true);
    REQUIRE(doc.as<int>() == 0);
    REQUIRE(doc.as<std::string>() == "0");  // issue #808
  }

  SECTION("Negative") {
    DeserializationError err = deserializeJson(doc, "-42");

    REQUIRE(err == DeserializationError::Ok);
    REQUIRE(doc.is<int>());
    REQUIRE_FALSE(doc.is<bool>());
    REQUIRE(doc.as<int>() == -42);
  }

  SECTION("Floats") {
    SECTION("Double") {
      DeserializationError err = deserializeJson(doc, "-1.23e+4");

      REQUIRE(err == DeserializationError::Ok);
      REQUIRE_FALSE(doc.is<int>());
      REQUIRE(doc.is<double>());
      REQUIRE(doc.as<double>() == Approx(-1.23e+4));
    }

    SECTION("NaN") {
      DeserializationError err = deserializeJson(doc, "NaN");
      REQUIRE(err == DeserializationError::Ok);
      REQUIRE(doc.is<float>() == true);
      REQUIRE(my::isnan(doc.as<float>()));
    }

    SECTION("Infinity") {
      DeserializationError err = deserializeJson(doc, "Infinity");
      REQUIRE(err == DeserializationError::Ok);
      REQUIRE(doc.is<float>() == true);
      REQUIRE(my::isinf(doc.as<float>()));
    }

    SECTION("+Infinity") {
      DeserializationError err = deserializeJson(doc, "+Infinity");
      REQUIRE(err == DeserializationError::Ok);
      REQUIRE(doc.is<float>() == true);
      REQUIRE(my::isinf(doc.as<float>()));
    }

    SECTION("-Infinity") {
      DeserializationError err = deserializeJson(doc, "-Infinity");
      REQUIRE(err == DeserializationError::Ok);
      REQUIRE(doc.is<float>() == true);
      REQUIRE(my::isinf(doc.as<float>()));
    }
  }
}
