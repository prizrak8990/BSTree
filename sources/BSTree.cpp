#include<iostream>
#include "BSTree.hpp"
#include <fstream>
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


void Tree::printEl ( Node *node ,int ch) {
    if (node == nullptr) {
        cout << "Tree is empty" << endl;
    } else {
        if (node->right != nullptr)
            printEl(node->right, ch + 1);
        for (int i = 0; i < ch; i++) {
            cout << "   ";
        }
        if ((node->data) != (root->data))
            cout << "-";

        cout << node->data << endl;
        if (node->left != nullptr)
            printEl(node->left, ch + 1);
    }
}

void Tree::print() {
    printEl(root, 0);
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

void Tree::destroyTree ( Node *node){
    if(node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
    node=nullptr;
}

void Tree::save_tree(ofstream &f, Node *node, int level)
{
    if (node!=nullptr) {
        if (node->right!=nullptr)
            save_tree (f,node->right, level+1);
        for (int i=0; i< level; i++) {
            f<< "   ";
        }
        if ((node->data)!=(root->data))
            f<< "--";
        f<< node->data << std::endl;
        if (node->left!=nullptr)
            save_tree (f,node->left, level+1);
    }
}

void Tree::infileEl(Node*node){
    ofstream fout;
    fout.open("BinTree.txt");
    save_tree(fout,node,0);
}

void Tree::savetofile(){
    infileEl(root);
}

void Tree::fromfileEl(){
    ifstream File("BinTree.txt");
    if (!File.is_open())
        cout<<"error";
    string a;
    getline (File,a);
    int countEL=0;
    for (int i=0; i< a.length(); i++) {
        if (a[i]==' ')
            countEL++;
    }
    File.close();
    File.open("BinTree.txt");
    for (int i=0; i<=countEL; i++) {
        File >> a;
        insert (atoi( a.data()));
    }
    File.close();
}

void Tree::uploadfromfile() {
    fromfileEl();
}

bool Tree::proverka_uzla(int n){
    Node * current =root;
    while(current !=nullptr){
        if (current->data==n)
            return true;
        else {
            if (current->data<n)
                current=current->right;
            else
                current=current->left;
        }
    }
}


bool Tree::delete_number(int number){
    Delete_number(root, number);
}

bool Tree::Delete_number(Node*& root, int number) {
    if (root == nullptr) {
        return root;
    }
    if (number < root->data) {
        root->left;
        Delete_number(root->left, number);
    } else if (number > root->data) {
        root->right;
        Delete_number(root->right, number);
    } else if (root->left != nullptr && root->right != nullptr) {
        root->data = root->right->data;
        root->right;
        Delete_number(root->right, root->data);
    } else if (root->left != nullptr)
        root = root->left;
    else
        root = root->right;
    return true;
}

Tree::~Tree(){
    destroyTree(root);
};
