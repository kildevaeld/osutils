#include <iostream>
#include <osutils/osutils.hpp>
using namespace osutils;
int main(int argc, char **argv) {

  filepath path("tes");

  if (path.is_valid()) {
    std::cout << "valid " << path.is_valid() << std::endl;
    std::cout << path << std::endl;
    std::cout << path.filename() << std::endl;
    std::cout << path.dir() << std::endl;
    std::cout << path.push("test") << std::endl;
  }

  std::cout << "Home " << home_dir() << "\n" 
  << "Temp " << tmp_dir() << "\n"
  << "Plaform " << platform_name() << std::endl;

  return 0;
}
