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
    friend class Deck;
};

template <class T>
class Deck
{
private:
    T *x;
    node<T> *front;
    node<T> *rear;
    int s;

public:
    Deck()
    {
        front = NULL;
        rear = NULL;
        s = 0;
    }

    void addatfront(T value);
    void addatback(T value);
    void removefromfront();
    void removefromback();
    bool empty();
    int size() { return s; }
    T getfront();
    T getback();
    void display();
};

class DeckException
{
private:
    string msg;

public:
    DeckException(string s)
    {
        msg = s;
    }
    string to_string()
    {
        return msg;
    }
};

template <class T>
void Deck<T>::addatfront(T value)
{
    node<T> *n = new node<T>(value);
    if (!n)
    {
        throw DeckException("Error! Heap Overflow.");
    }
    if (front == NULL)
    {
        front = n;
        rear = n;
        front->prev = rear;
        rear->next = front;
        s++;
        return;
    }
    n->next = front;
    front->prev = n;
    n->prev = rear;
    front = n;
    rear->next = front;
    s++;
}

template <class T>
void Deck<T>::addatback(T value)
{
    node<T> *n = new node<T>(value);
    if (!n)
    {
        throw DeckException("Error! Heap Overflow.");
    }
    if (front == NULL)
    {
        front = n;
        rear = n;
        n->next = front;
        n->prev = rear;
        s++;
        return;
    }
    node<T> *temp = front;
    while (temp->next != front)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = front;
    n->prev = temp;
    rear = n;
    s++;
}

template <class T>
void Deck<T>::removefromfront()
{
    if (front == NULL)
    {
        throw DeckException("Error! Deck Underflow.");
    }
    if (s == 1)
    {
        delete front;
        front = NULL;
        rear = NULL;
        s--;
        return;
    }
    node<T> *todel = front;
    front = front->next;
    front->prev = rear;
    rear->next = front;
    delete todel;
    s--;
}

template <class T>
void Deck<T>::removefromback()
{
    if (front == NULL)
    {
        throw DeckException("Error! Deck Underflow.");
    }
    if (s == 1)
    {
        delete front;
        front = NULL;
        rear = NULL;
        s--;
        return;
    }
    node<T> *todel = rear;
    rear = rear->prev;
    rear->next = front;
    front->next = rear;
    delete todel;
    s--;
}

template <class T>
bool Deck<T>::empty()
{
    if (front == NULL)
        return true;
    else
        return false;
}

template <class T>
T Deck<T>::getfront()
{
    if (front == NULL)
        throw DeckException("error!! Deck is empty.");
    else
        return front->data;
}

template <class T>
T Deck<T>::getback()
{
    if (rear == NULL)
        throw DeckException("error!! Deck is empty.");
    else
        return rear->data;
}

template <class T>
void Deck<T>::display()
{
    if (front == NULL)
    {
        cout << "empty" << endl;
        return;
    }

    node<T> *temp = front;
    do
    {
        cout << temp->data << " <<>> ";
        temp = temp->next;
    } while (temp != front);
    cout << endl;
}

Deck<int> q1; //global Deck variable

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
    catch (DeckException de)
    {
        cout << de.to_string() << endl;
        return;
    }
    cout << "--- Deck ---" << endl;
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
    catch (DeckException de)
    {
        cout << de.to_string() << endl;
        return;
    }
    cout << "--- Deck ---" << endl;
    q1.display();
}

template <class T>
void RemoveFromFrontMenu()
{
    try
    {
        q1.removefromfront();
    }
    catch (DeckException de)
    {
        cout << de.to_string() << endl;
        return;
    }

    cout << "Element removed successfully." << endl;
    cout << "--- Deck ---" << endl;
    q1.display();
}

template <class T>
void RemoveFromBackMenu()
{
    try
    {
        q1.removefromback();
    }
    catch (DeckException de)
    {
        cout << de.to_string() << endl;
        return;
    }

    cout << "Element removed successfully." << endl;
    cout << "--- Deck ---" << endl;
    q1.display();
}

template <class T>
void GetFrontMenu()
{
    T front_element;
    try
    {
        front_element = q1.getfront();
    }
    catch (DeckException de)
    {
        cout << de.to_string() << endl;
        return;
    }
    cout << "Front element of Deck : " << front_element << endl;
}

template <class T>
void GetBackMenu()
{
    T back_element;
    try
    {
        back_element = q1.getback();
    }
    catch (DeckException de)
    {
        cout << de.to_string() << endl;
        return;
    }
    cout << "Back element of Deck : " << back_element << endl;
}

void DisplayMenu()
{
    cout << "--- Deck ---" << endl;
    q1.display();
}

template <class T>
void menu()
{
    int choice;
    do
    {
        cout << "--- Deck Impelementation using Array ---" << endl;
        cout << "1. Add At Front" << endl;
        cout << "2. Add At Back" << endl;
        cout << "3. Remove From Front" << endl;
        cout << "4. Remove From Back" << endl;
        cout << "5. Get Front" << endl;
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
            GetFrontMenu<T>();
            break;
        case 6:
            GetBackMenu<T>();
            break;
        case 7:
            cout << "Size of Deck : " << q1.size() << endl;
            break;
        case 8:
            DisplayMenu();
            break;
        case 9:
            exit(0);
        default:
            cout << "Wrong!! choice try again..." << endl;
        }
        cout << endl;
        system("pause");
        system("cls");
    } while (choice != 9);
}
int main()
{
    menu<int>();
}