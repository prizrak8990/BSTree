//
// Created by DELL on 07.03.2018.
//

#ifndef HOMEWORK_1_SECOND_SEMESTR_BSTREE_H
#define HOMEWORK_1_SECOND_SEMESTR_BSTREE_H

#endif //HOMEWORK_1_SECOND_SEMESTR_BSTREE_H

namespace BSTree {
    struct Node {
        int data;
        Node *left;
        Node *right;
//      Tree *p;
    };

    class Tree {
        Node *root;

        void printEl(Node* node, int deep);
        void destroyTree(Node*node) ;
        void DirectGo(Node* node);
        void SimmetricGo(Node* root);
        void BackGo(Node* root);
    public:
        Tree();
        bool insert(int value);
        void print() ;
        void direct();
        void simmetric();
        void back();
        ~Tree();
    };
}
 
