cc_binary(
    name = "basic",
    srcs = ["basic.cc"],
    deps = [
        ":graph",
        "//node:node",
        "//nodeid:nodeid",
    ],
)


cc_library(
    name = "graph",
    srcs = ["graph.cc"],
    hdrs = ["graph.h"],
    deps = [
        "//node:node",
    ],
)

cc_library(
    name = "graphcreator",
    srcs = ["graphcreator.cc"],
    hdrs = ["graphcreator.h"],
)
