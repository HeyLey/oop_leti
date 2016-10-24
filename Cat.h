#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include "string.h"
#include "Message.h"
#include "Human.h"
#include "Place.h"
#include "Family.h"
#include "Message.h"

enum State {
    BUSY, FREE
};

class Cat : public Animal {

public:

    Place pos;
    State state;

    Cat() : Animal(CAT, "cat", 3) {}

    void doStep() {
        state = FREE;
        int random = rand() % 8 + 1;
        switch (random) {
            case 1:
                sleep();
                break;

            case 2:
                toilet();
                break;

            case 3:
                washUp();
                break;

            case 4:
                makeGood();
                break;

            case 5:
                makeBad();
                break;

            case 6:
                askFood();
                break;

            case 7:
                move();
                break;

        }
    };

    void move() {
        int random = rand() % 7 + 1;
        switch (random) {
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
        }

        cout << "Cat moves to the " << placeToString(pos) << std::endl;
    };

    void sleep() {
        std::cout << "Cat goes to sleep." << std::endl;
        state = BUSY;
    };

    void askFood() {
        std::cout << "Cat asks for food." << std::endl;
        AskFoodMessage msg("cat");
        sendToAll(&msg);
    };

    void eat(string id) {
        std::cout << id << " feeds the cat." << std::endl;
        state = BUSY;
    }

    void play(string id) {
        if (state == BUSY) {
            std::cout << id << " tries to play with cat, but cat is busy." << std::endl;
        } else {
            std::cout << id << " plays with cat." << std::endl;
            state = BUSY;
        }
    };

    void punish(string id) {
        std::cout << id << " punish the cat." << std::endl;
    };

    void pet(string id) {
        std::cout << id << " pets the cat." << std::endl;
    };

    void clean(string id) {
        std::cout << id << " clean after the cat." << std::endl;
    };

    void makeBad() {
        std::cout << "Cat makes something bad." << std::endl;
        sendToAll(new MakeSomethingBad("cat"));

    };

    void makeGood() {
        std::cout << "Cat makes something good." << std::endl;
        sendToAll(new MakeSomethingGood("cat"));
    };

    void toilet() {
        state = BUSY;
        std::cout << "Cat goes to the toilet." << std::endl;
        sendToAll(new CleanNeedMessage("cat"));
    };

    void washUp() {
        std::cout << "Cat washes up" << std::endl;
        state = BUSY;
    };

    void search(Message *msg) {
        for (Human *h: family) {
            if (h->getName() == msg->sender_id) {
                h->receiveMessage(new CatPositionMessage("cat", pos));
            }
        }
    }

    void sendToAll(Message *msg) {
        for (Human *h : family) {
            h->receiveMessage(msg);
        }
    }

    int receiveMessage(Message *msg) {
        if (typeid(*msg) == typeid(FindAnimalMessage)) {
            search(msg);
        } else if (typeid(*msg) == typeid(PatMessage)) {
            pet(msg->sender_id);
        } else if (typeid(*msg) == typeid(FeedMessage)) {
            eat(msg->sender_id);
        } else if (typeid(*msg) == typeid(PlayMessage)) {
            play(msg->sender_id);
        } else if (typeid(*msg) == typeid(CleanMessage)) {
            clean(msg->sender_id);
        } else if (typeid(*msg) == typeid(PunishMessage)) {
            punish(msg->sender_id);
        } else {
            std::cout << "Unsupported message type" << std::endl;
        }
        return 0;
    }
};

Cat cat;


#endif