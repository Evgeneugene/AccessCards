#include "Level.h"
#include "User.h"
#ifndef HWACCESS_PROFESSOR_H
#define HWACCESS_PROFESSOR_H

class Professor: public Stuff{
public:
    explicit Professor(string name){
        this->name = std::move(name);
        level = Yellow;
        userType = "Professor";
    }
};
#endif //HWACCESS_PROFESSOR_H
