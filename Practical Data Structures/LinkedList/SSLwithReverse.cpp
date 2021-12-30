#include<iostream>
using namespace std;

class node{
    private :
    int data;
    node *next;
    node(int value)
    {
        data=value;
        next=NULL;
    }

    friend class SLL;
};

class SLL
{
    private :
    node* head;
    public :
    SLL()
    {
        head=NULL;
    }
    void insertathead(int value);
    void insertattail(int value);
    void insertatpos(int pos,int value);
    bool deleteathead();
    bool deleteattail();
    bool deleteatpos(int pos);
    void traverse();
    node* search(int element);
    void concatenate(node* head1,node* head2);
    void reverseSLL();
};

void SLL :: traverse()
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* SLL :: search(int element)
{
    node* temp=head;
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

void SLL :: insertathead(int value)
{
    node* n = new node(value);
    n->next = head;
    head = n;
}

void SLL :: insertattail(int value)
{
    node* n = new node(value);
    node *temp = head;
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

void SLL :: insertatpos(int pos,int value)
{
    if(pos==1)
    {
        insertathead(value);
        return;
    }
    node* n = new node(value);
    int j=1;
    node* temp=head;
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

bool SLL :: deleteathead()
{
    if(head!=NULL)
    {
        node *temp=head;
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

bool SLL :: deleteattail()
{
    if(head->next==NULL)
    {
        node* temp = head;
        head=NULL;
        delete temp;
        return true;
    }
    else
    {
        node* temp=head;
        node* x;
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

bool SLL :: deleteatpos(int pos)
{
    if(head==NULL)
    {
        return false;
    }
    else
    {
        if(pos==1) return deleteathead();
        node *temp=head;
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
                        node* x;
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

void SLL :: concatenate(node* head1,node* head2)
{
    node*temp; node*x;
    if(head1!=NULL)
    {
    temp=head1;
    node* n = new node(temp->data);
    temp=temp->next; head=n; x=n;
    while(temp!=NULL)
    {
        node* n = new node(temp->data);
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
        node* n = new node(temp->data);
        head=n;
        x=n;
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        node* n = new node(temp->data);
        x->next=n;
        x=n;
        temp=temp->next;
    }
    }
}

void SLL :: reverseSLL()
{
if(head == NULL) return; // no element 
if(head->next == NULL) return; // one element

node* temp=head->next; //for traversing
node* prev=head; //for assining
node* xyz;
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
    SLL l1;

    //initializing with 3 values
    l1.insertattail(10);
    l1.insertattail(11);
    l1.insertattail(12);
    cout<<"SLL before reversing :-"<<endl;
    l1.traverse();
    l1.reverseSLL();
    cout<<"SLL after reversing :-"<<endl;
    l1.traverse();
}

