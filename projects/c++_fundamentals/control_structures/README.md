# Control Structures

## Overview

Control structures control the flow of a program's execution based on certain conditions or loops. The three main types of control structures in C++ are:

1. Sequence Structure
2. Selection Structure (also known as conditional or decision-making structures)
3. Loop Structure (also known as iteration)

Since we're already familiar with the basic sequence structure from the Syntax and Data Types section (where the code executes line by line in a sequential manner), we'll focus on selection and loop structures.

### **Selection Structures**

Selection structures allow your program to make decisions and execute different blocks of code based on certain conditions. The primary selection structures in C++ are `if`, `if-else`, and `switch` statements.

**If Statement**

```cpp
int a = 10;
if (a > 5) {
    std::cout << "a is greater than 5";
}
```

**If-Else Statement**

```cpp
  int a = 10;
  if (a > 15) {
      std::cout << "a is greater than 15";
  } else {
      std::cout << "a is not greater than 15";
  }
```

**Switch Statement**

```cpp
  int a = 2;
  switch (a) {
    case 1:
      std::cout << "a is 1";
      break;
    case 2:
      std::cout << "a is 2";
      break;
    default:
      std::cout << "a is not 1 or 2";
      break;
  }
```

### **Loop Structures**

Loop structures allow your program to execute a block of code multiple times. The primary loop structures in C++ are `for`, `while`, and `do-while` loops.

**For Loop**

```cpp
  for (int i = 0; i < 10; i++) {
      std::cout << "i is " << i << std::endl;
  }
```

**While Loop**

```cpp
  int i = 0;
  while (i < 10) {
    std::cout << "i is " << i << std::endl;
    i++;
  }
```

**Do-While Loop**

```cpp
  int i = 0;
  do {
    std::cout << "i is " << i << std::endl;
    i++;
  } while (i < 10);
```

### **Advanced Topics**

Beyond the basics of selection and loop structures, there are a few more advanced topics that you might find useful:

1. **Nested Control Structures**: Control structures can be nested within each other. For instance, you can have an `if` statement inside a `for` loop, or a `for` loop inside a `while` loop, etc. This allows for more complex logic and behavior in your programs.

```cpp
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      std::cout << i << " is even." << std::endl;
    } else {
      std::cout << i << " is odd." << std::endl;
    }
  }
```

2. **Ternary Operator (`?:`)**:This is a shorthand way of writing simple `if-else` statements. The syntax is `condition ? value_if_true : value_if_false`.

```cpp
  int a = 10;
  std::string result = (a > 5) ? "a is greater than 5" : "a is not greater than 5";
  std::cout << result << std::endl;
```

3. **Break and Continue**:These statements are used to control the flow of loops. `break` immediately exits the loop, while `continue` skips the rest of the current iteration and moves on to the next one.

```cpp
  for (int i = 0; i < 10; i++) {
    if (i == 5) break; // This will stop the loop when i equals 5
    std::cout << i << std::endl;
  }

  for (int i = 0; i < 10; i++) {
    if (i == 5) continue; // This will skip the iteration when i equals 5
    std::cout << i << std::endl;
  }
```

4. **Switch-Case Default**:In a switch-case structure, the `default` case is executed when none of the other cases match.

```cpp
  int a = 3;
  switch (a) {
    case 1: std::cout << "a is 1"; break;
    case 2: std::cout << "a is 2"; break;
    default: std::cout << "a is neither 1 nor 2"; break;
  }
```

- **Note**: `std::endl` is a manipulator in C++ that inserts a newline character into the output stream and flushes the stream. It's often used with `std::cout` to create line breaks in the output.

  Here's an example:

  ```cpp
    std::cout << "Hello" << std::endl << "World!" << std::endl;
  ```

  ```
    Hello
    World!
  ```

  The `<<` operator is known as the insertion or put-to operator. When used with `std::cout`, it inserts the data that follows it into the output stream. This is why you often see multiple `<<` operators in a single line with `std::cout` -- each one is used to insert a different piece of data (a variable, a string, a number, `std::endl`, etc.) into the output.

  For example, in this line of code:

  ```cpp
    std::cout << "Hello, " << "World!" << std::endl;
  ```

  The first `<<` inserts the string `"Hello, "` into the output stream. The second `<<` inserts another string `"World!"`, and the third `<<` inserts `std::endl`, which creates a line break. So, this line of code would output `Hello, World!` followed by a newline.

  In short, `std::endl and` `<<` are tools used in C++ for formatting output to the console.

## Control Structures Exercises

This directory contains exercises to practice control structures in C++. Each exercise is a separate C++ program.

1. [Exercise 1 - Fibonacci Series Generator](fibonacci.cpp)
   This program prompts the user for an integer N and generates the first N numbers in the Fibonacci series.

2. [Exercise 2 - Factorial Calculator](factorial.cpp)
   This program calculates the factorial of a number entered by the user.

3. [Bonus Exercise - Guessing Game](guessingGame.cpp)
   This is a guessing game. The program randomly selects a number between 1 and 100, and then prompts the user to guess the number. The program tells the user if their guess is too high, too low, or correct. When the user guesses the number correctly, the program prints out the number of attempts the user made.
