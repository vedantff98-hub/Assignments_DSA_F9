#include <iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number to check if it is prime or not :";
    cin>>n;
    int chck=0;
    int m=sqrt(n);
    for(int i=2;i<=m;i++){
        if(n%i==0){
            cout<<"Number is not prime"<<endl;
            chck=1;
            break;
        }
    }
    if(chck!=1){
        cout<<"Number is prime"<<endl;
    }
    return 0;
}