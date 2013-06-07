# Frequency
## Description
We are all curious about the words we use in our daily life. Now you are asked
to take statistics about the frequency of the word we use. Your work is to
collect sentences given by others and calculate frequency of each word. To
simplify your work, it's guaranteed that there will only be lowercase letters
and spaces in a sentence. You also need to implement a function to get the most
common word of all the words. If there are no words in the counter, just print
"No nords yet!". Operator<< is overloaded to print all words in the
counter. Please print all the words in lexicographical order.
Given the definition of the class, please implement it.

```
class Counter {  
  public:  
    void add_sentence(string str);  
    int operator[](string word);  
    string get_most_common();  
    friend ostream& operator<<(ostream& out, Counter c);  
  private:  
    // add any members you need!  
};  
```

## Sample Input
```
  Counter a;  
  std::cout << a.get_most_common() << std::endl;  
  a.add_sentence("to be or not to be");  
  std::cout << a["to"] << std::endl;  
  std::cout << a["not"] << std::endl;  
  std::cout << a["py"] << std::endl;  
  std::cout << a.get_most_common() << std::endl;  
  a.add_sentence(" that is not a question");  
  std::cout << a["not"] << std::endl;  
  a.add_sentence("that that");  
  std::cout << a.get_most_common() << std::endl;  
  std::cout << a;  
```

## Sample Output
```
No words yet!  
2  
1  
0  
to  
2  
that  
a : 1  
be : 2  
is : 1  
not : 2  
or : 1  
question : 1  
that : 3  
to : 2  
```
