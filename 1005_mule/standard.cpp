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
