//
//  main.cpp
//  Adapter
//
//  Created by YING JIEH XIA on 2024/4/5.
//

// The Adapter Design Pattern is a structural design pattern used to make two incompatible interfaces compatible.
// It allows objects with incompatible interfaces to collaborate.
// The adapter helps a class to be adapted for the use of other interfaces.
// There are class adapter, object adapter and two-way adapter

// In this example, we adapt Fahrenheit class to Celsius interface
#include <iostream>

// CelsiusTemperature interface
class CelsiusTemperature {
public:
    virtual double getCTemperature() const = 0;
};


// FahrenheitTemperature class
class FahrenheitTemperature {
private:
    double temperature;
    
public:
    FahrenheitTemperature(double t) : temperature(t) {}
    double getTemperature() const {
        return temperature;
    }
};


// FahrenheitToCelsiusAdapter class (class adapter)
//class FahrenheitToCelsiusAdapter : public CelsiusTemperature, private FahrenheitTemperature {
//public:
//    FahrenheitToCelsiusAdapter(double t) : FahrenheitTemperature(t) {}
//    double getCTemperature() const override {
//        return (getTemperature() - 32) * 5 / 9;
//    }
//};

// FahrenheitToCelsiusAdapter class (object adapter)
class FahrenheitToCelsiusAdapter : public CelsiusTemperature {
private:
    FahrenheitTemperature fahrenheit;
public:
    FahrenheitToCelsiusAdapter(const FahrenheitTemperature& f) : fahrenheit(f) {}
    double getCTemperature() const override {
        return (fahrenheit.getTemperature() - 32) * 5 / 9;
    }
};

int main(int argc, const char * argv[]) {
//    FahrenheitTemperature f(100);
//    FahrenheitToCelsiusAdapter adapter(f.getTemperature());
//    std::cout << "The temperature is " << adapter.getCTemperature() << " degree Celsius\n";
    
    FahrenheitTemperature f(100);
    FahrenheitToCelsiusAdapter adapter(f);
    std::cout << "The temperature is " << adapter.getCTemperature() << " degree Celsius\n";
    return 0;
}
