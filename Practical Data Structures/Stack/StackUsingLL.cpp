#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Stack{
private:
    Node *top;
public:
    Stack(){top=NULL;}
    ~Stack(){
        Node*p;
        while(top){
            p=top;
            top=top->next;            
            delete p;
        }
    }
    void push(int x);
    int pop();
    void Display();
    int peek(int pos);
    bool isEmpty();
    bool isFull();
    int StackTop();
};

void Stack::push(int x){
    Node *t=new Node;
    if(t==NULL)
        cout<<"\nStack is Full";
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int Stack::pop(){
    int x=-1;
    if(top==NULL)
        cout<<"Stack is Empty\n";
    else{
        x=top->data;Node *t=top;
        top=top->next;
        delete t;
    }
    return x;
}

void Stack::Display(){
    Node *p=top;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    delete p;
}

int Stack::peek(int pos){
    Node *p=top;
    
    for(int i=0;i<pos-1 && p;i++) p=p->next;
    if(p){
        return p->data;    
        delete p;
    }
    return -1;
}

int Stack::StackTop(){
    if(top)
       return top->data;
    return -1;   
}

bool Stack::isEmpty(){
    return top? false:true;
}

bool Stack::isFull(){
    Node *t=new Node;
    bool r= t? false:true;
    delete t;
    return r;
}

int main()
{
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.Display();
    cout<<stk.pop();
    cout<<endl<<stk.peek(2);

    return 0;
}