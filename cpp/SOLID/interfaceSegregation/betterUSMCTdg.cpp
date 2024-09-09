#include <iostream>
#include <string>

class Weapon {
public:
    virtual void use_as_weapon() = 0;
    virtual ~Weapon() = default;
};

class NavigationTool {
public:
    virtual void use_for_navigation() = 0;
    virtual ~NavigationTool() = default;
};

class CommunicationTool {
public:
    virtual void use_for_communication() = 0;
    virtual ~CommunicationTool() = default;
};

class SurvivalTool {
public:
    virtual void use_for_survival() = 0;
    virtual ~SurvivalTool() = default;
};

class Rifle : public Weapon, public SurvivalTool {
public:
    void use_as_weapon() override;
    void use_for_survival() override;
};

class Compass : public NavigationTool, public SurvivalTool {
public:
    void use_for_navigation() override;
    void use_for_survival() override;
};

class Radio : public CommunicationTool, public SurvivalTool {
public:
    void use_for_communication() override;
    void use_for_survival() override;
};

// File: good_design.cpp
#include "good_design.h"

void Rifle::use_as_weapon() {
    std::cout << "Using rifle to engage target" << std::endl;
}

void Rifle::use_for_survival() {
    std::cout << "Using rifle to hunt for food" << std::endl;
}

void Compass::use_for_navigation() {
    std::cout << "Using compass to determine direction" << std::endl;
}

void Compass::use_for_survival() {
    std::cout << "Using compass to find way back to safety" << std::endl;
}

void Radio::use_for_communication() {
    std::cout << "Using radio to call for support" << std::endl;
}

void Radio::use_for_survival() {
    std::cout << "Using radio to call for rescue" << std::endl;
}

// File: good_client.cpp
#include "good_design.h"

void use_weapon(Weapon& weapon) {
    weapon.use_as_weapon();
}

void navigate(NavigationTool& nav_tool) {
    nav_tool.use_for_navigation();
}

void communicate(CommunicationTool& comm_tool) {
    comm_tool.use_for_communication();
}

void survive(SurvivalTool& survival_tool) {
    survival_tool.use_for_survival();
}

int main() {
    Rifle rifle;
    Compass compass;
    Radio radio;

    std::cout << "Using Rifle:" << std::endl;
    use_weapon(rifle);
    survive(rifle);

    std::cout << "\nUsing Compass:" << std::endl;
    navigate(compass);
    survive(compass);

    std::cout << "\nUsing Radio:" << std::endl;
    communicate(radio);
    survive(radio);

    return 0;
}
