//
//  main.cpp
//  builder
//
//  Created by YING JIEH XIA on 2024/3/28.
//

#include <iostream>
#include <string>

// 1. Having the builders containing building steps in them
// 2. Having a director to create the product using the builder

class Milktea {
public:
    double price;
    std::string topping;
    std::string tea = "regularMilktea";
    int sugar = 100;
    
    Milktea() : price(7.0) {}
    
    double getPrice() {
        return this->price;
    }
};

class SignatureMilktea : public Milktea {
public:
    SignatureMilktea() {
        this->price = 5.7;
    }
};

class OolongMilktea : public Milktea {
public:
    OolongMilktea() {
        this->price = 6.2;
    }
};

class MilkteaBuilder {
public:
    virtual void reset() = 0;
    virtual void addTopping() = 0;
    virtual void addTea() = 0;
    virtual void addSugerLevel() = 0;
    virtual Milktea* getProduct() = 0;
};


class SignatureMilkteaBuilder : public MilkteaBuilder {
private:
    SignatureMilktea* product;
    
public:
    void reset() override {
        this->product = new SignatureMilktea();
    }
    
    void addTopping() override {
        product->topping = "boba";
    }
    
    void addTea() override {
        product->tea = "signature tea";
    }
    
    void addSugerLevel() override {
        product->sugar = 100;
    }
    
    Milktea* getProduct() override {
        std::cout << "Signature milktea: " << product->topping << ", " << product->tea
        << ", " << product->sugar << std::endl;
        return this->product;
    }

};

class OolongMilkteaBuilder : public MilkteaBuilder {
private:
    OolongMilktea* product;
    
public:
    void reset() override {
        this->product = new OolongMilktea();
    }
    
    void addTopping() override {
        product->topping = "jelly";
    }
    
    void addTea() override {
        product->tea = "oolong tea";
    }
    
    void addSugerLevel() override {
        product->sugar = 50;
    }
    
    Milktea* getProduct() override {
        std::cout << "Oolong milktea: " << product->topping << ", " << product->tea
        << ", " << product->sugar << std::endl;
        return this->product;
    }

};



class MilkteaDirector {
private:
    MilkteaBuilder* milkteaBuilder;
    
public:
    MilkteaDirector(MilkteaBuilder* builder) {
        this->milkteaBuilder = builder;
    }
    
    void changeBuilder(MilkteaBuilder* builder) {
        this->milkteaBuilder = builder;
    }
    
    Milktea* makeMilktea() {
        this->milkteaBuilder->reset();
        this->milkteaBuilder->addTopping();
        this->milkteaBuilder->addTea();
        this->milkteaBuilder->addSugerLevel();
        return this->milkteaBuilder->getProduct();
    }
    
    Milktea* make(std::string type) {
        if (type == "signature") {
            this->changeBuilder(new SignatureMilkteaBuilder);
        } else if (type == "oolong") {
            this->changeBuilder(new OolongMilkteaBuilder);
        }
        return this->makeMilktea();
    }
};


int main() {
    Milktea p1;
    p1.topping = "strawberry";
    std::cout << p1.getPrice() << ", " << p1.topping << ", " << p1.tea << "\n";
    
    // Use builder to make the signature milktea
    SignatureMilkteaBuilder* sBuilder1 = new SignatureMilkteaBuilder();
    sBuilder1->reset();
    sBuilder1->addTopping();
    sBuilder1->addTea();
    sBuilder1->getProduct();
    
    // Use director to make the signature milktea
    SignatureMilkteaBuilder* sBuilder2 = new SignatureMilkteaBuilder();
    MilkteaDirector director1(sBuilder2);
    director1.makeMilktea();
    
    // Use director to make the oolong milktea
    OolongMilkteaBuilder* oBuilder1 = new OolongMilkteaBuilder();
    MilkteaDirector director2(oBuilder1);
    director2.makeMilktea();
    
    director2.make("oolong");
    
    return 0;
}
