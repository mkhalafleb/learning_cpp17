cc_library(
    name = "textreader",
    srcs = ["textreader.cc"],
    hdrs = ["textreader.h"],
    visibility = ["//visibility:public"],
    deps = ["//parsehelp:parsehelp"],
)

cc_test(
    name = "textreader_test",
    srcs = ["textreader_test.cc"],
    data = ["Hello"],
    linkopts = ["-lstdc++fs"],
    deps = [
        ":textreader",
        "//parsehelp:parsehelp",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
