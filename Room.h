#include "Level.h"

#ifndef HWACCESS_ROOM_H
#define HWACCESS_ROOM_H

class Room{
protected:
    Level level;
    string name;
    int floor;
    int maxAmount;
    int amountOfPeople;

public:
    inline static bool emergency = false;
    Room(){
        floor = rand() % 3 + 1;
        amountOfPeople = 0;
        level = NoLevel;
        name = "Noname";
        maxAmount = 0;
    }
    int getFloor(){
        return floor;
    }
    Level getLevel(){
        return level;
    }
    void increaseAmount(){
        amountOfPeople++; //Here we increase amount of people in the room when someone entered
    }
    int getAmount(){
        return amountOfPeople;
    }
    bool Full() {
        return amountOfPeople == maxAmount; //check if there is enough space for entering this room
    }
    string getName(){
        return name;
    }
    static bool getEmergency(){
        return emergency;
    }

    virtual ~Room(){

    }
};

#endif //HWACCESS_ROOM_H
