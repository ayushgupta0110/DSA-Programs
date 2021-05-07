#include<iostream>
using namespace std;

int sum(int n){
    if (n == 0)
        return 0;
    return sum(n - 1) + n;
}

int Isum(int n){
    int res = 0;
    for (int i = 1; i <= n; i++)
        res+=i;
    return res;
}

int Fsum(int n){
    return (n*(n+1))/2;
}

int main()
{
    int x;
    cout<<"\nEnter x: ";
    cin>>x;
    cout<<"\n Sum of First n Natural nos. using recursion: "<<sum(x)<<endl;
    cout<<"\n Sum of First n Natural nos. using Iteration: "<<Isum(x)<<endl;
    cout<<"\n Sum of First n Natural nos. using Formula: "<<Fsum(x)<<endl;
    return 0;
}