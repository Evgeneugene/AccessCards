#include "Level.h"
#include "Room.h"

#ifndef HWACCESS_USER_H
#define HWACCESS_USER_H

class User{
protected:
    Level level;
    string userType;
    string givenBy;
    string name;
public:
    void setName(string s){
        name = std::move(s);
    }
    string getName(){
        return name;
    }
    string getType(){
        return userType;
    }
    User(){
        name = "noname";
        level = NoLevel;
        givenBy = "default";
        userType = "User";
    }
    Level getLevel(){
        return level;
    }
    void setLevel(Level l, string g){ //changing the level of access by admin
        this->level = l;
        this->givenBy = g;

    }

    virtual void printInfo() { //printing all available info

        cout << "Name: " << name << endl;
        cout << "User type: " << userType << endl;
        cout << "Level: " << printLevel(level) << endl;
        cout << "Level was given by: " << givenBy << endl;
    }
    void startEmergency(){
        Room::emergency = true;
    }
    virtual ~User(){

    }
};


#endif //HWACCESS_USER_H
