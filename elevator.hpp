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

            void setMaxFloor(int MaxFloor);
            int getMaxFloor() const;

            void setMinFloor(int MinFloor);
            int getMinFloor() const;
            

            // Funtions responsible for movement
            void moveUp();
            void moveDown();
            void stop();
            void moveToFloor(int destinationFloor);

            void MoveUp();
            void MoveDown();
            void MoveToFloor();

            // Functions for requests using FIFO queue
            void addTargetFloor(int floor);            
            int getNextTarget();
            void processRequests();

            int getQueueSize() const;
            direction getDirection() const;

            ~Elevator();
    };
};