
#ifndef HWACCESS_CLASSROOM_H
#define HWACCESS_CLASSROOM_H

class classRoom: public Room{
public:
    classRoom(){
        maxAmount = 5;
        level = NoLevel;
        name = "Class Room";
    }
};

#endif //HWACCESS_CLASSROOM_H
