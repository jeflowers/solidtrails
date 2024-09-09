
#pragma once
/**
 * @file Unit.cpp
 * @author chitownj
 * @date 9/9/24
 * @brief [Brief description of the file]
 *
 * Phase 2: Introduction of Abstract Base Class
 * We introduce an abstract Unit class to represent different types of units.
 * Marine now inherits from Unit, allowing for polymorphism.
 * This design allows for easier addition of new unit types (e.g., we could add a Sniper or Medic class).
 * We can now manage a collection of different unit types through the base class pointer.
 *
*/
// TODO: Implement this class

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Unit {
public:
    Unit(const string& name, int health) : m_name(name), m_health(health) {}
    virtual void move(int distance) = 0;
    virtual void action() = 0;
    virtual ~Unit() = default;

protected:
    string m_name;
    int m_health;

};

class Marine : public Unit {
public:
    Marine(const string& name, int health, int ammo) : Unit(name, health), m_ammo(ammo) {}

    void move(int distance ) override {
        cout << m_name << " moved " << distance << " meters. " << endl;
    }

    void action() override {
        shoot()
    }
private:
    void shoot() {
        if(m_ammo >  0 ) {
            m_ammo--;
            cout << m_name << " fired a shot.  Ammo left: " << m_ammo << endl;
        } else {
            cout << m_name << " is out of ammo!" << endl;
        }
    }

    int ammo;
};

/* Usage
 * int main() {
 *    vecto<Unit> units;
 *    units.push_back(new Marine("John Doe", 100, 30));
 *    units.push_back(new Marine("Jane Smith", 100, 25));
 *
 *      for (auto unit : units) {
 *          unit->move(50);
 *          unit->action();
 *          delete unit;
 *      }
 *      return 0;
 * }
 *
 */
