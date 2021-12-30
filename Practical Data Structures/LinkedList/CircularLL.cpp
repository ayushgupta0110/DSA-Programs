#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node *next;
}*tail;
 
class circular_llist
{
    public:
        void add_end(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void delete_element(int value);
    	void search(int ele);
        void display_list();
    	void reverse();
		circular_llist()
        {
            tail = NULL;           
        }
};
 
int main()
{
    int choice, element, position,ele;
    circular_llist cl;
    do{
    	cout<<"\nMain Menu";     
        cout<<"\n1.Add at end";
        cout<<"\n2.Add at beginning";
        cout<<"\n3.Add after";
        cout<<"\n4.Delete";
        cout<<"\n5.search";
    	cout<<"\n6.display";
        cout<<"\n7.Exit";
        cout<<"\nEnter your choice : ";
        cin>>choice;

		switch(choice)
        {
			case 1:
				cout<<"\nEnter the element: ";
				cin>>element;
				cl.add_end(element);
				cout<<endl;
				break;
			case 2:
				cout<<"\nEnter the element: ";
				cin>>element;
				cl.add_begin(element);
				cout<<endl;
				break;
			case 3:
				cout<<"\nEnter the element: ";
				cin>>element;
				cout<<"\nInsert element after position: ";
				cin>>position;
				cl.add_after(element, position);
				cout<<endl;
				break;
			case 4:
				if (tail == NULL)
				{
					cout<<"\nList is empty, nothing to delete";
					break;
				}
				cout<<"\nEnter the element for deletion: ";
				cin>>element;
				cl.delete_element(element);
				cout<<endl;
				break;
			case 5:cout<<"Enter the elemeent to be searched ";
						cin>>ele;
					cl.search(ele);         
					break;
			
			case 6:		cl.display_list();
				break;
            case 7: exit(0);     
            default: cout<<"\nInvalid choice";
        }
    }while(choice!=8);
}

void circular_llist::add_end(int value)
{
    node *temp;
    temp = new(node);
    temp->data = value;
    if (tail == NULL)
    {
        tail = temp;
        temp->next = tail;   
    }
    else
    {
        temp->next = tail->next; 
        tail->next = temp;
        tail = temp;
    }
}
 
void circular_llist:: search(int ele)
{
	int flag=0;
	int count=0;
	node *t;
	t=tail->next;
	while(t->next!=tail)
	{
		++count;
		if(t->data==ele)
		{	
			flag=1;
			cout<<"Element found at position "<<count;
			break;
		}
		t=t->next;
	}
	if(flag==0)
	cout<<"Element not found ";
}
 
void circular_llist::add_begin(int value)
{
    if (tail == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    node *temp;
    temp = new(node);
    temp->data = value;
    temp->next = tail->next;
    tail->next = temp;
}
 
void circular_llist::add_after(int value, int pos)
{
    if (tail == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    node *temp, *s;
    s = tail->next;

	for (int i = 0;i < pos-1;i++)
    {
        s = s->next;
        if (s == tail->next)
        {
            cout<<"There are less than ";
            cout<<pos<<" in the list"<<endl;
            return;
        }
    }

	temp = new(node);
    temp->next = s->next;
    temp->data = value;
    s->next = temp;

	if (s == tail)
    { 
        tail=temp;
    }
}
 
void circular_llist::delete_element(int value)
{
    node *temp, *s;
    s = tail->next;
    if (tail->next == tail && tail->data == value)  
    {
        temp = tail;
        tail = NULL;
        free(temp);
        return;
    }
    if (s->data == value)  
    {
        temp = s;
        tail->next = s->next;
        free(temp);
        return;
    }

	while (s->next != tail)
    {
        if (s->next->data == value)    
        {
            temp = s->next;
            s->next = temp->next;
            free(temp);
            cout<<"Element "<<value;
            cout<<" deleted from the list"<<endl;
            return;
        }
        s = s->next;
    }

	if (s->next->data == value)    
    {
        temp = s->next;
        s->next = tail->next;
        free(temp);		
        tail = s;
        return;
    }
    cout<<"Element "<<value<<" not found in the list"<<endl;
}
 
void circular_llist::display_list()
{
    node *s;
    if (tail == NULL)
    {
        cout<<"List is empty, nothing to display"<<endl;
        return;
    }
    s = tail->next;
    cout<<"Circular Link List: "<<endl;

	while (s != tail)
    {
        cout<<s->data<<" ->";
        s = s->next;
    }
    cout<<s->data<<endl;
}

void circular_llist:: reverse()
{
    node *p, *q, *r;
 
    p = q = r = tail->next;
    p = p->next->next;
    q = q->next;
    r->next = NULL;
    q->next = r;
 
    while (p != tail)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    tail = q;
}