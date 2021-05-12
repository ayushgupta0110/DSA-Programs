#include<iostream>
using namespace std;

class Array{
    public: int arr[10];
            int size;
            int len;
};

int BinSearch(Array A,int key){

    int l=0,h=A.len-1,mid=0;
    while(l<=h){
        mid=(l+h)/2;
        if(A.arr[mid]==key)
            return mid;
        else if(key<A.arr[mid])
            h=mid-1;
        else
            l=mid+1;       
    }
    return -1;
}

int RBinSearch(Array A,int l,int h,int key){

    int mid=0;
    while(l<=h){
        mid=(l+h)/2;
        if(A.arr[mid]==key)
            return mid;
        else if(key<A.arr[mid])
            return RBinSearch(A,l,mid-1,key);
        else
            return RBinSearch(A,mid+1,h,key);
    }
    return -1;
}

int main(){
    int key;
    Array A={{2,3,4,5,6},10,5};
    cout<<"\nEnter the element you want to search for: "<<endl;
    cin>>key;
    cout<<"\n1. The key is present at index(using Iteration): "<<BinSearch(A,key);
    cout<<"\n2. The key is present at index(using Recursion): "<<RBinSearch(A,0,A.len,key);
    return 0;
}