#include "testutils.h"
#include <filesystem>

namespace testutils {

std::string FullPath(const std::string &dirpath, const std::string &endpath) {
  std::filesystem::path basepath = std::getenv("TEST_SRCDIR");
  basepath /= std::filesystem::path(std::getenv("TEST_WORKSPACE"));
  basepath /= std::filesystem::path(dirpath);
  basepath /= std::filesystem::path(endpath);
  return (basepath.string());
};

} // namespace testutils
