/* 
Examination Roll no: 20067570010
Roll No: 20512
Set No: 2

Question 1:
Given a list of N elements, which is sorted in ascending order, you are required to search an element x
in the list. The list is stored using array data structure. If the search is successful, the output should be
the index at which the element occurs, otherwise returns -1 to indicate that the element is not present
in the list. Assume that the elements of the list are all distinct. Write a program to perform the desired
task.*/

#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 100

int main()
{
    int N;
    cout<<"\nProgram to search an element in a list sorted in ascending order!!\n";
    cout<<"\nEnter the number of elements in your list:";
    cin>>N;
    cout<<"\nNow enter the elements:\n";
    int arr[maxn]={0};
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }

    /*Logic to sort the list if the list is not sorted!*/
    sort(arr,arr+N);
    cout<<"Sorted List: "<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<" ";
    }
    bool flag=true;
    while(flag)
    {
        int ele,cc=0;
        cout<<"\nEnter the element to be searched :";
        cin>>ele;
        int low=0;
        int high=N-1;
        int res=-1;

        //Logic to search the element in the list : Binary Search Implementation
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==ele)
            {
                res=mid;
                break;
            }
            else if(arr[mid]<ele)
            {
                low=mid+1;
            }
            else
                high=mid-1;
        }
        if(res==-1)
            cout<<res<<endl;
        else
            cout<<"Element found at position : "<<res+1<<endl;
            cout<<"\nPress 0 to stop the search; 1 to continue searching : "<<endl;
            cin>>cc;
        if(cc==1) continue;
        else break;
    }
    return 0;
}