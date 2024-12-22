#pragma once

#include <iostream>
#include <vector>
#include "elevator.hpp"

// Stałe systemowe
constexpr int NUM_FLOORS = 30;
constexpr int NUM_ELEVATORS = 5;
constexpr int BUFF_SIZE = NUM_FLOORS;

namespace bk {
    class System {
    private:
        std::vector<Elevator> elevators; // Kolekcja wind
        void LinePrint(int length, int counter) const; // Pomocnicza metoda formatowania

    public:
        // Konstruktory
        System();
        System(int numElevators, int maxFloors);

        // Destruktor
        ~System();

        // Metody systemu
        void performNextStep();
        void elevatorStatus() const;
        void addElevator(const Elevator& elevator);

        // Metody pomocnicze
        bool isAbove(int elevatorIndex, int floor) const;
        bool isBelow(int elevatorIndex, int floor) const;
    };
}

