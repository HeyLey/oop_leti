#ifndef HUMAN_H
#define HUMAN_H

#include <string.h>
#include "Place.h"
#include "Message.h"

class Human {

public:

    Place pos;

    Human(char sex = 'm',
           std::string name = "",
          int age = 0) {
        this->sex=sex;
        this->age=age;
        this->name=name;
    };

    virtual void doStep() {

    }

    std::string getName() {
        return this->name;
    }

    void goToCat(Place plc) {
        pos = plc;
    };

    void move() {
        int random = rand() % 7 +1;
        switch(random) {
            case 1:
                pos = KITCHEN;
                break;

            case 2:
                pos = BED_ROOM1;
                break;

            case 3:
                pos = BED_ROOM2;
                break;

            case 4:
                pos = BATH_ROOM;
                break;

            case 5:
                pos = LIVING_ROOM;
                break;

            case 6:
                pos = BALKON;
                break;

            case 7:
                pos = ATTIC;
                break;

            default:
                pos = UNKNOWN;
        }
    };

    virtual void receiveMessage(const Message *msg) {
        // std::cout << "Message receaved: " << this->getName() << std::endl;
    }

private:

    char sex;
    string name;
    int age = 0;


};


#endif