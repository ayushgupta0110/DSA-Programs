/* 
 WAP to implement Insert,Delete and Display functions in a 1D-array.
*/

#include<iostream>
using namespace std;
#define MAX 10
int arr[MAX]={0};
int n=0;


void Display(){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Insert(){
    int index,ele=0;
    cout<<"Enter the element and index: ";
    cin>>ele>>index;
    
    if(index<0 || index>MAX){
        cout<<"Invalid Index";
        return;
    }
    for(int i=n;i>index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=ele;
    n++;
    cout<<endl;
    Display();
}

void Delete(){
    int index;
    cout<<"Enter the index: ";
    cin>>index;

    if(index<0 || index>n){
        cout<<"Invalid Index";
        return;
    }
    int x=arr[index];
    for(int i=index;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
    cout<<"\nDeleted element is: "<<x;
    cout<<endl;
    Display();
}

int main(){
    int choice;
    char ch;
    cout<<"\nEnter the number of elements: ";
    cin>>n;
    cout<<"\nEnter the elements in the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    do{   
    cout<<"1.Insert\n2.Delete\n3.Display\nEnter your choice: ";
    cin>>choice;
    switch(choice){
        case 1: Insert();break;
        case 2: Delete();break;
        case 3: Display();break;
        default: cout<<"Invalid Choice";
    }
    cout<<"\nTo continue press y or Y, anyother key to exit: ";
    cin>>ch;
    }while(ch == 'y' || ch == 'Y');
}