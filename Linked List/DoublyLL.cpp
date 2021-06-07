#include <iostream>
using namespace std;
class Node{
public:
    Node *prev;
    int data;
    Node *next;
};

class DoublyLL
{
    private:
        Node *first;
    public:
        DoublyLL(){first=NULL;}
        void create(int A[],int n);
        int length(Node *);
        ~DoublyLL();
        void Display();
        void Insert(int index,int x);
        int Delete(int index);
        void Reverse();
};

void DoublyLL::create(int A[],int n){
    Node *t,*last;
    first=new Node;
    first->data=A[0];
    first->next=first->prev=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

DoublyLL::~DoublyLL(){

}

int DoublyLL::length(Node *p){
    p=first;
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

void DoublyLL::Display(){
    Node *p=first;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

void DoublyLL::Insert(int index,int x){
    Node *p=first,*t=new Node;
    if(index<0||index>length(p))
        return;
    if(index==0){
        t->data=x;
        t->next=first;
        t->prev=NULL;
        first->prev=t;
        first=t;
    }else{
        for(int i=0;i<index-1;i++) p=p->next;
        t->data=x;
        t->next=p->next;
        t->prev=p;
        if(p->next)p->next->prev=t;
        p->next=t;
    }
}

int DoublyLL::Delete(int index){
    Node *p=first;
    int x;
    if(index<0 || index > length(p))
        return;
    if(index==0){
        first=first->next;
        x=p->data;
        if(first)first->prev=NULL;
        delete p;
        return x;
    }else{
        for(int i=0;i<index-1;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next) p->next->prev=p->prev;
        x=p->data;
        delete p;
        return x;    
    }    
}

void DoublyLL::Reverse(){
    Node *p=first,*temp;
    while(p){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;

        p=p->prev;
        if(p->next == NULL && p) first=p;
    }
}

int main(){

    return 0;
}