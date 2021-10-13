#include <sys/syscall.h>
#include <unistd.h>
#include <fcntl.h>

#include <iostream>
#include <thread>
#include <chrono>

int main()
{
  auto pidfd = syscall(SYS_pidfd_open, getpid(), 0);
  std::cout << "p1 pidfd: " << pidfd << "\n";

  auto fd = open("./p1.data", O_RDWR | O_CREAT);
  std::cout << "p1 fd: " << fd << "\n";

  while (1) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "1" << std::flush;
  }
  
  close(fd);
}
