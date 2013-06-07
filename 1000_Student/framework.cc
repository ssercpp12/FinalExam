#include <iostream>
#include <string>

#include "source.cpp"

int main(int argc, char *argv[]) {
  sysu::Student s(9388223, "ZCB", 23);
  s.setID(9388222);
  s.setName("CB");
  s.setAge(18);
  std::cout << s.getName() << " "
            << s.getID() << " "
            << s.getAge() << std::endl;
  return 0;
}
