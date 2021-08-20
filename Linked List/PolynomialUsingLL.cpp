#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

class Node
{
    public: 
    int coeff;
    int exp;
    Node *next;
}*poly=NULL;

void create(){
    Node *t,*last=NULL;
    int num,i;
    cout<<"Enter number of terms";
    cin>>num;
    cout<<"Enter each term with coeff and exp\n";
    for(i=0;i<num;i++)
    {
        t=new Node;
        cin>>t->coeff>>t->exp;
        t->next=NULL;
        if(poly==NULL)
        {
            poly=last=t;
        }
        else{
            last->next=t;
            last=t;
        }
    }
}

void Display(struct Node *p)
    {
    while(p){
        cout<<p->coeff<<p->exp<<" ";
        p=p->next;
    }
    cout<<"\n";
}
    
long Eval(struct Node *p, int x){
    long val=0;
    while(p)
    {
    val+=p->coeff*pow(x,p->exp);
    p=p->next;
    }
    return val;
}

int main()
{
    create();
    Display(poly);
    cout<<Eval(poly,1);
    return 0;
}