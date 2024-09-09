Dep
A. high-level modules should not depend on low-level modules.
Both should depend on abstractions.
B. Abstractions should not depend on details
Details should depend on abstractions

What do we mean by abstraction?
When we talk about abstraction we are talking about interfaces or base classes.

The code in the ConcreteBase.cpp, BaseToAbstract.cpp, and AbstractToTemplate.cpp are examples that evolves from a concrete class to a template-based solution using the USMC Tactical Decision Game (TDG) scenario. We'll go through phases, starting with a basic concrete implementation and gradually refactoring to a more flexible template-based design.

## Evolution of this code in the context of the USMC Tactical Decision Game scenario:

### Phase 1: Concrete Class Implementation

We start with a simple Marine class that represents a single unit in the game.
The class has basic attributes (name, health, ammo) and actions (move, shoot).
This approach is straightforward but limited in flexibility and extensibility.


### Phase 2: Introduction of Abstract Base Class

We introduce an abstract Unit class to represent different types of units.
Marine now inherits from Unit, allowing for polymorphism.
This design allows for easier addition of new unit types (e.g., we could add a Sniper or Medic class).
We can now manage a collection of different unit types through the base class pointer.


### Phase 3: Introduction of Templates

We refactor the code to use templates, parameterizing the numeric types used for health, ammo, and distances.
This allows for more flexibility in how we represent these values (e.g., integers for discrete values, floating-point for more precise simulations).
We introduce a new Medic class to demonstrate how easily we can add new unit types.
The performMission function template shows how we can write generic code that works with any unit type and numeric representation.


## Benefits of the Final Template-based Design:

Flexibility: We can now easily create units with different numeric precisions (int, double, float) without code duplication.
Extensibility: Adding new unit types (like the Medic class) is straightforward and doesn't require changes to existing code.
Type Safety: The use of templates ensures type consistency within each unit instance.
Reusability: The performMission function can work with any type of unit and any numeric type.
Simulation Accuracy: By allowing floating-point types, we can model more precise movements or partial resource usage if needed.

In the context of the USMC TDG:

This design allows for more complex and varied scenarios. We could easily add different unit types with unique actions (e.g., Sniper, Engineer).
The flexibility in numeric types allows for different levels of simulation precision. Integer-based units might be sufficient for basic scenarios, while floating-point units could be used for more detailed simulations.
The template-based design makes it easier to adapt the code for different types of tactical simulations or game scenarios without major rewrites.

This evolution demonstrates how we can start with a simple concrete implementation and gradually refactor it to a more flexible, reusable, and extensible design using C++ templates, all within the context of a tactical decision game scenario.
