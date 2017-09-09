#include <osutils/directories.hpp>
#include <pwd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

namespace osutils {

static const char *const HOME_ENV = "HOME";
static const char *const TMP_ENV[] = {"TMPDIR", "TMP", "TEMP", "TEMPDIR"};
static const char *const TMP_DEFAULT = "/tmp";
static const int TMP_ENV_LEN = 4; 

const char *home_dir() {
  const char *home;
  if ((home = getenv(HOME_ENV)) == NULL) {
    home = getpwuid(getuid())->pw_dir;
  }
  return home;
}

const char *tmp_dir() {
  const char *tmp = NULL;
  for (int i = 0; i < TMP_ENV_LEN; i++) {
    if ((tmp = getenv(TMP_ENV[i])) != NULL) {
      break;
    }
  }
  if (tmp == NULL) tmp = TMP_DEFAULT;
  return tmp;
}


}
