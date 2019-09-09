cc_binary(
  name = "basic",
  srcs = ["basic.cc"],
  deps = [
      ":node",
      ":nodeid",
      ":graph",
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

