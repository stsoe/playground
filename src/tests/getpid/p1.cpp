#include <sys/syscall.h>
#include <unistd.h>
#include <fcntl.h>

#include <iostream>
#include <thread>
#include <chrono>

int main()
{
  auto pid = getpid();
  std::cout << "p1 pid: " << pid << "\n";

  {
    auto fd = open("./p1.data", O_RDWR | O_CREAT);

    // write some data to fd
    std::string str("hello from p1");
    write(fd, str.data(), str.size());
    close(fd);
  }

  auto fd = open("./p1.data", O_RDWR | O_CREAT);
  std::cout << "p1 fd: " << fd << "\n";
  while (1) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "1" << std::flush;
  }
  
  close(fd);
}
