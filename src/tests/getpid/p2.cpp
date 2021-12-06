#include <sys/syscall.h>
#include <unistd.h>
#include <fcntl.h>

#include <iostream>
#include <thread>
#include <chrono>

int main(int argc, char* argv[])
{
  if (argc < 3) {
    std::cout << "Usage: p2.exe <pid> <fd>\n";
    return 1;
  }
  
  auto fd_local = open("./p2.data", O_RDWR | O_CREAT);

  auto pid = std::stoi(argv[1]);
  auto targetfd = std::stoi(argv[2]);

  std::cout << "p2 input pid: " << pid << "\n";
  std::cout << "p2 input fd: " << targetfd << "\n";

  auto pidfd = syscall(SYS_pidfd_open, pid, 0);
  std::cout << "p2 pidfd(" << pid << "): " << pidfd << "\n";
  
  auto fd = syscall(SYS_pidfd_getfd, pidfd, targetfd, 0);
  std::cout << "p2 imported fd: " << fd << "\n";

  char buf[128] = {0};
  while (read(fd, buf, 128)) {
    std::cout << "buf: " << buf << std::flush;
  }
  
  close(fd);
  close(fd_local);
}
