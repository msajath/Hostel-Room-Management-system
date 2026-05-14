#include "../include/BST.h"

BST::BST() : root(nullptr) {}

BST::~BST() {
    deleteTree(root);
}

void BST::deleteTree(BSTNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void BST::insert(Student student) {
    root = insertHelper(root, student);
}

BSTNode* BST::insertHelper(BSTNode* node, Student student) {
    if (!node) return new BSTNode(student);
    
    if (student.getStudentID() < node->student.getStudentID()) {
        node->left = insertHelper(node->left, student);
    } else if (student.getStudentID() > node->student.getStudentID()) {
        node->right = insertHelper(node->right, student);
    }
    return node;
}

Student* BST::search(long long studentID) {
    BSTNode* result = searchHelper(root, studentID);
    return result ? &result->student : nullptr;
}

const Student* BST::searchConst(long long studentID) const {
    BSTNode* node = root;
    while (node) {
        if (studentID == node->student.getStudentID()) {
            return &node->student;
        } else if (studentID < node->student.getStudentID()) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return nullptr;
}

BSTNode* BST::searchHelper(BSTNode* node, long long studentID) {
    if (!node) return nullptr;
    
    if (studentID == node->student.getStudentID()) {
        return node;
    } else if (studentID < node->student.getStudentID()) {
        return searchHelper(node->left, studentID);
    } else {
        return searchHelper(node->right, studentID);
    }
}

void BST::deleteStudent(long long studentID) {
    root = deleteHelper(root, studentID);
}

BSTNode* BST::deleteHelper(BSTNode* node, long long studentID) {
    if (!node) return nullptr;
    
    if (studentID < node->student.getStudentID()) {
        node->left = deleteHelper(node->left, studentID);
    } else if (studentID > node->student.getStudentID()) {
        node->right = deleteHelper(node->right, studentID);
    } else {
        if (!node->left) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }
        
        BSTNode* minRight = findMin(node->right);
        node->student = minRight->student;
        node->right = deleteHelper(node->right, minRight->student.getStudentID());
    }
    return node;
}

BSTNode* BST::findMin(BSTNode* node) {
    while (node->left) node = node->left;
    return node;
}

void BST::displayAll() const {
    cout << "\nAll Students in BST:" << endl;
    if (isEmpty()) {
        cout << "(Empty)" << endl;
    } else {
        displayHelper(root);
    }
}

void BST::displayHelper(BSTNode* node) const {
    if (!node) return;
    displayHelper(node->left);
    node->student.display();
    displayHelper(node->right);
}
