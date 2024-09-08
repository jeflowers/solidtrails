# Open/Closed Principle (OCP)

## Definition: 
Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification.

## Explanation: 
You should be able to extend a class's behavior without modifying its existing code. This can be achieved using inheritance and polymorphism.

## Example in C++:

Suppose you have a Shape base class for calculating the area:
```
class Rectangle {
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double area() const {
        return width * height;
    }

private:
    double width;
    double height;
};
```
Instead, use inheritance to extend the behavior without modifying the existing code:
```
class Shape {
public:
    virtual double area() const = 0;  // Pure virtual function
    virtual ~Shape() {}
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double area() const override {
        return width * height;
    }

private:
    double width;
    double height;
};

class Circle : public Shape {
public:
    Circle(double radius) : radius(radius) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

private:
    double radius;
};
```
