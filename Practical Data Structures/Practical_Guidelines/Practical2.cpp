/*
PRACTICAL NO: 2
Title:
Given a list of N elements, which is sorted in ascending order, you are required to search an element x
in the list. The list is stored using array data structure. If the search is successful, the output should be
the index at which the element occurs, otherwise returns -1 to indicate that the element is not present
in the list. Assume that the elements of the list are all distinct. Write a program to perform the desired
task.
*/

#include<iostream>
using namespace std;

void binary_search()
{
	char ch;
	int n,data; 
	cout<<"\n Enter the size of the array: ";
	cin>>n;
	int arr[n];
	cout<<"\n Enter the elements in the array...(in ascending order): ";
	for(int i=0;i<n;i++)
	    cin>>arr[i];
//Binary Search
    do{
    cout<<"\n Enter the element you want to search in the array: ";
	cin>>data;
	int lb=0,ub=n-1,mid,count=0,found=0;
	while((lb<=ub) && !(found))
	{
		count++;
		mid=(lb+ub)/2;
		if(data>arr[mid])
		    lb=mid+1;
		else if(data<arr[mid])
		    ub=mid-1;
	    else
		    found++; 
	}
    if(found==0)
       cout<<"\n The entered element is not present in the array.";
    else
	   cout<<"\n The entered element "<<data<<" is present at index  "<<mid;   	
	cout<<"\n Number of Comparisons required: "<<count;   
	cout<<"\n\n To continue Press Y or y,any other key to go back: ";
	cin>>ch;
	}while(ch=='y'||ch=='Y');
}

void Linear_usearch()
{
	char ch;
	int i,n,z; 
	cout<<"\n Enter the size of the array: ";
	cin>>n;
	int arr[n];
	cout<<"\n Enter the elements in the array: ";
	for(i=0;i<n;i++)
	    cin>>arr[i];
//Searching
    do{
    cout<<"\n Enter the element you want to search in the array: ";
	cin>>z;
	int count=0,found=0;
	for(i=0;i<n;i++)
	{   count++;
		if(arr[i]==z){
		     found++;
		     break;
			}	    
    }
    if(found==0)
       cout<<"\n The entered element is not present in the array.";
    else
	   cout<<"\n The entered element "<<z<<" is present at index  "<<i; 
	cout<<"\n Number of Comparisons required: "<<count;     
	cout<<"\n\n To continue Press Y or y,any other key to go back: ";
	cin>>ch;
    }while(ch=='y'||ch=='Y');
}

void Linear_osearch()
{
	char ch;
	int i,n,z; 
	cout<<"\n Enter the size of the array: ";
	cin>>n;
	int arr[n];
	cout<<"\n Enter the elements in the array...(in ascending order): ";
	for(i=0;i<n;i++)
	    cin>>arr[i];
//Searching
    do{
    cout<<"\n Enter the element you want to search in the array: ";
	cin>>z;
	int count=0,found=0;
	for(i=0;i<n;i++)
	{
		count++;
		if(arr[i]==z){
		     found++;
		     break;
			}
		else if(arr[i]>z)
		      break;		    
    }
    if(found==0)
       cout<<"\n The entered element is not present in the array.";
    else
	   cout<<"\n The entered element "<<z<<" is present at index  "<<i;    
	cout<<"\n Number of Comparisons required: "<<count;
	cout<<"\n\n To continue Press Y or y,any other key to go back: ";
	cin>>ch;
    }while(ch=='y'||ch=='Y');
} 
 
int main()
{    
     int choice;
     char ch;
	cout<<"\n\tThis is the Program to implement Searching in an Array!!!";
	do{
	cout<<"\n\n\t\t\tMENU";
	cout<<"\n  1. Linear Search in an Unordered Array!!";
	cout<<"\n  2. Linear Search in an Ordered Array!!";
	cout<<"\n  3. Binary Search!!";
	cout<<"\n  Enter Your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:   Linear_usearch();
		          break;
		case 2:   Linear_osearch();
				  break;
		case 3:   binary_search();
		 		  break;
		default:  cout<<"\nYou didn't choose a valid option... ";
	}
	cout<<"\n\n To continue Press 'y' or 'Y',Any other key to exit... ";
	cin>>ch;
    }while(ch=='y'||ch=='Y');
} 