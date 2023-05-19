# C++ Object-Oriented Programming (OOP)

OOP is a programming paradigm based on the concept of "objects", which can contain data and code: data in the form of fields (often known as attributes), and code in the form of procedures (methods). This approach enhances software design and makes it more modular and easier to maintain.

In C++, we can define our own types using classes. A class defines a blueprint for an object. Objects are instances of a class, and we can create as many as we need. Each object has its own memory space and can have its own state and behavior. This repository is intended to be a comprehensive guide to mastering OOP in C++.

## Table of Contents

1. [Introduction to OOP](#introduction-to-oop)
2. [Classes and Objects](#classes-and-objects)
3. [Encapsulation](#encapsulation)
4. [Classes vs Structs](#classes-vs-structs)
5. [Inheritance](#inheritance)
6. [Polymorphism](#polymorphism)
7. [Abstraction](#abstraction)
8. [Multiple Inheritance](#multiple-inheritance)
9. [Friend Functions](#friend-functions)
10. [Templates](#templates)
11. [Exception Handling](#exception-handling)
12. [Operator Overloading](#operator-overloading)

### **Introduction to OOP**

Object-Oriented Programming (OOP) is a paradigm that provides a means of structuring programs so that properties and behaviors are bundled into individual objects. This programming style came into prominence in the 1980s with the advent of languages like C++, and it represented a significant shift away from procedural programming.

An "object" in OOP is an instance of a class, which can be thought of as a blueprint for the object. Objects can contain:

1. **Attributes**: These are the properties that describe an object. For instance, a 'Car' object might have attributes like color, model, and make.

2. **Methods**: These are the behaviors or functionalities that an object can perform. For our 'Car' object, this might include methods like accelerate, brake, or turn.

The main principles of OOP are:

1. **Encapsulation**: The idea of bundling data (attributes) and methods that work on the data into a single unit called a class. This also includes hiding the data from being accessed directly (data hiding) - it can only be manipulated through the object's methods.

2. **Inheritance**: This is a way to form new classes using classes that have already been defined. The new classes, known as derived classes, inherit attributes and behavior of the pre-existing classes, which are referred to as base classes. Inheritance helps to model a relationship between different types of objects.

3. **Polymorphism**: This allows one interface to be used for a general class of actions. The specific action is determined by the exact nature of the situation. In more concrete terms, polymorphism allows objects of different classes to be treated as objects of a common superclass.

4. **Abstraction**: This principle is about reducing complexity by hiding unnecessary details from the user. The user interacts with only the essential functionalities.

These principles give OOP the ability to model real-world entities more closely, making programs easier to understand and work with.

Over the next sections, we will delve deeper into each of these principles and their implementation in C++. Each topic will include detailed examples and explanations. Let's embark on this exciting journey!

Next Topic: [Classes and Objects](#classes-and-objects)

### **Classes and Objects**

In the context of Object-Oriented Programming (OOP), a class can be thought of as a blueprint for creating objects. An object, in turn, is an instance of a class.

Let's break down these concepts further.

#### Class

A class is a user-defined data type that encapsulates related data and functions that operate on that data. It's the blueprint or template from which objects are created.

In C++, a class is defined using the `class` keyword. Here's an example of a simple class:

```cpp
  class Car {
    public:
      std::string color;
      std::string model;
      void honk() {
        std::cout << "Beep Beep!\n";
      }
  };
```

In this example, `Car` is a class with two attributes (`color` and `model`) and one method (`honk()`).

#### Object

An object is an instance of a class. When a class is defined, no memory is allocated but when it is instantiated (i.e., an object is created) memory is allocated.

Using our `Car` class from above, we can create an object like this:

```cpp
  Car myCar;
```

`myCar` is an object (an instance of the `Car` class). We can set its attributes and call its methods:

```cpp
  myCar.color = "Red";`
  myCar.model = "Tesla";
  myCar.honk(); // Outputs: Beep Beep!`
```

These concepts are foundational to understanding OOP. As we proceed through the subsequent sections, we'll explore more complex aspects of classes and objects, including constructors, destructors, and access specifiers.

### **Encapsulation**

Encapsulation is one of the fundamental concepts in object-oriented programming (OOP). It refers to the bundling of data, and the methods that operate on that data, into a single unit known as a class.

Encapsulation can be considered as a protective shield that prevents the data from being accessed by the code outside this shield (i.e., outside the class).

#### Access specifiers

In C++, we have three types of access specifiers: `public`, `private`, and `protected`.

- **`public`**: Members (attributes and methods) declared under this specifier can be accessed from anywhere.
- **`private`**: Members declared as private can only be accessed within the same class (i.e., outside access is not allowed).
- **`protected`**: Members declared as protected can be accessed within the same class and in its child (or derived) classes.

Here's an example:

```cpp
  class Car {
    private:
      int speed; // private attribute

    public:
      int getSpeed() { // public method
        return speed;
      }

      void setSpeed(int s) { // public method
        if (s >= 0) {
          speed = s;
        } else {
          std::cout << "Speed cannot be negative.\n";
        }
      }
  };
```

In this class, `speed` is a private attribute. This means it cannot be accessed directly from outside the class. Instead, we provide public "getter" and "setter" methods (i.e., `getSpeed` and `setSpeed`) that allow controlled access to the private attribute.

This is a simple example of encapsulation: we are hiding the details of how the speed attribute is managed inside the class, and only providing a controlled public interface for interacting with it.

The `protected` access specifier is another important aspect of encapsulation in C++. It is particularly relevant when it comes to inheritance, which is another key concept in object-oriented programming.

While `private` members of a class are accessible only within the context of that class, `protected` members are accessible within the context of the class and also within any class derived (inherited) from it.

Here's an example to illustrate:

```cpp
  class Vehicle {
    protected:
      int speed;

    public:
      void setSpeed(int s) {
        if (s >= 0) {
          speed = s;
        } else {
          std::cout << "Speed cannot be negative.\n";
        }
      }
  };

  class Car : public Vehicle {
    public:
      void increaseSpeed(int increment) {
        speed += increment; // This is valid because speed is protected in Vehicle
        std::cout << "Speed is now: " << speed << "\n";
      }
  };
```

In the code above, `speed` is a `protected` member of the `Vehicle` class. This means it's accessible not only within the `Vehicle` class, but also within any class that is derived from `Vehicle`, such as `Car`. That's why we're able to directly modify `speed` within the `increaseSpeed` method of the `Car` class.

On the other hand, `speed` would not be accessible directly from outside these classes, or from any non-derived class, maintaining the principles of encapsulation. We're still protecting and controlling access to the data.

### **Classes vs Structs**

In C++, both `struct` and `class` are user-defined data types that are essentially the same under the hood. They both allow you to define methods and properties and to create instances of those types. However, there are some default differences between them:

1. **Access specifier**: The most fundamental difference between a `struct` and `class` in C++ is the default access level. For a struct, members are public by default; for a `class`, members are private by default.

   ```cpp
     struct MyStruct {
       int x;  // This is public by default
     };

     class MyClass {
       int x;  // This is private by default
     };
   ```

2. **Inheritance**: By default, base classes are inherited as public for `struct`, and as private for `class`.

   ```cpp
     struct Base { };
     struct Derived : Base { };  // Base is inherited as public by default

     class Base2 { };
     class Derived2 : Base2 { };  // Base2 is inherited as private by default
   ```

Despite these differences, in practice, `struct` is often used for simple data structures where the members are typically public, and `class` is used when you want more complex behavior and encapsulation.

When it comes to `obj`, it's worth noting that `obj` is not a keyword or concept in C++. If by `obj` you are referring to objects, then both a `struct` and a `class` can be used to instantiate objects in C++:

```cpp
  MyStruct structInstance;
  MyClass classInstance;
```

In this code, `structInstance` is an object of type `MyStruct`, and `classInstance` is an object of type `MyClass`. Both `struct` and `class` define types, and an object is an instance of a type.

`Struct` and `class` can sometimes be a matter of coding style or convention. However, there are certain use cases where one might be more appropriate than the other:

1. **Use `struct` for simple data structures**: If you are creating a data structure that only holds data and does not require any complex behavior or encapsulation, you might choose to use a `struct`. This is because `struct` members are public by default, so using a `struct` signals to other programmers that this is a simple data structure without much associated behavior. For example, you might use a `struct` to represent a 2D point:

   ```cpp
     struct Point {
       double x;
       double y;
     };

     Point p = {1.0, 2.0};  // Create a Point struct and assign values
   ```

2. **Use `class` for objects that require encapsulation or complex behavior**: If you are creating an object that requires methods, encapsulation, or other complex behavior, you might choose to use a `class`. This is because `class` members are private by default, so using a `class` signals to other programmers that this object has associated behavior and that they should interact with it through its public methods. For example, you might use a `class` to represent a bank account:

   ```cpp
     class BankAccount {
     private:
       double balance;

     public:
       BankAccount(double initial_balance) : balance(initial_balance) { }

       void deposit(double amount) {
           if (amount > 0) {
               balance += amount;
           }
       }

       void withdraw(double amount) {
           if (amount <= balance && amount > 0) {
               balance -= amount;
           }
       }

       double get_balance() const {
           return balance;
       }
     };

   ```

Remember, these are general guidelines, not strict rules. Both struct and class in C++ are flexible enough to be used in a variety of situations, and in many cases, the choice between them is largely a matter of preference. The important thing is to write code that is clear and understandable.

### **Inheritance**

In object-oriented programming, inheritance is a mechanism that allows us to create a new class using the properties and methods of an existing class while adding new functionality or overriding the existing functionality. This facilitates code reusability and organization.

The existing class is known as the base class, or parent class, and the new class is known as the derived class, or child class. Inheritance forms a hierarchy of classes.

In C++, inheritance is declared in the derived class, like this:

```cpp
  class DerivedClass : access-specifier BaseClass
```

The `access-specifier` is optional and can be `public`, `protected`, or `private`, and it specifies how the members of the base class are accessed in the derived class.

Here's a simple example to illustrate:

```cpp
  class Vehicle { // base class
    public:
      void generalVehicleMethod() {
        std::cout << "This is a method from the Vehicle class.\n";
      }
  };

  class Car : public Vehicle { // derived class
    public:
      void carMethod() {
        std::cout << "This is a method from the Car class.\n";
      }
  };
```

In this example, `Vehicle` is the base class, and `Car` is the derived class. The `Car` class has inherited the `generalVehicleMethod` from `Vehicle`, in addition to having its own `carMethod`.

You can use these methods as follows:

```cpp
  int main() {
    Car myCar;
    myCar.carMethod(); // Accessible, as this is a method of the Car class.
    myCar.generalVehicleMethod(); // Accessible, as this method is inherited from the Vehicle class.
    return 0;
  }
```

The output would be:

```
  This is a method from the Car class.
  This is a method from the Vehicle class.
```

This is a basic example. Inheritance in C++ can get quite complex, as you can have multiple levels of inheritance (a class derived from a class derived from another class, and so forth), and even multiple inheritance (a class derived from more than one base class).

There are a few more aspects of inheritance in C++ that are worth knowing:

1. **Protected members**: We've already discussed public and private members. There's a third category, protected members, that behaves like private members but with one key difference: protected members of a class are accessible in the derived classes.

2. **Multiple Inheritance**: In C++, a class can be derived from more than one base class. This is known as multiple inheritance, and it's a feature that's not available in all object-oriented languages. It's declared like this:

   ```cpp
     class DerivedClass : access-specifier BaseClass1, access-specifier BaseClass2...
   ```

   Here's an example:

   ```cpp
     class BaseClass1 {
       public:
         void methodFromBaseClass1() {
             std::cout << "Method from BaseClass1.\n";
         }
     };

     class BaseClass2 {
       public:
         void methodFromBaseClass2() {
             std::cout << "Method from BaseClass2.\n";
         }
     };

     class DerivedClass : public BaseClass1, public BaseClass2 {
       public:
         void methodFromDerivedClass() {
             std::cout << "Method from DerivedClass.\n";
         }
     };

   ```

   In this example, DerivedClass inherits from both BaseClass1 and BaseClass2.

3. **Virtual Functions and Polymorphism**: These are powerful tools in C++ that allow methods in the derived class to override methods in the base class, and for methods to behave differently depending on what kind of object they're called on. These are big topics in themselves and are often covered under their own headings.

4. **Abstract Classes and Pure Virtual Functions**: These are used when you want to define a base class that isn't intended to be instantiated itself, but only to serve as a base class for other classes. A class with one or more pure virtual functions is considered an abstract class, and it cannot be used to instantiate objects.

5. **Access Control and Inheritance**: Access control with private, public, and protected members is an important aspect of inheritance in C++. It's important to know how these access specifiers affect what members of the base class the derived class can access.

### **Polymorphism**

Polymorphism is one of the fundamental principles of Object-Oriented Programming. The word Polymorphism comes from Greek and means having multiple forms. In C++ and other programming languages, Polymorphism allows objects of different classes to be treated as objects of a common superclass. This becomes particularly useful when classes share common methods but may implement them differently.

In the context of C++, we can have two types of Polymorphism:

1. **Compile-time Polymorphism**: This is also known as static, early or overloading polymorphism. It is achieved by function overloading or operator overloading.
2. **Run-time Polymorphism**: This is also known as dynamic, late or overriding polymorphism. It is achieved by Function Overriding, i.e., using virtual functions, where the function to be invoked is determined at run time.

Here's a brief overview of both types:

#### **Function Overloading (Compile-Time Polymorphism)**

Function overloading is a feature in C++ where two or more functions can have the same name but different parameters. Function overloading can be considered as an example of polymorphism feature in C++. The decision of which function to call is made at compile time. Here's an example:

```cpp
  #include<iostream>
  using namespace std;

  class Add {
  public:
      int sum(int num1, int num2){
          return num1+num2;
      }

      int sum(int num1, int num2, int num3){
          return num1+num2+num3;
      }
  };

  int main() {
      Add obj;
      cout<<obj.sum(10,20)<<endl;
      cout<<obj.sum(11,22,33)<<endl;
      return 0;
  }
```

#### **Virtual Functions (Run-Time Polymorphism)**

A virtual function is a member function in the base class that we expect to redefine in derived classes. When a class contains a virtual function, it maintains a vtable (virtual table) which is simply a table of function pointers. The correct function will then be resolved at runtime, hence runtime polymorphism. Here's an example:

```cpp
  #include<iostream>
  using namespace std;

  class Base {
  public:
      virtual void display(){
          cout<<"Display Base"<<endl;
      }
  };

  class Derived : public Base {
  public:
      void display(){
          cout<<"Display Derived"<<endl;
      }
  };

  int main() {
      Base* baseptr;
      Derived derivedobj;
      baseptr = &derivedobj;
      baseptr->display(); // prints "Display Derived"

      return 0;
  }
```

In this example, baseptr is a pointer of type Base, but we assign it the address of the derivedobj object. When we call baseptr->display(), it runs the version of display() in the Derived class, not the one in Base. This is run-time polymorphism.

Beyond these two types of polymorphism (compile-time and run-time), you should also be aware of:

#### **Abstract Classes and Pure Virtual Functions**

An abstract class in C++ is a class that has at least one pure virtual function (a virtual function that is set to 0). Abstract classes are used when you want to provide a common interface for different classes. If a class contains at least one pure virtual function, then it becomes abstract. No objects of an abstract class can be created. Abstract classes are mainly used for Upcasting, and you will learn more about them when you dive deeper into inheritance and polymorphism.

Here's an example:

```cpp
  #include <iostream>
  using namespace std;

  class AbstractClass {
    public:
        // pure virtual function providing interface framework.
        virtual int getValue() = 0;
  };

  class ConcreteClass : public AbstractClass {
    public:
        // An implementation of the pure virtual function.
        int getValue() {
          return 5;
        }
  };

  int main() {
    ConcreteClass cc;

    cout << "Value: " << cc.getValue() << endl;

    return 0;
  }
```

In this example, `AbstractClass` provides a pure virtual function `getValue()`. Any class that inherits from `AbstractClass` will have to provide an implementation for `getValue()`. The `ConcreteClass` provides this implementation and hence can be instantiated. The `AbstractClass` cannot be instantiated because it does not provide an implementation for `getValue()`.

Overall, the concept of polymorphism is a crucial part of a robust, object-oriented design, contributing to the creation of more maintainable and adaptable code. Understanding and applying the principles of polymorphism will allow to create structures where objects can interact with each other in dynamic ways, and where extending functionality can be achieved more efficiently.

### **Abstraction**

`Abstraction` is one of the crucial pillars of OOP, and it works hand in hand with encapsulation. While encapsulation is about hiding the internal states and implementation details, abstraction is about simplifying complex systems by breaking them down into smaller, more manageable parts, and exposing only the relevant details to the user.

Abstraction in C++ is mostly achieved through interfaces and abstract classes. We have discussed abstract classes a bit in the previous section, let's talk about them a bit more:

#### **Abstract Classes**

An abstract class is a class that cannot be instantiated and is meant to be subclassed. It can have data members, methods, and constructors, but it also contains at least one pure virtual function. Pure virtual functions are declared in the abstract class and can be overridden in the derived class. The purpose of an abstract class is to provide an appropriate base class from which other classes can inherit. Abstract classes cannot be used to instantiate objects and serves only as an interface.

Here's an example:

```cpp
  class AbstractEmployee
  {
      virtual void AskForPromotion() = 0; // Pure virtual function makes this class Abstract class
  };

  class Developer : public AbstractEmployee
  {
  public:
      void AskForPromotion()
      {
          cout << "I want a promotion!" << endl;
      }
  };
```

In this example, `AskForPromotion` is a pure virtual function in the `AbstractEmployee` class. `Developer`, which is a subclass of `AbstractEmployee`, provides an implementation of `AskForPromotion`. Notice that `AbstractEmployee` can't be used to create an object in the main function, but `Developer` can because it is not an abstract class.

The idea of abstraction is to focus on what an object does instead of how it does it. It provides you with a general idea or a blueprint of what the object should do, but the how part is usually implemented in subclasses. This allows you to make your code more generic and more easily adaptable to future changes. You can modify or extend the subclasses without affecting the superclass's abstraction.

Understanding and using abstraction correctly can result in code that is more organized, easier to debug, maintain, and extend.

The concept of abstraction in object-oriented programming (OOP) is primarily tied to the ideas of abstract classes and interfaces, as well as encapsulation, which we have already discussed.

However, there are a few additional aspects you might want to consider:

1. **Functional Abstraction**: This is not limited to OOP. The idea is that a function's implementation is hidden (or abstracted away) from the user. The user only needs to know what input the function takes and what output it produces. A common example of this is using libraries or built-in functions where the implementation details are unknown to you, but you can still use them because you know what they do.

2. **Data Abstraction**: This is again a principle closely tied to encapsulation. In OOP, a class provides a structure to abstract away data handling's complexity. When you create an object of a class, you do not need to understand how data is stored or manipulated within the class. You just need to know what methods and properties are exposed to you.

3. **Abstraction in Design**: The principle of abstraction is also heavily used in software design. Complex systems can be broken down into smaller, more manageable components or modules through abstraction. Each of these components can be understood, designed, and developed independently of the others. This modularity leads to better maintainability and flexibility of the software.

If you understand these aspects of abstraction, then you have a good grasp of the concept as it applies to OOP and software development in general. Next, we can move on to the last pillar of OOP: `Association`, `Aggregation`, and `Composition`.

### **Multiple Inheritance**

Multiple inheritance is a feature of some object-oriented programming languages in which a class (or an 'object' in prototyping-based languages) can inherit characteristics and features from more than one superclass. However, it's worth noting that not all languages support multiple inheritance. For instance, Java doesn't support multiple inheritance but C++ does.

C++ allows a class to inherit from more than one class. Here's an example of how it works:

```cpp
    class Base1 {
    public:
      void display() const{
          std::cout << "Base1::display()\n";
      }
    };

    class Base2 {
    public:
      void display() const{
          std::cout << "Base2::display()\n";
      }
    };

    class Derived: public Base1, public Base2 {
    public:
      void display() const{
          Base1::display();
          Base2::display();
      }
    };

    int main() {
      Derived d;
      d.display();  // Outputs: Base1::display() Base2::display()
    }
```

In this example, the `Derived` class inherits from both `Base1` and `Base2`. Therefore, it has access to the `display()` function of both base classes.

While multiple inheritance can be useful, it can also lead to a lot of confusion when two base classes have methods with the same names, or when a class inherits from two classes that have fields with the same names. This is known as the "Diamond Problem". C++ resolves this issue through the use of "virtual inheritance".

Despite its power, multiple inheritance is often seen as a source of complexity and ambiguity, and so it is typically avoided in practice. Instead, developers often use interfaces, or abstract classes, and composition to achieve similar benefits in a more controlled and less error-prone way.

#### Real world example

Imagine we're building a game, and we have two base classes, `Movable` and `Drawable`.

- **`Movable`** has the characteristics of anything that can move in our game, such as position, speed, direction, and the method `move()`.
- **`Drawable`**, on the other hand, is anything that can be drawn on the screen. It has a sprite, color, and a method `draw()`.
  Now, we're ready to implement a Player class. The player of our game can both move and be drawn on the screen, so it makes sense to inherit from both `Movable` and `Drawable`.

Here's a rough sketch of what that might look like in C++ code:

```cpp
  class Movable {
  public:
    // Position, speed, direction...
    virtual void move() {
        // Code to move the object...
    }
  };

  class Drawable {
  public:
    // Sprite, color...
    virtual void draw() {
        // Code to draw the object...
    }
  };

  class Player : public Movable, public Drawable {
    // The player class is both Movable and Drawable.
    // It inherits all public methods from both classes.
  };
```

In this example, the `Player` class is a specific type of object that is both `Movable` and `Drawable`. Therefore, it makes sense for it to inherit from both of these classes.

### **Friend Functions**

Friend functions are a special type of function in C++ that have access to the private and protected members of the class in which they are declared as friends. This is an exception to the general rule that private and protected members of a class can only be accessed directly by methods of that class.

Here's an example of a friend function:

```cpp
    class Rectangle {
    private:
      int width, height;

    public:
      Rectangle(int w, int h) : width(w), height(h) {}

      friend int area(const Rectangle& rectangle);
    };

    int area(const Rectangle& rectangle) {
      // Even though 'width' and 'height' are private, 'area' can access them directly
      // because it's a friend of the Rectangle class.
      return rectangle.width * rectangle.height;
    }

    int main() {
      Rectangle rectangle(5, 10);
      std::cout << "Area: " << area(rectangle) << std::endl;
      return 0;
    }

```

In this example, `area` is a friend function of the `Rectangle` class and can directly access its private members `width` and `height`.

Friend functions are not considered class methods because they are not declared with the class's scope and are not invoked using an object of the class. Rather, the class gives them access to its private and protected members. Therefore, the friend function can be defined anywhere in the code (but must have a matching declaration within the class definition).

However, friend functions should be used sparingly, as they break the principle of encapsulation by accessing private and protected members of the class directly. Use them when necessary, but avoid overusing them as it can make your code harder to understand and maintain.

Friend classes can also be declared, which would allow all the methods of the friend class to access private and protected members of the class in which it is declared a friend. This can be useful for highly related classes that need to share data in a way that would be cumbersome through getter and setter methods. However, it comes with the same cautions as friend functions regarding encapsulation.

Friend functions are typically used when two or more classes need to work together and need access to each other's private or protected members.

For example, consider a scenario where you have two classes, `Person` and `House`. Let's say that every house has an `address` that is private, and the `Person` has a method called `moveIn(House& h)`. Now, when a person moves into a house, we might want to update the `address` of the person. But we can't do that directly, because address is private.

Here is where a friend function comes in. We could make the `Person::moveIn()` method a friend function of the House class. Then it would have access to the private address member of House.

Here's how it might look:

```cpp
  class House;  // Forward declaration, since House is used before it's defined

  class Person {
  private:
    std::string name;
    std::string address;
  public:
    Person(std::string n) : name(n) {}
    void moveIn(House& h);
  };

  class House {
  private:
    std::string address;
  public:
    House(std::string a) : address(a) {}
    friend void Person::moveIn(House& h);
  };

  void Person::moveIn(House& h) {
    // The moveIn method can access private members of House because it's a friend
    this->address = h.address;
  }

  int main() {
    House myHouse("123 Main St.");
    Person me("Alice");
    me.moveIn(myHouse);
    return 0;
  }
```

In this code, `Person::moveIn(House& h)` is a friend function of `House`, so it can access the private `address` member of `House`. Without friend functions, this would not be possible, and we would have to provide a public "getter" function to retrieve the address, which may not always be desirable or appropriate.

Remember, the usage of friend functions can break the principle of encapsulation and it should be used sparingly.

### **Templates**

...

### **Exception Handling**

...

### **Operator Overloading**

...

### Notes

In C++, both stack and heap allocations are available. new is used when you want to allocate memory on the heap.

Here's an example of new:

```cpp
  House* myHouse = new House("123 Main St.");
```

Here, `myHouse` is a pointer to a `House` object allocated on the heap. You'll need to use the `->` operator to access its members.

The original example:

```cpp
  House myHouse("123 Main St.");
```

In this case, `myHouse` is a `House` object allocated on the stack. You access its members using the `.` operator.

Stack allocation is automatically managed: when `myHouse` goes out of scope, its destructor is automatically called and its memory is reclaimed.

Heap allocation is manual: you must eventually call `delete` on a heap-allocated object to reclaim its memory, or you will have a memory leak.

Generally, stack allocation is simpler and more efficient (since you don't have to manually manage memory), but it's limited by the size of the stack, which is relatively small. Heap allocation allows for dynamic memory management, which is essential for working with data structures of varying or large size. However, it requires manual memory management and is a common source of bugs.

So, to sum it up, whether you use `new` or not depends on whether you want to allocate memory on the heap (use `new`) or on the stack (don't use `new`).

#### Constructor notes:

In C++, there is a distinct difference between initialization and assignment.

When you do:

```cpp
  class MyClass {
    int value;
  public:
    MyClass(int v) {
        value = v;
    }
  };
```

You are first default-constructing `value` (which doesn't do anything for primitive types like `int`, but could do something for more complex types), and then assigning `v` to `value`. This is generally less efficient than initializing `value` directly with the value of `v`.

Instead, when you use an initialization list, like this:

```cpp
  class MyClass {
    int value;
  public:
    MyClass(int v) : value(v) {}
  };
```

You are directly initializing `value` with `v`, which is generally more efficient. For certain types of members (like `const` members, reference members, or members without default constructors), you must use an initialization list.

Additionally, there's a difference in naming. In the constructor body, `value = v` would work fine, but if you tried `value = value`, it would not do what you want -- `value` on the right hand side of `=` would refer to the member `value`, not the constructor parameter `value`. In contrast, in an initialization list, `value(v)` or `value(value)` unambiguously refers to the member `value` and the constructor parameter, respectively. It's still better to use different names to avoid confusion, though.

So, in general, it's better to use initialization lists in your constructors where possible.

Please navigate through the README to learn more about each concept. Let's dive into the exciting world of Object-Oriented Programming with C++!
