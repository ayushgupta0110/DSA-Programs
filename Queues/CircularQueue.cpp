#include <iostream>
using namespace std;

class Queue{
    int front;
    int rear;
    int size;
    int *Q;
public:
    Queue(){front=rear=0;size=10;Q=new int[size];}
    Queue(int size){front=rear=0; this->size=size; Q=new int[this->size];}
    void enqueue(int x);
    int dequeue();
    void Display();
};

void Queue::enqueue(int x){
    if((rear+1)%size==front)
        cout<<"\nQueue is Full";
    else
    {
        rear=(rear+1)%size;
        Q[rear]=x;
    }
}

int Queue::dequeue(){
    int x=-1;
    if(front==rear)
        cout<<"\nQueue is Empty.";
    else{
        front= (front+1)%size;
        x=Q[front];
    }
return x;
}

void Queue::Display(){
    int i=front+1;
    do{
        cout<<Q[i]<<" ";
        i++;
    }while(i!=(rear+1)%size);
    cout<<endl;
}

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.Display();

    cout<<"\nElement deleted is: "<<q.dequeue()<<endl;
    q.Display();
    return 0;
}