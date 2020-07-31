cc_library(
    name = "testutils",
    srcs = ["testutils.cc"],
    hdrs = ["testutils.h"],
    visibility = ["//visibility:public"],
    deps = [
    ],
)

cc_test(
    name = "testutils_test",
    srcs = ["testutils_test.cc"],
    linkopts = ["-lstdc++fs"],
    deps = [
        ":testutils",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
