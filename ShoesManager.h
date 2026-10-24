
#include "BST.h"

class ShoesManager{
    private:
        Node* pL;
        int Nos;//number of shoes
        HashTable Hash;
        BST Tree;
    public:
        ShoesManager();
        ~ShoesManager();
        int Insert(const Shoes&,Node*);
        void Show();
        void ShowMinToMax();
        void ShowMaxToMin();
        void ShowGreater(const long long&);
        void ShowLess(const long long&);
        int Delete(Node*);
        bool Update(const string&,const Shoes&);
        Node* Search(const string&);
        friend class HashTable;
        friend class BST;
};