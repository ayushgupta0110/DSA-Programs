#include<iostream>
using namespace std;

//Taylor Series using recursion and Static variable
double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return 1;
    r = e(x, n - 1);
    p = p * x;
    f = f * n;
    return (r + p / f);
}

//Taylor Series using Horner's Rule
double eH(int x, int n)
{
    static double s;
    if (n == 0)
        return s;
    s = 1 + x * s / n;
    return eH(x, n - 1);
}

//Taylor Series using Iteration
double eI(int x, int n)
{
    double s = 1;
    int i;
    double num = 1;
    double den = 1;
    for (i = 1; i <= n; i++)
    {
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}

int main(){
    int x,n;
    cout<<"\n Enter x and n: ";
    cin>>x>>n;
    cout<<"\n1. Result of Taylor series using Recursion: "<<e(x,n);
    cout<<"\n2. Result of Taylor series using Horner's Rule: "<<eH(x,n);
    cout<<"\n3. Result of Taylor series using Iteration: "<<eI(x,n);
    return 0;
}