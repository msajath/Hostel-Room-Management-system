#ifndef HOSTELSYSTEM_H
#define HOSTELSYSTEM_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "Student.h"
#include "Room.h"
#include "BST.h"
#include "HashTable.h"
using namespace std;

struct AllocationRecord {
    long long studentID;
    int roomNumber;
    bool isAllocation;
};

class HostelSystem {
private:
    BST studentRecords;
    HashTable studentLookup;
    vector<Room> boysRooms;
    vector<Room> girlsRooms;
    queue<Student> waitingList;
    stack<AllocationRecord> historyStack;
    
    void initializeRooms();
    Room* findRoomByNumber(char gender, int roomNum);
    void processWaitingList();
    char normalizeGender(string genderInput);
    
public:
    HostelSystem();
    
    void addStudent(long long id, string name, int year, string gender, string dept, long long phone);
    void removeStudent(long long studentID);
    
    bool allocateRoom(long long studentID);
    bool deallocateRoom(long long studentID);
    bool transferRoom(long long studentID, int newRoomNumber);
    
    void displayRoomStatus(char gender) const;
    void displayAllRooms() const;
    void displayWaitingList() const;
    void displayStudentInfo(long long studentID) const;
    void undoLastAction();
};

#endif
