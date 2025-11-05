#include <pybind11/pybind11.h>
// #include <pybind11/stl.h>
// #include <string>

#include "sampling.h"

namespace py = pybind11;

namespace rtp_llm {

PYBIND11_MODULE(binding, m) {
    m.doc() = "sampling";
    m.def("top_p_sampling_from_probs", &top_p_sampling_from_probs, "");
}

}