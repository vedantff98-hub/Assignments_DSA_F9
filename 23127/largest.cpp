//largest number of array
#include<iostream>
using namespace std;

class Max{
    private:
    int position;
    // int list[n];
    int largest;
    public:
    void putdata(int list[],int n){
        for(int i=0;i<n;i++){
            cout<<"Enter the "<<i+1<<"th number of array element:";
            cin>>list[i];
        }
    }
    void getdata(int list[],int n){
        for(int i=0;i<n;i++){
            cout<<list[i]<<endl;
        }
    }
    int getmax(int list[],int n){
        largest=list[0];
        for(int j=0;j<n;j++){
            if(largest<list[j]){
                largest=list[j];
                position=j+1;
            }
        }
        return largest;
    }
    void showneeded(int list[],int n){
        char choice;
        cout<<"do user want to see array?"<<endl;
        cout<<"Enter 'y' for yes and 'n' for no"<<endl;
        cin>>choice;
        switch(choice){
            case 'y':getdata(list,n);
            case 'n':return ;
            default:
            cout<<"User entered wrong input";
            showneeded(list,n);
        }
    }
    int showposition(){
        return position;
    }
    
};
int main(){
    Max m1;
    int n;
    cout<<"Enter the size of array (postive number):";
    cin>>n;
    int list[n];
    m1.putdata(list,n);
    cout<<"Largest number in array is:"<<m1.getmax(list,n)<<endl;
    cout<<"Position at which number is maximum is:"<<m1.showposition()<<endl;
    m1.showneeded(list,n);
    return 0;
}