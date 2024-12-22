#include <iostream>
#include <vector>
#include "elevator.hpp"
#include "system.hpp"


    // System WIP
namespace bk{
    
    bk::System::System(int numElevators, int maxFloors) {
    for (int i = 0; i < numElevators; ++i) {
        elevators.emplace_back(0, maxFloors, 0); // Tworzenie wind
    }
}

    void bk::System::LinePrint(int length, int counter) const {
        std::cout << "\n";
        for (int i = 0; i < length; i++) {
            std::cout << "=";
        }
        std::cout << " [counter: " << counter << "]\n"; 
    }

    void bk::System::elevatorStatus() const {
        static int counter = 0;

        LinePrint(84, counter++);

        for (size_t i = 0; i < elevators.size(); ++i) {
            const Elevator& elevator = elevators[i];
            std::cout << "Elevator " << i << ":\n";
            std::cout << "\tCurrent floor: " << elevator.getCurrentFloor()
                    << " || Next target: " << elevator.getNextTarget()
                    << " || Floors in queue: ";
            for (const int floor : elevator.getBuffer()) {
                std::cout << floor << ", ";
            }
            std::cout << "\n";
        }
    }


    void bk::System::performNextStep() {
        for (auto &elevator : elevators) {
            elevator.MoveToFloor();
        }
    }


    void bk::System::addElevator(const Elevator& elevator) {
        elevators.push_back(elevator);
}



};
