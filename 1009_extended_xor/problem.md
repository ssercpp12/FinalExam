# Extended XOR
## Description
XOR is an operator for binary numbers which applies an non-carry addition on
two numbers digit by digit. For example, 1010 XOR 0110 = 1100. Now we extend XOR
into m-based numbers. For example, for 5-based number, 40302 XOR 44312 = 34114.
That is, for two m-based digit x and y, x XOR y = (x + y) % m.

Given two m-based numbers with n digits, you can rearrange the number by
swapping any two digits in this number. After rearranging two numbers, you XOR
two numbers and get a new number.

For example, You can rearrange 40302 into 20034 and rearrange 44312 into 24431,
then you get 20034 XOR 24431 = 44410.

Please find the maximum possible number that can be obtained in the previous
step.

## Input
Input data contains multiple test cases.

The first line line contains two integers n, m(1 <= n, m <= 10^5 , m > 1).

The following two line contains n integers each, separated by space. Each
integer is from 0 to m - 1, representing a digit in a number. The digits in the
line are written in the order from the most significant digits to the least
significant ones.

## Output
Print n m-base digits. The resulting number written in the m-based
notation. Print the digits in the order from the most significant digits to the
least significant ones.

Note that no extra spaces should be printed at the end of line.

## Sample Input
```
4 7
5 4 3 2  
5 6 5 4  
5 5  
2 4 4 1 3  
1 0 1 2 4  
```

## Sample Output
```
6 4 2 1  
4 4 4 3 2  
```

## Hint
In first test case, rearrange the two numbers in the follow way:  

2 5 4 3  
4 6 5 5  
result is:  6 4 2 1  

