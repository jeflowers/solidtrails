/**
 * @file ResourecMgmtUnitTemplate.cpp
 * @author chitownj
 * @date 9/9/24
 * @brief [Brief description of the file]
 *
 * 
 */
// TODO: Implement this class

#include <iostream>
#include <string>
#include <vector>

// Resource management mixin
template <typename T, typename DerivedClass>
class ResourceManager {
public:
    ResourceManager(const std::string& resourceName, T initialAmount)
            : m_resourceName(resourceName), m_resourceAmount(initialAmount) {}

    void useResource() {
        if (m_resourceAmount > 0) {
            m_resourceAmount--;
            std::cout << static_cast<DerivedClass*>(this)->getName()
                      << " used a " << m_resourceName << ". "
                      << m_resourceName << " left: " << m_resourceAmount << std::endl;
        } else {
            std::cout << static_cast<DerivedClass*>(this)->getName()
                      << " is out of " << m_resourceName << "!" << std::endl;
        }
    }

protected:
    std::string m_resourceName;
    T m_resourceAmount;
};

template <typename T>
class Unit {
public:
    Unit(const std::string& name, T health) : m_name(name), m_health(health) {}
    virtual void move(T distance) = 0;
    virtual void action() = 0;
    virtual ~Unit() = default;

    const std::string& getName() const { return m_name; }

protected:
    std::string m_name;
    T m_health;
};

template <typename T>
class Marine : public Unit<T>, public ResourceManager<T, Marine<T>> {
public:
    Marine(const std::string& name, T health, T ammo)
            : Unit<T>(name, health), ResourceManager<T, Marine<T>>("ammo", ammo) {}

    void move(T distance) override {
        std::cout << this->m_name << " moved " << distance << " meters." << std::endl;
    }

    void action() override {
        this->useResource();  // Uses ammo
    }
};

template <typename T>
class Medic : public Unit<T>, public ResourceManager<T, Medic<T>> {
public:
    Medic(const std::string& name, T health, T medkits)
            : Unit<T>(name, health), ResourceManager<T, Medic<T>>("medkit", medkits) {}

    void move(T distance) override {
        std::cout << this->m_name << " moved " << distance << " meters." << std::endl;
    }

    void action() override {
        this->useResource();  // Uses medkit
    }
};

// New class: Engineer
template <typename T>
class Engineer : public Unit<T>, public ResourceManager<T, Engineer<T>> {
public:
    Engineer(const std::string& name, T health, T tools)
            : Unit<T>(name, health), ResourceManager<T, Engineer<T>>("tool", tools) {}

    void move(T distance) override {
        std::cout << this->m_name << " moved " << distance << " meters." << std::endl;
    }

    void action() override {
        this->useResource();  // Uses tool
    }
};

// Template function for unit actions
template <typename T>
void performMission(std::vector<Unit<T>*>& units, T moveDistance) {
    for (auto unit : units) {
        unit->move(moveDistance);
        unit->action();
    }
}

/*
 * int main() {
    std::vector<Unit<int>*> units;
    units.push_back(new Marine<int>("John Doe", 100, 30));
    units.push_back(new Medic<int>("Jane Smith", 80, 5));
    units.push_back(new Engineer<int>("Bob Builder", 90, 10));

    std::cout << "Mission start:" << std::endl;
    performMission(units, 50);

    // Clean up
    for (auto unit : units) delete unit;

    return 0;
}
 */
