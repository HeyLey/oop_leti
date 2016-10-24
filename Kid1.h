#ifndef KID1_H
#define KID1_H

#include "Human.h"
#include "string.h"

class Kid1:public Human {

public:

    Kid1():Human('w', "Lisa", 5){}

    virtual void receiveMessage(const Message *msg) {
    }

    virtual void doStep() override {
        if (rand() % 5 == 0) {
            PlayMessage msg(this->getName());
            cat.receiveMessage(&msg);
        }
    }

};


#endif