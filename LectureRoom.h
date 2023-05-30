

#ifndef HWACCESS_LECTUREROOM_H
#define HWACCESS_LECTUREROOM_H

class LectureRoom: public Room{
public:
    LectureRoom(){
        maxAmount = 10;
        level = Green;
        name = "Lecture Room";
    }
};

#endif //HWACCESS_LECTUREROOM_H
