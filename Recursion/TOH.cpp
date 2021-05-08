#include <iostream>
using namespace std;

//  TOH = Tower of Hanoi problem

void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        cout << "(" << A << "," << C << ")" << endl;
        TOH(n - 1, B, A, C);
    }
}

int main(){
    int x;
    cout<<"\nEnter the number of disc in the Tower of Hanoi problem: ";
    cin>>x;
    TOH(x,1,2,3);
    return 0;
}