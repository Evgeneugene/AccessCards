#ifndef HWACCESS_CABINET_H
#define HWACCESS_CABINET_H

class Cabinet: public Room{
private:
    bool booked;
    string owner;
public:
    Cabinet(){
        maxAmount = 2;
        booked = false;
        owner = "nobody";
        level = Red;
        name = "Cabinet";
    }
    bool isBooked(){ //
        return booked;
    }
    void Book(Stuff* s, int n){ //functions for booking the cabinet
        booked = true;
        owner = s->getName();
        s->newCabinet(n);
    }
    string getOwner(){
        return owner;
    }
};

#endif //HWACCESS_CABINET_H
