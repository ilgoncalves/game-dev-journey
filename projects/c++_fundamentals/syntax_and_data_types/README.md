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

## Project List

1. [Hello World](./helloWorld.cpp)
   - Description: Brief description of the project and its goals.
   - Concepts: List of key concepts demonstrated in the project.
   - Technologies: List of technologies, libraries, or tools used.

(Continue listing projects)
