

#ifndef HWACCESS_CONFERENCEROOM_H
#define HWACCESS_CONFERENCEROOM_H

class ConferenceRoom: public Room{
public:
    ConferenceRoom(){
        maxAmount = 4;
        level = Yellow;
        name = "Conference Room";
    }
};

#endif //HWACCESS_CONFERENCEROOM_H
