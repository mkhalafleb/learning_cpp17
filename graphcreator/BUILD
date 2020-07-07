cc_library(
    name = "graphcreator",
    srcs = ["graphcreator.cc"],
    hdrs = ["graphcreator.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//fixadjacency",
        "//graph",
        "//node",
        "//textreader",
    ],
)

cc_test(
    name = "graphcreator_test",
    srcs = ["graphcreator_test.cc"],
    data = ["basic_graph"],
    linkopts = ["-lstdc++fs"],
    deps = [
        ":graphcreator",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
