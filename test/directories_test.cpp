#include "catch.hpp"
#include <iostream>
#include <osutils/directories.hpp>

TEST_CASE("", "[directories]") {
  std::cout << osutils::home_dir() << std::endl;
}
