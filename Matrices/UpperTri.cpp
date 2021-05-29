#include <iostream>
using namespace std;

class UpperDiagonal
{
    private:
        int *A;
        int n;
    public:
        UpperDiagonal(){
            n=2;
            A=new int[2];
        }
        UpperDiagonal(int n){
            this->n=n;
            A=new int[(n*(n+1)/2)];
        }
        ~UpperDiagonal(){
            delete []A;
        }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    int GetDimension(){return n;}
};

/*Set Method using Row-major formula
    
    Row major:  Index(A[i][j]) = A[ (n*(i-1) - ((i-2)*(i-1)/2)) + (j-i) ]
    Column major: Index(A[i][j]) = A[(j*(j-1)/2) + i-1]
*/
void UpperDiagonal::Set(int i,int j,int x){
    if(i<=j)
        A[ (n*(i-1) - ((i-2)*(i-1)/2)) + (j-i) ]=x;
}


int UpperDiagonal::Get(int i,int j){
    if(i<=j)
    return A[ (n*(i-1) - ((i-2)*(i-1)/2)) + (j-i) ];
    return 0;
}
void UpperDiagonal::Display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i<=j)
            cout<<A[ (n*(i-1) - ((i-2)*(i-1)/2)) + (j-i) ]<<" ";
            else
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
    UpperDiagonal dm(d);
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