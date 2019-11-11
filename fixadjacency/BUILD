cc_library(
    name = "fixadjacency",
    srcs = ["fixadjacency.cc"],
    hdrs = ["fixadjacency.h"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "fixadjacency_test",
    srcs = ["fixadjacency_test.cc"],
    deps = [
        ":fixadjacency",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
