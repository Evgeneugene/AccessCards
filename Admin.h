
#ifndef HWACCESS_ADMIN_H
#define HWACCESS_ADMIN_H

class Admin: public Stuff{
private:
    string password = "123"; //password
public:
    Admin()= default;
    explicit Admin(User u){
        name = u.getName();
    }
    explicit Admin(string name){
        this->name = std::move(name);
        level = Red;
        userType = "Admin";
    }
    void giveAccess(User* u, Level requested){
        u->setLevel(requested, name); //function for giving the access by request
    }
    bool checkPass(const string& pass){ //check password
        return pass == password;
    }
    void cancelEmergency(){
        Room::emergency = false;
    }
};

#endif //HWACCESS_ADMIN_H
