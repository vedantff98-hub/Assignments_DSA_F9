#include<iostream>
using namespace std;
class student{
    private:
    int rollno;
    string name;
    char div;
    int mark;
    string grade;
    int s1,s2,s3,s4,s5;
    public:
    void setinfo(){
        cout<<"Enter the Name of student :";
        cin>>name;
        cout<<"Enter the Roll No. of student :";
        cin>>rollno;
        cout<<"Enter the Divison of student :";
        cin>>div;
    }
    void setmarks(){
        cout<<"Enter the marks for S1 :";
        cin>>s1;
        cout<<"Enter the marks for S2 :";
        cin>>s2;
        cout<<"Enter the marks for S3 :";
        cin>>s3;
        cout<<"Enter the marks for S4 :";
        cin>>s4;
        cout<<"Enter the marks for S5 :";
        cin>>s5;
        mark=s1+s2+s3+s4+s5;
    }
    void setgrade(){
        if(mark>75){
            grade="O";
        }
        else if(mark>60){
            grade="A+";
        }
        else if(mark>60){
            grade="A";
        }
        else if(mark>50){
            grade="B";
        }
        else if(mark>40){
            grade="C";
        }
        else{
            grade="Fail";
        }
    }
    void getinfo(){
        cout<<"Name of student is :"<<name<<endl;
        cout<<"Roll No. of student is :"<<rollno<<endl;
        cout<<"Divison of student is :"<<div<<endl;
        cout<<"Marks of student is :"<<mark<<endl;
        cout<<"Grade of student is :"<<grade<<endl;
    }
};
int main(){
    student s1;
    s1.setinfo();
    s1.setmarks();
    s1.setgrade();
    s1.getinfo();

    return 0;
}