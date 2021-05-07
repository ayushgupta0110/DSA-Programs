#include<iostream>
using namespace std;

int power(int m, int n)
{
    if (n == 0)
        return 1;
    return power(m, n-1)*m;
}
int power1(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power1(m * m, n/2);
    else    
        return m * power1(m * m, (n - 1) / 2);
}
int main()
{
    int x,y;
    cout<<"\n Enter x and y: ";
    cin>>x>>y;
    cout<<"\n1. Pow("<<x<<","<<y<<") using Recursion: "<<power(x,y)<<endl; 
    cout<<"\n1. Pow("<<x<<","<<y<<") using efficient method: "<<power(x,y)<<endl; 
    return 0;
}