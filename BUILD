cc_binary(
    name = "basic",
    srcs = ["basic.cc"],
    linkopts = ["-lstdc++fs"],
    deps = [
        ":graph",
        "//graphcreator:graphcreator",
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
    visibility = ["//visibility:public"],
)

