#ifndef HWACCESS_ACTIVITY_H
#define HWACCESS_ACTIVITY_H
void PrintUsers() {
    int k = 0;
    cout << guests << " Guests: " << endl;   //Printing all users with their names
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getType() == "Guest") {
            k++;
            cout << users[i]->getName();
            if (k < guests) cout << ", "; else cout << "." << endl;
        }
    }
    k = 0;
    cout << students << " Students: " << endl;
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getType() == "Student") {
            k++;
            cout << users[i]->getName();
            if (k < students) cout << ", "; else cout << "." << endl;
        }
    }
    k = 0;
    cout << professors << " Professors: " << endl;
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getType() == "Professor") {
            k++;
            cout << users[i]->getName();
            if (k < professors) cout << ", "; else cout << "." << endl;
        }
    }
    k = 0;
    cout << labEmployees << " Lab Employees: " << endl;
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getType() == "LabEmployee") {
            k++;
            cout << users[i]->getName();
            if (k < labEmployees) cout << ", "; else cout << "." << endl;
        }
    }
    k = 0;
    cout << admins << " Admins: " << endl;
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getType() == "Admin") {
            k++;
            cout << users[i]->getName();
            if (k < admins) cout << ", "; else cout << "." << endl;
        }
    }
    k = 0;
    cout << directors << " Director: " << endl;
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getType() == "Director") {
            k++;
            cout << users[i]->getName();
            if (k < directors) cout << ", "; else cout << "." << endl;
        }
    }
    cout << endl;
}

int UserCheck() {
    userPos = -1;
    while (1) { //loops for handling incorrect inputs
        cout << "Enter the name: " << endl;
        string first, second, name;
        cin >> first >> second;
        name += first;
        name += " ";
        name += second;
        bool noMatch = true;
        for (int i = 0; i < users.size(); i++) {
            if (users[i]->getName() == name) {
                noMatch = false;
                userPos = i;
                if (users[i]->getType() == "Admin") {
                    while (1) {
                        cout << "Enter admins' password:" << endl;
                        string pass;
                        auto *a = dynamic_cast<Admin *>(users[i]);
                        getlineSucks:
                        getline(cin, pass);
                        if (pass.empty()) goto getlineSucks;
                        if (a->checkPass(pass)) {
                            cout << "Noice!" << endl;
                            noMatch = false;
                            break;
                        } else {
                            cout << "Wrong Password" << endl;
                            noMatch = true;
                        }
                    }
                }
                break;
            }
        }
        if (noMatch) cout << "No such person in our base" << endl;
        if (!noMatch) break;
    }
    users[userPos]->printInfo();
    return userPos;
}

void AvailableRooms() {
    cout << "List of available rooms:" << endl;
    for (int i = 0; i < rooms.size(); i++) {
        bool accessible = false;
        if (users[userPos]->getLevel() == Blue) {
            if ((rooms[i]->getName() == "Lecture Room") ||
                (rooms[i]->getName() == "Conference Room" && rooms[i]->getFloor() == 1)) {
                accessible = true;
            }
        } else if (rooms[i]->getLevel() <= users[userPos]->getLevel() && !rooms[i]->Full()) {
            accessible = true;
            if (rooms[i]->getName() == "Cabinet" && dynamic_cast<Cabinet *>(rooms[i])->isBooked() &&
                users[userPos]->getType() != "Admin") {
                accessible = false;
            }
        }
        if (Room::getEmergency()) accessible = true;
        if (accessible) cout << rooms[i]->getName() << " " << i + 1 << "(floor " << rooms[i]->getFloor() << ") ";
    }
    cout << endl;
}

void AdminActivity() {
    cout << "Do you want to change somebody's level? ";
    while (1) {
        bool done = false;
        cout << "Print Y(Yes) or N(No)" << endl;
        string answer;
        getline(cin, answer);
        if (answer == "Y") {
            while (1) {
                cout << "Print the name of a person to change level" << endl;
                bool match = false;
                string first, second, name;
                cin >> first >> second;
                name += first;
                name += " ";
                name += second;
                for (int i = 0; i < users.size(); i++) {
                    if (users[i]->getName() == name) {
                        match = true;
                        done = true;
                        cout
                                << "Print the level of access to give this person: 0 - No level, 1 - Blue, 2 - Green, 3 - Yellow, 4 - Red"
                                << endl;
                        int level;
                        cin >> level;
                        auto *a = dynamic_cast<Admin *>(users[userPos]);
                        a->giveAccess(users[i], (Level) level);
                        cout << "Done! Current information about this person: " << endl;
                        users[i]->printInfo();
                    }
                }
                if (match) {
                    break;
                } else cout << "No such person in our base" << endl;
            }
        }
        if (answer == "N" || done) {
            break;
        }
    }
}

