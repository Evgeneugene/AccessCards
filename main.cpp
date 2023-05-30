#include <iostream>
#include <vector>
const static int guests = 32;
const static int students = 16;
const static int professors = 8;
const static int labEmployees = 4;
const static int admins = 2;
const static int directors = 1;
const static int lectureRooms = 5;
const static int classRooms = 10;
const static int conferenceRooms = 5;
const static int cabinets = 5;
#include "Room.h"
#include "User.h"
vector<User *> users;
vector<Room *> rooms;
int userPos;
#include "Level.h"
#include "Stuff.h"
#include "Student.h"
#include "Professor.h"
#include "Guest.h"
#include "LabEmplyee.h"
#include "Director.h"
#include "Admin.h"
#include "Cabinet.h"
#include "ConferenceRoom.h"
#include "LectureRoom.h"
#include "classRoom.h"
#include "Generate_elements.h"
#include "Activity.h"

using namespace std;

/** Сгенерить нормально всех гостей и студентов, добавить к комнатам этаж*/
int main() {
    //srand(time(0));

    generateUsers();

    generateRooms();

    PrintUsers();

    checking:
    userPos = UserCheck();

    AvailableRooms();

    if (users[userPos]->getType() == "Admin") {
        if(Room::emergency) CancelEmergency(); else StartEmergency();
        AdminActivity();
    } else if (!Room::getEmergency()) StartEmergency();

    EnterRoom();

    if ((users[userPos]->getType() == "Professor" || users[userPos]->getType() == "LabEmployee" ||
         users[userPos]->getType() == "Admin"
         || users[userPos]->getType() == "Director") && !dynamic_cast<Stuff *>(users[userPos])->HasCabinet()) {
        BookCabinet();
    }

    cout << "Do you want to continue checking? ";
    bool yes = AskToContinue();
    if (yes) goto checking;
    return 0;
}
