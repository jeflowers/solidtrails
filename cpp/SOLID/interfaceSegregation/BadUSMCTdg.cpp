// bad design - violating ISP
#include <iostream>
#include <string>

class Equipment {
public:
    virtual void use_as_weapon() = 0;
    virtual void use_for_navigation() = 0;
    virtual void use_for_communication() = 0;
    virtual void use_for_survival() = 0;
    virtual ~Equipment() = default;
};

class Rifle : public Equipment {
public:
    void use_as_weapon() override;
    void use_for_navigation() override;
    void use_for_communication() override;
    void use_for_survival() override;
};

class Compass : public Equipment {
public:
    void use_as_weapon() override;
    void use_for_navigation() override;
    void use_for_communication() override;
    void use_for_survival() override;
};

class Radio : public Equipment {
public:
    void use_as_weapon() override;
    void use_for_navigation() override;
    void use_for_communication() override;
    void use_for_survival() override;
};

// File: bad_design.cpp
#include "bad_design.h"
#include <stdexcept>

void Rifle::use_as_weapon() {
    std::cout << "Using rifle to engage target" << std::endl;
}

void Rifle::use_for_navigation() {
    throw std::runtime_error("Rifle cannot be used for navigation");
}

void Rifle::use_for_communication() {
    throw std::runtime_error("Rifle cannot be used for communication");
}

void Rifle::use_for_survival() {
    std::cout << "Using rifle to hunt for food" << std::endl;
}

void Compass::use_as_weapon() {
    throw std::runtime_error("Compass cannot be used as a weapon");
}

void Compass::use_for_navigation() {
    std::cout << "Using compass to determine direction" << std::endl;
}

void Compass::use_for_communication() {
    throw std::runtime_error("Compass cannot be used for communication");
}

void Compass::use_for_survival() {
    std::cout << "Using compass to find way back to safety" << std::endl;
}

void Radio::use_as_weapon() {
    throw std::runtime_error("Radio cannot be used as a weapon");
}

void Radio::use_for_navigation() {
    throw std::runtime_error("Radio cannot be used for navigation");
}

void Radio::use_for_communication() {
    std::cout << "Using radio to call for support" << std::endl;
}

void Radio::use_for_survival() {
    std::cout << "Using radio to call for rescue" << std::endl;
}

// File: bad_client.cpp
#include "bad_design.h"

void use_equipment(Equipment& eq) {
    eq.use_as_weapon();
    eq.use_for_navigation();
    eq.use_for_communication();
    eq.use_for_survival();
}

int main() {
    Rifle rifle;
    Compass compass;
    Radio radio;

    std::cout << "Using Rifle:" << std::endl;
    use_equipment(rifle);  // This will throw exceptions

    std::cout << "\nUsing Compass:" << std::endl;
    use_equipment(compass);  // This will throw exceptions

    std::cout << "\nUsing Radio:" << std::endl;
    use_equipment(radio);  // This will throw exceptions

    return 0;
}
