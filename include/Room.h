#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
using namespace std;

class Room {
private:
    int roomNumber;
    string hostelName;
    char gender;
    int capacity;
    vector<long long> occupants;
    
public:
    Room();
    Room(int roomNum, string hostel, char g, int cap);
    
    int getRoomNumber() const { return roomNumber; }
    string getHostelName() const { return hostelName; }
    char getGender() const { return gender; }
    int getCapacity() const { return capacity; }
    int getOccupancyCount() const { return occupants.size(); }
    bool isAvailable() const { return (int)occupants.size() < capacity; }
    vector<long long> getOccupants() const { return occupants; }
    
    bool addStudent(long long studentID);
    bool removeStudent(long long studentID);
    bool hasStudent(long long studentID) const;
    void display() const;
};

#endif
