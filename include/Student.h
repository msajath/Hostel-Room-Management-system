#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
using namespace std;

class Student {
private:
    long long studentID;
    string name;
    int year;
    char gender;
    string department;
    long long phoneNumber;
    bool allocated;
    int allocatedRoom;
    
public:
    Student();
    Student(long long id, string n, int y, char g, string dept, long long phone);
    
    long long getStudentID() const { return studentID; }
    string getName() const { return name; }
    int getYear() const { return year; }
    char getGender() const { return gender; }
    string getDepartment() const { return department; }
    long long getPhoneNumber() const { return phoneNumber; }
    bool isAllocated() const { return allocated; }
    int getAllocatedRoom() const { return allocatedRoom; }
    
    void setAllocated(bool status, int roomNum = -1) {
        allocated = status;
        allocatedRoom = roomNum;
    }
    
    void display() const;
};

#endif
