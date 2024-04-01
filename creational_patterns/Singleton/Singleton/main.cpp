//
//  main.cpp
//  Singleton
//
//  Created by YING JIEH XIA on 2024/4/1.
//

// Ensure one class only has one instance (a static member)
// Provide the only interface (getInstance()) for each class
// Useful for shared data, configuration management, caching, logging and object factories

#include <iostream>
#include <vector>
#include <string>

class Worker {
private:
    std::string name;
public:
    Worker(std::string aName) : name(aName) {}
    
    void serveCustomer() {
        std::cout << name << " is serving customers\n";
    }
};

class ServiceCenter {
private:
    bool holiday;
    std::vector<Worker> holidayWorkers;
    std::vector<Worker> nonHolidayWorkers;
  
    // Private constructor to prevent external instantiation
    ServiceCenter(bool holiday) : holiday(holiday) {
        holidayWorkers = {
            Worker("holiday worker 1"),
            Worker("holiday worker 2"),
            Worker("holiday worker 3")
        };
        nonHolidayWorkers = {
            Worker("nonHoliday worker 1"),
            Worker("nonHoliday worker 2"),
            Worker("nonHoliday worker 3")
        };
    }
public:
    // A static method getInstance() is provided to access the singleton instance.
    // returns a reference to the singleton instance, ensuring that all access is made to the same instance.
    static ServiceCenter& getInstance(bool holiday) {
        static ServiceCenter instance(holiday);
        return instance;
    }
    
    void setHoliday(bool holiday) {
        this->holiday = holiday;
    }
    
    void serveCustomer() {
        if (holiday) {
            for (Worker& w : holidayWorkers) {
                w.serveCustomer();
            }
        } else {
            for (Worker& w : nonHolidayWorkers) {
                w.serveCustomer();
            }
        }
    }
};



int main(int argc, const char * argv[]) {
    // obtain the singleton instance, ensuring that only one instance exists throughout the program.
    ServiceCenter& center1 = ServiceCenter::getInstance(false);
    center1.serveCustomer();
    ServiceCenter& center2 = ServiceCenter::getInstance(false);
    center2.serveCustomer();
    
    // change center1, center2 also be changed because they are the same object
    center1.setHoliday(true);
    center1.serveCustomer();
    center2.serveCustomer();
    return 0;
}
