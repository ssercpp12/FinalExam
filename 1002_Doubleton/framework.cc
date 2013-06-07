#include <iostream>
using namespace std;

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

class Doubleton {
 public:
  // Return the instances[0] and instances[1] alternately. For example, the
  // first time calling will return instances[0], the second will return 
  // instances[1], the third will return instances[0]... and so on.
  static Doubleton* getInstance();
  void foo();

 private:
  friend class AtExit;
  static Doubleton* instances[2];
  static int counter;
  static void deleteInstances();

  Doubleton(int id);
  DISALLOW_COPY_AND_ASSIGN(Doubleton);
  int id_;
};

void Doubleton::foo() {
  cout << id_ << endl;
}

// Your submitted code will be pasted here.
#include "source.cpp"

class AtExit {
 public:
  AtExit() {}
  ~AtExit() {
    Doubleton::deleteInstances();
  }
};

int main(int argc, char *argv[]) {
  AtExit a;
  for (int i = 0; i < 10; ++i) {
    Doubleton::getInstance()->foo();
  }
  return 0;
}
