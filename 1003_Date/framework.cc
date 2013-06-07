#include <iostream>
using namespace std;

#include "source.cpp"

int main(int argc, char *argv[]) {
  Date d(2013, 5, 25);
  cout << d++ << endl;
  cout << d << endl;

  Date d2(2013, 2, 28);
  cout << ++d2 << endl;

  Date d3(2012, 12, 30);
  d3++;
  cout << d3 << endl;
  ++d3;
  cout << d3 << endl;

  Date d4(2012, 2, 28);
  d4++;
  d4++;
  cout << d4 << endl;

  cout << d2 << endl;
  cout << d3 << endl;
  cout << (d2 != d3) << endl;
  cout << (d2 == d3) << endl;
  cout << (d2 > d3) << endl;
  cout << (d2 < d3) << endl;

  return 0;
}
