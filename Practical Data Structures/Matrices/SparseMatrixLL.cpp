#include<iostream>
using namespace std;

class Node{
public:
    int col;
    int value;
    Node *next;
    
    void create(){
        int row,n;
        cout<<"\nEnter the number of rows: ";
        cin>>row;
        Node *A=new Node[row];
        Node *p=NULL;
        for(int i=0;i<row;i++){
            cout<<"\nEnter the number of elements in row "<<i<<": ";
            cin>>n;
            for(int j=0;j<n;j++){
                cout<<"\nEnter the column number: ";
                cin>>p->col;
                cout<<"\nEnter the value: ";
                cin>>p->value;
                p=p->next;
            }   
        }
    }
};


int main()
{
    Node *A=new Node[5];
    A->create();
    return 0;
}
