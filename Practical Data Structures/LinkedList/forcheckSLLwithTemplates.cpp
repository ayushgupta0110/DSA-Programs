#include<iostream>
using namespace std;

template <class U>
class node{
    private:
    U data;
    node<U> *next;
    public:
    node(U value)
    {
        data=value;
        next=NULL;
    }

    template<class X> friend class SLL;
};

template <class T>
class SLL
{
    private:
    node<T> *head;
    public :
    SLL()
    {
        head=NULL;
    }
    node<T>* gethead()
    {
        return head;
    }
    void insertathead(T value);
    void insertattail(T value);
    void insertatpos(int pos,T value);
    bool deleteathead();
    bool deleteattail();
    bool deleteatpos(int pos);
    void traverse();
    node<T>* search(T element);
    void concatenate(node<T>* head1,node<T>* head2);
    void reverseTraverseHelp(node<T>* temp);
    void reverseTraverse();
    void reverseSLL();
};

template <class T>
void SLL<T> :: traverse()
{
    node<T>* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

template <class T>
node<T>* SLL<T> :: search(T element)
{
    node<T>* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==element)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

template <class T>
void SLL<T> :: insertathead(T value)
{
    node<T>* n = new node<T>(value);
    n->next = head;
    head = n;
}

template <class T>
void SLL<T> :: insertattail(T value)
{
    node<T>* n = new node<T>(value);
    node<T> *temp = head;
    if(head==NULL)
    {
        head=n;
        return;
    }
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

template <class T>
void SLL<T> :: insertatpos(int pos,T value)
{
    if(pos==1)
    {
        insertathead(value);
        return;
    }
    node<T>* n = new node<T>(value);
    int j=1;
    node<T>* temp=head;
    while(j!=pos-1 && temp->next!=NULL)
    {
        temp=temp->next;
        j++;
    }
    if(j!=pos-1)
    {
        cout<<"error!! pos is greater than size of list"<<endl;
        return;
    }
    n->next=temp->next;
    temp->next=n;
}

template <class T>
bool SLL<T> :: deleteathead()
{
    if(head!=NULL)
    {
        node<T> *temp=head;
        if(head->next!=NULL)
        {
            head=head->next;
        }
        else
        {
            head=NULL;
        }
        delete temp;
    return true;
    }

return false;
}

template <class T>
bool SLL<T> :: deleteattail()
{
    if(head->next==NULL)
    {
        node<T>* temp = head;
        head=NULL;
        delete temp;
        return true;
    }
    else
    {
        node<T>* temp=head;
        node<T>* x;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        x=temp->next;
        temp->next=NULL;
        delete x;
        return true;
    }
return false;
}

template <class T>
bool SLL<T> :: deleteatpos(int pos)
{
    if(head==NULL)
    {
        return false;
    }
    else
    {
        if(pos==1) return deleteathead();
        node<T> *temp=head;
        int j=1;
        while(temp!=NULL && j!=pos-1)
        {
            temp=temp->next;
            j++;
        }
        if(j==pos-1)
        {
            if(temp!=NULL)
            {
                if(temp->next!=NULL)
                {
                    if(temp->next->next!=NULL)
                    {
                        node<T>* x;
                        x=temp->next;
                        temp->next=temp->next->next;
                        delete x;
                    }
                    else return deleteattail();
                }
                else return false;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
return true;
}

template <class T>
void SLL<T> :: concatenate(node<T>* head1,node<T>* head2)
{
    node<T>*temp; node<T>*x;
    if(head1!=NULL)
    {
    temp=head1;
    node<T>* n = new node<T>(temp->data);
    temp=temp->next; head=n; x=n;
    while(temp!=NULL)
    {
        node<T>* n = new node<T>(temp->data);
        x->next=n; x=n;
        temp=temp->next;
    }
    }
    else
    {
        if(head2==NULL) return;
    }
    if(head2!=NULL)
    {
    temp=head2;
    if(head==NULL)
    {
        node<T>* n = new node<T>(temp->data);
        head=n;
        x=n;
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        node<T>* n = new node<T>(temp->data);
        x->next=n;
        x=n;
        temp=temp->next;
    }
    }
}

template <class T>
void SLL<T> :: reverseTraverseHelp(node<T>* temp)
{
    if(temp==NULL) return;
    reverseTraverseHelp(temp->next);
    cout<<temp->data<<" -> ";
}

template <class T>
void SLL<T> :: reverseTraverse()
{
    reverseTraverseHelp(head);
    cout<<"NULL"<<endl;
}

template <class T>
void SLL<T> :: reverseSLL()
{
if(head == NULL) return; // no element 
if(head->next == NULL) return; // one element

node<T>* temp=head->next; //for traversing
node<T>* prev=head; //for assining
node<T>* xyz;
while(temp!=NULL)
{
    xyz=temp;
	temp = temp->next;
	xyz->next = prev;
	prev = xyz;
}
head->next=NULL;
head = prev;
}

int main()
{
    SLL<int> l1;

    //initializing with 3 values
    l1.insertattail(10);
    l1.insertattail(11);
    l1.insertattail(12);
    l1.traverse();
    l1.reverseSLL();
    l1.traverse();
    
    SLL<int> l11;

    //initializing with 3 values
    l11.insertattail(10);
    l11.insertattail(11);
    l11.insertattail(12);
    l11.traverse();
    l11.reverseSLL();
    l11.traverse();

    SLL<int> l12;
    l12.concatenate(l1.gethead(),l11.gethead());
    l12.traverse();
    l12.reverseTraverse();

    SLL<double> l2;

    //initializing with 3 values
    l2.insertattail(10.5);
    l2.insertattail(11.6);
    l2.insertattail(12.1);
    l2.traverse();
    l2.reverseSLL();
    l2.traverse();


    SLL<char> l3;

    //initializing with 3 values
    l3.insertattail('a');
    l3.insertattail('b');
    l3.insertattail('c');
    l3.traverse();
    l3.reverseSLL();
    l3.traverse();

    SLL<string> l4;

    //initializing with 3 values
    l4.insertattail("Hello");
    l4.insertattail("Ravi");
    l4.insertattail("Mahto");
    l4.traverse();
    cout<<l4.search("Mahto")<<endl;
    l4.reverseSLL();
    l4.traverse();
}

