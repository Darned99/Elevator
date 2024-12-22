#pragma once
#include <iostream>
#include <queue>
#include <vector>

enum direction {up, down, idle}; //idle non operating in that moment

namespace bk {
    class Elevator {
        protected:
            int m_CurrentFloor;
            int m_MaxFloor;
            int m_MinFloor;
            bool m_isOperational; //Assuming that our elevator is always operational
            direction m_CurrentDirection;
            std::queue<int> m_requests; //simple fifo buffer
            std::vector<int> buffer;

        public:
            Elevator(int CurrentFloor, int maxFloor, int minFloor);

            
            // Overloaded operators
            bool operator==(const Elevator& other) const;
            bool operator!=(const Elevator& other) const;
            

            // Setters and getters
            
            void setCurrentFloor(int CurrentFloor);
            int getCurrentFloor() const;

            // Funtions responsible for movement
            void MoveUp();
            void MoveDown();
            void stop();
            void MoveToFloor();

            void addTargetFloor(int floor);   

            const std::vector<int>& getBuffer() const;
            int getNextTarget() const;
            
            ~Elevator();
    };
};