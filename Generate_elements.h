

#ifndef HWACCESS_GENERATE_ELEMENTS_H
#define HWACCESS_GENERATE_ELEMENTS_H

string randomName(int length) { //Function for generating random names for students
    static int i = 0;
    if(i < 2) {
        char consonants[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w',
                             'x', 'z'};
        char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
        string name;
        int random = rand() % 2;
        int count = 0;
        for (int c = 0; c < length; c++) {
            if (random < 2 && count < 2) {
                name += consonants[rand() % 19];
                count++;
            } else {
                name += vowels[rand() % 5];
                count = 0;
            }
            random = rand() % 2;
        }
        name[0] = toupper(name[0]);
        i++;
        if(i == 1) name+= " ";
        name += randomName(length);
        return name;
    } else {
        i = 0;
        return "";
    }

}
void generateUsers(){ //Generating Students
    for(int i = 0; i < guests; i++){
        auto *s = new Guest(randomName(5 + rand() % 5));
        users.push_back(s);
    }
    for(int i = 0; i < students; i++){
        auto *s = new Student(randomName(5 + rand() % 5));
        users.push_back(s);
    }
    for(int i = 0; i < professors; i++){
        auto *s = new Professor(randomName(5 + rand() % 5));
        users.push_back(s);
    }
    for(int i = 0; i < labEmployees; i++){
        auto *s = new LabEmployee(randomName(5 + rand() % 5));
        users.push_back(s);
    }
    for(int i = 0; i < admins; i++){
        auto *s = new Admin(randomName(5 + rand() % 5));
        users.push_back(s);
    }
    for(int i = 0; i < directors; i++){
        auto *s = new Director(randomName(5 + rand() % 5));
        users.push_back(s);
    }
}
void generateRooms() { //Generating rooms
    for(int i = 0; i < classRooms; i++){
        auto* s = new classRoom();
        rooms.push_back(s);
    }
    for(int i = 0; i < lectureRooms; i++){
        auto* s = new LectureRoom();
        rooms.push_back(s);
    }
    for(int i = 0; i < conferenceRooms; i++){
        auto* s = new ConferenceRoom();
        rooms.push_back(s);
    }
    for(int i = 0; i < cabinets; i++){
        auto* s = new Cabinet();
        rooms.push_back(s);
    }
}

#endif //HWACCESS_GENERATE_ELEMENTS_H
