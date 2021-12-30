#include <iostream>
using namespace std;

template<class T>
class UpperDiagonal
{
    private:
        T *A;
        int n;
    public:
        UpperDiagonal(){
            n=2;
            A=new T[2];
        }
        UpperDiagonal(int n){
            this->n=n;
            A=new T[(n*(n+1)/2)];
        }
        ~UpperDiagonal(){
            delete []A;
        }
    void Set(int i,int j,T x);
    T Get(int i,int j);
    void Display();
    int GetDimension(){return n;}
};

/*Set Method using Row-major formula
    
    Row major:  Index(A[i][j]) = A[ (n*(i-1) - ((i-2)*(i-1)/2)) + (j-i) ]
    Column major: Index(A[i][j]) = A[(j*(j-1)/2) + i-1]
*/
template<class T>
void UpperDiagonal<T>::Set(int i,int j,T x){
    if(i<=j)
        A[ (n*(i-1) - ((i-2)*(i-1)/2)) + (j-i) ]=x;
}

template<class T>
T UpperDiagonal<T>::Get(int i,int j){
    if(i<=j)
    return A[ (n*(i-1) - ((i-2)*(i-1)/2)) + (j-i) ];
    return 0;
}

template<class T>
void UpperDiagonal<T>::Display(){
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
    cout<<"Enter Dimensions: ";
    cin>>d;
    UpperDiagonal<int> dm(d);
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