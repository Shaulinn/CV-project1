#pragma once

std::ostream& manipDisplay(std::ostream& stream);

class Vehicle
{
protected:
    char* name;
    char* producer;
    int wheels;
public:
    Vehicle()
    {
        name = new(std::nothrow) char[strlen("No input") + 1];
        strcpy(name, "No input");
        producer = new(std::nothrow) char[strlen("No input") + 1];
        strcpy(producer, "No input");
        wheels = 0;
    }
    Vehicle(char* text, char* text2, int val)
    {
        name = new(std::nothrow) char[strlen(text) + 1];
        strcpy(name, text);
        producer = new(std::nothrow) char[strlen(text2) + 1];
        strcpy(producer, text2);
        wheels = val;
    }
    Vehicle(const Vehicle& obj)
    {
        name = new(std::nothrow) char[strlen(obj.name) + 1];
        producer = new(std::nothrow) char[strlen(obj.producer) + 1];
        strcpy(this->name, obj.name);
        strcpy(this->producer, obj.producer);
        this->wheels = obj.wheels;
    }
    void setName(char* text) {
        name = new(std::nothrow) char[strlen(text) + 1];
        strcpy(name, text);
    }
    void setProducer(char* text) {
        producer = new(std::nothrow) char[strlen(text) + 1];
        strcpy(producer, text);
    }
    void setWheels(int val) {
        wheels = val;
    }
    int getWheels() {
        return wheels;
    }
    char* getName() {
        return name;

    }
    char* getPrpoducer() {
        return producer;

    }
    virtual void display() {
        std::cout << "\n\nObject data: \nName: " << manipDisplay << name << "\nProducer: " << manipDisplay << producer
            << "\nWheels: " << manipDisplay << wheels;
    }
    friend std::ofstream& operator<<(std::ofstream& stream, Vehicle& obj);
};

class Car : public Vehicle
{
    int power;
    int capacity;
public:
    Car(char* text1, char* text2, int val1, int val2, int val3) : Vehicle(text1, text2, val1), power(val2), capacity(val3) { }
    Car() : Vehicle(), power(0), capacity(0) { }
    Car(const Car& obj) :Vehicle(obj), power(obj.power), capacity(obj.capacity) { }

    void setPower(int val) {
        power = val;
    }
    void setCapacity(int val)
    {
        capacity = val;
    }
    int getPower()
    {
        return power;
    }
    int getCapacity()
    {
        return capacity;
    }
    friend std::ofstream& operator<<(std::ofstream& stream, Car& obj);
    void display() override {
        std::cout << "\n\nObject data: \nName: " << manipDisplay << name << "\nProducer: " << manipDisplay << producer
            << "\nWheels: " << manipDisplay << wheels << "\nPower: " << manipDisplay << power << "\nCapacity: " << capacity;
    }
};

std::ostream& manipDisplay(std::ostream& stream)
{
    stream.unsetf(std::ios::left);
    stream.setf(std::ios::left);
    stream.width(30);

    return stream;
}
std::ofstream& operator<<(std::ofstream& stream, Vehicle& obj)
{
    stream << "OBJ DATA(VEHICLE): " << obj.name << " " << obj.producer << " " << obj.wheels << "\n";

    return stream;
}
std::ofstream& operator<<(std::ofstream& stream, Car& obj)
{
    stream << "OBJ DATA(CAR):" << obj.name << " " << obj.producer << " " << obj.wheels << " " << obj.power << " " << obj.capacity << "\n";

    return stream;
}
