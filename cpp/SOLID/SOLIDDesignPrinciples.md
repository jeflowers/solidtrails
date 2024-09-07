SOLID principle with examples in C/C++ to demonstrate how these principles can be applied in a lower-level, object-oriented language like C++.

### 1. **Single Responsibility Principle (SRP)**
- **Definition**: A class should have only one reason to change, meaning it should only have one job or responsibility.
- **Explanation**: If a class has more than one responsibility, those responsibilities become coupled, and changes to one may affect the other. SRP encourages creating separate classes for different concerns to promote modularity.

**Example in C++:**

Instead of having a class that handles both user data and its storage:

```cpp
class User {
public:
    User(const std::string& name, const std::string& email) : name(name), email(email) {}
    
    void saveToDatabase() {
        // Code to save user data to the database
    }

private:
    std::string name;
    std::string email;
};
```

Apply SRP by separating concerns:

```cpp
class User {
public:
    User(const std::string& name, const std::string& email) : name(name), email(email) {}

    std::string getName() const { return name; }
    std::string getEmail() const { return email; }

private:
    std::string name;
    std::string email;
};

class UserRepository {
public:
    void saveToDatabase(const User& user) {
        // Code to save user data to the database
    }
};
```

### 2. **Open/Closed Principle (OCP)**
- **Definition**: Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification.
- **Explanation**: You should be able to extend a class's behavior without modifying its existing code. This can be achieved using inheritance and polymorphism.

**Example in C++:**

Suppose you have a `Shape` base class for calculating the area:

```cpp
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

```cpp
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

### 3. **Liskov Substitution Principle (LSP)**
- **Definition**: Subtypes must be substitutable for their base types without altering the correctness of the program.
- **Explanation**: If class `B` is a subclass of class `A`, then objects of type `A` should be replaceable with objects of type `B` without affecting the functionality. This principle promotes proper inheritance.

**Example in C++:**

Suppose you have a base class `Bird`:

```cpp
class Bird {
public:
    virtual void fly() {
        std::cout << "Bird is flying" << std::endl;
    }
};
```

A subclass `Penguin` should not violate the LSP:

```cpp
class Penguin : public Bird {
public:
    void fly() override {
        throw std::runtime_error("Penguins can't fly!");  // Violates LSP
    }
};
```

Instead, design it correctly:

```cpp
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

### 4. **Interface Segregation Principle (ISP)**
- **Definition**: Clients should not be forced to depend on interfaces they do not use.
- **Explanation**: Rather than having one large interface, create smaller, more specific ones so that clients only need to know about the methods that are relevant to them.

**Example in C++:**

Instead of a large interface:

```cpp
class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
};
```

Apply ISP by creating smaller, more specific interfaces:

```cpp
class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() {}
};

class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() {}
};

class Worker : public Workable, public Eatable {
public:
    void work() override {
        std::cout << "Worker is working" << std::endl;
    }

    void eat() override {
        std::cout << "Worker is eating" << std::endl;
    }
};
```

### 5. **Dependency Inversion Principle (DIP)**
- **Definition**: High-level modules should not depend on low-level modules. Both should depend on abstractions. Abstractions should not depend on details; details should depend on abstractions.
- **Explanation**: This principle promotes loose coupling between different modules or layers of an application.

**Example in C++:**

Instead of directly depending on low-level modules:

```cpp
class BackendDeveloper {
public:
    std::string develop() {
        return "Writing C++ code";
    }
};

class FrontendDeveloper {
public:
    std::string develop() {
        return "Writing JavaScript code";
    }
};

class Project {
public:
    Project() : backend(new BackendDeveloper()), frontend(new FrontendDeveloper()) {}

    ~Project() {
        delete backend;
        delete frontend;
    }

    std::string develop() {
        return backend->develop() + " and " + frontend->develop();
    }

private:
    BackendDeveloper* backend;
    FrontendDeveloper* frontend;
};
```

Apply DIP by introducing abstractions:

```cpp
class Developer {
public:
    virtual std::string develop() = 0;
    virtual ~Developer() {}
};

class BackendDeveloper : public Developer {
public:
    std::string develop() override {
        return "Writing C++ code";
    }
};

class FrontendDeveloper : public Developer {
public:
    std::string develop() override {
        return "Writing JavaScript code";
    }
};

class Project {
public:
    Project(const std::vector<Developer*>& devs) : developers(devs) {}

    std::string develop() {
        std::string result;
        for (auto& developer : developers) {
            result += developer->develop() + " and ";
        }
        result = result.substr(0, result.size() - 5);  // Remove the last " and "
        return result;
    }

private:
    std::vector<Developer*> developers;
};
```

### Conclusion

By applying the **SOLID principles** in C++, you create a clean, modular, and maintainable codebase. These principles encourage proper use of object-oriented design, such as inheritance and polymorphism, leading to more robust, flexible, and testable software. By adhering to these principles, the code is more understandable and adaptable to changes in requirements.
