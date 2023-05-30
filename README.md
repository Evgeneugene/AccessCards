# [Evgenii Evlampev B20-01] **Programming Software Systems 2**

## Assignment 3 - **University Access Simulation**

University Access Cards Simulation is a program that simulates the usual behaviour of people in the university using their personal cards for different purposes.

> The main goal is to make the simulation as close to the reality as possible and to consider different activities for different people to make it more complex and real.

***

### **Requirements**

C++17  
gcc

### **How To Run The Program**

Building:
1) Download the files
2) Open the folder with files in bash
3) Then write "mkdir build && cd build"
4) "cmake .."
5) "make"
6) Open the folder "build" and run "HWaccess"

***

## How it works?

The program generates people(Students, Guests, Professors, Lab Employees, Directors, Admins) with random names. Then you print the name you want to have. After that program will output the whole current information about this person. If a person with this name is Admin then you will be suggested to change the level of access of any person. After that you will be suggested to enter any room, and in case of lack of access the request will be denied. Otherwise, you'll successfully enter the room, but if this room have already been entered by too many people, you'll have to choose another one. Also, for Professors, Lab Employees, Director and Admins there is a possibility to book personal cabinet, so after that no one except Admins and the owner will be able to enter it. Also I tried to handle all possible incorrect inputs. 

**Types**

*User Types*: students, guests, professors, lab employees, directors, admins.

*Stuff types*: professors, lab employees, directors, admins.

*Room Types*: class room, lecture room, conference room, cabinet.

*Access Levels*: no level, blue, green, yellow, red.

### Updates from the previous assignment

I fixed all the previous bags, and now only class objects called "Cabinet" have ability to be booked, since such methods are declared in this class, and I use dynamic cast from vector of Users to use these methods(I lost 0.2 points from previous assignment for that). Moreover, I made the main.cpp to look much cleaner and simple using functions declared in the separate file. Added new Blue level for guests, so they can enter only Conference rooms on the 1st floor and Lecture rooms. Also, now any person can launch the Emergency Mode and all the rooms become accessible for everyone. However, only Admins can cancel this mode. Furthermore, Directors have new ability to exclude any person from university.


***

