cc_library(
    name = "algorithm",
    srcs = ["algorithm.cc"],
    hdrs = ["algorithm.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//graph",
        "//node",
        "//nodeid",
    ],
)

cc_test(
    name = "algorithm_test",
    srcs = ["algorithm_test.cc"],
    data = ["basic_graph"],
    linkopts = ["-lstdc++fs"],
    deps = [
        ":algorithm",
        "//graph",
        "//graphcreator",
        "//testutils",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
