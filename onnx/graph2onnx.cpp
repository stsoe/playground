#include "graph2onnx.h"
#include "onnx.proto3.pb.h"

#include <fstream>
#include <string>

using onnx_model = ::onnx::ModelProto;

static onnx_model
graph2onnx()
{
  onnx_model model;
  return model;
}

void
write_onnx(const std::string& filename)
{
  auto model = graph2onnx();

  std::ofstream ofs(filename, std::ios::binary);
  if (!model.SerializeToOstream(&ofs))
    throw std::runtime_error("Failed to write onnx model to file: " + filename);
}

