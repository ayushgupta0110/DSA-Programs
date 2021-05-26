#include<iostream>
#include<cstring>
using namespace std;

void perm(char s[],int k){

    static int A[10]={10};
    static char res[10];
    if(s[k]=='\0'){
        res[k]='\0';
        cout<<res<<endl;
    } else{
        for(int i=0;s[i]!='\0';i++){
            if(A[i]==0)
            {
                res[k]=s[i];
                A[i]=1;
                perm(s,k+1);
                A[i]=0;
            }
        }
    }
}

void permR(char s[],int l,int h){
    int i;
    if(l==h){
        cout<<s<<endl;
    } else{
        for(int i=l;i<=h;i++){
            swap(s[l],s[i]);
            permR(s,l+1,h);
            swap(s[l],s[i]);
        }
    }
}

int main(){
    char str[10];
    int len=0;
    cout<<"\n Enter the string: ";
    cin>>str;
    len=strlen(str);
    cout<<"\n\n Permutation of the string entered is: ";
    perm(str,0);
    cout<<"\n\n Permutation of the string entered is: ";
    permR(str,0,len-1);
}