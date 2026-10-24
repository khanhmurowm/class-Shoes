#include "HashTable.h"

class BST {
    private:
        Node *TreeRoot;
    public:
        BST();
        ~BST();
        void Clear(Node*);
        void MinToMax(Node*);
        void MaxToMin(Node*);
        Node* Maximum(Node*);
        Node* Minimum(Node*);
        void Insert(Node*);
        Node* Successor(Node*);
        Node* Desuccessor(Node*);
        Node* Find_By_IAP(Node*,const string&,const long long&);
        Node* Find_By_P(Node*,const long long&);
        void Delete(Node*);
        void Greater(const long long&);
        void Less(const long long&);
        friend class ShoesManager;
};
