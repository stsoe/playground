#include <sys/syscall.h>
#include <unistd.h>

#include <iostream>
#include <thread>
#include <chrono>

int main(int argc, char* argv[])
{
  if (argc < 3) {
    std::cout << "Usage: p2.exe <pidfd> <fd>\n";
    return 1;
  }

  auto pidfd = std::stoi(argv[1]);
  auto targetfd = std::stoi(argv[2]);

  std::cout << "p2 input pidfd: " << pidfd << "\n";
  std::cout << "p2 input fd: " << targetfd << "\n";

  
  auto fd = syscall(SYS_pidfd_getfd, pidfd, targetfd, 0);
  std::cout << "p2 imported fd: " << fd << "\n";

  while (1) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "1" << std::flush;
  }
  
  close(fd);
}
