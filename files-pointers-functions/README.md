# Modularization
Modularization is a software design technique that involves breaking a program into smaller, independent modules or components. This can make a program easier to understand, maintain, and modify.

In C, modularization is typically achieved using functions. A function is a block of code that performs a specific task and can be called from other parts of the program. By dividing a program into smaller, independent functions, you can make the program more modular and easier to understand.

To create a function in C, you use the `function` keyword, followed by the function name, the parameter list enclosed in parentheses, and the function body enclosed in braces. For example:

```C
void print_message() {
  printf("Hello, world!\n");
}
```

This is a simple function named print_message that does not take any arguments and does not return a value. It simply prints a message to the screen using the printf function.

To call a function from another part of your program, you use the function name followed by the argument list enclosed in parentheses. For example:
```C
int main() {
  print_message();
  return 0;
}
```

In this code, we have defined the print_message function and then called it from the main function. When the program is run, this will print the message "Hello, world!" to the screen.

Functions can also take arguments and return values. For example:
```C
int sum(int a, int b) {
  return a + b;
}
```
This is a function named sum that takes two integer arguments, a and b, and returns the sum of these values. To call this function and get the sum of two numbers, you can use code like this:
```C
int main() {
  int x = 3, y = 4;
  int result = sum(x, y);
  printf("The sum of %d and %d: %d",x,y,result);
```
