#include<iostream>
using namespace std;

class complex{
    private:
    int real;
    int imag;
    public:
    complex(int real,int imag){
        this->real=real;
        this->imag=imag;
    }
    void getnums(){
        cout<<"Enter real part :";
        cin>>real;
        cout<<"Enter imag part :";
        cin>>imag;
    }
    void add(complex &c1){
        this->real=this->real+c1.real;
        this->imag=this->imag=c1.imag;
    }
    void subtract(complex &c1){
    }
};
int main(){
    int real,imag;
    cout<<"Enter data for first number"<<endl;
    cout<<"Enter real part of number:";
    cin>>real;
    cout<<"Enter imag part of number:";
    cin>>imag;
    complex c1(real,imag);
    cout<<"Enter data for second number"<<endl;
    cout<<"Enter real part of number:";
    cin>>real;
    cout<<"Enter imag part of number:";
    cin>>imag;
    complex c2(real,imag);
    complex c3=c1+c2;
    c3.shownum();
    c3=c1-c2;
    c3.shownum();
}