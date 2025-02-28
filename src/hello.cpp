#include <iostream>
#include <string>

class X
{
  std::string m_string;
public:
  X(const std::string& str) : m_string(str) {}

  const std::string
  get_string()
  {
    return m_string;
  }
};

const std::string hello()
{
  std::string str = "hello";
  X x(str);
  return x.get_string();
}

int main()
{
  std::cout << hello() << std::endl;
  return 0;
}
