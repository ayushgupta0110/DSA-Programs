#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class LinkedList
{
    public:
        Node *first;
        LinkedList(){first=NULL;}
        LinkedList(int A[],int n);
        ~LinkedList();
        void Display();
        void InsertAtBeg(int x);
        void InsertAtith(int index,int x);
        void InsertAtEnd(Node *p,int x);
        int DeletefromBeg();
        int Deletefromith(int index);
        int Length();
        int Max(Node *p);
        int Sum(Node *p);
        Node* Search(Node *p,int key);
        void concatenate(Node *p,Node *q);
        void removefromEnd(Node *p);
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

void LinkedList::InsertAtBeg(int x){
    Node *t=new Node;
    t->data=x;
    t->next=first;
    first=t;
}

void LinkedList::InsertAtith(int index,int x){
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

int LinkedList::DeletefromBeg(){
    Node *p=first;
    if(p==NULL){
        cout<<"List is empty"<<endl;
        return -1;
    }
    int x;
    x=first->data;
    first=first->next;
    delete p;
    return x;  
}    

int LinkedList::Deletefromith(int index){
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

void LinkedList::concatenate(Node *p,Node *q){  
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
}

void LinkedList::removefromEnd(Node *p){
    Node *q=NULL;
    while(p->next!=NULL){
        q=p;
        p=p->next;
    }
    q->next=NULL;
    delete p;
}

void LinkedList::InsertAtEnd(Node *p,int x){
    Node *q=NULL;
    q->data=x;
    q->next=NULL;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
    delete p;
}

int main()
{
    cout<<"\nLinked List Operations!!!";
    cout<<"\n\t\tMENU";
    cout<<"\n1.Insertion";
    cout<<"\n2.Deletion";
    cout<<"\n3.Search";
    cout<<"\n4.Display";
    cout<<"\n5.Length";
    cout<<"\n6.Max";
    cout<<"\n7.Sum";
    cout<<"\n8.Exit";
    int choice,n,x,index,key;
    int A[20];
    LinkedList L;
    Node *p;
    do{
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"\nEnter the number of elements: ";
                cin>>n;
                cout<<"\nEnter the elements: ";
                for(int i=0;i<n;i++)
                    cin>>A[i];
                L=LinkedList(A,n);
                break;
            case 2:
                cout<<"\nEnter the index: ";
                cin>>index;
                x=L.Deletefromith(index);
                if(x!=-1)
                    cout<<"\nDeleted element is: "<<x;
                else
                    cout<<"\nInvalid index";
                break;
            case 3:
                cout<<"\nEnter the key: ";
                cin>>key;
                p=L.Search(L.first,key);
                if(p)
                    cout<<"\nElement found at index: "<<p->data;
                else
                    cout<<"\nElement not found";
                break;
            case 4: 
                L.Display();
                break;
            case 5:
                cout<<"\nLength of the list is: "<<L.Length();
                break;
            case 6:
                cout<<"\nMax element is: "<<L.Max(L.first);
                break;
            case 7:
                cout<<"\nSum of the list is: "<<L.Sum(L.first);
                break;
            case 8:
                exit(0);
            default:    cout<<"\nInvalid choice";
        }
    }while(choice!=8);
    return 0;   
} 