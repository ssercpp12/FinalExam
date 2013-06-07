#include <iostream>
using namespace std;

#include "source.cpp"

class DeletionTest {
 public:
  explicit DeletionTest(bool* deletion_flag) : deletion_flag_(deletion_flag) {
    *deletion_flag_ = false;
  }
  
  ~DeletionTest() {
    *deletion_flag_ = true;
  }

  void foo() {
    cout << "foo" << endl;
  }

 private:
  bool* deletion_flag_;
};

int main(int argc, char *argv[]) {
  // Test deletion, get and operatro->, *.
  {
    bool isDeleted = false;
    {
      scoped_ptr<DeletionTest> d(new DeletionTest(&isDeleted));
      d.get()->foo();
      d->foo();
      (*d).foo();
    }
    cout << isDeleted << endl;
  }

  // Reset test
  {
    int *p = new int;
    scoped_ptr<int> sp(p);
    *sp = 100;
    sp.reset(p);
    cout << (*p == 100) << endl;
  }

  {
    bool isDeleted = false;
    {
      bool stuff = false;
      scoped_ptr<DeletionTest> d(new DeletionTest(&isDeleted));
      d.reset(new DeletionTest(&stuff));
      cout << isDeleted << endl;
    }
  }

  return 0;
}
