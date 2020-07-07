cc_library(
    name = "textreader",
    srcs = ["textreader.cc"],
    hdrs = ["textreader.h"],
    visibility = ["//visibility:public"],
    deps = ["//parsehelp"],
)

cc_test(
    name = "textreader_test",
    srcs = ["textreader_test.cc"],
    data = [
        "basic_list",
        "basic_list_dup",
    ],
    linkopts = ["-lstdc++fs"],
    deps = [
        ":textreader",
        "//parsehelp",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
