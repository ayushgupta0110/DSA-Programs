#include<iostream>
using namespace std;

int fact(int n){
    if(n==0)
        return 1;
    else
        return fact(n-1)*n;
}
//nCr using Factorial function
int nCr(int n,int r){
    int num,deno;
    num=fact(n);
    deno=fact(r)*fact(n-r);
    return num/deno;
}

/*nCr using Pascal's algorithm
    nCr = (n-1)C(r-1) + (n-1)C(r)
*/            
int C(int n,int r){
    if(r==0 || n==r)
        return 1;
    else
        return C(n-1,r-1)+C(n-1,r);    
} 

int main(){
    int x,y;
    cout<<"\nEnter n and r: ";
    cin>>x>>y;
    cout<<"\nThe result of "<<x<<"C"<<y<<"using recursion is: "<<nCr(x,y);
    cout<<"\nThe result of "<<x<<"C"<<y<<"using Pascals' formula is: "<<nCr(x,y);
    return 0;
}