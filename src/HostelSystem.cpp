#include "../include/HostelSystem.h"
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

char HostelSystem::normalizeGender(string genderInput) {
    if (genderInput.empty()) return 'M';
    
    transform(genderInput.begin(), genderInput.end(), genderInput.begin(), ::toupper);
    
    if (genderInput == "M" || genderInput == "MALE" || genderInput == "BOY" || 
        genderInput == "BOYS" || genderInput == "MAN" || genderInput == "BOYS") {
        return 'M';
    } else if (genderInput == "F" || genderInput == "FEMALE" || genderInput == "GIRL" || 
               genderInput == "GIRLS" || genderInput == "WOMAN" || genderInput == "WOMEN") {
        return 'F';
    }
    
    if (!genderInput.empty() && (genderInput[0] == 'M' || genderInput[0] == 'F')) {
        return genderInput[0];
    }
    return 'M';
}

HostelSystem::HostelSystem() {
    initializeRooms();
}

void HostelSystem::initializeRooms() {
    for (int i = 101; i <= 108; i++) {
        boysRooms.push_back(Room(i, "Boys Hostel", 'M', 2));
    }
    for (int i = 201; i <= 208; i++) {
        girlsRooms.push_back(Room(i, "Girls Hostel", 'F', 2));
    }
    cout << "\nHostel System Initialized!" << endl;
    cout << "Boys Hostel: 8 rooms (101-108)" << endl;
    cout << "Girls Hostel: 8 rooms (201-208)" << endl;
}

void HostelSystem::addStudent(long long id, string name, int year, string genderInput, string dept, long long phone) {
    char gender = normalizeGender(genderInput);
    Student student(id, name, year, gender, dept, phone);
    studentRecords.insert(student);
    
    Student* ptr = studentRecords.search(id);
    if (ptr) {
        studentLookup.insert(id, ptr);
        cout << "\nStudent " << name << " (ID: " << id << ") added successfully!" << endl;
    }
}

Room* HostelSystem::findRoomByNumber(char gender, int roomNum) {
    vector<Room>& rooms = (gender == 'M') ? boysRooms : girlsRooms;
    for (auto& room : rooms) {
        if (room.getRoomNumber() == roomNum) return &room;
    }
    return nullptr;
}

bool HostelSystem::allocateRoom(long long studentID) {
    Student* student = studentRecords.search(studentID);
    if (!student) {
        cout << "\nStudent not found!" << endl;
        return false;
    }
    
    if (student->isAllocated()) {
        cout << "\nStudent already has a room!" << endl;
        return false;
    }
    
    vector<Room>& hostel = (student->getGender() == 'M') ? boysRooms : girlsRooms;
    
    for (auto& room : hostel) {
        if (room.isAvailable()) {
            room.addStudent(studentID);
            student->setAllocated(true, room.getRoomNumber());
            historyStack.push({studentID, room.getRoomNumber(), true});
            cout << "\nRoom " << room.getRoomNumber() << " allocated to Student " << studentID << "!" << endl;
            return true;
        }
    }
    
    waitingList.push(*student);
    cout << "\nNo rooms available. Student " << studentID << " added to waiting list." << endl;
    return false;
}

bool HostelSystem::deallocateRoom(long long studentID) {
    Student* student = studentRecords.search(studentID);
    if (!student) {
        cout << "\nStudent not found!" << endl;
        return false;
    }
    
    if (!student->isAllocated()) {
        cout << "\nStudent has no room allocated!" << endl;
        return false;
    }
    
    int roomNum = student->getAllocatedRoom();
    Room* room = findRoomByNumber(student->getGender(), roomNum);
    
    if (room) {
        room->removeStudent(studentID);
        student->setAllocated(false, -1);
        historyStack.push({studentID, roomNum, false});
        cout << "\nStudent " << studentID << " removed from Room " << roomNum << "!" << endl;
        processWaitingList();
        return true;
    }
    return false;
}

