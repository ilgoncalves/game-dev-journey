# Functions, Recursion and Advanced Concepts

Functions in C++ are blocks of code that perform specific tasks. This section covers advanced function concepts including function overloading, default arguments, passing by reference vs passing by value, inline functions, function pointers, and lambda functions.

## Function

A function is a group of statements that perform a specific task. Functions provide modularity and a clear structure to your code. They also offer reusability, allowing you to invoke the same code from various parts of your program without having to write the same code repeatedly.

Here is a simple example of a function in C++:

```cpp
  #include<iostream>
  void greet() {
    std::cout << "Hello, World!";
  }

  int main() {
    greet(); // Call the function
    return 0;
  }
```

In C++, functions can also accept parameters and return values. For example:

```cpp
  #include<iostream>

  int add(int a, int b) {
    return a + b;
  }

  int main() {
    int sum = add(5, 3); // Call the function with arguments 5 and 3
    std::cout << "The sum is: " << sum;
    return 0;
  }
```

## Recursion

Recursion in computer science is a method where the solution to a problem depends on solutions to smaller instances of the same problem. In simpler terms, it's when a function calls itself.

Here is a simple example of a recursive function in C++:

```cpp
  #include<iostream>

  int factorial(int n) {
    if (n == 0) {
      return 1;
    } else {
      return n * factorial(n - 1);
    }
  }

  int main() {
    int result = factorial(5); // Call the recursive function
    std::cout << "The factorial of 5 is: " << result;
    return 0;
  }
```

In this example, factorial is a function that calculates the factorial of a number using recursion. The function calls itself with a smaller value until it reaches the base case (n == 0), then it starts returning and multiplying the results.

Note: It's crucial to have a base case in recursive functions to prevent infinite recursion, which can cause a stack overflow error.

## **Advanced Topics**

1. **Function Overloading**: In C++, you can have multiple functions with the same name but different parameters. This is called function overloading. The compiler will call the correct version of the function based on the arguments you pass. Here's a simple example:

   ```cpp
     #include <iostream>

     void print(int i) {
       std::cout << "Here is int " << i << std::endl;
     }

     void print(double f) {
       std::cout << "Here is double " << f << std::endl;
     }

     int main() {
       print(10);
       print(10.10);
       return 0;
     }
   ```

2. **Default Arguments**: In C++, you can specify default values for parameters. If you call the function without providing a value for a parameter with a default value, the function will use the default value. Here's a simple example:

   ```cpp
     #include <iostream>

     int add(int a, int b = 20) {
       return a + b;
     }

     int main() {
       std::cout << add(10) << std::endl;     // Outputs 30 (10 + 20)
       std::cout << add(10, 5) << std::endl;  // Outputs 15 (10 + 5)
       return 0;
     }
   ```

3. **Passing by Reference vs Passing by Value**: In C++, you can pass arguments to functions either by value or by reference. When you pass an argument by value, a new copy of the argument is created for the function to use. When you pass an argument by reference, the function uses the original argument directly, not a copy. Here's a simple example:

   ```cpp
     #include <iostream>

     void incrementByValue(int a) {
       a++;
     }

     void incrementByReference(int& a) {
       a++;
     }

     int main() {
       int x = 10;
       incrementByValue(x);
       std::cout << x << std::endl;  // Outputs 10

       incrementByReference(x);
       std::cout << x << std::endl;  // Outputs 11
       return 0;
     }
   ```

4. **Inline Functions**: If a function is small, you might want to consider making it an inline function. An inline function is a function that the compiler attempts to expand the body of (i.e., substitute the function code at the point of the function call) when invoked. This can potentially make your code faster by eliminating the overhead of function calls. But use it judiciously, as it can make the compiled code larger. Here's a simple example:

   ```cpp
     inline int Max(int a, int b) {
       return a > b ? a : b;
     }

     int main() {
       std::cout << "Max (20,10): " << Max(20, 10) << std::endl;
       return 0;
     }
   ```

   The inline keyword is a hint to the compiler that it should attempt to insert the complete body of the function in every context where that function is used. The goal of making a function inline is to hint to the compiler that it would be beneficial to perform this optimization.

   In this case, the `Max` function is declared with the `inline` keyword. If the compiler decides to inline this function, then every place the `Max` function is called, the call will be replaced with the body of the function itself.

   This is a trade-off: on one hand, it can make your code faster by eliminating the overhead of function calls; on the other hand, it can make your binary larger because the code for the function is repeated multiple times. The compiler is not required to respect the inline keyword - it's merely a suggestion.

   ### Real case example

   Imagine you're working with a 3D graphics program, and you're doing a lot of vector dot products. The dot product is a simple operation, but it's used extensively. This is a perfect use case for an inline function.

   ```cpp
     inline float DotProduct(const Vector3& v1, const Vector3& v2) {
       return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
     }
   ```

   The operation is simple and small enough that the overhead of the function call might be comparable to the computation time. By inlining this function, the function call overhead can be eliminated, which might lead to a noticeable performance increase given the frequency of the operation.

