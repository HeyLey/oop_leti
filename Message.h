#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

using namespace std;


class Message {
public:
    string sender_id;

    Message(string sender_id) {
        this->sender_id =  sender_id;
    };

    virtual ~Message(){}
};

class FindAnimalMessage: public Message {
public:
    FindAnimalMessage(string sender_id):Message(sender_id) {}

};

class PatMessage: public Message {
public:
    PatMessage(string sender_id):Message(sender_id) {}

};

class FeedMessage: public Message {
public:
    FeedMessage(string sender_id):Message(sender_id) {}
};

class PlayMessage: public Message {
public:
    PlayMessage(string sender_id):Message(sender_id) {}

};

class PunishMessage: public Message {
public:
    PunishMessage(string sender_id):Message(sender_id) {}
};

class CleanMessage: public Message {
public:
    CleanMessage(string sender_id): Message(sender_id) {}
};

// Messages that cat sends to other

class CatPositionMessage:public Message {
public:
    CatPositionMessage(string sender_id, Place pos):Message(sender_id) {
        this->pos=pos;
    }
    Place pos;

};

class MakeSomethingGood: public Message {
public:
    MakeSomethingGood(string sender_id):Message(sender_id) {}

};

class MakeSomethingBad: public Message {
public:
    MakeSomethingBad(string sender_id):Message(sender_id) {}
};

class AskFoodMessage: public Message {
public:
    AskFoodMessage(string sender_id):Message(sender_id) {}

};


class CleanNeedMessage:public Message {
public:
    CleanNeedMessage(string sender_id):Message(sender_id) {}

};


#endif // MESSAGE_H