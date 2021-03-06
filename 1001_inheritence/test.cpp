#include <iostream>

class A {
  public:
    A(int x) {std::cout << "A: " << x << std::endl;}
    ~A() {std::cout << "A destructed" << std::endl;}
};

class B {
  public:
    B(int y) {std::cout << "B: " << y << std::endl;}
    ~B() {std::cout << "B destructed" << std::endl;}
};

class C : public B, public A {
  public:
    C(int x, int y, int z) : A(x), B(y) {std::cout << "C: " << z << std::endl;}
    ~C() {std::cout << "C destructed" << std::endl;}
};

int main(int argc, const char *argv[]) {
  C *c = new C(3, 4, 5);
  delete c;
  return 0;
}
