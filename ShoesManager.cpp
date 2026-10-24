#include "ShoesManager.h"
const int TRUE=1;
const int FALSE=0;

ShoesManager::ShoesManager() : Hash(101){
    this->pL=new Node;
    this->Nos=0;
}

ShoesManager::~ShoesManager(){
    while(this->pL!=NULL){
        Node* tmp=this->pL;
        this->pL=this->pL->Next;
        delete tmp;
    }
}

int ShoesManager::Insert(const Shoes& s,Node* p){
    Node* NewNode=new Node(s);
    if(NewNode==NULL)
        return FALSE;
    if(p==NULL)
        p=this->pL;
    NewNode->Next=p->Next;
    NewNode->Previous=p;
    if(NewNode->Next!=NULL)
        NewNode->Next->Previous=NewNode;
    p->Next=NewNode;
    this->Nos++;

    //insert vo hash
    this->Hash.Insert(NewNode);
    //insert vo tree
    this->Tree.Insert(NewNode);
    return TRUE;
}

void ShoesManager::Show(){
    Node* tmp=this->pL->Next;
    while(tmp!=NULL){
        tmp->data.Output();
        tmp=tmp->Next;
    }
}

void ShoesManager::ShowGreater(const long long& price){
    this->Tree.Greater(price);
}

void ShoesManager::ShowLess(const long long& price){
    this->Tree.Less(price);
}

void ShoesManager::ShowMinToMax(){
    this->Tree.MinToMax(this->Tree.TreeRoot);
}

int ShoesManager::Delete(Node* p){
    if(p==NULL || p==this->pL)
        return FALSE;
    p->Previous->Next=p->Next;
    if(p->Next!=NULL)
        p->Next->Previous=p->Previous;
    this->Nos--;

    //delete khoi hash
    this->Hash.Delete(p);

    //delete khoi tree
    this->Tree.Delete(p);
    return TRUE;
}

Node* ShoesManager::Search(const string& ID){
    return this->Hash.Search(ID);
}

bool ShoesManager::Update(const string& ID,const Shoes& s){
    Node* p = this->Search(ID);

    if(p == NULL)
        return false;

    // Xoa ban sao cu khoi Hashtable,BST
    this->Hash.Delete(p);
    this->Tree.Delete(p);

    // Cap nhat thong tin giay
    p->data.SetID(s.GetID());
    p->data.SetName(s.GetName());
    p->data.SetBrand(s.GetBrand());
    p->data.SetSize(s.GetSize());
    p->data.SetPrice(s.GetPrice());
    p->data.SetQuantity(s.GetQuantity());

    // Chen lai vao Hash,BST voi gia moi
    this->Tree.Insert(p);
    this->Hash.Insert(p);
    return true;
}