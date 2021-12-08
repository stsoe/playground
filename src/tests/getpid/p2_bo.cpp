#include "xrt/xrt_device.h"
#include "xrt/xrt_bo.h"

#include <sys/syscall.h>
#include <unistd.h>
#include <fcntl.h>

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

  auto pidfd = syscall(SYS_pidfd_open, pid, 0);
  if (pidfd < 0)
    throw std::runtime_error("pidfd_open failed: " + std::to_string(errno));
    
  std::cout << "p2 pidfd(" << pid << "): " << pidfd << "\n";
  
  auto fd = syscall(SYS_pidfd_getfd, pidfd, targetfd, 0);
  if (fd < 0)
    throw std::runtime_error("pidfd_getfd failed: " + std::to_string(errno));

  std::cout << "p2 imported fd: " << fd << "\n";

  xrt::device device(0);
  xrt::bo bo(device, fd);

  auto bo_map = bo.map<char*>();


  bo.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
  std::cout << "bo: " << bo_map << '\n';

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

  
