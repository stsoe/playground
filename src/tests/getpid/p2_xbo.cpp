#include "xrt/xrt_device.h"
#include "xrt/xrt_bo.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <stdexcept>

int
run(int argc, char* argv[])
{
  if (argc < 3) {
    std::cout << "Usage: p2.exe <pid> <fd>\n";
    return 1;
  }
  
  auto pid = std::stoi(argv[1]);
  auto targetfd = std::stoi(argv[2]);

  std::cout << "p2 input pid: " << pid << "\n";
  std::cout << "p2 input fd: " << targetfd << "\n";

  xrt::device device(0);
  xrt::bo bo(device, pid, targetfd);
  auto bo_map = bo.map<char*>();

  bo.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
  std::cout << "bo: " << bo_map << '\n';

  strncpy(bo_map, "hello from p2", bo.size());
  bo.sync(XCL_BO_SYNC_BO_TO_DEVICE);

  return 0;
}

int
main(int argc, char* argv[])
{
  try {
    return run(argc,argv);
  }
  catch (const std::exception& ex) {
    std::cout << "FAILED: " << ex.what() << '\n';
  }
  return 1;
}

  
