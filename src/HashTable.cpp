#include "../include/HashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable() : size(0) {
    table.resize(HASH_SIZE);
}

HashTable::~HashTable() {}

int HashTable::hashFunction(long long studentID) const {
    return studentID % HASH_SIZE;
}

void HashTable::insert(long long studentID, Student* student) {
    int index = hashFunction(studentID);
    int start = index;
    
    while (table[index].occupied) {
        if (table[index].studentID == studentID) {
            table[index].student = student;
            return;
        }
        index = (index + 1) % HASH_SIZE;
        if (index == start) {
            cout << "Hash table full!" << endl;
            return;
        }
    }
    
    table[index].student = student;
    table[index].studentID = studentID;
    table[index].occupied = true;
    size++;
}

Student* HashTable::search(long long studentID) {
    int index = hashFunction(studentID);
    int start = index;
    
    while (table[index].occupied) {
        if (table[index].studentID == studentID) {
            return table[index].student;
        }
        index = (index + 1) % HASH_SIZE;
        if (index == start) break;
    }
    return nullptr;
}

void HashTable::remove(long long studentID) {
    int index = hashFunction(studentID);
    int start = index;
    
    while (table[index].occupied) {
        if (table[index].studentID == studentID) {
            table[index].occupied = false;
            table[index].studentID = -1;
            table[index].student = nullptr;
            size--;
            return;
        }
        index = (index + 1) % HASH_SIZE;
        if (index == start) break;
    }
}

void HashTable::display() const {
    cout << "\nHash Table (Entries: " << size << "):" << endl;
    int count = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        if (table[i].occupied) {
            cout << "  [" << i << "] ID: " << table[i].studentID << endl;
            count++;
            if (count >= 10) {
                cout << "  ... and " << (size - count) << " more" << endl;
                break;
            }
        }
    }
}

int HashTable::getLoadFactor() const {
    return (size * 100) / HASH_SIZE;
}
