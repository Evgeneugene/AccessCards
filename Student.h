
#ifndef HWACCESS_STUDENT_H
#define HWACCESS_STUDENT_H

class Student: public User{
public:
    explicit Student(string name){
        this->name = std::move(name);
        level = NoLevel;
        userType = "Student";
    }
};

#endif //HWACCESS_STUDENT_H
