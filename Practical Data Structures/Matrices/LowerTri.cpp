#include <iostream>
using namespace std;

template <class T>
class LowerDiagonal
{
    private:
        T *A;
        int n;
    public:
        LowerDiagonal(){
            n=2;
            A=new T[2];
        }
        LowerDiagonal(int n){
            this->n=n;
            A=new T[(n*(n+1)/2)];
        }
        ~LowerDiagonal(){
            delete []A;
        }
    void Set(int i,int j,T x);
    T Get(int i,int j);
    void Display();
    int GetDimension(){return n;}
};

/*Set Method using Row-major formula
    
    Row major:  Index(A[i][j]) = A[ (i*(i-1)/2) + j-1 ]
    Column major: Index(A[i][j]) = A[(n*(j-1) - ((j-2)(j-1)/2)) + (i-j)]
*/
template <class T>
void LowerDiagonal<T>::Set(int i,int j,T x){
    if(i>=j)
        A[(i*(i-1)/2)+j-1]=x;
}

template <class T>
T LowerDiagonal<T>::Get(int i,int j){
    if(i>=j)
    return A[(i*(i-1)/2)+j-1];
    return 0;
}

template <class T>
void LowerDiagonal<T>::Display(){
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
    cout<<"Enter Dimensions: ";
    cin>>d;
    LowerDiagonal<int> dm(d);
    int x;
    cout<<"Enter All Elements: "<<endl;
    for(int i=1;i<=d;i++){
        for(int j=1;j<=d;j++){
            cin>>x;
            dm.Set(i,j,x);
        }
    }
    dm.Display();
    return 0;
}