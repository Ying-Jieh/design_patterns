//
//  main.cpp
//  factory_method
//
//  Created by YING JIEH XIA on 2024/3/28.
//

// factory method
// each factory produce one product

#include <iostream>

class Car {
public:
    virtual bool startEngine() = 0;
    virtual void turnOffEngine() = 0;
    virtual ~Car() {}
};

class ModelA : public Car {
public:
    bool startEngine() override {
        std::cout << "modelA startEngine\n";
        return true;
    }
    
    void turnOffEngine() override {
        std::cout << "modelA turnOffEngine\n";
    }
};

class ModelB : public Car {
public:
    bool startEngine() override {
        std::cout << "modelB startEngine\n";
        return true;
    }
    
    void turnOffEngine() override {
        std::cout << "modelB turnOffEngine\n";
    }
};


class CarFactory {
public:
    virtual Car* makeCar() = 0;
    virtual ~CarFactory() {}
};

class ModelAFactory : public CarFactory {
public:
    Car* makeCar() override {
        Car* modelA = new ModelA();
        if (modelA->startEngine()) {
            modelA->turnOffEngine();
            return modelA;
        } else {
            delete modelA;
            return nullptr;
        }
    }
};

class ModelBFactory : public CarFactory {
public:
    Car* makeCar() override {
        Car* modelB = new ModelB();
        if (modelB->startEngine()) {
            modelB->turnOffEngine();
            return modelB;
        } else {
            delete modelB;
            return nullptr;
        }
    }
};


// client code
class ClientStorage {
private:
    Car* carStorage[10];
    
public:
    void importCars() {
        ModelAFactory factoryA;
        ModelBFactory factoryB;
        for (int i=0; i<5; i++) {
            carStorage[i] = factoryA.makeCar();
        }
        for (int i=5; i<10; i++) {
            carStorage[i] = factoryB.makeCar();
        }
    }
    
    ~ClientStorage() {
        for(int i=0; i<10; i++) {
            delete carStorage[i];
        }
    }
};



int main() {
    ClientStorage storage;
    storage.importCars();
    return 0;
}
