#include <iostream>
#include "source.cpp"

using namespace std;

int main() {
  Horse *a = new Horse(500);
  Donkey *b = new Donkey(300);
  Mule *c = new Mule(100);
  cout << a->get_weight() << endl;
  cout << b->get_weight() << endl;
  cout << c->get_weight() << endl;
  delete a;
  cout << endl;
  delete b;
  cout << endl;
  delete c;
  cout << endl;
  return 0;
}
