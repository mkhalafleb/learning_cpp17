
cc_library(
  name = "textreader",
  srcs = ["textreader.cc"],
  hdrs = ["textreader.h" ],
  deps = ["//parsehelp:parsehelp",],
  visibility = ["//visibility:public"],
)


cc_test(
  name = "textreader_test",
  srcs = ["textreader_test.cc"],
  deps = [
      "@gtest//:gtest",
      "@gtest//:gtest_main",
      ":textreader",
      "//parsehelp:parsehelp",
  ],
  data = ["Hello"],
  linkopts = ["-lstdc++fs"],
)

