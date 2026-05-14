#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

const int HASH_SIZE = 1009; 

struct HashEntry {
    long long studentID;
    Student* student;
    bool occupied;
    
    HashEntry() : studentID(-1), student(nullptr), occupied(false) {}
};

class HashTable {
private:
    vector<HashEntry> table;
    int size;
    int hashFunction(long long studentID) const;
    int findSlot(long long studentID);
    
public:
    HashTable();
    ~HashTable();
    
    void insert(long long studentID, Student* student);
    Student* search(long long studentID);
    void remove(long long studentID);
    void display() const;
    int getLoadFactor() const;
};

#endif
