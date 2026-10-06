#include<iostream>
using namespace std;
class result{
    private:
    int n;
    public:
    void getvalue(){
        cout<<"Enter the number to check :";
        cin>>n;
    }
    void check(){
        if(n%2==0){
            cout<<"The number is even"<<endl;
        }
        else{
            cout<<"The number is odd"<<endl;
        }
    }
};

int main(){
    result s1;
    s1.getvalue();
    s1.check();
    return 0;
}