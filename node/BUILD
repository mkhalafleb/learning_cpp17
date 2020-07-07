cc_test(
    name = "node_test",
    srcs = ["node_test.cc"],
    deps = [
        ":node",
        "//nodeid",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "node",
    srcs = ["node.cc"],
    hdrs = ["node.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//nodeid",
    ],
)
