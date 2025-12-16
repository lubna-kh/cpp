#include <iostream>
#include <string>
#include <cstddef> // for size_t

// ----- Base class -----
class Animal {
protected:
    std::string name; // automatically deep-copied by std::string
    int age;

public:
    Animal() : name(""), age(0) {}

    // 1) Base copy constructor: copies base part
    Animal(const Animal& other) : name(other.name), age(other.age) {
        // (no body logic needed here)
    }

    // Rule of Three: since Animal doesn't own raw resources, default dtor is fine
    virtual ~Animal() {} // virtual because we will delete via base* sometimes
};

// ----- Derived class -----
class Dog : public Animal {
    // Pretend we own a dynamic array -> must deep copy
    int* tricks;       // dynamic resource we own
    size_t trickCount; // how many elements

public:
    Dog() : Animal(), tricks(0), trickCount(0) {}

    // 2) Derived copy constructor: copy Base + our own members
    Dog(const Dog& other)
        : Animal(other),                 // (a) copy the Base subobject
          tricks(0),                     // (b) initialize pointers safely
          trickCount(other.trickCount)   // (c) copy sizes/counts first
    {
        // (d) deep copy the dynamic array if it exists
        if (trickCount > 0 && other.tricks) {
            tricks = new int[trickCount];
            for (size_t i = 0; i < trickCount; ++i)
                tricks[i] = other.tricks[i];
        }
    }

    // Copy assignment (Rule of Three) — shown for completeness
    Dog& operator=(const Dog& other) {
        if (this != &other) {
            // (1) copy Base part
            Animal::operator=(other); // <-- this requires Animal to define operator=.
            // For a quick example without defining it, you could manually copy:
            // this->name = other.name; this->age = other.age;

            // (2) copy our own members
            // free old
            delete[] tricks;
            trickCount = other.trickCount;
            tricks = 0;
            if (trickCount > 0 && other.tricks) {
                tricks = new int[trickCount];
                for (size_t i = 0; i < trickCount; ++i)
                    tricks[i] = other.tricks[i];
            }
        }
        return *this;
    }

    ~Dog() {
        delete[] tricks; // (e) release owned memory
    }
};

int main() {
    Dog d1;            // build original
    Dog d2 = d1;       // calls Dog copy constructor (and Animal copy ctor inside)
    Dog d3(d1);        // same as above
    d2 = d3;           // calls Dog::operator=
}
