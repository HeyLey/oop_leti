#ifndef ANIMAL_H
#define ANIMAL_H

#include <string.h>
#include "Place.h"

enum Type { CAT, DOG, MOUSE, HORSE, BIRD, TURTLE, FISH };

class Animal {

private:

    Type type;
    string name;
    int age;

public:

    Animal(Type type,
           string name = "",
           int age = 0) {
        this->age = age;
        this->name = name;
        this->type = type;
    };

};

#endif