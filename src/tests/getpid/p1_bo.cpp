#include "xrt/xrt_bo.h"
#include "xrt/xrt_device.h"
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
  auto pid = getpid();
  std::cout << "p1 pid: " << pid << "\n";

  xrt::device device(0);
  xrt::bo bo(device, 4096, xrt::bo::flags::cacheable, 1);

  auto bo_map = bo.map<char*>();
  strcpy(bo_map, "hello from p1");
  bo.sync(XCL_BO_SYNC_BO_TO_DEVICE);

  auto ehdl = bo.export_buffer();
  std::cout << "p1 bo fd: " << ehdl << '\n';

  while (1) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "1" << std::flush;
  }
}
