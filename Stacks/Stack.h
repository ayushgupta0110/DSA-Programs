#include<iostream>
using namespace std;
template<class T>
class Stack{
    int top;
    int size;
    T *stk;
public:
    Stack(){
        top=-1;
        size=10;
        stk=new T[size];
    }

    Stack(int s){
        size=s;
        top=-1;
        stk=new T[size];
    }

    ~Stack(){
        delete[] stk;
    }

    void push(T x);
    int pop();
    int peek(int pos);
    bool isFull();
    bool isEmpty();
    void display();
    T stackTop();
};

template<class T>
void Stack<T>::push(T x){
    if(isFull())
        cout<<"\nOverflow";
    else{
        stk[++top]=x;
    }    
}

template<class T>
int Stack<T>::pop(){
    int x=-1;
    if(isEmpty()){
        cout<<"\nUnderflow";
    }
    else{
        x=stk[top--];
    }    
    return x;
}

template<class T>
int Stack<T>::peek(int pos){
    int index=top-pos+1;
    if(index<0){
        return -1;
    }
    else{
        return stk[index];
    }
}

template<class T>
T Stack<T>::stackTop(){
    if(top==-1)return -1;
    else
        return stk[top];
}

template<class T>
bool Stack<T>::isFull(){
    if(top==size-1) return true;
    else return false;
}

template<class T>
bool Stack<T>::isEmpty(){
    if(top==-1) return true;
    else return false;
}

template<class T>
void Stack<T>::display(){
    for(int i=top;i>=0;i--){
        cout<<stk[i]<<endl;
    }
}

// int main(){
//     int sz,pos;
//     cout<<"\nEnter the size of the stack: ";
//     cin>>sz;
//     Stack<int> S(sz);
//     for(int i=0; i<sz; i++) S.push(i);
//     S.display();

//     cout<<"\nEnter the position of the element: ";
//     cin>>pos;
//     cout<<"\nThe element present is: "<<S.peek(pos);
//     return 0;
// }