#include<iostream>
using namespace std;

class Array{
    public: int arr[10];
            int size;
            int len;
};

void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int LSearch(Array A,int key){
    for(int i=0;i<A.len;i++){
        if(A.arr[i]==key)
            return i;
    }
    return -1;
}

/*Improving performance of Linear Search by:
        1. Transposition
        2. Move to Front/Head
*/
int L1Search(Array A,int key){
    for(int i=0;i<A.len;i++){
        if(A.arr[i]==key){
            swap(A.arr[i],A.arr[i-1]);
            return i;
        }
    }
    return -1;
}

int L2Search(Array A,int key){
    for(int i=0;i<A.len;i++){
        if(A.arr[i]==key){
            swap(A.arr[i],A.arr[0]);
            return i;
        }
    }
    return -1;
}

int main(){
    Array A={{2,3,4,5,6},10,5};


    return 0;
}