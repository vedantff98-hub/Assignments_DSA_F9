//program to write table of any number
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number to calculate table:";
    cin>>n;
    if(1<n<100){
        for(int i=1;i<=10;i++){
            cout<<n<<"*"<<i<<"="<<n*i<<endl;
        }
    }
    else{
        cout<<"User entered wrong input";
        main();
    }   
    return 0;
}
