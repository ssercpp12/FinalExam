#include <iostream>

class A {
  public:
    A(int x) {std::cout << "A: " << x << std::endl;}
    virtual ~A() {std::cout << "A destructed" << std::endl;}
};

class B {
  public:
    B(int y) {std::cout << "B: " << y << std::endl;}
    virtual ~B() {std::cout << "B destructed" << std::endl;}
};

class C : public B, public A {
  public:
    C(int x, int y, int z) : A(x), B(y) {std::cout << "C: " << z << std::endl;}
    ~C() {std::cout << "C destructed" << std::endl;}
};
