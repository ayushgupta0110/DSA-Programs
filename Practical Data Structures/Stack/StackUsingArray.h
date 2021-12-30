#include <iostream>
using namespace std;
#define MAX_SIZE 10

template <class T>
class stack{
    int tos;
    T *array;

public:
        stack(){
            tos = -1;
            array = new int[MAX_SIZE];
        }
        ~stack(){
            delete[] array;
        }

        void push(T x){
            if(tos == MAX_SIZE - 1){
                cout << "Stack Overflow" << endl;
                return;
            }
            tos++;
            array[tos] = x;
        }

        int pop(){
            if(tos == -1){
                cout << "Stack Underflow" << endl;
                return 0;
            }
            T temp = array[tos];
            tos--;
            return temp;
        }

        int peek(){
            if(tos == -1){
                cout << "Stack Underflow" << endl;
                return 0;
            }
            return array[tos];
        }

        bool isEmpty(){
            return tos == -1;
        }

        bool isFull(){
            return tos == MAX_SIZE - 1;
        }
        
        void display(){
            for(int i = 0; i <= tos; i++){
                cout << array[i] << " ";
            }
            cout << endl;
        }
};
