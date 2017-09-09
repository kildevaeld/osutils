#pragma once
#include "defines.hpp"
#include <memory>
#include <string>

OSUTILS_NS_BEGIN

namespace internal {
class filepath_private;
}

struct filepath {

public:
  filepath(const std::string &p);
  filepath(const filepath &other);

  ~filepath();

  std::string dir() const;
  std::string filename() const;

  bool is_valid() const;

  filepath &push(const std::string &p);
  filepath &pop();

  static filepath join(const filepath &p, const filepath &p2);
  static filepath resolve(const std::string &p);
  friend std::ostream &operator<<(std::ostream &stream, const filepath &path);

  bool operator==(const filepath &other);

private:
  std::unique_ptr<internal::filepath_private> d;
};

OSUTILS_NS_END
