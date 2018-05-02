//
// Created by DELL on 07.03.2018.  //

#include<iostream>
#include "BSTree.hpp"
using namespace std;
using namespace BSTree;

Tree::Tree() { root = nullptr; }

bool Tree::insert(int value) {
    if (root == nullptr) {
        root = new Node{value, nullptr, nullptr};
        return true;
    }
    Node *current = root;
    while (true) {
        if (value > (current->data) && current->right != nullptr){
            current = current->right;
            continue;
        }
        else {
            if (value > (current->data) && ((current->right) == nullptr)) {
                current->right = new Node{value, nullptr, nullptr};
                return true;
            }
        }
        if (value < (current->data) && current->left != nullptr){
            current = current->left;
            continue;
        }
        else {
            if (value < (current->data) && ((current->left) == nullptr)) {
                current->left = new Node{value, nullptr, nullptr};
                return true;
            }
        }
    }

}

void Tree::printEl ( Node *node ,int deep) {

    if (node == nullptr) {
        cout << "Tree is empty" << endl;
    } else {
        if (node->right != nullptr)
            printEl(node->right, deep + 1);
        for (int i = 0; i < deep; i++) {
            cout << "   ";
        }
        if ((node->data) != (root->data))
            cout << "-";
        cout << node->data << endl;
        if (node->left != nullptr)
            printEl(node->left, deep + 1);
    }
}

void Tree::SimmetricGo(Node* node) {
    if (node) {
        SimmetricGo(node->left);
        cout<< node->data<<' ';
        SimmetricGo(node->right);
    }
}

void Tree::simmetric()  {
    SimmetricGo(root);
}


void Tree::DirectGo(Node* node) {
    if (node) {
        cout<<node->data<<' ';
        DirectGo(node->left);
        DirectGo(node->right);
    }
}
void Tree::direct()  {
    DirectGo(root);
}

void Tree::BackGo(Node* node) {
    if (node) {
        BackGo(node->left);
        BackGo(node->right);
        cout << node->data<<' ';
    }
}
void Tree::back()  {
    BackGo(root);
}

void Tree::print() {
    printEl(root, 0);
}

void Tree::destroyTree ( Node *node){
    if(node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
    node=nullptr;
}

Tree::~Tree(){
    destroyTree(root);
};
