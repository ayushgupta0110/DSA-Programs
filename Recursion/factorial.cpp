#include<iostream>
using namespace std;

int fact(int n){
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

int Ifact(int n){
    int res = 1;
    for (int i = 1; i <= n; i++)
        res*=i;
    return res;
}

int main()
{
    int x;
    cout<<"\nEnter x: ";
    cin>>x;
    cout<<"\n Factorial using recursion: "<<fact(x)<<endl;
    cout<<"\n Factorial using Iteration: "<<Ifact(x)<<endl;
    return 0;
}