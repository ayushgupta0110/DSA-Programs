#include<iostream>
using namespace std;

class Stack{
    int top;
    int size;
    int *stk;
public:
    Stack(){
        top=-1;
        size=10;
        stk=new int[size];
    }

    Stack(int s){
        size=s;
        top=-1;
        stk=new int[size];
    }

    ~Stack(){
        delete[] stk;
    }

    void push(int x);
    int pop();
    int peek(int pos);
    bool isFull();
    bool isEmpty();
    void display();
};

void Stack::push(int x){
    if(isFull())
        cout<<"\nOverflow";
    else{
        stk[++top]=x;
    }    
}

int Stack::pop(){
    int x=-1;
    if(isEmpty()){
        cout<<"\nUnderflow";
    }
    else{
        x=stk[top--];
    }    
    return x;
}

int Stack::peek(int pos){
    int index=top-pos+1;
    if(index<0){
        return -1;
    }
    else{
        return stk[index];
    }
}

bool Stack::isFull(){
    if(top==size-1) return true;
    else return false;
}

bool Stack::isEmpty(){
    if(top==-1) return true;
    else return false;
}

void Stack::display(){
    for(int i=top;i>=0;i--){
        cout<<stk[i]<<endl;
    }
}
int main(){
    int sz,pos;
    cout<<"\nEnter the size of the stack: ";
    cin>>sz;
    Stack S(sz);
    for(int i=0; i<sz; i++) S.push(i);
    S.display();

    cout<<"\nEnter the position of the element: ";
    cin>>pos;
    cout<<"\nThe element present is: "<<S.peek(pos);
    return 0;
}