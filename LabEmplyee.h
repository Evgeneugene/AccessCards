#include "Level.h"
#include "User.h"
#ifndef HWACCESS_LABEMPLYEE_H
#define HWACCESS_LABEMPLYEE_H

class LabEmployee: public Stuff{
public:
    explicit LabEmployee(string name){
        this->name = std::move(name);
        level = Green;
        userType = "LabEmployee";
    }
};

#endif //HWACCESS_LABEMPLYEE_H
