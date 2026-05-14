#ifndef BST_H
#define BST_H

#include <iostream>
#include "Student.h"

using namespace std;

struct BSTNode {
    Student student;
    BSTNode* left;
    BSTNode* right;
    
    BSTNode(Student s) : student(s), left(nullptr), right(nullptr) {}
};

class BST {
private:
    BSTNode* root;
    
    BSTNode* insertHelper(BSTNode* node, Student student);
    BSTNode* searchHelper(BSTNode* node, long long studentID);
    BSTNode* deleteHelper(BSTNode* node, long long studentID);
    BSTNode* findMin(BSTNode* node);
    void displayHelper(BSTNode* node) const;
    void deleteTree(BSTNode* node);
    
public:
    BST();
    ~BST();
    
    void insert(Student student);
    Student* search(long long studentID);
    const Student* searchConst(long long studentID) const;
    void deleteStudent(long long studentID);
    void displayAll() const;
    bool isEmpty() const { return root == nullptr; }
};

#endif
