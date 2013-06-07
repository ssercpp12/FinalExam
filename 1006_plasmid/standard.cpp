#include <iostream>
using namespace std;

enum TYPE {
  PROTEIN,
  DNA,
  RNA
};

struct Component {
  Component(string s, TYPE t) {
    sequence = s;
    type = t;
  }
  string sequence;
  TYPE type;
};

class Plasmid {
  public:
    virtual void add_component(Component&) = 0; // add component to plasmid
    virtual void add_suffix() = 0; // add suffix to the plasmid
    string get_sequences() const {
      return sequences;
    }
  protected:
    string sequences; // sequence of plasmid
    int count; // the amount of components that have been added to plasmid
};

class RFC10 : public Plasmid {
  public:
    RFC10() {
      sequences = "GATACAG";
      count = 0;
    }
    void add_component(Component& c) {
      if (count != 0)
        sequences += "TACTAGAG";
      else
        if (c.type == PROTEIN)
          sequences = "GATAG";
      sequences += c.sequence;
      count++;
    }
    void add_suffix() {
      sequences += "TACGCAG";
    }
};

class RFC25 : public Plasmid {
  public:
    RFC25() {
      sequences = "GAACGGC";
      count = 0;
    }
    void add_component(Component& c) {
      if (count != 0)
        sequences += "ACCGGC";
      if (c.type == PROTEIN)
        sequences += "GAACTAG";
      sequences += c.sequence;
      count++;
    }
    void add_suffix() {
      sequences += "ACCGCAG";
    }
};
