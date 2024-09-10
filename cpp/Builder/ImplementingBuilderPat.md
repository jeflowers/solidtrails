# Tutorial: Implementing the Builder Pattern for Code Generation

## Introduction

In this tutorial, we'll implement the Builder design pattern to generate simple chunks of code. The Builder pattern is particularly useful when constructing complex objects step by step. In our case, we'll use it to build class definitions dynamically.

## Requirements

We need to create a `CodeBuilder` class with the following functionality:
- Initialize with a class name
- Add fields (name and type) to the class
- Generate a formatted string representation of the class

The usage should look like this:

```cpp
auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
cout << cb;
```

And produce this output:

```
class Person
{
  string name;
  int age;
};
```

## Implementation

Here's the final, correct implementation of the `CodeBuilder` class:

```cpp
#include <string>
#include <ostream>
#include <vector>
#include <utility> // Required for std::pair
using namespace std;

class CodeBuilder
{
private:
    string class_name;
    vector<pair<string, string>> fields;
    
public:
    CodeBuilder(const string& class_name): class_name(class_name) {}
  
    CodeBuilder& add_field(const string& name, const string& type)
    {
        fields.emplace_back(name, type);
        return *this;
    }

    friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
    {
        os << "class " << obj.class_name << "\n{\n";
        for (const auto& field : obj.fields)
        {
            os << "  " << field.second << " " << field.first << ";\n";
        }
        os << "};";
        return os;
    }
};
```

## Analysis of the Implementation

### Key Components

1. **Class Structure**: 
   - Private members: `class_name` (string) and `fields` (vector of string pairs)

2. **Constructor**:
   ```cpp
   CodeBuilder(const string& class_name): class_name(class_name) {}
   ```
   Uses an initializer list for efficient member initialization.

3. **add_field Method**:
   ```cpp
   CodeBuilder& add_field(const string& name, const string& type)
   {
     fields.emplace_back(name, type);
     return *this;
   }
   ```
   - Adds a new field to the `fields` vector
   - Returns `*this` for method chaining

4. **operator<< Overload**:
   ```cpp
   friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
   {
     os << "class " << obj.class_name << "\n{\n";
     for (const auto& field : obj.fields)
     {
       os << "  " << field.second << " " << field.first << ";\n";
     }
     os << "};";
     return os;
   }
   ```
   Generates the formatted class definition string.

### Why It Works

1. **Correct Formatting**: 
   - Includes newlines and proper indentation
   - Matches the expected format in the tests

2. **Field Order**: 
   - Correctly outputs type before name for each field

3. **Efficient Implementation**: 
   - Uses `emplace_back` for in-place construction of elements

4. **Proper Initialization**: 
   - Constructor uses an initializer list

5. **Method Chaining**: 
   - `add_field` returns `*this`, enabling fluent interface design

### Potential Improvements

1. **Error Handling**: 
   - Add checks for invalid input (e.g., empty class names)

2. **Customization Options**: 
   - Allow customization of indentation or brace styles

3. **Move Semantics**: 
   - Implement move constructor and move assignment operator

4. **Const Correctness**: 
   - Mark non-modifying methods as `const`

## Conclusion

This implementation successfully applies the Builder pattern to generate simple class definitions. It provides a clean, intuitive interface and produces correctly formatted output. The design allows for easy extension and modification, making it a solid foundation for more complex code generation tasks.
