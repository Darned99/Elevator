#pragma once
#include <iostream>
#include "elevator.hpp"


    // System WIP
namespace bk{
    class System{
        private:
            
            double m_id;
            

        public:
           
        // Potential methods for elevator system
        void isAbove();
        void isBelow();

        void LinePrint(int length, int counter);
        void elevatorStatus();
    };
}