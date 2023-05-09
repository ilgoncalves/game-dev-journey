# Syntax and data types

## Overview

In C++, syntax and data types are fundamental concepts that form the building blocks of the language. Understanding them is crucial for writing efficient and maintainable code. In this topic, you'll learn about:

### 1. Basic Syntax

C++ has a specific syntax for structuring programs, which is similar to TypeScript in many ways.

- **Comments**: C++ supports single-line and multi-line comments.

  ```cpp
   // This is a single-line comment

   /* This is a
      multi-line comment */
  ```

- **Semicolons**: Like TypeScript, C++ statements end with semicolons.

  ```cpp
   int age = 25;
  ```

- **Code blocks**: Code blocks in C++ use curly braces `{}` just like in TypeScript..

  ```cpp
   if (age > 18) {
      std::cout << "You are an adult.";
   }
  ```

### 2. Variables

Variables in C++ are similar to TypeScript, with some differences in declaration and initialization.

- **Variable declaration**:In C++, you must specify the data type when declaring a variable.

  ```cpp
   int age; // Declares an integer variable named "age"
  ```

- **Variable assignment**:Assigning a value to a variable is similar to TypeScript.

  ```cpp
   age = 25;
  ```

- **Variable declaration and assignment**: You can declare and assign a value to a variable in a single line.

  ```cpp
   int age = 25;
  ```

- **Naming conventions:**: C++ follows similar naming conventions as TypeScript: camelCase, PascalCase, or snake_case. It's essential to choose a convention and stick to it.

### 3. Data Types

C++ has a range of built-in data types, some of which have direct analogies in TypeScript.

- **Primitive data types**: C++ has several primitive data types for representing numbers, characters, and boolean values.

  - int: Integer numbers (e.g., `int age = 25;`)
  - float: Single-precision floating-point numbers (e.g., `float height = 1.75;`)
  - double: Double-precision floating-point numbers (e.g., `double pi = 3.141592653589793;`)
  - char: Single characters (e.g., `char grade = 'A';`)
  - bool: Boolean values (e.g., `bool isAdult = true;`)

  Note that C++ has separate data types for single-precision and double-precision floating-point numbers, unlike TypeScript, which uses the `number` type for both.

- **Modifiers**: Modifiers can be used with numeric data types to change their default behavior.

  - signed (default): Allows negative and positive values (e.g., `signed int x = -5;`)
  - unsigned: Allows only non-negative values (e.g., `unsigned int x = 5;`)
  - short: Reduces the size of the data type, allowing for smaller values (e.g., `short int x = 32000;`)
  - long: Increases the size of the data type, allowing for larger values (e.g., `long int x = 1000000000;`)

- **Constants**: Constants are like variables, but their values cannot be changed after they're set. In C++, you can use the `const` keyword or the `enum` keyword for defining constants.

  - const keyword (e.g., `const int DAYS_IN_YEAR = 365;`)
  - enumeration (e.g., `enum Weekdays { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY };`)

### 4. Type Casting

Type casting is the process of converting a value from one data type to another. It can be done implicitly (automatically) or explicitly.

- **Implicit type casting**: C++ automatically performs type casting when assigning a value of one data type to another. This is known as "type promotion" or "type coercion." However, it can sometimes lead to data loss or unexpected behavior.

  ```cpp
  int x = 5;
  float y = x; // Implicit type casting from int to float
  ```

In TypeScript, you might encounter similar behavior when dealing with the any type or when TypeScript cannot infer the correct type.

- **Explicit type casting**:If you need more control over type casting, you can perform explicit type casting using C-style casting, `static_cast`, or other specialized casting operators.

  - C-style casting:

  ```cpp
   int x = 5;
   float y = (float)x; // Explicit type casting from int to float using C-style casting
  ```

  - static_cast:

  ```cpp
   int x = 5;
   float y = static_cast<float>(x); // Explicit type casting from int to float using static_cast
  ```

  In TypeScript, you can achieve similar results using type assertions (e.g., `<type>value` or `value as type`).

### 5. Strings

In C++, strings can be represented using character arrays or the `std::string` class from the C++ Standard Library.

- **Character arrays**: A string can be represented as an array of characters, with a null character (`\0`) at the end to indicate the end of the string.

  ```cpp
  char greeting[] = "Hello, World!";
  ```

  Character arrays can be manipulated using functions from the `<cstring>` header (e.g., `strlen`, `strcpy`, `strcat`, `strcmp`). However, working with character arrays can be error-prone, and it's generally recommended to use the std::string class instead.

