# C++ Object-Oriented Programming (OOP)

OOP is a programming paradigm based on the concept of "objects", which can contain data and code: data in the form of fields (often known as attributes), and code in the form of procedures (methods). This approach enhances software design and makes it more modular and easier to maintain.

In C++, we can define our own types using classes. A class defines a blueprint for an object. Objects are instances of a class, and we can create as many as we need. Each object has its own memory space and can have its own state and behavior. This repository is intended to be a comprehensive guide to mastering OOP in C++.

## Table of Contents

1. [Introduction to OOP](#introduction-to-oop)
2. [Classes and Objects](#classes-and-objects)
3. [Encapsulation](#encapsulation)
4. [Inheritance](#inheritance)
5. [Polymorphism](#polymorphism)
6. [Abstraction](#abstraction)
7. [Interfaces and Abstract Classes](#interfaces-and-abstract-classes)
8. [Multiple Inheritance](#multiple-inheritance)
9. [Virtual Functions / Methods](#virtual-functions-methods)
10. [Friend Functions](#friend-functions)
11. [Templates](#templates)
12. [Exception Handling](#exception-handling)
13. [Operator Overloading](#operator-overloading)

### Introduction to OOP

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

### Classes and Objects

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

### Encapsulation

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

### Inheritance

...

### Polymorphism

...

### Abstraction

...

### Interfaces and Abstract Classes

...

### Multiple Inheritance

...

### Virtual Functions / Methods

...

### Friend Functions

...

### Templates

...

### Exception Handling

...

### Operator Overloading

...

Please navigate through the README to learn more about each concept. Let's dive into the exciting world of Object-Oriented Programming with C++!
