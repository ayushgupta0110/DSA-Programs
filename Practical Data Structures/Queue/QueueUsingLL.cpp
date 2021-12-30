#include<iostream>
#include "LinkedList.cpp"
using namespace std;

class QueueLL{
	Linkedlist l;
	public:
		void enqueue(int data){
			l.insertattail(data);
		}

		int dequeue(){
			if(!l.issempty()){
				return l.deletehead();
			}
			else{
				cout<<"Error: Queue is empty"<<endl;
				return -1;
			}
		}

        void display(){
            l.display();
        }
        
		bool isempty(){
			if(l.issempty())
			    return true;
			else
			    return false;
		}
};


int main(){
	QueueLL q;
	char ch;
	do{
		cout<<"\n1 to insert element in Queue";
		cout<<"\n2 to retrieve first element from Queue";
		cout<<"\n3 to check Queue is empty or not"<<endl;
		int x,data;
		cin>>x;
		switch(x){
			case 1:
				cout<<"\nEnter the element you want to insert : ";
				cin>>data;
				q.enqueue(data);
				break;
			case 2:
				cout<<"\nThe retrieved element is: ";
				cout<<q.dequeue();
				break;
			case 3:
				if(q.isempty())
                    cout<<"\nQueue is empty";
                else
                    cout<<"\nQueue is not empty";
				break;
			default:
				cout<<"\nInvalid input... ";
		}
		cout<<"\nTo continue press Y or y, anyother key to exit... ";
		cin>>ch;
		
	}while(ch=='y'||ch=='Y');
}