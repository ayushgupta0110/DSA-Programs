#include<iostream>
#include"Stack.h"
#include<cstring>
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

char* convert(char *infix){
    int sz = strlen(infix);
    Stack<char> stk(sz+1);
    char *postfix=new char[sz+1];
    int i=0,j=0;

    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(pre(infix[i])>pre(stk.stackTop())) stk.push(infix[i++]);
            else
                postfix[j++]=stk.pop();
        }
    }
    while(!stk.isEmpty()){
        postfix[j++]=stk.pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char *infix="a+b*c-d/e";

    cout<<"\nThe infix expression is: "<<infix;
    cout<<"\nThe postfix expression is: "<<convert(infix);
    return 0;
}