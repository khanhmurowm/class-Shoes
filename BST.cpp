#include "BST.h"
#include <iostream>
using namespace std;
BST::BST() {
    this->TreeRoot = NULL;
}


BST::~BST() {
    this->Clear(this->TreeRoot);
    this->TreeRoot=NULL;
}

void BST::Clear(Node* x){
    if(x!=NULL){
        this->Clear(x->Left);
        this->Clear(x->Right);
        delete x;
    }
}


void BST::MinToMax(Node* x){
    if(x!=NULL){
        MinToMax(x->Left);
        x->data.Output();
        MinToMax(x->Right);
    }
}

void BST::MaxToMin(Node* x){
    if(x!=NULL){
        MaxToMin(x->Right);
        x->data.Output();
        MaxToMin(x->Left);
    }
}

Node* BST::Maximum(Node* x){
    while(x->Right!=NULL)
        x=x->Right;
    return x;
}

Node* BST::Minimum(Node* x){
    while(x->Left!=NULL)
        x=x->Left;
    return x;
}

void BST::Insert(Node* n){
    Node* z=new Node;
    z->data=n->data;
    Node* x=this->TreeRoot;
    Node* y=NULL;
    while(x!=NULL){
        y=x;
        if(x->data.GetPrice()>n->data.GetPrice())
            x=x->Left;
        else
            x=x->Right;
    }
    z->Parent=y;
    if(y==NULL)
        this->TreeRoot=z;
    else if(z->data.GetPrice() < y->data.GetPrice())
        y->Left=z;
    else    
        y->Right=z;
}

Node* BST::Successor(Node* x){
    if(x->Right!=NULL){
        return this->Minimum(x->Right);
    }
    Node *y=x->Parent;
    while(y!=NULL && x==y->Right){
        x=y;
        y=y->Parent;
    }
    return y;
}

Node* BST::Desuccessor(Node* x){
    if(x->Left!=NULL){
        return this->Minimum(x->Left);
    }
    Node *y=x->Parent;
    while(y!=NULL && x==y->Left){
        x=y;
        y=y->Parent;
    }
    return y;
}

Node* BST::Find_By_IAP(Node *tmp,const string& ID,const long long& Price){
    if(tmp==NULL || (tmp->data.GetID()==ID && tmp->data.GetPrice()==Price))
        return tmp;
    if(tmp->data.GetPrice() > Price)
        return this->Find_By_IAP(tmp->Left,ID,Price);
    else
        return this->Find_By_IAP(tmp->Right,ID,Price);
}

Node* BST::Find_By_P(Node *tmp,const long long& Price){
    if(tmp==NULL || (tmp->data.GetPrice()==Price))
        return tmp;
    if(tmp->data.GetPrice() > Price)
        return this->Find_By_P(tmp->Left,Price);
    else
        return this->Find_By_P(tmp->Right,Price);
}

void BST::Delete(Node* n){
    Node *z=this->Find_By_IAP(this->TreeRoot,n->data.GetID(),n->data.GetPrice());
    Node *x,*y;
    if(z->Left==NULL || z->Right==NULL)
        y=z;
    else
        y=this->Successor(z);
    if(y->Left!=NULL)
        x=y->Left;
    else
        x=y->Right;
    if(x!=NULL)
        x->Parent=y->Parent;
    if(y->Parent==NULL)
        this->TreeRoot=x;
    else if(y->Parent->Left==y)
        y->Parent->Left=x;
    else
        y->Parent->Right=x;
    if(y!=z)
        z->data=y->data;
    delete y;
}

void BST::Greater(const long long& Price){
    Node* x = this->TreeRoot;
    Node* first = NULL;

    while(x != NULL){
        if(x->data.GetPrice() >= Price){
            first = x;
            x = x->Left;
        }
        else{
            x = x->Right;
        }
    }

    while(first != NULL && first->data.GetPrice() >= Price){
        first->data.Output();
        first = this->Successor(first);
    }
}

void BST::Less(const long long& Price){
    Node* x = this->Minimum(this->TreeRoot);

    while(x != NULL && x->data.GetPrice() <= Price){
        x->data.Output();
        x = this->Successor(x);
    }
}

