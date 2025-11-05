load("//:def.bzl", "rocm_copts",)
load("//bazel:arch_select.bzl", "torch_deps")

cc_library(
    name = "sampling",
    srcs = [
        "api.cc",
        # "kernel.cuh",
    ],
    deps = [
        "@local_config_rocm//rocm:rocm_headers",
    ] + torch_deps(),
    copts = rocm_copts() + ["-DUSE_ROCM=1"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "binding.so",
    srcs = [
        "binding.cc"
        "sampling.h",
    ],
    deps = [
        ":sampling",
        "//rtp_llm/cpp/pybind:py_utils",
    ],
    linkstatic = False,
    # features = ["-use_header_modules"],  # 避免模块化编译问题
    visibility = ["//visibility:public"],
)