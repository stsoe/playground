#include <iostream>
#include <string>

static std::string
get_msg()
{
  std::string msg('a',10);
  return msg;
}

int main()
{
  std::cout << "hello" << '\n';
  std::cout << "msg" << get_msg() << '\n';
  return 0;
}
