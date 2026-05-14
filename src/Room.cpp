#include "../include/Room.h"
#include <iostream>
using namespace std;

Room::Room() : roomNumber(0), hostelName(""), gender('M'), capacity(0) {}

Room::Room(int roomNum, string hostel, char g, int cap)
    : roomNumber(roomNum), hostelName(hostel), gender(g), capacity(cap) {}

bool Room::addStudent(long long studentID) {
    if ((int)occupants.size() < capacity) {
        occupants.push_back(studentID);
        return true;
    }
    return false;
}

bool Room::removeStudent(long long studentID) {
    for (auto it = occupants.begin(); it != occupants.end(); it++) {
        if (*it == studentID) {
            occupants.erase(it);
            return true;
        }
    }
    return false;
}

bool Room::hasStudent(long long studentID) const {
    for (long long id : occupants) {
        if (id == studentID) return true;
    }
    return false;
}

void Room::display() const {
    cout << "\nRoom #" << roomNumber << " | " << hostelName << " | Gender: " << gender
         << " | Capacity: " << occupants.size() << "/" << capacity << " | Status: "
         << (isAvailable() ? "Available" : "Full");
    if (!occupants.empty()) {
        cout << " | Occupants: ";
        for (long long id : occupants) cout << id << " ";
    }
    cout << endl;
}
