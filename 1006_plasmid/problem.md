# Plasmid
## Description
Plasmid(质粒) can be treated as a connection of different components. Components
can be protein(蛋白质), DNA or RNA. A plasmid starts with a prefix(前缀), then a certain 
components connected by a intervening sequence(间隔序列), finally a suffix(后缀).
Furthermore, plasmid can be assembled by multiple rules, for instance, RFC10 and RFC25.
Each rule defines its own prefix, suffix, intervening sequence and some special
rules.

RFC10 assembles components in such way:

1. If the first component is DNA or RNA, then prefix is
   "GATACAG".
2. If the first component is protein, the prefix is "GATAG"
3. The intervening sequence is "TACTAGAG".
4. The suffix is "TACGCAG".

RFC25 assembles components in such way:

1. The prefix is "GAACGGC".
2. The intervening sequence is "ACCGGC".
3. The suffix is "ACCGCAG".
4. If the component is protein, add sequence "GAACTAG" right before the
   component(after prefix or intervening sequence).

> for simplicity, the sequences above are shortened than real-world ones.

Given class Component and class Plasmid, your work is to write class RFC10 and
class RFC25, which are derived from class Plasmid.

Please submit everything except the main function.

```
enum TYPE {  
  PROTEIN,  
  DNA,  
  RNA  
};  
```

```
struct Component {  
  Component(string s, TYPE t) {  
    sequence = s;  
    type = t;  
  }  
  string sequence;  
  TYPE type;  
};  
```

```
class Plasmid {  
  public:  
    virtual void add_component(Component&) = 0; // add component to plasmid  
    virtual void add_suffix() = 0; // add suffix to the plasmid  
    string get_sequences() const; // return the sequences of the plasmid  
  protected:  
    string sequences; // sequence of plasmid  
    int count; // the amount of components that have been added to plasmid  
};  
```

## Sample Input
```
  Plasmid *a = new RFC10();  
  // For debugging purposes, the letters in sequence of component are all  
  // lowercase. You DO NOT need to make any changes to these letters.  
  Component x("aaaa", PROTEIN);  
  Component y("gggg", DNA);  
  a->add_component(x);  
  cout << a->get_sequences() << endl;  
  a->add_component(y);  
  cout << a->get_sequences() << endl;  
  a->add_suffix();  
  cout << a->get_sequences() << endl;  
```

```
  Plasmid *b = new RFC25();  
  b->add_component(x);  
  cout << b->get_sequences() << endl;  
  b->add_component(y);  
  cout << b->get_sequences() << endl;  
  b->add_suffix();  
  cout << b->get_sequences() << endl;  
```

## Sample Output
```
GATAGaaaa  
GATAGaaaaTACTAGAGgggg  
GATAGaaaaTACTAGAGggggTACGCAG  
GAACGGCGAACTAGaaaa  
GAACGGCGAACTAGaaaaACCGGCgggg  
GAACGGCGAACTAGaaaaACCGGCggggACCGCAG  
```
