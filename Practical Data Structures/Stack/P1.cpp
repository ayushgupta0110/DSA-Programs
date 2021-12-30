#include <iostream>
using namespace std;
#include "StackUsingArray.h"
#define MAX_SIZE 10


stack<int> addTwoNumbers(){
    stack<int> s1,s2,res;
    int num1,n=0,i=0;

    cout<<"\nEnter the number of digits in num1: "<<endl;
    cin>>n;
    while(!s1.isFull() && i<n){
        cin>>num;
        s1.push(num);
        i++;
    }

    cout<<"\nEnter the number of digits in num2: "<<endl;
    cin>>n;
    i=0;
    while(!s2.isFull() && i<n){
        cin>>num;
        s2.push(num);
        i++;
    }

    int carry=0;
    while(!s1.isEmpty() && !s2.isEmpty()){
        num = s1.pop() + s2.pop() + carry;
        res.push(num%10);
        carry = num/10;
    }

    // loops to handle the remaining digits in the stack s1 and s2
    while(!s1.isEmpty()){
        num = s1.pop() + carry;
        res.push(num%10);
        carry = num/10;
    }
    while(!s2.isEmpty()){
        num = s2.pop() + carry;
        res.push(num%10);
        carry = num/10;
    }

    //condition to handle the carry
    if(carry!=0)
        res.push(carry);

    return res;
}
int main(){
    stack<int> res;

    res = addTwoNumbers();    
    cout<<"\nThe sum of the 2 numbers entered is: ";
    while(!res.isEmpty()){
        cout<<res.pop();
    }
    cout<<endl;
    return 0;
}