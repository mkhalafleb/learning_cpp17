cc_binary(
  name = "basic",
  srcs = ["basic.cc"],
  deps = [
      ":node",
      ":nodeid",
      ":graph",
  ],
)



cc_test(
  name = "nodeid_test",
  srcs = ["nodeid_test.cc"],
  deps = [
      "@gtest//:gtest",
      "@gtest//:gtest_main",
      ":nodeid",
  ],
)

cc_test(
  name = "node_test",
  srcs = ["node_test.cc"],
  deps = [
      "@gtest//:gtest",
      "@gtest//:gtest_main",
      ":node",
  ],
)

cc_library(
  name = "node",
  srcs = ["node.cc"],
  hdrs = ["node.h"],
  deps = [":nodeid",
  ],
)

cc_library(
  name = "nodeid",
  srcs = ["nodeid.cc"],
  hdrs = ["nodeid.h"],
)

cc_library(
  name = "graph",
  srcs = ["graph.cc"],
  hdrs = ["graph.h"],
  deps = [":node",
  ],
)

cc_library(
  name = "graphcreator",
  srcs = ["graphcreator.cc"],
  hdrs = ["graphcreator.h"],
)

cc_library(
  name = "textreader",
  srcs = ["textreader.cc"],
  hdrs = ["textreader.h",
          "parsehelp.h",
          ],
  deps = [":parsehelp",],
)

cc_library(
  name = "parsehelp",
  srcs = ["parsehelp.cc"],
  hdrs = ["parsehelp.h"],
)

cc_test(
  name = "textreader_test",
  srcs = ["textreader_test.cc"],
  deps = [
      "@gtest//:gtest",
      "@gtest//:gtest_main",
      ":textreader",
      ":parsehelp",
  ],
  data = ["Hello"],
)

cc_test(
  name = "parsehelp_test",
  srcs = ["parsehelp_test.cc"],
  deps = [
      "@gtest//:gtest",
      "@gtest//:gtest_main",
      ":parsehelp",
  ],
)


