#include "catch.hpp"
#include <iostream>
#include <osutils/directories.hpp>

extern std::string HomeDir;

TEST_CASE("", "[directories]") {
  REQUIRE(strcmp(osutils::home_dir(), HomeDir.c_str()) == 0);
  std::cout << osutils::tmp_dir() <<std::endl;
}
