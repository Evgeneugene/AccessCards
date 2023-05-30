#include "Level.h"
#include "User.h"

#ifndef HWACCESS_DIRECTOR_H
#define HWACCESS_DIRECTOR_H

class Director: public Stuff{
public:
    explicit Director(string name){
        this->name = std::move(name);
        level = Yellow;
        userType = "Director";
    }
};

#endif //HWACCESS_DIRECTOR_H
