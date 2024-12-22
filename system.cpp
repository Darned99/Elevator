#include <iostream>
#include <vector>
#include "elevator.hpp"
#include "system.hpp"


    // System WIP
namespace bk{
    
    bk::System::System() {};
        
    
        

    void bk::System::LinePrint(int length, int counter) {
        std::cout << "\n";
        for (int i = 0; i < length; i++) {
            std::cout << "=";
        }
        std::cout << " [counter: " << counter << "]\n"; 
    }


};
