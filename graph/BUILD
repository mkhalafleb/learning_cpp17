cc_test(
    name = "graph_test",
    srcs = ["graph_test.cc"],
    data = [
        "basic_graph",
    ],
    linkopts = ["-lstdc++fs"],
    deps = [
        ":graph",
        "//graphcreator",
        "//node",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "graph",
    srcs = ["graph.cc"],
    hdrs = ["graph.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//node",
    ],
)
