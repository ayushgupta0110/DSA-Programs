#include<iostream>
using namespace std;

void missing1(int *arr,int sz){
    int diff=arr[0]-0;
    for(int i=0;i<sz;i++){
        if(arr[i]-i!=diff){
            
            while(diff<arr[i]-i){
                cout<<i+diff<<"  ";
                diff++;
            }
        }
    }
    delete[] arr;
}

int Max(int *arr,int len)
{
    int max = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
    delete [] arr;
}
    
void missing2(int *arr,int sz){
    int max = Max(arr,sz);
    int *H =new int[max];

    for(int i=0;i<sz;i++){
        H[arr[i]]++;
    }
    for(int i=0;i<=max;i++){
        if(H[i]==0)
          cout<<i<<"  ";
    }
    delete[] H,arr;
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
    cout<<"\n The missing element/s in the sorted array is/are: ";
    missing1(arr,sz);

    
    cout<<"\n\nEnter size of the array: ";
    cin>>sz;
    cout<<"\nEnter the array(sorted/unsorted): ";
    for(int i=0;i<sz;i++){
        cin>>arr[i];
    }
    cout<<"\n The missing element/s in the sorted array is/are (Using Hashing Technique): ";
    missing2(arr,sz);
    delete []arr;
    return 0;
}