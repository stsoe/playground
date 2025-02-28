#include <iostream>
#include <string>

class X
{
  std::string m_string;
public:
  X(const std::string& str) : m_string(str) {}

  std::string
  get_string()
  {
    return m_string;
  }
};

std::string hello()
{
  std::string const str = "hello";
  X x(str);
  return x.get_string();
}

int main()
{
  std::cout << hello() << '\n';
  return 0;
}
