//
// Created by chitownj on 9/8/24.
//
#include <iostream>
#include <string>
#include <vector>
#include <memory>

/*
 * Identify the Base Class or Interface In our example, we start by defining a base class or
 * interface that represents the common behavior:
 */

class NavigationStrategy {
public:
    virtual ~NavigationStrategy() = default;
    virtual std::string navigate(const std::string& start, const std::string& end)
};
// This NavigationStrategy class defines the contract that all navigation strategies must follow.

/*
 * Create Derived Classes:  create implementations that inherit from the base class:
 */
class LensaticCompassStrategy : public NavigationStrategy {
public:
    std::string navigate(const std::string& start, const std::string& end) const override {
        return "Navigating from " + start + " to " + end + " using a lensatic compass for precise bearings.";
    }
};
/*
 * Each derived class provides its own implementation of the navigate function.
 */

/*
 * Each derived class provides its own implementation of the navigate function.
Step 4: Design Client Code to Use the Base Class
Create a class that uses the NavigationStrategy without knowing the specific implementation:
 */
class Traveler {
private:
    std::unique_ptr<NavigationStrategy> strategy;

public:
    explicit Traveler(std::unique_ptr<NavigationStrategy> strategy)
            : strategy(std::move(strategy)) {}

    void setStrategy(std::unique_ptr<NavigationStrategy> newStrategy) {
        strategy = std::move(newStrategy);
    }

    std::string travel(const std::string& start, const std::string& end) const {
        return strategy->navigate(start, end);
    }
};
/*
 * The Traveler class works with any NavigationStrategy without knowing its specific type.
 */

/*
 * Step 5: Demonstrate Substitutability
Show that you can use different derived classes interchangeably:
 */
int main() {
    Traveler traveler(std::make_unique<LensaticCompassStrategy>());
    std::cout << traveler.travel("Argentina", "US") << std::endl;

    traveler.setStrategy(std::make_unique<MapStrategy>());
    std::cout << traveler.travel("Argentina", "US") << std::endl;

    traveler.setStrategy(std::make_unique<GPSStrategy>());
    std::cout << traveler.travel("Argentina", "US") << std::endl;

    return 0;
}

/*
 * Step 6: Verify LS Principle Compliance
 * To ensure your design follows the LS principle, check that:
 *  The Traveler class doesn't need to change when you add new navigation strategies.
 *  You can replace any NavigationStrategy with another without breaking the Traveler class.
 *  The behavior of the program remains correct regardless of which specific strategy is used.
 */



