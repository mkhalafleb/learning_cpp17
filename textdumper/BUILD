cc_library(
    name = "textdumper",
    srcs = ["textdumper.cc"],
    hdrs = ["textdumper.h"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "textdumper_test",
    srcs = ["textdumper_test.cc"],
    data = ["basic_list"],
    linkopts = ["-lstdc++fs"],
    deps = [
        ":textdumper",
        "//cmpfiles",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
