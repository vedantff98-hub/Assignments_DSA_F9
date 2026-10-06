//Arithmetic Calculator without passing object

#include<iostream>
using namespace std;
class cal{
    private:
    float a,b;
    char action;
    public:
    void getchoice(){
        cout<<"Welcome to Simple Calculator"<<endl;
        cout<<"Enter first number :";
        cin>>a;
        cout<<"Enter second number :";
        cin>>b;
        cout<<"Enter '+' for addition"<<endl;
        cout<<"Enter '-' for substraction"<<endl;
        cout<<"Enter '/' for division"<<endl;
        cout<<"Enter '*' for multiplication"<<endl;
        cout<<"Enter your choice :";
        cin>>action;
    }
    void Switches(){
        switch(action){
        case '+':cout<<"The result is :"<<add()<<endl;break;
        case '-':cout<<"The result is :"<<sub()<<endl;break;
        case '/':cout<<"The result is :"<<div()<<endl;break;
        case '*':cout<<"The result is :"<<multi()<<endl;break;
        default:cout<<"User entered wrong input"<<endl;
        }
    }
    float add(){
        return a+b;
    }
    float sub(){
        return a-b;
    }
    float div(){
        return a/b;
    }
    float multi(){
        return a*b;
    }
    void another(){
        cout<<"Do user want to do another calculation ?"<<endl;
        cout<<"Enter 'n' for No"<<endl;
        cout<<"Enter 'y' for Yes"<<endl;
        cin>>action;
        if(action=='y'){
            overall();
        }
    }
    void overall(){
        getchoice();
        Switches();
        another();
    }
};
int main(){
    cal c1;
    c1.overall();
    return 0;
}