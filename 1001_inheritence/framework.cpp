#include <iostream>
#include "source.cpp"

int main(int argc, const char *argv[]) {
  C *c = new C(3, 4, 5);
  delete c;
  return 0;
}
