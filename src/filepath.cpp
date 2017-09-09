#include <iostream>
#include <locale>
#include <osutils/filepath.hpp>

OSUTILS_NS_BEGIN

namespace internal {

#define SEPARATOR "/"

class filepath_private {
public:
  filepath_private() {}

  void validate();

  std::string path;
  bool is_valid = false;
};

void filepath_private::validate() {
  is_valid = false;
  char l = 0;
  for (auto c : path) {
    if (!(std::isalnum(c) || c == '/')) {
      return;
    }
    if (c == '/' && c == l) {
      return;
    }
    l = c;
  }

  is_valid = true;
}

} // namespace internal

filepath::filepath(const std::string &p) : d(new internal::filepath_private()) {
  d->path = p;
  d->validate();
}

filepath::filepath(const filepath &other) : d(new internal::filepath_private) {
  d->path = other.d->path;
}

filepath::~filepath() {}

static int last_index_of(const std::string &path, const char *sep) {
  int i = -1;
  std::string::size_type loc = path.find(SEPARATOR, ++i);
  while (loc != std::string::npos) {
    loc = path.find(SEPARATOR, ++i);
  }
  return i;
}

std::string filepath::dir() const {
  auto i = last_index_of(d->path, SEPARATOR);
  if (!i || i == -1) {
    if (d->path[0] == '/')
      return SEPARATOR;
    return ".";
  }

  return d->path.substr(0, i - 1);
}

std::string filepath::filename() const {
  int i = 0;
  std::string::size_type loc = d->path.find(SEPARATOR, i);
  while (loc != std::string::npos) {
    loc = d->path.find(SEPARATOR, ++i);
  }

  return d->path.substr(i);
}

bool filepath::is_valid() const { return d->is_valid; }

filepath &filepath::push(const std::string &p) {
  if (p.length() == 0 || p == SEPARATOR) {
    return *this;
  }

  if (!((d->path[d->path.length() - 1]) == '/' || p[0] == '/')) {
    d->path.append(SEPARATOR);
  }
  d->path.append(p);
  return *this;
}

filepath &filepath::pop() {
  if (d->path == "/" || d->path == "")
    return *this;

  d->path = dir();

  return *this;
}

filepath filepath::join(const filepath &p, const filepath &p2) {}

filepath filepath::resolve(const std::string &p) {}

std::ostream &operator<<(std::ostream &stream, const filepath &path) {
  stream << path.d->path;
  return stream;
}

bool filepath::operator==(const filepath &other) {}

OSUTILS_NS_END
