#include <iostream>
#include "source.cpp"
using namespace std;

int main() {
  Plasmid *a = new RFC10();
  Component x("aaaa", PROTEIN);
  Component y("gggg", DNA);
  a->add_component(x);
  cout << a->get_sequences() << endl;
  a->add_component(y);
  cout << a->get_sequences() << endl;
  a->add_suffix();
  cout << a->get_sequences() << endl;

  Plasmid *b = new RFC25();
  b->add_component(x);
  cout << b->get_sequences() << endl;
  b->add_component(y);
  cout << b->get_sequences() << endl;
  b->add_suffix();
  cout << b->get_sequences() << endl;
}
