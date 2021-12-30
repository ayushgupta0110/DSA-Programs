#include <iostream>
using namespace std;

template <class T>
class Node
{
    public:
    T data; 
    Node *next;
    Node *previous;

    Node(T value)
    {
        this->data=value;
        next = NULL;
        previous = NULL;
    }
};

template <class T>
class DLList 
{
    Node<T> *head=NULL; 
    Node<T> *tail=NULL;
    int length {};

    public:
    void insertAtHead(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
        this->length++;
    }

    void insertAtEnd(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if(tail == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
        this->length++;
    }

    void display()
    {
        Node<T> *current = this->head;
        while(current != NULL)
        {
            cout<<current->data<<" "; 
            current = current->next;
        }
        cout<<endl;
    }

    void displayOdd()
    {
        Node<T> *current = this->head;
        while(current != NULL)
        {
            cout<<current->data<<" "; 
            current = current->next;

            if(current) current = current->next;
        }
        cout<<endl;
    }

    void insert(int index, T value)
    {
        if(index > this->length || index<0)
        {
            cout<<("\n[-]Invalid index for insert method\n");
            return;
        }

        Node<T> *newNode = new Node<T>(value);
        if(index==this->length) this->tail=newNode;
        this->length++;
        if(index==0)
        {
            newNode->next = head;
            head->previous = newNode;
            newNode->previous = NULL;
            head = newNode;
            return;
        }

        Node<T> *current = head;
        for(int i=1;i<index;i++)
        {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->previous = current;
        if(current->next != NULL) current->next->previous = newNode;
        current->next = newNode;
    }

    void remove(int index)
    {
        if(index > this->length-1 || index<0)
        {
            cout<<("\n[-]Invalid index for remove method\n");
            return;
        }

        this->length--;
        Node<T> *current = this->head;

        if(index==0)
        {
            this->head = this->head->next;
            if(head!=NULL) this->head->previous=NULL;
            delete current;
            return;
        }

        for(int i=0;i<index;i++)
        {
            current = current->next;
        }

        current->previous->next = current->next;
        if (current->next!=NULL)
        {
            current->next->previous=current->previous;
        }

        else this->tail = current->previous;
        delete current;
    }

    float average()
    {
        double avg = 0.0;
        Node<T> *current = this->head;
        while(current != NULL)
        {
            avg+=current->data;
            current = current->next;
        }
        return (avg/length);
    }

    T getMiddle()
    {
        Node<T> *current = this->head;
        for(int i=0; i<(length/2); i++)
        {
            current = current->next;
        }

        return current->data;
    }

    bool isEqual(DLList<T> *list){
        if(this->length != list->length) return false;

        Node<T> *current = this->head;
        Node<T> *listCurrent = list->head;
        while(current != NULL && listCurrent != NULL)
        {
            if(current->data != listCurrent->data) return false;
            current = current->next;
            listCurrent = listCurrent->next;
        }
        return true;
    }
    ~DLList(){
        delete head;
        delete tail;
    }
};

int main(){
    DLList<int> dll;
    DLList<int> dll2;
    int choice, value=0, index,n;

    while(1){
    cout<<"\n\t\tOperations in Doubly Linked List!!\n";
    cout<<"\n 1. Insert n elements at head \n 2. remove an element \n 3. Display \n 4. Average of all elements \n 5. Display the middle element \n 6. Check if 2 list are same \n 7. Exit"<<endl;
    cout<<" Enter your choice: "<<endl;
    cin>>choice;
    switch(choice){
        case 1: cout<<"\n Enter the number of elements to be inserted: ";
                cin>>n;
                for(int i=0;i<n;i++){
                    cout<<"\n Enter the value: ";
                    cin>>value;
                    dll.insertAtHead(value);
                }
                break;
        case 2: cout<<"\n Enter the index of the element to be removed: ";
                cin>>index;
                dll.remove(index);
                break;
        case 3: dll.display();
                break;
        case 4: cout<<"\n Average of all elements: "<<dll.average();
                break;
        case 5: cout<<"\n Middle element: "<<dll.getMiddle();
                break;
        case 6: cout<<"\n Enter the number of elements in the list: ";
                cin>>n;
                for(int i=0; i<n; i++)
                {
                    cout<<"\n Enter the value: ";
                    cin>>value;
                    dll2.insertAtEnd(value);
                }
                dll.display();
                dll2.display();
                if(dll.isEqual(&dll2)) cout<<"\n Both lists are equal";
                else cout<<"\n Both lists are not equal";
                break;
        case 7: exit(0);        
        default: cout<<"\n Invalid choice...";
    }
}
    return 0;
}