5. **Function Pointers**: A function pointer is a variable that holds the memory address of a function. This can be used to dynamically call a function without knowing at compile time which function will be invoked. This is useful for passing functions as arguments to other functions, or to use functions as lookup tables, among other things.

   ```cpp
     #include <iostream>

     int add(int a, int b) {
       return a + b;
     }

     int main() {
       int (*fp)(int, int); // Declaring a function pointer
       fp = &add; // Assigning address of the function to pointer

       // Now we can use the function pointer to call the function
       int sum = fp(2, 3);
       std::cout << "The sum is: " << sum << std::endl;  // Outputs 5

       return 0;
     }
   ```

   In this example, `fp` is a function pointer that points to the `add` function. We then use `fp` to call the `add` function.

   Function pointers are particularly useful when you want to have some form of runtime polymorphism but don't want to incur the cost of a virtual function call, or when you want to provide a function as a callback to another function.

   For instance, imagine you're implementing a sorting function and you want to let the user provide their own comparison function. You could do this with a function pointer.

   ```cpp
     // A comparison function to sort in ascending order
     bool Ascending(int a, int b) {
       return a < b;
     }

     // A comparison function to sort in descending order
     bool Descending(int a, int b) {
       return a > b;
     }

     // Our sort function that takes a comparison function as a parameter
     void Sort(int* arr, int size, bool (*comparisonFn)(int, int)) {
       // Sorting code that uses comparisonFn for comparing elements...
     }

     int main() {
       int arr[] = {3, 1, 4, 1, 5, 9};
       // We can now sort in ascending order...
       Sort(arr, 6, Ascending);
       // And in descending order using the same sort function
       Sort(arr, 6, Descending);
       return 0;
     }
   ```

   In this example, we've implemented a `Sort` function that takes a function pointer as a parameter. This allows the user to provide their own comparison function, making the sort function more flexible.

6. **Lambda Functions (or anonymous functions)**: C++11 introduced lambda functions, which are a kind of anonymous function that can be defined at the point where it's used. They can capture variables from their surrounding scope, which can be very convenient:

   ```cpp
     #include <iostream>
     #include <vector>
     #include <algorithm>

     int main() {
       std::vector<int> v {4, 2, 3, 1};

       // Sort using a lambda expression
       std::sort(v.begin(), v.end(), [](int a, int b) {
         return a < b;
       });

       for(int i : v) {
         std::cout << i << ' ';
       }

       return 0;
     }
   ```

In this example, we use a lambda function as a custom comparator for the `std::sort` function. The lambda function takes two arguments and returns `true` if the first argument is less than the second.

## Notes

In C++, both `&` and `*` are used in the context of pointers, but they serve different purposes.

`&`: This is the address-of operator. When placed before a variable, it returns the memory address of that variable. For example:

```cpp
  int x = 10;
  int* ptr = &x;
```

Here, `&x` gets the memory address of `x` and stores it in the pointer `ptr`.

`*`: This is the dereference operator when used in an expression, and the pointer declaration operator when used in a type.

- When used in an expression, it fetches the value stored at the memory address held by a pointer. For example:

  ```cpp
    int x = 10;

    int* ptr = &x;
    int y = *ptr; // y is now 10
  ```

  Here, `*ptr` fetches the value stored at the memory location that `ptr` points to.

- When used in a type, it declares a pointer variable. For example:

  ```cpp
    int* ptr;
  ```

  Here, `int* ptr;` declares a pointer to an integer.

  So in summary: & is used to get the memory address of a variable, and \* is used to either declare a pointer variable or dereference a pointer.

## Functions Exercises

1. [Exercise 1: Function Overloading](./function_overloading.cpp)
   Write two functions with the same name `printArea`. One function takes the radius of a circle (a `double`) and prints the area of the circle. The other function takes the length and width of a rectangle (two `doubles`) and prints the area of the rectangle. In the main function, call both versions of `printArea`.

2. [Exercise 2: Default Arguments]()
   Write a function `power` that takes two `int` parameters: `base` and `exponent`. The `exponent` parameter should have a default value of `2`. The `power` function should return the `base` raised to the `exponent`. In the `main` function, call `power` with two arguments and with one argument.

3. [Exercise 3: Passing by Reference]()
   Write a function `swap` that takes two `int` parameters by reference and swaps their values. In the `main` function, create two `int` variables, print their values, call `swap` on them, and then print their values again to confirm that they were swapped.

4. [Exercise 4: Inline Functions]()
   Write an inline function `max` that takes two `int` parameters and returns the larger one. In the `main` function, call `max` with two different integers and print the result.

5. [Exercise 5: Function Pointers]()
   Create a function pointer for a function that takes two `int` parameters and returns an `int`. Assign the `add` function to the function pointer, and then use the function pointer to call add and print the result.

6. [Exercise 6: Lambda Functions]()
   Create a `std::vector<int>` and fill it with some numbers. Then use `std::sort` with a lambda function to sort the vector in descending order. Print the sorted vector to confirm that it's sorted correctly.
