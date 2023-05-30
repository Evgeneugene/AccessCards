
#ifndef HWACCESS_GUEST_H
#define HWACCESS_GUEST_H

#include "User.h"

class Guest: public User{
public:
    explicit Guest(string name){
        this->name = std::move(name);
        level = Blue;
        userType = "Guest";
    }
};
#endif //HWACCESS_GUEST_H
