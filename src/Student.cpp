#include "../include/Student.h"

Student::Student() : studentID(-1), name(""), year(0), gender('M'), 
                     department(""), phoneNumber(0), allocated(false), allocatedRoom(-1) {}

Student::Student(long long id, string n, int y, char g, string dept, long long phone)
    : studentID(id), name(n), year(y), gender(g), department(dept), 
      phoneNumber(phone), allocated(false), allocatedRoom(-1) {}

void Student::display() const {
    cout << "\nStudent ID: " << studentID << endl;
    cout << "Name: " << name << endl;
    cout << "Year: " << year << endl;
    cout << "Gender: " << gender << endl;
    cout << "Department: " << department << endl;
    cout << "Phone: " << phoneNumber << endl;
    cout << "Allocated: " << (allocated ? "Yes" : "No");
    if (allocated) cout << " (Room: " << allocatedRoom << ")";
    cout << endl;
}
