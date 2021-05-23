#include<iostream>
using namespace std;

void SumPair(int *arr,int sz){
    int k=0;
    cout<<"\nEnter k(sum): ";
    cin>>k;

    for(int i=0;i<sz;i++){
        for(int j=i+1;j<sz;j++){
            if(arr[i]+arr[j]==k)
                    cout<<"("<<arr[i]<<","<<arr[j]<<")"<<"  ";
        }
    }
    delete[] arr;
}

    
void SumPair2(int *arr,int sz){
    int k,i=0;
    int j=sz-1;

    cout<<"\nEnter k(sum): ";
    cin>>k;

    while(i<j){
        if(arr[i]+arr[j]==k){
            cout<<"("<<arr[i]<<","<<arr[j]<<")"<<"  ";
            i++;
            j--;
        }
        else if(arr[i]+arr[j]<k) i++;
        else j--;
    }
    delete[] arr;
}

int main(){
    int sz;
    cout<<"\nEnter size of the array: ";
    cin>>sz;
    int *arr = new int[sz];
    cout<<"\nEnter the array(sorted): ";
    for(int i=0;i<sz;i++){
        cin>>arr[i];
    }
    cout<<"\n The Pair of element/s with sum k is/are: ";
    SumPair(arr,sz);

    cout<<"\n The Pair of element/s with sum k is/are: ";
    SumPair2(arr,sz);

    delete []arr;
    return 0;
}