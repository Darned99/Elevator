#include <iostream>
#include "elevator.hpp"
//#include "system.hpp"



int main(){
    
    /*double number_of_elevators;
    double number_of_floors;

    std::cout << "Set up program. How many elevator would you like" << std::endl;
    std::cin >> number_of_elevators;

    std::cout << "How many floors are in the building?" << std::endl;
    std::cin >> number_of_floors;
    std::cout << ""
    */

    int CurrentFloor;
    int MaxFloor;
    int MinFloor;
    int TargetFloor;

    std::cout << "Set up program:\n";
    std::cout << "Enter starting floor: ";
    std::cin >> CurrentFloor;

    std::cout << "Enter top floor: ";
    std::cin >> MaxFloor;
    
    std::cout << "Enter bottom floor: ";
    std::cin >> MinFloor;

    bk::Elevator elevator(CurrentFloor, MaxFloor, MinFloor);

    std::cout << "\nEnter actions.\n";

    while (true) {
        std::cout << "\nChoose an option:\n";
        std::cout << "1. Set target floor\n";
        std::cout << "2. Do nothing (possible movement simulation)\n";
        std::cout << "Enter your choice (1 or 2): ";
        
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter destination floor: ";
            std::cin >> TargetFloor;
            elevator.addTargetFloor(TargetFloor);
            elevator.MoveToFloor();
        }
        else if (choice == 2) {
            if (elevator.getBuffer().empty()) {
                std::cout << "No requests in buffer. Elevator is idle.\n";
            } else {
                if (elevator.getNextTarget() > elevator.getCurrentFloor()){
                    std::cout << "Elevator goes one floor up\n";
                    elevator.MoveUp();
                }
                else if (elevator.getNextTarget() < elevator.getCurrentFloor()){
                    std::cout << "Elevator goes one floor down\n";
                    elevator.MoveDown();
                }
            }
        }
        else {
            std::cout << "Invalid choice. Please select 1 or 2.\n";
        }
    }

    return 0;

    /*
    std::cout << "Set up program. Which floor we're starting at: ";
    std::cin >> CurrentFloor;
    std::cout << " What's the top floor the building has: ";
    std::cin >> MaxFloor;
    std::cout << " What's the bottom floor the building has: ";
    std::cin >> MinFloor;

    bk::Elevator elevator(CurrentFloor, MaxFloor, MinFloor);

    std::cout << "Proceed to enter destination: ";
    std::cin >> TargetFloor;
    elevator.addTargetFloor(TargetFloor);       //Example 7
    //elevator.processRequests();
    
    std::cout << "Proceed to enter destination: ";
    std::cin >> TargetFloor;
    elevator.addTargetFloor(TargetFloor);       //Example -3
    //elevator.processRequests();
    
    
    std::cout << "Proceed to enter destination: ";
    std::cin >> TargetFloor;
    elevator.addTargetFloor(TargetFloor);       //Example 11
    //elevator.processRequests();

    while (true) {
        elevator.MoveToFloor();
        if (std::cin.get() == 'q' ) break;
    }
    */
    
    //elevator.processRequests();

    //return 0;
}