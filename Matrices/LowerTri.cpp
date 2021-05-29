#include <iostream>
using namespace std;

class LowerDiagonal
{
    private:
        int *A;
        int n;
    public:
        LowerDiagonal(){
            n=2;
            A=new int[2];
        }
        LowerDiagonal(int n){
            this->n=n;
            A=new int[(n*(n+1)/2)];
        }
        ~LowerDiagonal(){
            delete []A;
        }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    int GetDimension(){return n;}
};

/*Set Method using Row-major formula
    
    Row major:  Index(A[i][j]) = A[ (i*(i-1)/2) + j-1 ]
    Column major: Index(A[i][j]) = A[(n*(j-1) - ((j-2)(j-1)/2)) + (i-j)]
*/
void LowerDiagonal::Set(int i,int j,int x){
    if(i>=j)
        A[(i*(i-1)/2)+j-1]=x;
}


int LowerDiagonal::Get(int i,int j){
    if(i>=j)
    return A[(i*(i-1)/2)+j-1];
    return 0;
}
void LowerDiagonal::Display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j)
            cout<<A[(i*(i-1)/2)+j-1]<<" ";
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
    LowerDiagonal dm(d);
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