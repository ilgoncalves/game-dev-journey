#include <iostream>
#include <vector>
#include <memory>

class Person {
public:
    virtual void Display() const = 0;  // Pure virtual function
    virtual ~Person() {}  // Virtual destructor
};

class Student : public Person {
public:
    Student() = default;
    virtual void Study() = 0;  // Students can study, further refined in subclasses
    void Display() const override {
        std::cout << "Student\n";
    }
};

class Undergraduate : public Student {
public:
    Undergraduate() = default;
    void Study() override {
        std::cout << "Studying for a bachelor's degree\n";
    }
};

class Graduate : public Student {
public:
    Graduate() = default;
    void Study() override {
        std::cout << "Studying for a master's or doctoral degree\n";
    }
};

class Faculty : public Person {
public:
    Faculty() = default;
    virtual void Teach() = 0;  // Faculty members can teach, further refined in subclasses
    void Display() const override {
        std::cout << "Faculty\n";
    }
};

class Professor : public Faculty {
public:
    Professor() = default;
    void Teach() override {
        std::cout << "Teaching advanced classes\n";
    }
};

class Instructor : public Faculty {
public:
    Instructor() = default;
    void Teach() override {
        std::cout << "Teaching introductory classes\n";
    }
};

class Staff : public Person {
public:
    Staff() = default;
    void Display() const override {
        std::cout << "Staff\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Person>> university;

    university.push_back(std::make_unique<Undergraduate>());
    university.push_back(std::make_unique<Graduate>());
    university.push_back(std::make_unique<Professor>());
    university.push_back(std::make_unique<Instructor>());
    university.push_back(std::make_unique<Staff>());

    for (const auto& person : university) {
        person->Display();

        // Use dynamic_cast to call class-specific methods
        if (Student* student = dynamic_cast<Student*>(person.get())) {
            student->Study();
        }
        else if (Faculty* faculty = dynamic_cast<Faculty*>(person.get())) {
            faculty->Teach();
        }
    }

    return 0;
}