// open closed principle
// open for extension, closed for modification

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//using namespace boost;

// each product has the following traits
enum class Color { red, green, blue };
enum class Size { small, medium, large };

// product with attributes or traits
struct Product {
    string name;
    Color color;
    Size size;
};


// Interfaces
// Specification interface: a filter criterion
template <typename T>
struct Specification {
    virtual bool is_satisfied(T* item) = 0;

};

// Filter interface
template <typename T>
struct Filter{
    virtual vector<T*> filter(const vector<T*>& items, const Specification<T>& spec) = 0;
};

// Filter by color specification
struct ColorSpecification : Specification<Product> {
    Color color;

    ColorSpecification(Color color) : color(color){}

    bool is_satisfied(Product* item) const override {
        return item->color == color;
    }
};

// Filter by size specification
struct SizeSpecification : Specification<Product> {
    Size size;

    SizeSpecification(Size size) : size(size){}

    bool is_satisfied(Product* item) const override{
        return item->size == size;
    }
};

// AndSpecification for combining filters
template <typename T>
struct AndSpecification : Specification<T> {
    const Specification<T>& first;
    const Specification<T>& second;

    AndSpecification(const Specification<T>& first, const Specification<T>& second)
    : first(first), second(second) {}

    bool is_satisfied(T* item) const override {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

// Concrete Filter implementation
struct ProductFilter : Filter<Product> {
    vector<Product*> filter(const vector<Product*>& items, const Specification<Product>& spec) override {
        vector<Product*> result;
        for(auto& item : items)
            // check to see if filter conforms to specification
            if(spec.is_satisfied(item))
                result.push_back(item);
        return result;
    }
};

int main()
{
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    vector<Product*>  all{ &apple, &tree, &house };

    ProductFilter pf;
    ColorSpecification green(Color::green);
    auto green_things = pf.filter(all, green);

    for(auto& item : green_things)
        cout << item->name << " is green\n";

    SizeSpecification large(Size::large);
    AndSpecification<Product> green_and_large(green, large);
    auto green_and_large_things = pf.filter(all, green_and_large);

    for(auto& item : green_and_large_things)
        cout << item->name << " is green and large\n";

    return 0;
}
