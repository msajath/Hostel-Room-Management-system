#include <iostream>
#include <iomanip>
#include "../include/HostelSystem.h"
using namespace std;

void showMenu() {
    cout << "\n======= HOSTEL MANAGEMENT SYSTEM =======" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Allocate Room" << endl;
    cout << "3. Deallocate Room" << endl;
    cout << "4. Transfer Room" << endl;
    cout << "5. Search Student" << endl;
    cout << "6. Remove Student" << endl;
    cout << "7. Display Room Status" << endl;
    cout << "8. Display Waiting List" << endl;
    cout << "9. Undo Last Action" << endl;
    cout << "10. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter choice: ";
}

int main() {
    HostelSystem system;
    int choice;
    
    cout << "\n*** Welcome to Hostel Room Allocation System ***\n" << endl;
    
    while (true) {
        showMenu();
        cin >> choice;
        cin.ignore();
        
        if (choice == 1) {
            long long id, phone;
            string name, dept, gender;
            int year;
            
            cout << "\n--- Add Student ---" << endl;
            cout << "Student ID: ";
            cin >> id;
            cin.ignore();
            cout << "Name: ";
            getline(cin, name);
            cout << "Year (1-4): ";
            cin >> year;
            cin.ignore();
            cout << "Gender (M/Male/F/Female): ";
            getline(cin, gender);
            cout << "Department: ";
            getline(cin, dept);
            cout << "Phone: ";
            cin >> phone;
            
            system.addStudent(id, name, year, gender, dept, phone);
            
        } else if (choice == 2) {
            long long id;
            cout << "\n--- Allocate Room ---" << endl;
            cout << "Student ID: ";
            cin >> id;
            system.allocateRoom(id);
            
        } else if (choice == 3) {
            long long id;
            cout << "\n--- Deallocate Room ---" << endl;
            cout << "Student ID: ";
            cin >> id;
            system.deallocateRoom(id);
            
        } else if (choice == 4) {
            long long id;
            int roomNum;
            cout << "\n--- Transfer Room ---" << endl;
            cout << "Student ID: ";
            cin >> id;
            cout << "New Room Number: ";
            cin >> roomNum;
            system.transferRoom(id, roomNum);
            
        } else if (choice == 5) {
            long long id;
            cout << "\n--- Search Student ---" << endl;
            cout << "Student ID: ";
            cin >> id;
            system.displayStudentInfo(id);
            
        } else if (choice == 6) {
            long long id;
            cout << "\n--- Remove Student ---" << endl;
            cout << "Student ID: ";
            cin >> id;
            system.removeStudent(id);
            
        } else if (choice == 7) {
            int opt;
            cout << "\n--- Room Status ---" << endl;
            cout << "1. Boys Hostel" << endl;
            cout << "2. Girls Hostel" << endl;
            cout << "3. Both" << endl;
            cout << "Choose: ";
            cin >> opt;
            
            if (opt == 1) {
                system.displayRoomStatus('M');
            } else if (opt == 2) {
                system.displayRoomStatus('F');
            } else if (opt == 3) {
                system.displayAllRooms();
            }
            
        } else if (choice == 8) {
            system.displayWaitingList();
            
        } else if (choice == 9) {
            system.undoLastAction();
            
        } else if (choice == 10) {
            cout << "\nThank you! Exiting..." << endl;
            break;
            
        } else {
            cout << "\nInvalid choice!" << endl;
        }
    }
    
    return 0;
}
