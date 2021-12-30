#include <iostream>
using namespace std;
#define MAX 10

template <class T>
class QueueUsingArray{
    T front;
    T rear;
    int size;
    T *Q;
public:
    QueueUsingArray(){front=rear=0;size=10;Q=new T[size];}
    QueueUsingArray(int size){front=rear=0; this->size=size; Q=new T[this->size];}
    void enqueue(T x);
    T dequeue();
    T isEmpty();
    T Front();
    void Display();
};

template <class T>
void QueueUsingArray<T>::enqueue(T x){
    if((rear+1)%size==front)
        cout<<"\nQueue is Full";
    else
    {
        rear=(rear+1)%size;
        Q[rear]=x;
    }
}

template <class T>
T QueueUsingArray<T>::dequeue(){
    T x=-1;
    if(front==rear)
        cout<<"\nQueue is Empty.";
    else{
        x=Q[front];
        front= (front+1)%size;
    }
return x;
}

template <class T>
T QueueUsingArray<T>::isEmpty(){
    if(front==rear)
        return 1;
    else
        return 0;
}

template <class T>
T QueueUsingArray<T>::Front(){
    return Q[front];
}

template <class T>
void QueueUsingArray<T>::Display(){
    int i=front+1;
    do{
        cout<<Q[i]<<" ";
        i++;
    }while(i!=(rear+1)%size);
    cout<<endl;
}

int main()
{
 int choice=0;
    int x;
    char ch;
    QueueUsingArray<int> Q(MAX);
    cout<<"\n\t\tPROGRAM TO IMPLEMENT QUEUES USING ARRAY!!";
    do{
    cout<<"\n 1. Insert an element";
    cout<<"\n 2. Delete an element";
    cout<<"\n 3. See the First element of the Queue";
    cout<<"\n 4. check if Queue is empty";
    cout<<"\n 5. Display the Queue";
    cout<<"\n Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1: cout<<"\nEnter the element: ";
                cin>>x;
                Q.enqueue(x);
                break;
        case 2: cout<<"\nThe deleted element from the Queue is: "<<Q.dequeue();
                break;
        case 3: cout<<"\nThe first element from the Queue is: "<<Q.Front();
                break;   
        case 4: if(Q.isEmpty()){
                    cout<<"\nQueue is Empty.";
                }
                else{
                    cout<<"\nThe Queue is: ";
                    Q.Display();
                }
                break;             
        case 5: cout<<"\nThe element/s present in the Queue is/are: "<<endl;
                Q.Display();       
    }
    cout<<"\nTo continue press y or Y,anyother key to exit: ";
    cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}