bool HostelSystem::transferRoom(long long studentID, int newRoomNumber) {
    Student* student = studentRecords.search(studentID);
    if (!student) {
        cout << "\nStudent not found!" << endl;
        return false;
    }
    
    if (!student->isAllocated()) {
        cout << "\nStudent is not allocated!" << endl;
        return false;
    }
    
    Room* newRoom = findRoomByNumber(student->getGender(), newRoomNumber);
    if (!newRoom) {
        cout << "\nRoom not found!" << endl;
        return false;
    }
    
    if (!newRoom->isAvailable()) {
        cout << "\nTarget room is full!" << endl;
        return false;
    }
    
    int oldRoomNum = student->getAllocatedRoom();
    Room* oldRoom = findRoomByNumber(student->getGender(), oldRoomNum);
    
    if (oldRoom) {
        oldRoom->removeStudent(studentID);
        newRoom->addStudent(studentID);
        student->setAllocated(true, newRoomNumber);
        
        // Record transfer in history (push in order so undo works correctly)
        historyStack.push({studentID, oldRoomNum, false});      // deallocation from old room
        historyStack.push({studentID, newRoomNumber, true});    // allocation to new room
        
        cout << "\nStudent " << studentID << " transferred from Room " << oldRoomNum 
             << " to Room " << newRoomNumber << "!" << endl;
        return true;
    }
    return false;
}

void HostelSystem::processWaitingList() {
    while (!waitingList.empty()) {
        Student student = waitingList.front();
        vector<Room>& hostel = (student.getGender() == 'M') ? boysRooms : girlsRooms;
        
        bool allocated = false;
        for (auto& room : hostel) {
            if (room.isAvailable()) {
                room.addStudent(student.getStudentID());
                Student* ptr = studentRecords.search(student.getStudentID());
                if (ptr) {
                    ptr->setAllocated(true, room.getRoomNumber());
                    cout << "Waiting student " << student.getStudentID() 
                         << " allocated to Room " << room.getRoomNumber() << "!" << endl;
                }
                allocated = true;
                break;
            }
        }
        
        if (!allocated) break;
        waitingList.pop();
    }
}

void HostelSystem::displayRoomStatus(char gender) const {
    const vector<Room>& hostel = (gender == 'M') ? boysRooms : girlsRooms;
    cout << "\n====== " << (gender == 'M' ? "Boys" : "Girls") << " Hostel Status ======" << endl;
    for (const auto& room : hostel) {
        room.display();
    }
    cout << "================================" << endl;
}

void HostelSystem::displayAllRooms() const {
    displayRoomStatus('M');
    displayRoomStatus('F');
}

void HostelSystem::displayWaitingList() const {
    cout << "\n====== Waiting List ======" << endl;
    if (waitingList.empty()) {
        cout << "No students waiting!" << endl;
    } else {
        queue<Student> temp = waitingList;
        int index = 1;
        while (!temp.empty()) {
            const Student& s = temp.front();
            cout << index << ". ID: " << s.getStudentID() << " | Name: " << s.getName() 
                 << " | Year: " << s.getYear() << " | Gender: " << s.getGender() << endl;
            temp.pop();
            index++;
        }
    }
    cout << "==========================" << endl;
}

void HostelSystem::displayStudentInfo(long long studentID) const {
    const Student* student = studentRecords.searchConst(studentID);
    if (student) {
        student->display();
        
        queue<Student> temp = waitingList;
        bool inWaiting = false;
        while (!temp.empty()) {
            if (temp.front().getStudentID() == studentID) {
                inWaiting = true;
                break;
            }
            temp.pop();
        }
        if (inWaiting) cout << "Status: IN WAITING LIST" << endl;
    } else {
        cout << "\nStudent not found!" << endl;
    }
}

void HostelSystem::undoLastAction() {
    if (historyStack.empty()) {
        cout << "\nNo history to undo!" << endl;
        return;
    }
    
    AllocationRecord rec = historyStack.top();
    historyStack.pop();
    
    Student* student = studentRecords.search(rec.studentID);
    if (!student) return;
    
    Room* room = findRoomByNumber(student->getGender(), rec.roomNumber);
    if (!room) return;
    
    if (rec.isAllocation) {
        room->removeStudent(rec.studentID);
        student->setAllocated(false, -1);
        cout << "\nUndone: Student " << rec.studentID << " removed from Room " << rec.roomNumber << endl;
    } else {
        room->addStudent(rec.studentID);
        student->setAllocated(true, rec.roomNumber);
        cout << "\nUndone: Student " << rec.studentID << " restored to Room " << rec.roomNumber << endl;
    }
}

void HostelSystem::removeStudent(long long studentID) {
    deallocateRoom(studentID);
    studentRecords.deleteStudent(studentID);
    studentLookup.remove(studentID);
    cout << "\nStudent " << studentID << " removed from system!" << endl;
}
