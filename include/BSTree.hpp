namespace BSTree {
    struct Node {
        int data;
        Node *left;
        Node *right;
    };

    class Tree {
        Node *root;
        void printEl(Node* node, int a);
        void destroyTree(Node*node) ;
        void DirectGo(Node* node);
        void SimmetricGo(Node* root);
        void BackGo(Node* root);
        void infileEl(Node*root);
        void fromfileEl();
        void save_tree(std::ofstream &File,  Node * root,int  space);
        bool Delete_number(Node*& node, int number);
    public:
        Tree();
        bool insert(int value);
        void print() ;
        void direct();
        void simmetric();
        void back();
        void savetofile();
        void uploadfromfile();
        bool delete_number(int number);
        bool proverka_uzla(int n);
        ~Tree();
    };
}
