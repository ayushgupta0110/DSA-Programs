/* Toeplitz Matrix - Matrix in which the diagonal elements are same.*/

#include <iostream>
using namespace std;

class ToeplitzMatrix
{
    private:
        int *A;
        int n;
    public:
        ToeplitzMatrix(){
            n=2;
            A=new int[2];
        }
        ToeplitzMatrix(int n){
            this->n=n;
            A=new int[2*n-1];
        }
        ~ToeplitzMatrix(){
            delete []A;
        }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    int GetDimension(){return n;}
};

void ToeplitzMatrix::Set(int i,int j,int x){
    if(i<=j){
        A[j-i]=x;
    }else
        A[n+i-j-1]=x;
}


int ToeplitzMatrix::Get(int i,int j){
    if(i<=j){
       return A[j-i];
    }else
       return A[n+i-j-1];
    return 0;
}
void ToeplitzMatrix::Display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i<=j){
                cout<<A[j-i];
            }else if(i>j)
                cout<<A[n+i-j-1];
        }
        cout<<endl;
    }
}

int main()
{
    int d;
    cout<<"Enter Dimensions";
    cin>>d;
    ToeplitzMatrix dm(d);
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