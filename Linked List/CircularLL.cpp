#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};

class Cir_LinkedList
{
    private:
        Node *Head;
    public:
        Cir_LinkedList(){Head=NULL;}
        ~Cir_LinkedList();
        void Display();
        void Insert(int index,int x);
        int Delete(int index);
};

Cir_LinkedList::~Cir_LinkedList(){
    Node *p=Head;
    while(Head){
        Head=Head->next;
        delete p;
        p=Head;
    }
}

void Cir_LinkedList::Insert(int index,int x){
  Node* t,*p;
  if(index==0){
      t=new Node;
      t->data=x;
      if(Head==NULL){
          Head=t;
          Head->next=Head;
      }else{
          p=Head;
          while(p->next!=Head)
            p=p->next;
          p->next=t;
          t->next=Head;
          Head=t;  
      }
  }
  else{
      p=Head;
      for(int i=0;i<index-1;i++) p=p->next;
      t=new Node;
      t->data=x;
      t->next=p->next;
      p->next=t;
  }
}

void Cir_LinkedList::Display(){
    Node* p=Head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=Head);
}

int Cir_LinkedList::Delete(int index){
    Node* p,*q;
    int x;
    if(index==0){
        p=Head;
        while(p->next!=Head) p=p->next;
        x=Head->data;
        if(p==Head){
            delete Head;
            Head=NULL;
        }
        else{
            p->next=Head->next;
            delete Head;
            Head=p->next;
        }
    }
    else{
        p=Head;
        for(int i=0;i<index-2;i++)p=p->next;
        q=p->next;
        x=q->data;
        p->next=q->next;
        delete q;
    }
    return x;
}

int main(){

    return 0;
}