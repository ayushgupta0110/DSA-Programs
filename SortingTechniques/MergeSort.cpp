#include<iostream>
using namespace std;

void Merge(int A[],int l,int mid,int h){
    int i=l,j=mid+1,k=l;
    int B[100];
    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
        B[k++]=A[i++];
        else
        B[k++]=A[j++];
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];
    for(i=l;i<=h;i++)
        A[i]=B[i];
}

//Recursive algorithm for Merge Sort
void MergeSort(int A[],int l,int h){
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

//Iterative Merge Sort
void IMergeSort(int A[],int n){
    int p,l,h,mid,i;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<=n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<n)
    Merge(A,0,p/2-1,n);
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
    MergeSort(A,0,n-1);
    for(i=0;i<10;i++)
    cout<<A[i]<<" ";
    cout<<"\n";
    return 0;
}