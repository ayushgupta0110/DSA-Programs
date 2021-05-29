/* Since in Symmetric Matrix M[i][j] = M[j][i]
    then there is no need to store all the elements since (i,j) elements == (j,i)
    Thus,
        Symmetric Matrix can be implemented using either LowerDiagonal Matrix approach 
        or UpperDiagonal Matrix approach.
*/

#include <iostream>
using namespace std;

class SymmetricMatrix
{
    private:
        int *A;
        int n;
    public:
        SymmetricMatrix(){
            n=2;
            A=new int[2];
        }
        SymmetricMatrix(int n){
            this->n=n;
            A=new int[(n*(n+1)/2)];
        }
        ~SymmetricMatrix(){
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
void SymmetricMatrix::Set(int i,int j,int x){
    if(i>=j)
        A[(i*(i-1)/2)+j-1]=x;
}


int SymmetricMatrix::Get(int i,int j){
    if(i>=j)
    return A[(i*(i-1)/2)+j-1];
    return 0;
}
void SymmetricMatrix::Display(){
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
    SymmetricMatrix dm(d);
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