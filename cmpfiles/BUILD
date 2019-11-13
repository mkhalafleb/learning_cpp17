cc_library(
    name = "cmpfiles",
    srcs = ["cmpfiles.cc"],
    hdrs = ["cmpfiles.h"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "cmpfiles_test",
    srcs = ["cmpfiles_test.cc"],
    data = ["basic_list",
            "basic_list_dup",
           ],
    linkopts = ["-lstdc++fs"],
    deps = [
        ":cmpfiles",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
