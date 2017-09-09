#include "catch.hpp"
#include <osutils/filepath.hpp>

using osutils::filepath;

TEST_CASE("path can be parsed", "[filepath]") {
  REQUIRE(filepath("").is_valid() == true);
  REQUIRE(filepath("/").is_valid() == true);
}
