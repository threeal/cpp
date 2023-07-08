#include <fmt/core.h>

#include <catch2/catch_test_macros.hpp>
#include <error/error.hpp>
#include <sstream>
#include <string>

TEST_CASE("Error Construction") {
  const error::Error err = error::make("unknown error");
  REQUIRE(err.message == "unknown error");
}

TEST_CASE("Error Construction With Formatting") {
  const error::Error err = error::format("HTTP error {}", 404);
  REQUIRE(err.message == "HTTP error 404");
}

TEST_CASE("Error Comparison") {
  const auto err = error::make("unknown error");
  const auto err_copy = err;
  CHECK(err == err_copy);
  CHECK_FALSE(err != err_copy);
  const auto other_err = error::make("other error");
  CHECK_FALSE(err == other_err);
  CHECK(err != other_err);
}

TEST_CASE("Error Printing") {
  const auto err = error::make("unknown error");

  SECTION("Using ostream") {
    const auto ss = std::stringstream() << err;
    REQUIRE(ss.str() == "error: unknown error");
  }

  SECTION("Using fmtlib") {
    REQUIRE(fmt::format("{}", err) == "error: unknown error");
  }
}
