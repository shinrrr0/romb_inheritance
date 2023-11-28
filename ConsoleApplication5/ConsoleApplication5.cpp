#include <iostream>

class Transport {
public:
    Transport() {}

    virtual ~Transport() = default;

    // Общие методы для транспорта
    virtual void move() const = 0;
    virtual void makeSound() const = 0;
};

// Классы наследники типов двигателя
class Engine {
public:
    Engine() {}

    virtual ~Engine() = default;

    virtual void start() const = 0;
    virtual void stop() const = 0;
};

// Класс велосипеда
class Bicycle : public Transport {
public:
    Bicycle() {}

    virtual ~Bicycle() = default;

    void move() const override {
        std::cout << "The bicycle is pedaling." << std::endl;
    }

    void makeSound() const override {
        std::cout << "The bicycle bell rings." << std::endl;
    }
};

// Класс электросамоката
class ElectricScooter : public Transport, public Engine {
public:
    ElectricScooter() {}

    virtual ~ElectricScooter() = default;

    void move() const override {
        std::cout << "The electric scooter is moving silently." << std::endl;
    }

    void makeSound() const override {
        std::cout << "The electric scooter beeps softly." << std::endl;
    }

    void start() const override {
        std::cout << "The electric scooter engine starts." << std::endl;
    }

    void stop() const override {
        std::cout << "The electric scooter engine stops." << std::endl;
    }
};

// Класс автомобиля
class Car : public Transport, public Engine {
public:
    Car() {}

    virtual ~Car() = default;

    void move() const override {
        std::cout << "The car is driving on the road." << std::endl;
    }

    void makeSound() const override {
        std::cout << "The car honks loudly." << std::endl;
    }

    void start() const override {
        std::cout << "The car engine roars to life." << std::endl;
    }

    void stop() const override {
        std::cout << "The car engine shuts down." << std::endl;
    }
};

// Полиморфный автопарк
int main() {
    Bicycle* bicycle = new Bicycle();
    ElectricScooter* electro_scooter = new ElectricScooter();
    Car* car = new Car();

    bicycle->move();
    bicycle->makeSound();

    electro_scooter->move();
    electro_scooter->makeSound();
    electro_scooter->start();
    electro_scooter->stop();

    car->move();
    car->makeSound();
    car->start();
    car->stop();

    delete bicycle;
    delete electro_scooter;
    delete car;

    return 0;
}