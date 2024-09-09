//
// Created by chitownj on 9/8/24.
//
#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Abstract base class defining the contract for all navigation strategies
// This adheres to the Liskov Substitution Principle by providing a common interface
class NavigationStrategy {
public:
    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~NavigationStrategy() = default;

    // Pure virtual function that derived classes must implement
    // This defines the contract that all navigation strategies must follow
    virtual std::string navigate(const std::string& start, const std::string& end) const = 0;
};

// Concrete implementation of NavigationStrategy using a lensatic compass
class LensaticCompassStrategy : public NavigationStrategy {
public:
    // Override the navigate function to provide specific implementation
    std::string navigate(const std::string& start, const std::string& end) const override {
        return "Navigating from " + start + " to " + end + " using a lensatic compass for precise bearings.";
    }
};

// Concrete implementation of NavigationStrategy using a map
class MapStrategy : public NavigationStrategy {
public:
    // Another specific implementation of the navigate function
    std::string navigate(const std::string& start, const std::string& end) const override {
        return "Navigating from " + start + " to " + end + " using a map for terrain association.";
    }
};

// Concrete implementation of NavigationStrategy using GPS
class GPSStrategy : public NavigationStrategy {
public:
    // GPS-specific implementation of the navigate function
    std::string navigate(const std::string& start, const std::string& end) const override {
        return "Navigating from " + start + " to " + end + " using GPS for real-time positioning.";
    }
};

// Traveler class that uses a NavigationStrategy
// This class demonstrates the Liskov Substitution Principle in action
class Traveler {
private:
    // Use a unique_ptr to manage the lifecycle of the strategy object
    std::unique_ptr<NavigationStrategy> strategy;

public:
    // Constructor that takes any NavigationStrategy
    // This allows for dependency injection and flexibility in choosing strategies
    explicit Traveler(std::unique_ptr<NavigationStrategy> strategy)
        : strategy(std::move(strategy)) {}

    // Method to change the strategy at runtime
    // This demonstrates the ability to substitute different strategies
    void setStrategy(std::unique_ptr<NavigationStrategy> newStrategy) {
        strategy = std::move(newStrategy);
    }

    // Method that uses the current strategy to navigate
    // This method works with any NavigationStrategy, demonstrating Liskov Substitution
    std::string travel(const std::string& start, const std::string& end) const {
        return strategy->navigate(start, end);
    }
};

int main() {
    // Create a Traveler with an initial LensaticCompassStrategy
    Traveler traveler(std::make_unique<LensaticCompassStrategy>());
    std::cout << traveler.travel("Argentina", "US") << std::endl;

    // Change to MapStrategy - the Traveler class works without modification
    traveler.setStrategy(std::make_unique<MapStrategy>());
    std::cout << traveler.travel("Argentina", "US") << std::endl;

    // Change to GPSStrategy - again, no changes needed to Traveler
    traveler.setStrategy(std::make_unique<GPSStrategy>());
    std::cout << traveler.travel("Argentina", "US") << std::endl;

    return 0;
}



