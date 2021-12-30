#include<iostream>
using namespace std;

#define MAX 10

class TwoDArray{
private: int arr[MAX][MAX];
         int rw,col;

public: 
    TwoDArray(int r,int c){
        rw=r;
        col=c;
        for(int i=0;i<rw;i++)
            for(int j=0;j<col;j++)
                cin>>arr[i][j];
    }
    void insert(int row, int col, int value){
        arr[row][col] = value;
    }
    void traverse(){
        for(int i = 0; i < rw; i++){
            for(int j = 0; j < col; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    void Delete(int row, int col){
        arr[row][col] =-1;
    }
};

int main(){
    int row,col,value;
    cout<<"\t\t Basic Functions in 2D Array"<<endl;
    cout<<"\t\t----------------------------"<<endl;
    cout<<"Enter the dimensions of 2d array(row,column): "<<endl;
    cin>>row>>col;
    TwoDArray arr(row,col);
    cout<<"\t\t1.Insert"<<endl;
    cout<<"\t\t2.Delete"<<endl;
    cout<<"\t\t3.Traverse"<<endl;
    cout<<"\t\t4.Exit"<<endl;
    cout<<"\t\tEnter your choice: ";
    int choice;
    cin>>choice;
    while(choice!=4){
        switch(choice){
            case 1:
                cout<<"\t\tEnter the row and column: ";
                cin>>row>>col;
                cout<<"\t\tEnter the value to be inserted: ";
                cin>>value;
                arr.insert(row,col,value);
                break;
            case 2: 
                cout<<"\t\tEnter the row and column: ";
                cin>>row>>col;
                arr.Delete(row,col);
                break;
            case 3:
                arr.traverse();
                break;
            default:
                cout<<"\t\tInvalid choice"<<endl;
                break;
        }
        cout<<"\t\tEnter your choice: ";
        cin>>choice;
    }
    return 0;
}