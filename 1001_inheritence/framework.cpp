#include <iostream>
#include "source.cpp"

int main(int argc, const char *argv[]) {
  A* ptr = new C(3, 4, 5);
  delete ptr;
  return 0;
}
