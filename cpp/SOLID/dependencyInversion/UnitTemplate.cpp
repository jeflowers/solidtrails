/**
 * @file UnitTemplate.cpp UnitTemplate.cpp
 * @author chitownj
 * @date 9/9/24
 * @brief [Brief description of the file]
 *
 * [Detailed description if needed]
 */
// TODO: Implement this class

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T> class UnitTemplate {
public:
    UnitTemplate(const string& name, T health) : m_name, m_health(health) {}
    virtual void move(T distance) = 0;
    virtual void action() = 0;
    virtual ~UnitTemplate() = default;

protected:
    string m_name;
    T m_health;
};

template  <typename T> class Marine : public Unit<T> {
public:
    Marine(const string& name, T health, T ammo) : Unit<T>(name, health), m_ammo(ammo) {}

    void move(T distance) override {
        cout << this->m_name << " moved " << distance << " meters. " << endl;
    }

    void action() override {
        shoot();
    }

private:
    void shoot(){
        if(m_ammo > 0) {
            m_ammo--;
            cout << this->m_name << " fired a shot.  Ammo left: " << endl;
        } else {
            cout << this->m_name << " is out of ammo!! " << endl;
        }
    }

    T m_ammo;
};

// New class utilizing the template
template <typename T>
class Medic : public Unit<T> {
public:
    Medic(const std::string& name, T health, T medkits)
            : Unit<T>(name, health), m_medkits(medkits) {}

    void move(T distance) override {
        std::cout << this->m_name << " moved " << distance << " meters." << std::endl;
    }

    void action() override {
        heal();
    }

private:
    void heal() {
        if (m_medkits > 0) {
            m_medkits--;
            std::cout << this->m_name << " used a medkit. Medkits left: " << m_medkits << std::endl;
        } else {
            std::cout << this->m_name << " is out of medkits!" << std::endl;
        }
    }

    T m_medkits;
};

// Template function for unit actions
template <typename T>
void performMission(std::vector<Unit<T>*>& units, T moveDistance) {
    for (auto unit : units) {
        unit->move(moveDistance);
        unit->action();
    }
}
