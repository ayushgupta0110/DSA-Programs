#include<iostream>
using namespace std;

/* This function is used to find duplicates in a string using Simple Searching Technique
*/
void duplicate(char *str){

}

/* This function is used to find duplicates in a string using the Hashing Technique
*/
void duplicate_Hash(char *str){
    int H[26]={-1};
    for(int i=0;str[i]!='\0';i++){
        H[str[i]-97]+=1;
    }
    for(int i=0;i<26;i++){
        if(H[i]>1)
            cout<<(char)(i+97)<<" is appearing "<<H[i]<<" times"<<endl;
    }   
    delete str;
}

/* This function is used to find duplicates in a string using the bitwise operators
    Techniques used-
    1. Bit Masking 
    2. Bit Merging
*/
void duplicate_bit(char *str){
    int H=0,x=0;

    for(int i=0;str[i]!='\0';i++){
        x=1;
        x=x<<(str[i]-97);
        if(x&H>0)
            cout<<str[i]<<" is duplicate"<<endl;
        else
            H|=x; 
    }
    delete str;
}

int main(){
    char *str = "finding";
    cout<<"\n\tFinding Duplicates using Simple searching: "<<endl;
    // duplicate(str);
    cout<<"\n\tFinding Duplicates using Hashing Technique: "<<endl;
    duplicate_Hash(str);
    cout<<"\n\tFinding Duplicates using Bitwise Operations: "<<endl;
    duplicate_bit(str);
}