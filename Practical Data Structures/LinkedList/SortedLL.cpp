#include <iostream>
using namespace std;
 
// Node of a doubly linked list
class Node {
    public:
    int data;
    Node* prev, *next;
    Node(int d) { data = d; prev = next = NULL; }
    ~Node() {delete prev; delete next;}
};

class SortedDLL {
    Node *head =NULL, *tail=NULL;


public: void sortedInsert(int data);
        void remove(int data);
        void traverse();
        int search(int data);
        ~SortedDLL(){
            while(head != NULL){
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }
};
 
// function to insert a new node in sorted way in
// a sorted doubly linked list
void SortedDLL::sortedInsert(int data){
   Node* newNode = new Node(data);
			Node* temp = head;
			if(head == NULL){
				head = newNode;
				tail = newNode;
				return;
			}
			if(head->data >= data){
				newNode->next = head;
				head->prev = newNode;
				head = newNode;
				return;
			}
			while(temp->next != NULL){
				if(temp->data >= data){
					temp->prev->next = newNode;
					newNode->prev = temp->prev;
					temp->prev = newNode;
					newNode->next = temp;
					return;
				}
				temp = temp->next;
			}
			if(tail->data >= data){
				tail->prev->next = newNode;
				newNode->prev = tail->prev;
				tail->prev = newNode;
				newNode->next = tail;
				return;
			}
			if(data > tail->data){
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}
}    


// function to remove a node from a sorted doubly linked list
void SortedDLL::remove(int data){
    Node*p;
    // if the node is the first node
    if(head->data == data){
        p = head;
        head = head->next;
        delete p;
        return;
    }
    // if the node is the last node
    if(tail->data == data){
        p = tail;
        tail = tail->prev;
        delete p;
        return;
    }
    // if the node is in between
    p = head;
    while(p->next != NULL){
        if(p->next->data == data){
            p->next = p->next->next;
            p->next->prev = p;
            return;
        }
        p = p->next;
    }
}

// function to print the doubly linked list
void SortedDLL::traverse(){
			if(head == NULL)
				cout<<"\nThe list is empty! \n";
			else{
				cout<<"\nForward traverse: ";
				Node* temp = head;
				while(temp != NULL){
					cout<<temp->data<<" ";
					temp = temp->next;
				}
				cout<<"\nTail: "<<tail->data<<endl;
				
				cout<<"\nBackward traverse: ";
				temp = tail;
				while(temp != NULL){
					cout<<temp->data<<" ";
					temp = temp->prev;
				}
				cout<<"\nHead: "<<head->data<<endl;
			}	
}

//function to search a node in the doubly linked list
int SortedDLL::search(int data){
        if(head == NULL){
            cout<<"\nThe list is empty! \n";
            return 0;
        }
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == data){
                return 1;
            }
            temp = temp->next;
        }
        return 0;
}

 
// Driver program to test above
int main()
{
    SortedDLL list;
    list.sortedInsert(10);
    list.sortedInsert(30);
    list.sortedInsert(20);
    list.sortedInsert(50);
    list.sortedInsert(40);

    list.traverse();

    list.remove(20);
    list.traverse();

    if(list.search(30))
        cout<<"\n30 is present in the list";
    else
        cout<<"\n30 is not present in the list";

    if(list.search(20))
        cout<<"\n20 is present in the list";
    else
        cout<<"\n20 is not present in the list";

    return 0;
}