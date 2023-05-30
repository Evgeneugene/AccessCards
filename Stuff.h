
#ifndef HWACCESS_STUFF_H
#define HWACCESS_STUFF_H
class Stuff: public User{
private:
    bool hasCabinet;
    int cabinet;
public:
    void printInfo(){
        cout << "Name: " << name << endl;
        cout << "User type: " << userType << endl;
        cout << "Level: " << printLevel(level) << endl;
        cout << "Level was given by: " << givenBy << endl;
        cout << "Personal cabinet number: ";
        if(hasCabinet) cout << cabinet << endl;
        else cout << "no cabinet" << endl;
    }
    Stuff(){
        hasCabinet = false;
        cabinet = -1;
    }
    bool HasCabinet(){
        return hasCabinet;
    }
    int getCabinet(){
        return cabinet;
    }
    void newCabinet(int i){
        hasCabinet = true;
        cabinet = i;
    }
};
#endif //HWACCESS_STUFF_H
