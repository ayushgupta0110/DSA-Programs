#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int val){
			data=val;
			next=NULL;
		}
};
class Linkedlist{
	Node* head;
	Node* tail;
	public:
		Linkedlist(){
			head=NULL;
			tail=NULL;
		}
		void traverse(){
    	Node* n=head;
    	if(n==NULL){
    		cout<<"No element exist";
    		return;
		}
	    while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
	}
	cout<<"\nhead->data= "<<head->data<<" tail->data= "<<tail->data;
	}
	
		void insertathead(int data){
	    Node* newhead=new Node(data);
	    if(head==NULL){
	    	head=newhead;
	    	if(tail==NULL)
	    	tail=head;
	    	return;
		}
	    newhead->next=head;
	    head=newhead;
	  
    }
    void insertatindex(int index,int data){
	Node* temp=new Node(data);
	if(index==0){
		cout<<"to insert at 0 use insertathead method";
		return;
	}
	int count=0;
	Node* p=head;
	while(count<(index-1) && p!=NULL){
        p=p->next;
		count++;
	}
	if(p==NULL && index>count){
		cout<<"index not exist";
		return;
	}
	
	temp->next=p->next;
	p->next=temp;

}
    void deleteatindex(int index){
	Node* temp=NULL;
	Node* p=head;
	int count=0;
	if(index==0){
		cout<<"To delete head use deletehead method";
		return;
		
	}
	while(count<(index-1)&&p!=NULL){
		p=p->next;
		count++;
		
	}
	if(p==NULL&&count<=index){
		cout<<"index not exist ";
		return;
	}
	temp=p->next;
	p->next=temp->next;
	delete(temp);
	
}
    int deletehead(){
		int x=head->data;
	Node* temp=head;
	head=temp->next;
	delete(temp);
	return x;
	
}
    void search(int data){
	Node* temp=head;
	if(temp->data==data){
		cout<<head;
		return;
	}
	temp=temp->next;
	while(temp!=NULL){
		if(temp->data==data){
			cout<<temp;
		return;}
		else
		temp=temp->next;
	}
		return;
	}
	
	void concat(Linkedlist x){
		if(tail!=NULL&&x.head!=NULL){
		tail->next=x.head;
		tail=x.tail;
	}
	return;
	}
    void insertattail(int data){
	Node* newtail=new Node(data);
	if(tail==NULL){
		tail=newtail;
		if(head==NULL){
			head=tail;
		}
		return;
	}
	tail->next=newtail;
	tail=newtail;
    }
    
    int deletetail(){
	Node* temp=head;
	Node* p=NULL;
    while(temp->next!=NULL){
	p=temp;
	temp=temp->next;
    }
    p->next=NULL;
    tail=p;
    int x=temp->data;
    delete(temp);
	return x;
}
    
    bool issempty(){
        if(head==NULL)
        return true;
        else
        return false;
    }
		
};