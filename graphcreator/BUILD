cc_library(
    name = "graphcreator",
    srcs = ["graphcreator.cc"],
    hdrs = ["graphcreator.h"],
    deps = ["//:graph",
            "//textreader:textreader",
            "//fixadjacency:fixadjacency",
            "//node:node",
           ],
    visibility = ["//visibility:public"],
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
