cc_binary(
  name = "basic",
  srcs = ["basic.cc"],
  deps = [
      ":node",
      ":nodeid",
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

