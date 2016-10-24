#ifndef MOTHER_H
#define MOTHER_H

#include "Human.h"
#include "string.h"

class Mother:public Human {

public:

    Mother():Human('w', "Nana", 35){}

    void clean() {

    };

    void punish() {

    };

    virtual void doStep() override {
        if (rand() % 5 == 0) {
            PlayMessage msg(this->getName());
            cat.receiveMessage(&msg);
        }
    }

    virtual void receiveMessage(const Message *msg) override {
        if (typeid(*msg) == typeid(CleanNeedMessage)) {
            CleanMessage msg(this->getName());
            cat.receiveMessage(&msg);
        }
        if (typeid(*msg) == typeid(MakeSomethingBad)) {
            if (rand() % 3 == 0) {
                PunishMessage msg(this->getName());
                cat.receiveMessage(&msg);
            }
        }
        if (typeid(*msg) == typeid(MakeSomethingGood)) {
            if (rand() % 4 != 0) {
                PatMessage msg(this->getName());
                cat.receiveMessage(&msg);
            }
        }
        if (typeid(*msg) == typeid(AskFoodMessage)) {
            if (rand() % 2 != 0) {
                FeedMessage msg(this->getName());
                cat.receiveMessage(&msg);
            }
        }
    }
};


#endif