#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};

class LinkedList
{
    private:
        Node *first;
    public:
        LinkedList(){first=NULL;}
        LinkedList(int A[],int n);
        ~LinkedList();
        void Display();
        void Insert(int index,int x);
        void Insert_Sort(int x);
        int Delete(int index);
        int Length();
        int Max(Node *p);
        int Sum(Node *p);
        bool IsSorted();
        void remove_dup();
        void reverse();
        void R_reverse(Node*,Node*);
        bool isLoop(Node*);
        Node* Search(Node *p,int key);
};

LinkedList::LinkedList(int A[],int n){
    Node *last,*t;
    int i=0;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

LinkedList::~LinkedList(){
    Node *p=first;
    while(first){
        first=first->next;
        delete p;
        p=first;
    }
}

void LinkedList::Display(){
    Node *p=first;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int LinkedList::Length(){
    Node *p=first;
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

void LinkedList::Insert(int index,int x){
    Node *t,*p=first;
    if(index <0 || index > Length())
        return;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        for(int i=0;i<index-1 && p;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
   }
}

int LinkedList::Delete(int index){
    Node *p,*q=NULL;
    int x=-1;
    if(index < 1 || index > Length())
        return -1;
    if(index==1){
        p=first;
        first=first->next;
        x=p->data;
        delete p;
    }
    else{
        p=first;
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
return x;
}

Node* LinkedList::Search(Node* p,int key){
    while(p!=NULL){
        if(key==p->data){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

int LinkedList::Sum(Node* p){
    int sum=0;
    while(p){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int LinkedList::Max(Node* p){
    int max=-32768;
    while(p){
        if(p->data>max){
            max=p->data;
        }
        p=p->next;
    }
    return max;
}

void LinkedList::Insert_Sort(int x){
    Node *q=NULL,*p=first,*t;
    while(p){
        if(p->data>x){
            t->data=x;
            q->next=t;
            t->next=p;
        }
    q=p;
    p=p->next;    
    }
}

bool LinkedList::IsSorted(){
    Node *p=first;
    int x=-32768;
    while(p){
        if(p->data>x)
            x=p->data;
        else
            return false;
    p=p->next;       
    }
    return true;            
}

void LinkedList::remove_dup(){
    Node* p=first,*q=first->next;
    while(q){
        if(p->data != q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}

//Reversing the Links in a LinkedList using Sliding Pointers
void LinkedList::reverse(){
    Node *p=first,*q=NULL,*r=NULL;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }    
    first=q;
}

//Reversing the links in a LinkedList using Recursion
void LinkedList::R_reverse(Node* q,Node* p){
    if(p){
        R_reverse(p,p->next);
        p->next=q;
    }else{
        first=q;
    }
}

bool LinkedList::isLoop(Node* f){
    Node *p,*q=NULL;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:NULL;
    }while(p && q && p!=q);

    if(p==q)return true;
    else return false;
}

int main()
{
    int A[]={1,2,3,4,5};
    LinkedList l(A,5);
    l.Insert(3,10);
    l.Display();
    return 0;
}