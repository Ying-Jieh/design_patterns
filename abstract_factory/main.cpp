//
//  main.cpp
//  abstract_factory
//
//  Created by YING JIEH XIA on 2024/3/20.
//

#include <iostream>

// Abstract Factory
// Main function: Use the interface (pure virtual class) to make the products of same brand
// 1. Create product interfaces (Sedan, SUV), inherit them
// 2. Create Factory interface (CarFactory), inherit it
class Sedan {
public:
    virtual void turnOnHeadLight() = 0;
    virtual ~Sedan() {}
};

class SUV {
public:
    virtual void turnOnHeadLight() = 0;
    virtual ~SUV() {}
};

class BMWM5 : public Sedan {
public:
    void turnOnHeadLight() override {
        std::cout << "BMW M5 headlight turned on.\n";
    }
};

class BMWX5 : public SUV {
public:
    void turnOnHeadLight() override {
        std::cout << "BMW X5 headlight turned on.\n";
    }
};

class TeslaModelS : public Sedan {
public:
    void turnOnHeadLight() override {
        std::cout << "Tesla Model S headlight turned on.\n";
    }
};

class TeslaModelY : public SUV {
public:
    void turnOnHeadLight() override {
        std::cout << "Tesla Model Y headlight turned on.\n";
    }
};

class CarFactor {
public:
    virtual Sedan* createSedan() = 0;
    virtual SUV* createSUV() = 0;
};

class BMWFactory : public CarFactor {
public:
    Sedan* createSedan() override {
        return new BMWM5();
    }
    
    SUV* createSUV() override {
        return new BMWX5();
    }
};

class TeslaFactory : public CarFactor {
public:
    Sedan* createSedan() override {
        return new TeslaModelS();
    }
    
    SUV* createSUV() override {
        return new TeslaModelY();
    }
};

class BrandBooth {
private:
    Sedan* sedan;
    SUV* suv;
    
public:
    BrandBooth(CarFactor* factory) {
        this->sedan = factory->createSedan();
        this->suv = factory->createSUV();
    }
    
    void showTime() {
        sedan->turnOnHeadLight();
        suv->turnOnHeadLight();
    }
    
    ~BrandBooth() {
        delete sedan;
        delete suv;
    }
};

int main(int argc, const char * argv[]) {
    BMWFactory bFactory; // We can use factory to create the brand, we don't need to worry about
    TeslaFactory tFactory;
    SUV* teslaY1(tFactory.createSUV());
    SUV* bmwX5(bFactory.createSUV());
    bmwX5->turnOnHeadLight();
    teslaY1->turnOnHeadLight();
//    BrandBooth bmwBooth(&bFactory); // We can assure that the booth has all the same brand, becase we use the certain factory
//    BrandBooth teslaBooth(&tFactory);
//    bmwBooth.showTime();
//    teslaBooth.showTime();
    return 0;
}
