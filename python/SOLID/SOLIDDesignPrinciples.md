**SOLID design patterns** are a set of five principles that help developers create more maintainable, understandable, and flexible software systems. These principles were introduced by Robert C. Martin (Uncle Bob) and are widely used in object-oriented programming. Here’s a description of each SOLID principle with examples in Python:

### 1. **Single Responsibility Principle (SRP)**
- **Definition**: A class should have only one reason to change, meaning it should only have one job or responsibility.
- **Explanation**: If a class has more than one responsibility, those responsibilities become coupled, and changes to one responsibility may affect the other. SRP promotes separation of concerns, leading to more modular and easier-to-maintain code.

**Example in Python:**

Instead of having a class that handles both user data and its storage:

```python
class User:
    def __init__(self, name, email):
        self.name = name
        self.email = email

    def save_to_database(self):
        # Code to save user data to the database
        pass
```

Apply SRP by separating concerns:

```python
class User:
    def __init__(self, name, email):
        self.name = name
        self.email = email

class UserRepository:
    def save_to_database(self, user: User):
        # Code to save user data to the database
        pass
```

### 2. **Open/Closed Principle (OCP)**
- **Definition**: Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification.
- **Explanation**: You should be able to add new functionality without changing existing code, which reduces the risk of introducing new bugs. This can be achieved using inheritance and interfaces.

**Example in Python:**

Suppose you have a `Shape` class for calculating the area:

```python
class Rectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height
```

If you want to add new shapes, don’t modify the existing code. Instead, extend it:

```python
from abc import ABC, abstractmethod

class Shape(ABC):
    @abstractmethod
    def area(self):
        pass

class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return 3.14 * self.radius * self.radius
```

### 3. **Liskov Substitution Principle (LSP)**
- **Definition**: Subtypes must be substitutable for their base types without altering the correctness of the program.
- **Explanation**: If a class `B` is a subclass of class `A`, then objects of type `A` should be replaceable with objects of type `B` without affecting the functionality of the program. This principle promotes the use of interfaces and abstract classes.

**Example in Python:**

Suppose you have a base class `Bird`:

```python
class Bird:
    def fly(self):
        print("Bird is flying")
```

A subclass `Penguin` should not violate the `LSP`:

```python
class Bird:
    def fly(self):
        print("Bird is flying")

class Penguin(Bird):
    def fly(self):
        raise Exception("Penguins can't fly!")
```

Instead, design it correctly:

```python
class Bird(ABC):
    @abstractmethod
    def move(self):
        pass

class FlyingBird(Bird):
    def move(self):
        print("Bird is flying")

class Penguin(Bird):
    def move(self):
        print("Penguin is swimming")
```

### 4. **Interface Segregation Principle (ISP)**
- **Definition**: Clients should not be forced to depend on interfaces they do not use.
- **Explanation**: Instead of having a single, "fat" interface, it’s better to have multiple, smaller, and more specific interfaces so that clients only need to know about the methods that are of interest to them.

**Example in Python:**

Instead of having a large interface:

```python
class Worker:
    def work(self):
        pass

    def eat(self):
        pass
```

Apply ISP by creating smaller, more specific interfaces:

```python
class Workable(ABC):
    @abstractmethod
    def work(self):
        pass

class Eatable(ABC):
    @abstractmethod
    def eat(self):
        pass

class Worker(Workable, Eatable):
    def work(self):
        print("Worker is working")

    def eat(self):
        print("Worker is eating")
```

### 5. **Dependency Inversion Principle (DIP)**
- **Definition**: High-level modules should not depend on low-level modules. Both should depend on abstractions. Also, abstractions should not depend on details; details should depend on abstractions.
- **Explanation**: This principle promotes loose coupling between different modules and layers of an application.

**Example in Python:**

Instead of directly depending on low-level modules:

```python
class BackendDeveloper:
    def develop(self):
        return "Writing Python code"

class FrontendDeveloper:
    def develop(self):
        return "Writing JavaScript code"

class Project:
    def __init__(self):
        self.backend = BackendDeveloper()
        self.frontend = FrontendDeveloper()

    def develop(self):
        return f"{self.backend.develop()} and {self.frontend.develop()}"
```

Apply DIP by introducing abstractions:

```python
from abc import ABC, abstractmethod

class Developer(ABC):
    @abstractmethod
    def develop(self):
        pass

class BackendDeveloper(Developer):
    def develop(self):
        return "Writing Python code"

class FrontendDeveloper(Developer):
    def develop(self):
        return "Writing JavaScript code"

class Project:
    def __init__(self, developers: List[Developer]):
        self.developers = developers

    def develop(self):
        results = [developer.develop() for developer in self.developers]
        return " and ".join(results)
```

### Conclusion

These **SOLID principles** in Python help create a clean, maintainable, and extendable codebase, enhancing software design and making the code easier to understand, test, and modify over time. By adhering to these principles, you can avoid tightly coupled designs and create more flexible and robust applications.
