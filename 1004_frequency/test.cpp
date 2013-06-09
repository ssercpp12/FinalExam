#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Counter {
  public:
    void add_sentence(string str);
    int operator[](string word);
    string get_most_common();
    friend ostream& operator<<(ostream& out, Counter c);
  private:
    map<string, int> frequency_;
};

void Counter::add_sentence(string str) {
  stringstream stream(str);
  string word;
  while (getline(stream, word, ' ')) {
    if (word == "")
      continue;
    if (frequency_.find(word) != frequency_.end())
      frequency_[word]++;
    else
      frequency_.insert(make_pair(word, 1));
  }
}

int Counter::operator[](string word) {
  if (frequency_.find(word) != frequency_.end())
    return frequency_[word];
  else
    return 0;
}

string Counter::get_most_common() {
  int maxl = -1;
  string ret = "No words yet!";
  for (map<string, int>::iterator it = frequency_.begin();
      it != frequency_.end(); it++)
    if (it->second > maxl) {
      maxl = it->second;
      ret = it->first;
    }
  return ret;
}

ostream& operator<<(ostream& out, Counter c) {
  for (map<string, int>::iterator it = c.frequency_.begin();
      it != c.frequency_.end(); it++)
    out << it->first << " : " << it->second << std::endl;
  return out;

}
int main(int argc, const char *argv[]) {
  Counter a;  
  std::cout << a.get_most_common() << std::endl;  
  a.add_sentence("to be or not to be");  
  std::cout << a["to"] << std::endl;  
  std::cout << a["not"] << std::endl;  
  std::cout << a["py"] << std::endl;  
  std::cout << a.get_most_common() << std::endl;  
  a.add_sentence("     that is not a question");  
  std::cout << a["not"] << std::endl;  
  a.add_sentence("that that");  
  std::cout << a.get_most_common() << std::endl;  
  std::cout << a;  
  return 0;
}
