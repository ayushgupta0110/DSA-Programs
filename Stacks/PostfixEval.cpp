#include<iostream>
#include<cstring>
#include"Stack.h"
using namespace std;


bool isOperand(char x){
    if(x=='+' || x=='-' || x=='*'|| x=='/')
        return false;
    return true;    
}

int pre(char x){
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    else
    return 0;        
}

int Evaluate(char *postfix){
    int sz=strlen(postfix);
    Stack<int> stk(sz);

    int i,x1,x2,res=0;
    for(i=0;postfix[i]!='\0';i++){
        if(isOperand(postfix[i]))
            stk.push(postfix[i]-'0');
        else{
            x2=stk.pop();
            x1=stk.pop();
            switch(postfix[i]){
                case '+': res=x1+x2; break;
                case '-': res=x1-x2; break;
                case '*': res=x1*x2; break;
                case '/': res=x1/x2; break;
            }
            stk.push(res);
        }    
    }
    return stk.pop();
}

int main(){
    char *postfix="345*+62/-";    
    
    cout<<"\nThe value of the entered postfix expression is: "<<Evaluate(postfix);
    
    return 0;
}