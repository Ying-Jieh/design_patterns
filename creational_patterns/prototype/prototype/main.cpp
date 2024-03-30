//
//  main.cpp
//  prototype
//
//  Created by YING JIEH XIA on 2024/3/29.
//

// Prototype
// It's used to clone objects. There is a clone() method, and it returns a new object of that object
// We also use prototype manager, which uses hashmap to store the prototypes

#include <iostream>
#include <unordered_map>

class RacketPrototype {
protected:
    std::string brand;
    std::string model;
    double weight;
    double balancePoint;

public:
    RacketPrototype(std::string brand, std::string model, double weight, double balancePoint)
    : brand(brand), model(model), weight(weight), balancePoint(balancePoint) {}
    
    virtual RacketPrototype* clone() = 0;
};

class WilsonTennisRacket : public RacketPrototype {
public:
    WilsonTennisRacket(std::string brand, std::string model, double weight, double balancePoint)
    : RacketPrototype(brand, model, weight, balancePoint) {}
    
    RacketPrototype* clone() override {
        std::cout << "Wilson clone: " << brand << " " << model << " " << weight << " " << balancePoint << std::endl;
        return new WilsonTennisRacket(brand, model, weight, balancePoint);
    }
};


class HeadTennisRacket : public RacketPrototype {
public:
    HeadTennisRacket(std::string brand, std::string model, double weight, double balancePoint)
        : RacketPrototype(brand, model, weight, balancePoint) {}

    HeadTennisRacket* clone() override {
        std::cout << "Head clone: " << brand << " " << model << " " << weight << " " << balancePoint << std::endl;
        return new HeadTennisRacket(brand, model, weight, balancePoint);
    }
};

class RacketPrototypeManager {
private:
    static std::unordered_map<std::string, RacketPrototype*> racketMap;
    
public:
    static void buildProtoypes() {
        WilsonTennisRacket* r1 = new WilsonTennisRacket("Wilson", "Pro Staff", 320.0, 32.5);
        racketMap["Pro Staff"] = r1;
        HeadTennisRacket* h1 = new HeadTennisRacket("Head", "Graphene 360 Speed", 320.0, 32.5);
        racketMap["graphene 360"] = h1;
    }
    
    static RacketPrototype* getClonedRacket(std::string model) {
        RacketPrototype* r = racketMap[model];
        return r->clone();
    }
};

// In C++, static member variables need to be defined outside of the class definition.
// This is because static member variables are shared among all instances of the class and exist independently of any particular instance.
// They need to be allocated storage space separately from the instances of the class.
// you need to define it outside the class to allocate memory for it
std::unordered_map<std::string, RacketPrototype*> RacketPrototypeManager::racketMap;


int main(int argc, const char * argv[]) {
    RacketPrototypeManager::buildProtoypes(); // it's static function, just use scope method
    for (int i=0; i<10; i++) {
        RacketPrototypeManager::getClonedRacket("Pro Staff");
    }
    return 0;
}
