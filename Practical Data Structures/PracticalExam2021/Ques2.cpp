/* 
Examination Roll no: 20067570010
Roll No: 20512
Set No: 2

Question 2:
Implement Double-ended Queues using Linked list representation 
*/

#include <iostream>
using namespace std;

template <class T>
class node
{
    private:
        T data;
        node<T> *next;
        node<T> *prev;

    public:
        node(T value)
        {
            data = value;
            next = NULL;
            prev = NULL;
        }
        template <class U>
        friend class DLL;
};

template <class T>
class DLL
{
    private:
        node<T>* head;
        node<T>* tail;
        int s;
    public:
        DLL()
        {
            head=NULL;
            tail=NULL;
            s=0;
        }
        void insertathead(T value);
        void insertattail(T value);
        void deletefromhead();
        void deletefromtail();
        int size(){return s;}
        T getheadelement(){
            if(head==NULL)
                throw "Error! Queue is Empty";
            return head->data;
        }
        T gettailelement(){
            if(tail==NULL)
                throw "Error! Queue is Empty";
            return tail->data;
        }
        void display();
};

template <class T>
void DLL<T>::insertathead(T value)
{
    node<T> *n = new node<T>(value);
    if (!n)
    {
        throw "Error! Heap Overflow.";
    }
    if (head == NULL)
    {
        head = n;
        tail = n;
        s++;
        return;
    }
    n->next = head;
    head->prev = n;
    head = n;
    s++;
}

template <class T>
void DLL<T>::insertattail(T value)
{
    node<T> *n = new node<T>(value);
    if (!n)
    {
        throw "Error! Heap Overflow.";
    }
    if (head == NULL)
    {
        head = n;
        tail = n;
        s++;
        return;
    }
    tail->next = n;
    n->prev = tail;
    tail = n;
    s++;
}

template <class T>
void DLL<T>::deletefromhead()
{
    if (head == NULL)
    {
        throw "Error! Deque Underflow";
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
        s--;
        return;
    }
    node<T> *todel = head;
    head = head->next;
    head->prev = NULL;
    delete todel;
    s--;
}

template <class T>
void DLL<T>::deletefromtail()
{
    if (head == NULL)
    {
        throw "Error! Deque Underflow";
    }
    if (head->next == NULL)
    {
        delete tail;
        head = NULL;
        tail = NULL;
        s--;
        return;
    }
    node<T> *todel = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete todel;
    s--;
}

template <class T>
void DLL<T>::display()
{
    if (head == NULL)
    {
        cout << "empty" << endl;
        return;
    }

    node<T> *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " <<-->> ";
        temp = temp->next;
    }
    cout << endl;
}


template <class T>
class Deque
{
    private:
        DLL<T> list;

    public:
        void addatfront(T value);
        void addatback(T value);
        void removefromfront();
        void removefromback();
        bool empty();
        int size() { return list.size(); }
        T front();
        T back();
        void display();
};

template <class T>
void Deque<T>::addatfront(T value) 
{
    list.insertathead(value);
}

template <class T>
void Deque<T>::addatback(T value) 
{
    list.insertattail(value);
}

template <class T>
void Deque<T>::removefromfront() 
{
    list.deletefromhead();
}

template <class T>
void Deque<T>::removefromback() 
{
    list.deletefromtail();
}

template <class T>
bool Deque<T>::empty()
{
    if (size() == 0)
        return true;
    else
        return false;
}

template <class T>
T Deque<T>::front() 
{
    return list.getheadelement();
}

template <class T>
T Deque<T>::back() 
{
    return list.gettailelement();
}

template <class T>
void Deque<T>::display()
{
    list.display();
}

Deque<int> q1; //global Deque variable

template <class T>
void AddAtFrontMenu()
{
    T element;
    cout << "Enter element to push : ";
    cin >> element;
    try
    {
        q1.addatfront(element);
    }
    catch (const char* e)
    {
        cout << e << endl;
        return;
    }
    cout << " Deque: " << endl;
    q1.display();
}

template <class T>
void AddAtBackMenu()
{
    T element;
    cout << "Enter element to push : ";
    cin >> element;
    try
    {
        q1.addatback(element);
    }
    catch (const char* e)
    {
        cout << e << endl;
        return;
    }
    cout << " Deque :" << endl;
    q1.display();
}

template <class T>
void RemoveFromFrontMenu()
{
    try
    {
        q1.removefromfront();
    }
    catch (const char* e)
    {
        cout << e << endl;
        return;
    }

    cout << "Element removed successfully." << endl;
    cout << " Deque: " << endl;
    q1.display();
}

template <class T>
void RemoveFromBackMenu()
{
    try
    {
        q1.removefromback();
    }
    catch (const char* e)
    {
        cout << e << endl;
        return;
    }

    cout << "Element removed successfully." << endl;
    cout << " Deque: " << endl;
    q1.display();
}

template <class T>
void FrontMenu()
{
    T front_element;
    try
    {
        front_element = q1.front();
    }
    catch (const char* e)
    {
        cout << e << endl;
        return;
    }
    cout << "Front element of Deque : " <<front_element<<endl;
}

template <class T>
void backMenu()
{
    T back_element;
    try
    {
        back_element = q1.back();
    }
    catch (const char* e)
    {
        cout << e << endl;
        return;
    }
    cout << "Back element of Deque : " << back_element << endl;
}

void DisplayMenu()
{
    cout << " Deque: " << endl;
    q1.display();
}

template <class T>
void menu()
{
    int choice;
    do
    {
        cout << "\t\tDeque Impelementation using Double Linked List!!" << endl;
        cout << "1. Insert At head" << endl;
        cout << "2. Insert At Back" << endl;
        cout << "3. Remove From head" << endl;
        cout << "4. Remove From Back" << endl;
        cout << "5. Get front" << endl;
        cout << "6. Get Back" << endl;
        cout << "7. Get Size" << endl;
        cout << "8. Display" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            AddAtFrontMenu<T>();
            break;
        case 2:
            AddAtBackMenu<T>();
            break;
        case 3:
            RemoveFromFrontMenu<T>();
            break;
        case 4:
            RemoveFromBackMenu<T>();
            break;
        case 5:
            FrontMenu<T>();
            break;
        case 6:
            backMenu<T>();
            break;
        case 7:
            cout<<"Size of Deque : "<<q1.size()<<endl;
            break;
        case 8:
            DisplayMenu();
            break;
        case 9:
            exit(0);
        default:
            cout<<"Invalid choice! Please try again..."<<endl;
        }
        cout<<endl;
    } while (choice != 9);
}
int main()
{
    menu<int>();
}