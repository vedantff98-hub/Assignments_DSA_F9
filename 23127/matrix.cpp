#include<iostream>
using namespace std;

class matrix{
    public:
    void getarray(int arr[][2],int n){
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cout<<"Enter the number in matrix at"<<"("<<j+1<<")"<<"("<<i+1<<") :";
                cin>>arr[j][i];
            }
            
        }
    }
    void add(int arr[][2],int arr1[][2],int n){
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=arr[i][j]+arr1[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    matrix m1;
    int n;
    cout<<"Enter columns in array(rows are fixed to 2 rows) :";
    cin>>n;
    int arr1[n][2];
    int arr2[n][2];
    cout<<"Enter numbers for first matrix"<<endl;
    m1.getarray(arr1,n);
    cout<<"Enter numbers for second matrix"<<endl;
    m1.getarray(arr2,n);
    cout<<"After addition result is:"<<endl;
    m1.add(arr1,arr2,n);
    return 0; 
}