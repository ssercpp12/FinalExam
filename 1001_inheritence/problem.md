# Inheritence
## Description
Watch the following code.

```
int main(int argc, const char *argv[]) {
  A* ptr = new C(3, 4, 5);
  delete ptr;
  return 0;
}
```

It will print output like this.

```
B: 4  
A: 3  
C: 5  
C destructed  
A destructed  
B destructed  
```

Please implement class A, B and C.
