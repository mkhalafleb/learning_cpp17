cc_library(
    name = "parsehelp",
    srcs = ["parsehelp.cc"],
    hdrs = ["parsehelp.h"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "parsehelp_test",
    srcs = ["parsehelp_test.cc"],
    deps = [
        ":parsehelp",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
