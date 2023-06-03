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
13. [Code Split](#code-split)
14. [Basic Exercises](#basic-exercises)
15. [Advanced Exercises](#advanced-exercises)

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

Templates in C++ provide a way to write generic code that can work with different data types. Essentially, templates allow us to define the behavior of a function or class, without specifying the exact types it works with.

#### **Template Functions**

A function template behaves like a function except that the template can have one or more unspecified variables, called template parameters. Here is a simple example of a template function:

```cpp
  template <typename T>
  T max(T a, T b) {
    return (a > b) ? a : b;
  }
```

You can call the function `max()` with any data type that supports the `>` operator, like this:

```cpp
  std::cout << max(3, 7) << std::endl;  // prints: 7
  std::cout << max(3.14, 2.71) << std::endl;  // prints: 3.14
```

#### **Template Classes**

Similarly, class templates are used to create generic classes. Here is a simple example of a template class:

```cpp
  template <typename T>
  class Box {
  private:
    T content;
  public:
    Box(T content) : content(content) {}

    T get() {
        return content;
    }
  };
```

You can create instances of the class `Box` with any type:

```cpp
  Box<int> intBox(123);
  Box<std::string> strBox("Hello world");
```

#### **Specialization**

Templates also allow for specialization, which means you can define a different implementation of a function or class for a specific type. For instance, if you wanted to handle strings differently in the `max()` function, you could specialize it like so:

```cpp
  template <>
  std::string max(std::string a, std::string b) {
    return (a.size() > b.size()) ? a : b;
  }
```

This version of `max()` will be called when the function is used with `std::string` arguments. It compares the strings by their lengths instead of their lexicographical order.

Templates are a powerful feature of C++ that contribute significantly to its flexibility and efficiency. They can be somewhat complex, especially when involving multiple template parameters, template member functions in template classes, and template specialization. Therefore, it's recommended to understand the basics first and then delve into more complex uses as needed.

#### Real World Examples

Let's take a real-world example where templates can come in handy. Suppose you are designing a game and you have different types of game objects like `Player`, `Enemy`, `Item` etc. Now you want to have a function that can check for collision between two game objects.

Without templates, you might have to write separate functions for each combination of game object types that could collide. With templates, you can write a generic function that works with all game object types.

First, let's suppose each game object type has a `getBoundingBox()` member function which returns a `Box` object. The `Box` object represents the area occupied by the game object in the game world, and it has `intersects()` member function that checks if it intersects with another `Box`.

Now we can write a generic `collides` function with templates:

```cpp
  template <typename T1, typename T2>
  bool collides(const T1& obj1, const T2& obj2) {
    Box bbox1 = obj1.getBoundingBox();
    Box bbox2 = obj2.getBoundingBox();

    return bbox1.intersects(bbox2);
  }
```

```cpp
  Player player;
  Enemy enemy;
  Item item;

  bool playerEnemyCollision = collides(player, enemy);  // true if the player and the enemy collide
  bool playerItemCollision = collides(player, item);  // true if the player and the item collide
```

This example demonstrates how templates can help you write code that is both more flexible and easier to maintain. Instead of having to write and update several specific collision detection functions, you have a single, generic function that can be applied to any game object type.

### **Exception Handling**

Exception handling in C++ is a process to handle runtime errors. It is a robust mechanism where a block of code is executed which may throw an error during execution, and this error can be caught and handled appropriately to ensure that the program continues to function correctly.

Key Concepts:

- **`Exceptions`**: An exception is a problem that arises during the execution of a program. When a C++ exception is thrown, the normal program flow is stopped and control is transferred to some exception-handling code.
- **`Throwing an Exception`**: The keyword throw is used to indicate an exception. The operand of the throw statement determines the type for the exception that is being thrown.

  ```cpp
    throw exceptionObject;
  ```

- **`Catching an Exception`**: The try/catch block is used to capture and handle exceptions. Code that could potentially throw an exception is put inside a try block. Immediately following the try block are one or more catch blocks that catch and handle the exception.

  ```cpp
    try {
      // code that may throw an exception
    } catch (ExceptionType1 ex) {
      // handle exception of type ExceptionType1
    } catch (ExceptionType2 ex) {
      // handle exception of type ExceptionType2
    }
  ```

- **`Standard Exceptions`**: The C++ Standard library provides a base exception class (`std::exception`) along with a handful of common exception types for basic needs. Some of them are `std::runtime_error`, `std::out_of_range`,` std::invalid_argument`, `std::bad_alloc`, etc. You can also define your own exception classes by inheriting from `std::exception` or any other standard exception class.

Here is a simple example of exception handling:

```cpp
  #include <iostream>
  #include <stdexcept> // for std::runtime_error

  int divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::runtime_error("Denominator cannot be zero");
    }
    return numerator / denominator;
  }

  int main() {
    try {
        std::cout << divide(10, 2) << "\n";  // prints 5
        std::cout << divide(10, 0) << "\n";  // throws an exception
    } catch (std::runtime_error& e) {
        std::cout << "Caught an exception: " << e.what() << "\n";
    }
  }
```

In this example, the `divide` function throws an exception of type `std::runtime_error` when the denominator is zero. In `main`, we call `divide` inside a `try` block. If an exception is thrown, it is caught and handled in the `catch` block.

One important thing to note is that when an exception is thrown, the program flow is immediately transferred to the nearest `catch` block that can handle the type of exception thrown. This means that if there is any code after the line that throws the exception inside the `try` block, that code will not be executed.

### **Operator Overloading**

In C++, most built-in operators (like +, -, \*, /, etc.) can be redefined or "overloaded" for user-defined types (i.e., classes and structs). This is a powerful feature that allows programmers to use natural syntax for operations on these types, which can make the code more intuitive and easy to read.

Here's an outline of how to overload an operator:

```cpp
  ReturnType operator_symbol(Parameters) { /*...*/ }
```

Where:

- `ReturnType` is the type of value that the operator returns.
- `operator_symbol` is the keyword `operator` followed by the operator symbol to be overloaded.
- `Parameters` are the parameters required for the operator.
  For example, let's create a Complex class to represent a complex number and overload the + operator for it:

For example, let's create a `Complex` class to represent a complex number and overload the + operator for it:

```cpp
  class Complex {
  public:
    double real, imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overloading the + operator
    Complex operator + (const Complex& rhs) {
        return Complex(this->real + rhs.real, this->imag + rhs.imag);
    }
  };

  int main() {
    Complex c1(1.0, 2.0), c2(2.0, 3.0);
    Complex c3 = c1 + c2;  // uses the overloaded + operator
    std::cout << "c3 = (" << c3.real << ", " << c3.imag << ")\n";
  }
```

This program defines a `Complex` class for complex numbers and then overloads the + operator for it. In the `main` function, we can now use the + operator to add two `Complex` objects naturally.

Note that operators should be overloaded responsibly to avoid confusion. The overloaded operator should perform an operation consistent with what would be expected given the semantics of the original operator. For example, overloading `+` to perform subtraction would likely confuse users of your class.

It's also important to note that not all operators can be overloaded in C++. The following operators cannot be overloaded:

- Scope operator `::`
- Sizeof
- Member selector `.`
- Member pointer selector `.*`
- Ternary operator `?:`
- typeid

The assignment operator `=` has a special property: if not overloaded, the compiler creates a default one.

#### Real World Example

A real-world use case for operator overloading could be a `Vector` class.

In mathematics and physics, a vector has both a magnitude (size) and direction, and vectors can be added together, subtracted, scaled (multiplied by a scalar), and so forth. These operations are naturally expressed with operators like `+`, `-`, and `*`.

Let's take a look at an example:

```cpp
  class Vector {
  public:
    double x, y;

    Vector(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    // Overload + for vector addition
    Vector operator+(const Vector& rhs) {
        return Vector(this->x + rhs.x, this->y + rhs.y);
    }

    // Overload - for vector subtraction
    Vector operator-(const Vector& rhs) {
        return Vector(this->x - rhs.x, this->y - rhs.y);
    }

    // Overload * for scalar multiplication
    Vector operator*(double rhs) {
        return Vector(this->x * rhs, this->y * rhs);
    }
  };

  int main() {
    Vector v1(1.0, 2.0), v2(2.0, 3.0);

    Vector v3 = v1 + v2;  // vector addition
    std::cout << "v3 = (" << v3.x << ", " << v3.y << ")\n";

    Vector v4 = v1 - v2;  // vector subtraction
    std::cout << "v4 = (" << v4.x << ", " << v4.y << ")\n";

    Vector v5 = v1 * 3;   // scalar multiplication
    std::cout << "v5 = (" << v5.x << ", " << v5.y << ")\n";
  }
```

In this case, operator overloading makes the code much more readable and intuitive. It's easy to see that `v3` is the result of adding `v1` and `v2`, `v4` is the result of subtracting `v2` from `v1`, and `v5` is the result of multiplying `v1` by 3.

It's worth mentioning that in more complex mathematical libraries, vectors and other mathematical structures are often implemented with more thorough error checking and handling (for things like dimensionality mismatches), more operations (like dot product and cross product for vectors), and optimizations for performance.

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

### **Code Split**

You can split the definition and implementation of a class across multiple files in C++. This is commonly done in large software projects to improve code organization, readability, and modularity. Here's how you do it:

1. **`Header file (.h)`**: Contains the class definition. This typically includes the data members and function prototypes for the class.

   ```cpp
     // MyClass.h

     #ifndef MYCLASS_H
     #define MYCLASS_H

     class MyClass {
     public:
       MyClass();               // Constructor
       ~MyClass();              // Destructor

       void SomeMethod();       // Method declaration
     private:
       int myVariable;          // Member variable
     };

     #endif
   ```

2. **`Source file (.cpp)`**: Contains the implementation of the class functions.

   ```cpp
     // MyClass.cpp

     #include "MyClass.h"       // Include the class definition

     MyClass::MyClass() {
       // Constructor implementation
     }

     MyClass::~MyClass() {
       // Destructor implementation
     }

     void MyClass::SomeMethod() {
       // Method implementation
     }
   ```

3. **`In another file`**: Include the header file where you want to use the class. The compiler will handle linking the implementation from the .cpp file.

   ```cpp
     // Main.cpp

     #include "MyClass.h"

     int main() {
       MyClass instance;      // Create an instance of MyClass
       instance.SomeMethod(); // Call a method of MyClass

       return 0;
     }
   ```

This setup uses what's called a "header guard" (`#ifndef`, `#define`, and `#endif`) to prevent multiple inclusions of the same header file, which can cause problems.

Also remember that the .cpp file with the `main` function must be linked with the .cpp file that implements the class, which is usually done by the build system you're using (like make or cmake).

In a nutshell, this is how classes are typically separated into different files in C++. This can make your code easier to manage, especially as your project grows larger.

### **Basic Exercises**

1. [**`Exercise 1: Create a Class (Encapsulation)`**](./exercise_1/encapsulation.cpp)
   Create a `Person` class that encapsulates data about a person such as `name`, `age`, and `address`. Add methods for changing and displaying this data. Create a few instances of your class and test your code.

2. [**`Exercise 2: Create a Subclass (Inheritance)`**](./exercise_2/inheritance.cpp)
   Extend the `Person` class to create a `Student` class. Add additional properties that are relevant for a student, like `major` and `GPA`. Overload a method in the Student class, and demonstrate calling both the `Person` and `Student` versions of the method.

3. [**`Exercise 3: Shapes and Polymorphism`**](./exercise_3/main.cpp)
   Create an abstract `Shape` class and then derive `Rectangle`, `Circle`, `Triangle` classes from it. Have each class implement methods to calculate `Area()` and `Perimeter()`. In your `main()` function, create an array of `Shape` pointers and initialize it with various shapes. Then, loop through the array, calling the `Area()` and `Perimeter()` methods and display the results.

4. [**`Exercise 4: Operator Overloading`**](./exercise_4/main.cpp)
   Extend the Vector class from the operator overloading example to overload more operators: `+=`, `-=`, `\*=` (scaling), and `==` (checking for equality). Make sure to test all your overloaded operators.

5. [**`Exercise 5: Templates`**](./excercise_5/main.cpp)
   Create a `Stack` template class that can store elements of any type. Implement methods to `push()` (add) elements, `pop()` (remove) elements, and check if the stack is `empty()`. Test your stack with a few different data types.

6. [**`Exercise 6: Exception Handling`**](./exercise_6/main.cpp)
   Extend the `Stack` class from the previous exercise to throw an exception when trying to `pop()` an element from an empty stack. Catch this exception in your `main()` function and print an appropriate message.

7. [**`Exercise 7: Multiple Inheritance`**](./exercise_7/main.cpp)
   Create classes `Employee`, `Student` and `TeachingAssistant`. `TeachingAssistant` should inherit from both `Employee` and `Student`. Make sure each class has some unique properties and/or methods, and then demonstrate creating a `TeachingAssistant` object and working with it.

8. [**`Exercise 8: Friend Functions`**](./exercise_8/main.cpp)
   Create a class `Bank` which stores `name` and `balance`. Create a friend function `updateBalance()` which can access and modify private data of `Bank`.

### **Advanced Exercises**

9. [**`Exercise 9: Database Management (Encapsulation, Inheritance, Polymorphism)`**]()
   Design a simple database system with a base class `Record`. `Record` could have attributes such as `id`, `createdAt`, `updatedAt` and methods like `save`, `update`, `delete`. Then derive specific classes like `UserRecord`, `ProductRecord`, `OrderRecord` from `Record`, each with its own additional attributes. For example, `UserRecord` could have `name`, `email`, `password`; `ProductRecord` could have `productName`, `price`, `quantity` etc. Ensure that when you call `save`, `update`, it modifies the `createdAt`, `updatedAt` fields respectively.
10. [**`Exercise 10: Geometric Operations (Operator Overloading, Templates)`**]()
    Create a `Point` class for a point in a 2D space (with `x` and `y` as coordinates). Implement operator overloading for `+`, `-`, `==`, and !=. Also, implement a `Point3D` as a subclass of Point with an additional z-coordinate. You should be able to add and subtract 3D points using the overloaded operators.

11. [**`Exercise 11: University System (Multiple Inheritance, Polymorphism, Friend Functions)`**]()
    Create a class hierarchy for a University. Have a base class `Person` and derive classes like `Student`, `Faculty`, and `Staff` from it. Further subclass `Student` into `Undergraduate` and `Graduate`. Subclass `Faculty` into `Professor` and `Instructor`. Each class should have relevant data and behaviors. Demonstrate polymorphic behavior by storing various types in a `std::vector<Person*>` and calling methods on them.

12. [**`Exercise 12: Custom String Class (Operator Overloading, Exception Handling)`**]()
    Create your own `String` class that encapsulates a `char` array. Include some of the main `std::string` methods like `length()`, `substr()`, and `find()`. Overload operators like `+`, `+=`, `==`, `!=`, and `<<` (for output to `std::ostream`).

13. [**`Exercise 13: Generic Data Structure (Templates, Exception Handling)`**]()
    Create a templated `LinkedList` class that can handle data of any type. Implement methods for adding elements, removing elements, searching for elements, and printing the list. If the list is empty and the remove method is called, throw and handle an appropriate exception.

### **Game Dev OOP Exercises**

14. [**`Exercise 1: Design Basic Game Characters`**]()

    Create an abstract base class `Character` with attributes such as `name`, `health`, and `strength`. The Character class should have pure virtual functions like `attack()`, `defend()`, and `move()`. Implement derived classes like `Warrior`, `Mage`, and `Archer` each with unique ways of attacking, defending, and moving. Create a main function where you can instantiate objects of these classes and call their member functions.

15. [**`Exercise 2: Inventory System`**]()

    Design an inventory system for a role-playing game. Create an `Item` base class and derive different kinds of items from it like `Potion`, We`apon, `Armor`, etc. Each class should have methods like `use()`. Now, create a class Inventory which can hold a collection of `Item`objects. This`Inventory`class should have methods to`add(Item)`, `remove(Item)`and`use(Item)`. In the main function, create a few items and an inventory to hold them.

16. [**`Exercise 3: Game Level and Polymorphism`**]()

    Design a very basic game level system. Create an abstract base class `Level` with a pure virtual function `play()`. Derive different level classes from it like `Level1`, `Level2`, etc., each with a different implementation of `play()`. Now, create a `Game` class that uses polymorphism to hold a pointer to a `Level` object. It should have a function `setLevel(Level*)` that can be used to change which level is currently being played.

17. [**`Exercise 4: Exception Handling in Game`**]()

    Build upon the inventory system from Exercise 2. When `use(Item)` is called on the `Inventory`, and if the item does not exist in the inventory, throw an exception. In the main function, demonstrate how this exception can be caught and handled.

18. [**`Exercise 5: Game Entities and Multiple Inheritance (Multiple Inheritance, Polymorphism)`**]()

    Extend the game from Exercise 1. Create an `Entity` base class that represents an object in the game world, with attributes like `position` and methods like `draw()`. Now, suppose there are some entities in your game which can be both `Character` and `Item`. To represent these, create a class like `TreasureGuardian` that inherits from both `Character` and `Item`. Demonstrate how such an object can be used as both a `Character` and an `Item` in your game.

19. [**`Exercise 6: Grid-Based Game and Overloaded Operators (Operator Overloading)`**]()

    Consider a grid-based game where the game world is a 2D grid of cells. Create a `Grid` class that represents this grid. Each cell in the grid can be accessed using its row and column indices. Implement operator overloads for `()`, so you can access cells in the grid like this: `grid(row, column)`. Each cell can contain an `Entity` object (using the `Entity` class from Exercise 4).

20. [**`Exercise 7: Game Events and Template Classes (Templates)`**]()

    Consider a game where events happen at certain times. An event has a time at which it happens and an action that is triggered when the event happens. The action can be represented as a string (like "spawn_enemy", "start_boss_fight"). Create a `GameEvent` template class where the time can be of any numeric type (like `int` for frames, or `float` for seconds) and the action is always a `string`. The `GameEvent` class should have methods like `getTime()` and `getAction()`. Create a `GameTimeline` class that holds a list of `GameEvent` objects. It should have methods like `addEvent(GameEvent)`, `removeEvent(GameEvent)`, and `getEventsAtTime(T)`, where T is the same type as the time in `GameEvent`.
