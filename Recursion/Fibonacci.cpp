#include <iostream>
using namespace std;

//Fibonacci Series using Iteration
int fib(int n)
{
    int t0 = 0, t1 = 1, res = 0;
    if (n <= 1)
        return n;
    for (int i = 2; i <= n; i++)
    {
        res = t0 + t1;
        t0 = t1;
        t1 = res;
    }
    return res;
}
//Fibonacci Series using recursion
int rfib(int n)
{
    if (n <= 1)
        return n;
    return rfib(n - 2) + rfib(n - 1);
}

//Fibonacci Series using Memoization
int F[10];
int mfib(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
            F[n - 2] = mfib(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = mfib(n - 1);
        F[n] = F[n - 2] + F[n - 1];
        return F[n - 2] + F[n - 1];
    }
}

int main(){
    int x = 0;
    cout<<"\nEnter x: ";
    cin>>x;
    //Initailising all elements of array to -1
    for(int i=0;i<10;i++){
        F[i]=-1;
    }
    cout<<"\n The "<<x<<" term of the Fibonacci series using Iteration is: "<<fib(x);
    cout<<"\n The "<<x<<" term of the Fibonacci series using recursion is: "<<rfib(x);
    cout<<"\n The "<<x<<" term of the Fibonacci series using Memoization is: "<<mfib(x);
}