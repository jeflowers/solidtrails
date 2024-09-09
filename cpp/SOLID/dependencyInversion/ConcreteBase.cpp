#pragma once
/**
 * @file ConcreteBase.cpp
 * @author chitownj
 * @date 9/9/24
 * @brief [Brief description of the file]
 *
 * Phase 1:  Concrete Class Implementation
 * We start with a simple Marine class that represents a single unit in the game.
 * The class has basic attributes (name, health, ammo) and actions (move, shoot).
 * This approach is straightforward but limited in flexibility and extensibility.
 */
// TODO: Implement this class
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Marine {
public:
    Marine(const strng &name, int health, int ammo)
            : m_name(name), m_health(health), m_ammo(ammo) {}

    void move(int distance) {
        cout << m_name << " moved " << distance << " meters. " << endl;
    }

    void shoot() {
        if (m_ammo > 0) {
            m_ammo--;
            cout << m_name << " fired a shot. Ammo left: " << m_ammo << endl;
        } else {
            cout << m_name << " is out of ammo!" << endl;
        }
    }

private:
    string m_name;
    int m_health;
    int ammo;

};

// Usage
/*
 * // Usage
 * int main() {
 * Marine marine("John Doe", 100, 30);
 * marine.move(50);
 * marine.shoot();
 * return 0;
}
*/
