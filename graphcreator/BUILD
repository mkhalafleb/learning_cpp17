cc_library(
    name = "graphcreator",
    srcs = ["graphcreator.cc"],
    hdrs = ["graphcreator.h"],
    deps = ["//:graph"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "graphcreator_test",
    srcs = ["graphcreator_test.cc"],
    deps = [
        ":graphcreator",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
