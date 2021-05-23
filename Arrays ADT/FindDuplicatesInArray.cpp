#include<iostream>
using namespace std;

//  Function to display duplicate(sorted array) TC= O(n)
void duplicate1(int *arr,int sz){
    int lastdup=0;
    for(int i=0;i<sz-1;i++){
        
        if(arr[i]==arr[i+1] && arr[i]!=lastdup){
            cout<<arr[i]<<"  ";
            lastdup=arr[i];
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

// Function to dsiplay duplicates in an array using hashing(sorted/unsorted)
void duplicate_Hash(int *arr,int sz){
    int max = Max(arr,sz);
    int *H =new int[max];

    for(int i=0;i<sz;i++){
        H[arr[i]]++;
    }
    for(int i=0;i<=max;i++){
        if(H[i]>1)
          cout<<i<<" is appearing for "<<H[i]<<" times."<<endl;
    }
    delete[] H,arr;
}

// Function to display duplicates in an unsorted array  T.C. = O(n^2)
void duplicate_unsorted(int *arr,int sz){
    int count;
    for(int i=0;i<sz;i++){
        count=1;
        if(arr[i]!=-1){
            for(int j=i+1;j<sz;j++){
                if(arr[j]==arr[i]){
                    count++;
                    arr[j]=-1;
                }
            }
            if(count>1) cout<<arr[i]<<" appears "<<count<<" times."<<endl;
        }
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
    cout<<"\n The missing element/s in the sorted array is/are: ";
    duplicate1(arr,sz);

    
    cout<<"\n\nEnter size of the array: ";
    cin>>sz;
    cout<<"\nEnter the array(sorted/unsorted): ";
    for(int i=0;i<sz;i++){
        cin>>arr[i];
    }
    cout<<"\n The duplicate element/s in the sorted array is/are (Using Hashing Technique): ";
    duplicate_Hash(arr,sz);
    
    cout<<"\n\nEnter size of the array: ";
    cin>>sz;
    cout<<"\nEnter the array(sorted/unsorted): ";
    for(int i=0;i<sz;i++){
        cin>>arr[i];
    }
    cout<<"\n The duplicate element/s in the unsorted array is/are: ";
    duplicate_unsorted(arr,sz);
    delete []arr;
    return 0;
}