cc_library(
    name = "textdumper",
    srcs = ["textdumper.cc"],
    hdrs = ["textdumper.h"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "textdumper_test",
    srcs = ["textdumper_test.cc"],
    linkopts = ["-lstdc++fs"],
    data = ["basic_list"],
    deps = [
        ":textdumper",
        "//cmpfiles:cmpfiles", 
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

