/****************************************************************************************************
 * This file is part of System for Elevator service
 * 
 ****************************************************************************************************/

#include <iostream>
#include <queue> //Needed for FIFO buffer
#include <vector>
#include <algorithm>
#include "elevator.hpp"

namespace bk{
    
    bk::Elevator::Elevator(int CurrentFloor,int MaxFloor, int MinFloor) : 
        m_CurrentFloor(CurrentFloor), m_CurrentDirection(direction::idle),
        m_MaxFloor(MaxFloor), m_MinFloor(MinFloor), m_isOperational(true) {
        
        std::cout << "Constructor: " << "Current floor: " << CurrentFloor <<
        " Max Floor: " << MaxFloor << " Min Floor: " << MinFloor << std::endl;
    };
    
    
    // Overloaded operators
    bool bk::Elevator::operator==(const bk::Elevator& other) const {
        return (m_CurrentFloor == other.m_CurrentFloor &&
        m_MaxFloor == other.m_MaxFloor &&
        m_MinFloor == other.m_MinFloor);
    }
    
    bool bk::Elevator::operator!=(const bk::Elevator& other) const {
        return !(*this == other);
    }
    

    // Setters and getters to possible implementation for data validation
    
    void bk::Elevator::setCurrentFloor(int CurrentFloor){
        m_CurrentFloor = CurrentFloor;
    }

    int bk::Elevator::getCurrentFloor() const {
        return m_CurrentFloor;
    }

    /*
    void bk::Elevator::setMaxFloor(int MaxFloor){
        m_MaxFloor = MaxFloor;
    }

    int bk::Elevator::getMaxFloor() const {
        return m_MaxFloor;
    }

    void bk::Elevator::setMinFloor(int MinFloor){
        m_MinFloor = MinFloor;
    }

    int bk::Elevator::getMinFloor() const {
        return m_MinFloor;
    }
    */
    

    //Elevator movement

    /*
    void bk::Elevator::moveUp(){
        if(m_isOperational){
            if(m_CurrentFloor < m_MaxFloor){
                m_CurrentDirection = direction::up;
                m_CurrentFloor++;
                std::cout << "Moving up. Current floor: " << m_CurrentFloor << std::endl;
            }
        }
    }

    void bk::Elevator::moveDown(){
        if(m_isOperational){
            if(m_CurrentFloor > m_MinFloor){
                m_CurrentDirection = direction::down;
                m_CurrentFloor--;
                std::cout << "Moving down. Current floor: " << m_CurrentFloor << std::endl;
            }
        }
    }

    void bk::Elevator::stop(){
        if(m_isOperational){
            m_CurrentDirection = direction::idle;
            std::cout << "Elevator stopped at floor: " << m_CurrentFloor << std::endl;
        }
    }


    void bk::Elevator::moveToFloor(int destinationFloor) {
        if(m_isOperational){
            while (m_CurrentFloor != destinationFloor){
                if (m_CurrentFloor < destinationFloor) {
                    moveUp();
                }
                else if (m_CurrentFloor > destinationFloor) {
                    moveDown();
                } 
            }
        }
    }
    */


    void bk::Elevator::MoveUp() {
        m_CurrentFloor++;
        std::cout << "Moving up to floor: " << m_CurrentFloor << std::endl;

        auto it = std::find(buffer.begin(), buffer.end(), m_CurrentFloor);
        if (it != buffer.end()) {
            buffer.erase(it);
            std::cout << "Stopping at floor: " << m_CurrentFloor << std::endl;
        }

        if (!buffer.empty() && buffer.front() > m_CurrentFloor) {
            m_CurrentDirection = direction::up;
        }
    }

    void bk::Elevator::MoveDown() {
        m_CurrentFloor--;
        std::cout << "Moving down to floor: " << m_CurrentFloor << std::endl;

        auto it = std::find(buffer.begin(), buffer.end(), m_CurrentFloor);
        if (it != buffer.end()) {
            buffer.erase(it);
            std::cout << "Stopping at floor: " << m_CurrentFloor << std::endl;
        }

        if (!buffer.empty() && buffer.front() < m_CurrentFloor) {
            m_CurrentDirection = direction::down;
        }
    }


    void bk::Elevator::MoveToFloor() {
        if (buffer.empty()) {
            std::cout << "No requests in buffer, elevator idle." << std::endl;
            m_CurrentDirection = direction::idle;
            return;
        }

        if (m_CurrentFloor == buffer.front()) {
            std::cout << "Stopping at floor: " << m_CurrentFloor << std::endl;
            buffer.erase(buffer.begin());
        }

        if (!buffer.empty()) {
            if (buffer.front() > m_CurrentFloor) {
                m_CurrentDirection = direction::up;
                MoveUp();
            }
            else {
                m_CurrentDirection = direction::down;
                MoveDown();
            }
        }
    }


    void bk::Elevator::addTargetFloor(int floor) {
        if (floor < m_MinFloor || floor > m_MaxFloor) {
            
            std::cout << "Invalid floor request: " << floor << std::endl;
            return;
        }

        if (std::find(buffer.begin(), buffer.end(), floor) == buffer.end()) {
            
            buffer.push_back(floor);
            std::cout << "Added target floor: " << floor << std::endl;

            if (m_CurrentDirection == direction::up) {
                std::sort(buffer.begin(), buffer.end());
            } 
            else if (m_CurrentDirection == direction::down) {
                std::sort(buffer.rbegin(), buffer.rend());
            }
        }
    }


    const std::vector<int>& bk::Elevator::getBuffer() const {
        return buffer;
    }
   
    int bk::Elevator::getNextTarget() const {
        return buffer.empty() ? m_CurrentFloor : buffer.front();
    }



    //Elevator targets
    /* I'll be using targets with buffer FIFO (First in first out) 
    */
    /*
    void bk::Elevator::addTargetFloor(int floor){
        if(floor >= m_MinFloor && floor <= m_MaxFloor){ 
            m_requests.push(floor); // Add request at the end of the queue vector
            std::cout << "Added target floor: " << floor << std::endl;
        }
         else {
            std::cout << "Invalid floor request: " << floor << std::endl;
         }
    }

    // Getting first floor request (oldest) from the queue to move the elevator to the target floor
    int bk::Elevator::getNextTarget(){
        if(!m_requests.empty()) { 
            int nextFloor = m_requests.front(); // It gets the first value from the queue
            m_requests.pop(); // Delete the value from queue
            return nextFloor;
        }
        else {
            return m_CurrentFloor;
        }
    }

    // This method process all queued floors and moves the elevator to each target
    void bk::Elevator::processRequests(){
        while (!m_requests.empty()) { 
            int nextFloor = getNextTarget();
            moveToFloor(nextFloor);
            stop(); 
        }
    }

    */
    // Size of buffer

    int bk::Elevator::getQueueSize() const {
        return m_requests.size();
    }


    //Curent state
    /*direction bk::Elevator::getDirection() const {
        return m_CurrentDirection;
    }
    */

    bk::Elevator::~Elevator() {
        std::cout << "Destructor called" << std::endl;
    }
}

