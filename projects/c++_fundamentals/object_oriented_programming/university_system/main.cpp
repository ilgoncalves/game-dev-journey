#include <iostream>
#include <vector>

class Person {
public:
    virtual void Display() const = 0;
    virtual ~Person() {} 
};

class Student : public Person {
public:
    virtual void Study() = 0;  
    void Display() const override {
        std::cout << "Student\n";
    }
};

class Undergraduate : public Student {
public:
    void Study() override {
        std::cout << "Studying for a bachelor's degree\n";
    }
};

class Graduate : public Student {
public:
    void Study() override {
        std::cout << "Studying for a master's or doctoral degree\n";
    }
};

class Faculty : public Person {
public:
    virtual void Teach() = 0;  
    void Display() const override {
        std::cout << "Faculty\n";
    }
};

class Professor : public Faculty {
public:
    void Teach() override {
        std::cout << "Teaching advanced classes\n";
    }
};

class Instructor : public Faculty {
public:
    void Teach() override {
        std::cout << "Teaching introductory classes\n";
    }
};

class Staff : public Person {
public:
    void Display() const override {
        std::cout << "Staff\n";
    }
};

int main() {
    std::vector<Person*> university;

    university.push_back(new Undergraduate());
    university.push_back(new Graduate());
    university.push_back(new Professor());
    university.push_back(new Instructor());
    university.push_back(new Staff());

    for (const auto& person : university) {
        person->Display();

        if (Student* student = dynamic_cast<Student*>(person)) {
            student->Study();
        }
        else if (Faculty* faculty = dynamic_cast<Faculty*>(person)) {
            faculty->Teach();
        }
    }

    for (auto& person : university) {
        delete person;
    }

    return 0;
}