cc_test(
    name = "nodeid_test",
    srcs = ["nodeid_test.cc"],
    deps = [
        ":nodeid",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "nodeid",
    srcs = ["nodeid.cc"],
    hdrs = ["nodeid.h"],
    visibility = ["//visibility:public"],
)