- **std::string**:The `std::string` class provides a more convenient and safer way to work with strings in C++. To use `std::string`, you'll need to include the `<string>` header.

  ```cpp
   #include <string>
   std::string greeting = "Hello, World!";
  ```

  The std::string class provides several member functions and operators for working with strings, such as concatenation, comparison, and searching.

  ```cpp
   std::string firstName = "John";
   std::string lastName = "Doe";
   std::string fullName = firstName + " " + lastName; // Concatenation

   if (firstName == lastName) {
      // Comparison
   }

   std::size_t found = fullName.find("Doe"); // Searching
  ```

  In TypeScript, strings are represented using the `string` type, and most string operations can be performed using built-in methods or operators. The `std::string` class in C++ provides similar functionality to the `string` type in TypeScript, making it easier for you to work with strings in C++.

## Understanding `std::` and the Scope Resolution Operator `::` in C++

### **std::**

In C++, `std::` is a namespace identifier that denotes the standard C++ library namespace. The standard C++ library consists of a collection of classes, functions, constants, and objects that provide commonly-used functionality. By using the `std::` prefix, you're accessing these standard library components.

Namespaces in C++ are used to organize code and prevent naming conflicts between different parts of a program. The `std` namespace contains all the standard library components, and by using the `std::` prefix, you're explicitly stating that you're referring to a component within the standard namespace.

For example, when you use `std::string`, you're referring to the `string` class within the standard C++ library namespace. Similarly, when you use `std::cout`, you're referring to the standard output stream object within the standard library namespace.

In TypeScript, namespaces are less commonly used, as modules are the primary means of organizing code. However, if you come across a TypeScript namespace, it serves a similar purpose in organizing code and preventing naming conflicts.

Keep in mind that you can use the using directive in C++ to avoid writing std:: every time you want to access a standard library component. For example, you can write:

```cpp
#include <iostream>
using std::cout;

int main() {
    cout << "Hello, World!";
}

```

However, it's generally not recommended to use using namespace std; to import the entire standard namespace, as it can lead to naming conflicts and decreased code readability.

### **Scope Resolution Operator `::`**

In C++, the double colon `::` is known as the scope resolution operator. It's used to specify the namespace, class, or structure in which a particular identifier (such as a variable, function, or type) is defined. By using the scope resolution operator, you can access elements that are defined within a specific scope, such as a namespace, class, or structure.

Here are some common use cases for the scope resolution operator `::` in C++:

1. **Accessing elements within a namespace**: When you want to access a specific element within a namespace, you can use the scope resolution operator to specify the namespace.

   ```cpp
   std::string name = "John"; // Accessing the 'string' class within the 'std' namespace
   ```

2. **Accessing static members of a class**: Static members of a class (such as static member variables or static member functions) are associated with the class itself, rather than with individual objects of the class. To access a static member of a class, you can use the scope resolution operator.

   ```cpp
   class MyClass {
   public:
    static int myStaticVar;
    static void myStaticFunction() {
        // ...
    }
   };


   int MyClass::myStaticVar = 5; // Defining the static member variable outside the class
   MyClass::myStaticFunction(); // Calling the static member function
   ```

3. **Defining member functions outside of a class**: If you want to define a member function of a class outside of the class definition, you can use the scope resolution operator to specify the class to which the member function belongs.

   ```cpp
   class MyClass {
   public:
      void myFunction();
   };

   void MyClass::myFunction() {
      // Function definition outside the class
   }
   ```

   In summary, the scope resolution operator :: in C++ is used to specify the scope (namespace, class, or structure) to which a specific identifier belongs, allowing you to access elements within that scope.

## Project List

1. [Hello World](./helloWorld.cpp)

- Description: Just a simple Hello World to print a name

2. [Exercise 1](./exercise1.cpp)

   ```cpp
   // Create a simple program that demonstrates your understanding of C++ syntax and data types. The program should:

   // 1. Prompt the user to enter their first name, last name, and age.
   // 2. Store the first name and last name as strings and the age as an integer.
   // 3. Calculate the user's age in days, assuming 365 days per year. Store the result as a double.
   // 4. Output a personalized message to the user, including their full name and age in days.
   // 5. Use comments to explain the code and follow proper variable naming conventions.
   // 6. Use constants where appropriate.
   // 7. Include type casting when necessary.
   ```
