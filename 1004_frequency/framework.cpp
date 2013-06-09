#include <string>
#include <iostream>
#include "standard.cpp"

using namespace std;

int main(int argc, const char *argv[]) {
  Counter a;  
  std::cout << a.get_most_common() << std::endl;  
  a.add_sentence("to be or not to be");  
  std::cout << a["to"] << std::endl;  
  std::cout << a["not"] << std::endl;  
  std::cout << a["py"] << std::endl;  
  std::cout << a.get_most_common() << std::endl;  
  a.add_sentence("that is not a question");  
  std::cout << a["not"] << std::endl;  
  a.add_sentence("that that");  
  std::cout << a.get_most_common() << std::endl;  
  std::cout << a;  
  return 0;
}
