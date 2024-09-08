# Liskov Substitution Principle (LSP)

## Definition: 
Subtypes must be substitutable for their base types without altering the correctness of the program.

## Explanation: 
If class B is a subclass of class A, then objects of type A should be replaceable with objects of type B without affecting the functionality. This principle promotes proper inheritance.

## Example in C++:

Suppose you have a base class Bird:
```
class Bird {
public:
    virtual void fly() {
        std::cout << "Bird is flying" << std::endl;
    }
};
```
A subclass Penguin should not violate the LSP:
```
class Penguin : public Bird {
public:
    void fly() override {
        throw std::runtime_error("Penguins can't fly!");  // Violates LSP
    }
};
```
Instead, design it correctly:
```
class Bird {
public:
    virtual void move() = 0;  // Pure virtual function
    virtual ~Bird() {}
};

class FlyingBird : public Bird {
public:
    void move() override {
        std::cout << "Bird is flying" << std::endl;
    }
};

class Penguin : public Bird {
public:
    void move() override {
        std::cout << "Penguin is swimming" << std::endl;
    }
};
```
