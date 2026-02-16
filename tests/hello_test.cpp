#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

TEST_CASE("Basic comparisons", "[strcmp_case_insensitive]") {
    // equal strings, same case
    REQUIRE(strcmp_case_insensitive("hi", "hi") == 0);

    // equal strings, different case
    REQUIRE(strcmp_case_insensitive("Hi", "hi") == 0);
    REQUIRE(strcmp_case_insensitive("HI", "hi") == 0);
    REQUIRE(strcmp_case_insensitive("HeLLo", "hElLo") == 0);

    // first string < second string
    REQUIRE(strcmp_case_insensitive("basket", "basketball") == -1);
    REQUIRE(strcmp_case_insensitive("Foot", "Football") == -1);

    // first string > second string
    REQUIRE(strcmp_case_insensitive("zero", "agile") == 1);
    REQUIRE(strcmp_case_insensitive("Zero", "Agile") == 1);
}

TEST_CASE("Different lengths", "[strcmp_case_insensitive]") {
    // first string shorter
    REQUIRE(strcmp_case_insensitive("mag", "magazine") == -1);

    // second string shorter
    REQUIRE(strcmp_case_insensitive("magazine", "mag") == 1);
}

TEST_CASE("Empty strings", "[strcmp_case_insensitive]") {
    // both empty
    REQUIRE(strcmp_case_insensitive("", "") == 0);

    // first empty
    REQUIRE(strcmp_case_insensitive("", "full") == -1);

    // second empty
    REQUIRE(strcmp_case_insensitive("full", "") == 1);
}

TEST_CASE("Numbers and symbols", "[strcmp_case_insensitive]") {
    REQUIRE(strcmp_case_insensitive("123", "123") == 0);
    REQUIRE(strcmp_case_insensitive("123", "124") == -1);
    REQUIRE(strcmp_case_insensitive("!@#", "!@#") == 0);
    REQUIRE(strcmp_case_insensitive("!@#", "!@!") == 1);
}
