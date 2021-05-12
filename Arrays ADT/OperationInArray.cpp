#include <iostream>
using namespace std;

class Array
{
public:
    int arr[10];
    int size;
    int len;
};

void display(Array *A)
{
    for (int i = 0; i < A->len; i++)
        cout << A->arr[i] << " ";
}

void append(Array *A, int x)
{
    if (A->len < A->size)
    {
        A->arr[A->len] = x;
        A->len++;
    }
}

void Insert(Array *A, int x, int index)
{
    if (index >= 0 && index <= A->len)
    {
        for (int i = A->len; i > index; i--)
            A->arr[i] = A->arr[i - 1];
        A->arr[index] = x;
        A->len++;
    }
}

void Delete(Array *A, int index)
{
    if (index >= 0 && index < A->len)
    {
        int x = A->arr[index];
        for (int i = index; i < A->len - 1; i++)
            A->arr[i] = A->arr[i + 1];
        A->len--;
    }
}

//     MORE OPERATIONS IN ARRAY
int Get(Array A, int index)
{
    if (index >= 0 && index < A.len)
        return A.arr[index];
    return -1;
}

void Set(Array *A, int index, int x)
{
    if (index >= 0 && index < A->len)
        A->arr[index] = x;
}

int Max(Array A)
{
    int max = A.arr[0];
    for (int i = 1; i < A.len; i++)
    {
        if (A.arr[i] > max)
            max = A.arr[i];
    }
    return max;
}
int Min(Array A)
{
    int min = A.arr[0];
    for (int i = 1; i < A.len; i++)
    {
        if (A.arr[i] < min)
            min = A.arr[i];
    }
    return min;
}

int Sum(Array A)
{
    int sum = 0;
    for (int i = 0; i < A.len; i++)
        sum += A.arr[i];
    return sum;
}

float Avg(Array A)
{
    return (float)Sum(A) / A.len;
}

int main()
{
    int x, indx;
    Array A = {{2, 3, 4, 5, 6}, 10, 5};
    display(&A);
    cout << "\nEnter element to Append: ";
    cin >> x;
    append(&A, x);
    cout << "\nThe updated Array is: ";
    display(&A);
    cout << "\nEnter element to insert at an index(element,index): ";
    cin >> x >> indx;
    Insert(&A, x, indx);
    cout << "\nThe updated Array is: ";
    display(&A);
    cout << "\nEnter the index from which you want to delete the element: ";
    cin >> indx;
    Delete(&A, indx);
    cout << "\nThe updated Array is: ";
    display(&A);
    return 0;
}