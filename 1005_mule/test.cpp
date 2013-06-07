#include <iostream>
using namespace std;

class Animal {
  public:
    Animal() {
    }
    Animal(int weight);
    int get_weight();
    ~Animal() {
      cout << "Animal destructed!" << endl;
    }
  protected:
    int weight_;
};

Animal::Animal(int weight) {
  weight_ = weight;
}

int Animal::get_weight() {
  return weight_;
}

class Horse: virtual public Animal {
  public:
    Horse() {}
    Horse(int weight);
    ~Horse() {
      cout << "Horse destructed!" << endl;
    }
};

Horse::Horse(int weight) : Animal(weight) {}

class Donkey: virtual public Animal {
  public:
    Donkey() {}
    Donkey(int weight);
    ~Donkey() {
      cout << "Donkey destructed!" << endl;
    }
};

Donkey::Donkey(int weight) : Animal(weight) {}

class Mule: public Horse, public Donkey {
  public:
    Mule(int weight);
    ~Mule() {
      cout << "Mule destructed!" << endl;
    }
};

Mule::Mule(int weight) : Animal(weight) {}

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
