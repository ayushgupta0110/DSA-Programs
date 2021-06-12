#include<iostream>
#include"Stack.h"
#include<cstring>
using namespace std;

bool isBalanced(char *exp){
    
    int size=strlen(exp);
    Stack<char> stk(size);

    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(') stk.push(exp[i]);
        else if(exp[i]==')'){
            if(stk.isEmpty()) return false;
            else stk.pop();
        }
    }
    return stk.isEmpty()? true : false;
}

int main(){
    char *exp="((a+b)*(c+d))";

    bool res=isBalanced(exp);
    if(res) cout<<"\nThe Parenthesis are matching!!";
    else cout<<"\nThe Parenthesis are not matching!!";    
    return 0;
}