void EnterRoom() {
    cout << "Do you want to enter any room? ";
    exception:
    cout << "Y/N" << endl;
    string en;
    cin >> en;
    if (en == "Y") {
        another:
        cout << "Enter the room number" << endl;
        int number;
        cin >> number;
        number--;
        auto *cab = dynamic_cast<Cabinet *> (rooms[number]);
        if (Room::getEmergency()) {
            if (!rooms[number]->Full()) {
                cout << "Done! " << users[userPos]->getName() << " entered the room " << number + 1 << endl;
                rooms[number]->increaseAmount();
            } else {
                cout << "Sorry, " << users[userPos]->getName() << ", the room is full, choose another one." << endl;
                goto another;
            }
        } else if (rooms[number]->getName() == "Cabinet" && cab->isBooked() &&
                   users[userPos]->getName() == cab->getOwner()) {
            cout << "Done! " << users[userPos]->getName() << " entered his personal cabinet " << number + 1 << "."
                 << endl;
            rooms[number]->increaseAmount();
        } else if (users[userPos]->getLevel() == Red) {
            cout << "Done! " << users[userPos]->getName() << " entered the room " << number + 1 << endl;
            rooms[number]->increaseAmount();
        } else if (users[userPos]->getLevel() == Blue) {
            if ((rooms[number]->getName() == "Lecture Room") ||
                (rooms[number]->getName() == "Conference Room" && rooms[number]->getFloor() == 1)) {
                cout << "Done! " << users[userPos]->getName() << " entered the room " << number + 1 << endl;
                rooms[number]->increaseAmount();
            } else {
                cout << "Sorry, " << users[userPos]->getName()
                     << ", you have no access to this room, choose another one." << endl;
                goto another;
            }
        } else if (rooms[number]->getLevel() > users[userPos]->getLevel()) {
            cout << "Sorry, " << users[userPos]->getName() << ", you have no access to this room, choose another one."
                 << endl;
            goto another;
        } else if (rooms[number]->Full()) {
            cout << "Sorry, " << users[userPos]->getName() << ", the room is full, choose another one." << endl;
            goto another;
        } else if (rooms[number]->getName() == "Cabinet" && cab->isBooked() &&
                   cab->getOwner() != users[userPos]->getName()) {
            cout << "Sorry, " << users[userPos]->getName() << ", the cabinet is booked, choose another one." << endl;
            goto another;
        } else {
            rooms[number]->increaseAmount();
            cout << "Done! " << users[userPos]->getName() << " entered the room " << number + 1 << endl;
        }
    }
    if (en != "N" && en != "Y") goto exception;
}

void BookCabinet() {

    cout << "Do you want to book one personal cabinet? ";
    while (1) {
        cout << "Y/N" << endl;
        string s;
        cin >> s;
        if (s == "Y") {
            cout << "Free cabinets are: ";
            for (int i = 0; i < rooms.size(); i++) {
                if (rooms[i]->getName() == "Cabinet" && !dynamic_cast<Cabinet *>(rooms[i])->isBooked()) {
                    cout << i + 1 << " ";
                }
            }
            cout << endl;
            while (1) {
                cout << "Enter the cabinet number" << endl;
                int number;
                cin >> number;
                if (number > rooms.size() || rooms[number - 1]->getName() != "Cabinet") {
                    cout << "This room is not cabinet, choose another one" << endl;
                    continue;
                }
                if (dynamic_cast<Cabinet *>(rooms[number - 1])->getOwner() != users[userPos]->getName()
                    && dynamic_cast<Cabinet *>(rooms[number - 1])->isBooked()) {
                    cout << "This cabinet is already booked by "
                         << dynamic_cast<Cabinet *>(rooms[number - 1])->getOwner()
                         << ", choose another one" << endl;
                    continue;
                } else {
                    dynamic_cast<Cabinet *>(rooms[number - 1])->Book(dynamic_cast<Stuff *>(users[userPos]), number - 1);
                    cout << "Done! Cabinet number " << number << " is booked by "
                         << dynamic_cast<Cabinet *>(rooms[number - 1])->getOwner()
                         << endl;
                    break;
                }
            }
            break;
        } else if (s == "N") break;
        else {
            continue;
        }
    }
}

bool AskToContinue() {
    wrong_letter:
    cout << "Print Y or N" << endl;
    string ans;
    cin >> ans;
    if (ans == "Y") return true;
    else if (ans == "N") {
        cout << "Goodbye!";
        return false;
    } else {
        goto wrong_letter;
    }
}

void StartEmergency() {
    cout << "Launch Emergency Mode? ";
    while (1) {
        cout << "Y/N" << endl;
        string ans;
        cin >> ans;
        if (ans == "Y") {
            users[userPos]->startEmergency();
            cout << "Done! All rooms 1-" << rooms.size() << " are opened! RUN!" << endl;
            break;
        } else if (ans == "N") {
            break;
        }
    }
}
void CancelEmergency (){
    cout << "Do you want to cancel Emergency Mode? ";
    while(1){
        cout << "Y/N" << endl;
        string ans;
        cin >> ans;
        if(ans == "Y"){
            dynamic_cast<Admin *>(users[userPos])->cancelEmergency();
            cout << "Done! Emergency Mode is off." << endl;
            break;
        } else if(ans == "N") break;
    }
}
#endif //HWACCESS_ACTIVITY_H
