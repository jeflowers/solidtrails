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
    CodeBuilder(const string& class_name) : class_name(class_name) {}

    CodeBuilder& add_field(const string& name, const string& type)
    {
        // Store name and type in the correct order
        fields.emplace_back(name, type);
        return *this;
    }

    friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
    {
        os << "class " << obj.class_name << "\n{\n";
        for (const auto& field : obj.fields)
        {
            // Corrected order: type first, then name
            os << "  " << field.second << " " << field.first << ";\n";
        }
        os << "};";
        return os;
    }
};
