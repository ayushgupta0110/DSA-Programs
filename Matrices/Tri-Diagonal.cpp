#include <iostream>
using namespace std;

class TriDiagonal
{
    private:
        int *A;
        int n;
    public:
        TriDiagonal(){
            n=2;
            A=new int[2];
        }
        TriDiagonal(int n){
            this->n=n;
            A=new int[3*n-2];
        }
        ~TriDiagonal(){
            delete []A;
        }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    int GetDimension(){return n;}
};

void TriDiagonal::Set(int i,int j,int x){
    if(i-j==1){
        A[i-1]=x;
    }else if(i-j==0){
        A[n-1+i-1]=x;
    }else{
        A[2*n+i-2]=x;
    }
}


int TriDiagonal::Get(int i,int j){
    if(i-j==1){
       return A[i-1];
    }else if(i-j==0){
       return A[n-1+i-1];
    }else{
       return A[2*n+i-2];
    }
    return 0;
}
void TriDiagonal::Display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i-j==1){
                cout<<A[i-1];
            }else if(i-j==0){
                cout<<A[n-1+i-1];
            }else if(i-j==-1){
                cout<<A[2*n+i-2];
            }else
                cout<<"0 ";
            }
            cout<<endl;
    }
}

int main()
{
    int d;
    cout<<"Enter Dimensions";
    cin>>d;
    TriDiagonal dm(d);
    int x;
    cout<<"Enter All Elements";
    for(int i=1;i<=d;i++){
        for(int j=1;j<=d;j++){
            cin>>x;
            dm.Set(i,j,x);
        }
    }
    dm.Display();
    return 0;
}