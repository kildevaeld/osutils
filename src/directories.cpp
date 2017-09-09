#include <osutils/directories.hpp>
#include <pwd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

namespace osutils {

static const char *const HOME_ENV = "HOME";

const char *home_dir() {
  const char *home;
  if ((home = getenv(HOME_ENV)) == NULL) {
    home = getpwuid(getuid())->pw_dir;
  }
  return home;
}
}
