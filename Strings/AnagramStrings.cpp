#include<iostream>
using namespace std;

bool isAnagram(char *A,char *B){
    int i,H[26]={0};

    for(i=0;A[i]!='\0';i++){
        H[A[i]-97]+=1;
    }

    for(i=0;B[i]!='\0';i++){
        H[B[i]-97]-=1;
        if(H[B[i]-97]<0){
            return false;
        }
    }
    if(B[i]=='\0'){
        return true;
    }    
}



int main(){
    char str1[10],str2[10];
    bool Anagram;
    cout<<"\n Program to check whether a string is Anagram or not!!!"<<endl;
    cout<<"\nEnter String 1: ";
    cin>>str1;    
    cout<<"\nEnter String 2: ";
    cin>>str2;
    Anagram = isAnagram(str1,str2);
    if(Anagram)
        cout<<"\nEntered Strings"<<str1<<" and "<<str2<<" are Anagram.";
    else
        cout<<"\nEntered Strings"<<str1<<" and "<<str2<<" are not Anagram.";
    return 0;
}