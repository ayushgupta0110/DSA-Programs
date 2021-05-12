#include<iostream>
using namespace std;

class Array{
    public: int arr[10];
            int size;
            int len;
};

void display(Array A){
    for(int i=0;i<A.len;i++)
       cout<<"\n"<<A.arr[i]<<" "<<endl;
}

void append(Array *A,int x){
    if(A->len<A->size){
        A->arr[A->len]=x;
        A->len++;
    }
}

void Insert(Array *A,int x,int index){
    if(index>=0 && index<=A->len){
        for(int i=A->len;i>index;i--)
            A->arr[i]=A->arr[i-1];
        A->arr[index]=x;
        A->len++;    
    }
}

void Delete(Array *A,int index){
    if(index>=0 && index<A->len){
        int x=A->arr[index];
        for(int i=index;i<A->len-1;i++)
            A->arr[i]=A->arr[i+1];
        A->len--;    
    }        
}

int main(){
    Array A={{2,3,4,5,6},10,5};


}