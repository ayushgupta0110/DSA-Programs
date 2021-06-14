#include<iostream>
using namespace std;


class Node{
  public:  int data;
    Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    Node *t=new Node;
    if(t==NULL) 
        cout<<"\nQueue is FULL!"<<endl;
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL) front=rear=t;
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue(){
    int x=-1;
    Node *p;
    if(front==NULL)
        cout<<"\nQueue is empty!"<<endl;
    else{
        x=front->data;
        p=front;
        front=front->next;
        delete p;
    }    
    return x;
}

void Display(){
    Node *p=front;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

void Delete(){
    Node *p;
    while(front){
        p=front;
        front=front->next;
        delete p;
    }
    delete front,rear;
}

int main(){
    int choice=0,x;
    char ch;
    cout<<"\n\t\tPROGRAM TO IMPLEMENT QUEUES USING LINKEDLIST!!";
    do{
    cout<<"\n 1. Insert an element";
    cout<<"\n 2. Delete an element";
    cout<<"\n 3. Display the Queue";
    cout<<"\n Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1: cout<<"\nEnter the element: ";
                cin>>x;
                enqueue(x);
                break;
        case 2: cout<<"\nThe deleted element from the queue is: "<<dequeue();
                break;
        case 3: cout<<"\nThe element/s present in the queue is/are: "<<endl;
                Display();       
    }
    cout<<"\nTo continue press y or Y,anyother key to exit: ";
    cin>>ch;
    }while(ch=='y' || ch=='Y');
    Delete();
    return 0;
}