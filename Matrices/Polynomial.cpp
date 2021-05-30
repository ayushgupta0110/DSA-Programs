/*This Program is used to Represent, Evaluate and Add two Polynomials
*/
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

class Term{
    public: int coeff;
            int exp;
};

class Poly{
    int n;
    Term *t;
    public: 
        void create(){
        
            cout<<"\nEnter the number of terms: ";
            cin>>this->n;
            this->t = new Term[this->n];
            cout<<"\nEnter the Polynomial term: ";
            for(int i=0; i<this->n;i++){
                cout<<"\nEnter "<<i+1<<" term: ";
                cin>>this->t[i].coeff;
                cin>>this->t[i].exp;
            }
        }

        void display(){
            cout<<"\nThe Polynomial enetered is: "<<endl;
            for(int i=0; i<this->n; i++){
                if(i==n-1){
                    cout<<this->t[i].coeff<<"x^"<<this->t[i].exp;
                }else{
                    cout<<this->t[i].coeff<<"x^"<<this->t[i].exp<<" +";
                }
            }
        }

        void evaluate(){
            int x,sum=0;
            cout<<"\nEnter the value of x: "<<endl;
            cin>>x;
            for(int i=0; i<this->n; i++){
                sum+=((this->t[i].coeff)*pow(x,this->t[i].exp));
            }
            cout<<"\nThe Value of the Polynomial is: "<<sum<<endl;
        }

        Poly* operator +(Poly const &p2){
            int i=0,j=0,k=0;
            Poly *sum = new Poly;
            sum->t =new Term[this->n+p2.n];
            
            while(i<this->n && j<p2.n)
            {
                if(this->t[i].exp>p2.t[j].exp)
                    sum->t[k++]=this->t[i++];
                else if(this->t[i].exp < p2.t[j].exp)
                    sum->t[k++]=p2.t[j++];
                else{
                    sum->t[k].exp=this->t[i].exp;
                    sum->t[k++].coeff=this->t[i++].coeff+p2.t[j++].coeff;
                }
            }
            for(;i<this->n;i++)sum->t[k++]=this->t[i];
            for(;j<p2.n;j++)sum->t[k++]=p2.t[j];
            sum->n=k;
            return sum;
            }    
};


int main()
{
    Poly p1,p2,*p3;
    p1.create();
    p2.create();
    cout<<endl;
    p1.display();
    cout<<endl;
    p2.display();
    cout<<endl;
    p3=p1+p2;
    cout<<"The Sum of the two Polynomials entered is: "<<endl;
    p3->display();
    cout<<endl;
    p3->evaluate();
    return 0;
}