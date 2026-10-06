/*"Efficient Data Management Using Linked Lists: Implementing Dynamic Operations for
Contact Management System"*/
#include <iostream>
#include <string.h>

using namespace std;
class Node{
    public:
    string name;
    long long number;
    Node *next;
};
class MySLL{
    Node *head;
    public:
    Node *getnode(){
        Node *p=new Node;
        cout<<"Enter the name :";
        cin.ignore();
        getline(cin,p->name);
        cout<<"Enter the number :";
        cin>>p->number;
        p->next=NULL;
        return p;
    }
    //function to create linked list
    void create(int n){
        Node *p,*q;
        for(int i=0;i<n;i++){
            p=getnode();
            //checking if list exist or not
            if(head==NULL){
                head=p;
                q=p;
            }
            else{
                q->next=p;
                q=p;
            }
        }
    }
    //function to display linked list
    void display(){
        Node *p;
        p=head;
        int count=0;
        //checking if list exist or not
        if(head==NULL){
            cout<<"Data not exists to display"<<endl;
        }
        else{
            cout<<"List of numbers is:"<<endl;
            // cout<<"Name \t\t Contact No."<<endl;
            while(p!=NULL){
                count++;
                cout<<count<<"."<<p->name<<":"<<p->number<<endl;
                p=p->next;
            }
        }
        cout<<"-------------------------------------------------------------------"<<endl;
    }
    //function to insert an element at beginning linked list
    void insert_start(){
        Node *p;
        cout<<"Enter the data to add at beginning :"<<endl;
        p=getnode();
        //checking if list exist or not
        if(head==NULL){
            head=p;
        }
        // p->next=NULL;
        else{
        p->next=head;
        head=p;}
        cout<<"Data added successfully"<<endl;
    }

    void insert_end(){
        Node *t,*p;
        cout<<"Enter the data element to add at last :"<<endl;
        p=getnode();
        //checking if list exist or not
        if(head==NULL){
            head=p;
        }
        else{
        t=head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=p;
        }
        cout<<"Data added successfully"<<endl;
    }
    
    void insert_between(){
        Node *t,*p;
        p=new Node;
        cout<<"Enter the data to insert in list:";
        p=getnode();
        p->next=NULL;
        t=head;
        int n;
        //checking if list exist or not
        if(head==NULL){
            cout<<"Data not found";
            delete p;
            return ; 
        }

        else{
            string key;
            cout<<"If user want to search Phone number by Name then type ""name"" "<<endl;
            cout<<"If user want to search Phone number by Number then type ""number"" "<<endl;
            cin.ignore();
            getline(cin,key);
            if(key=="number"){
                long long key1;
                cout<<"Enter number after which data has to inserted:";
                cin>>key1;//taking what to find from user 
                while(t->number!=key1 &&t!=NULL){
                    t=t->next;
                }
                p->next=t->next;
                t->next=p;
                    
                cout<<"Entered number isn't available in system"<<endl;
            }
            else if(key=="number"){
                cout<<"Enter name after which data has to inserted:";//taking what to find from user 
                cin.ignore();
                getline(cin,key);
                while(t->name!=key &&t!=NULL){
                    t=t->next;
                }
                p->next=t->next;
                t->next=p;
                cout<<"Entered name isn't available in system"<<endl;
            }
            else{
                cout<<"User entered wrong data";
            }
            
        }
            cout<<"Data added successfully"<<endl;

    }
    //     //with position 

    //     // cin>>n;//with 
    //     // for(int i=1;i<n-2;i++){
    //     //     t=t->next;
    //     // }
    //     // p->next=t->next;
    //     // t->next=p;
    //     cout<<"Node added successfully"<<endl;
    //     }
    


    // function for searching 
    void search(){
        Node *t;//creating node
        t=head;//assigning node t to head to traverse the list
        int position=1;
        string key;
        cout<<"If user want to search Phone number by Name then type ""name"" "<<endl;
        cout<<"If user want to search Phone number by Number then type ""number"" "<<endl;
        cin.ignore();
        getline(cin,key);
        if(key=="number"){
            long long key1;
            cout<<"Enter number to find :";//taking what to find from user 
            cin>>key1;
            while(t!=NULL){
                if(t->number==key1){
                    cout<<"Position of the data is :"<<position<<endl;
                    cout<<"Contact name is:"<<t->name<<endl;
                    cout<<"Contact number is:"<<t->number<<endl;
                    return;
                }
                else{
                    t=t->next;
                    position++;
                }
            }
            cout<<"Entered number isn't available in system"<<endl;
        }
        else{
            cout<<"Enter number to find :";//taking what to find from user 
            cin>>key;
            while(t!=NULL){
                if(t->name==key){
                    cout<<"Position of the data is :"<<position<<endl;
                    cout<<"Contact name is:"<<t->name;
                    cout<<"Contact number is:"<<t->number;
                    return;
                }
                else{
                    t=t->next;
                    position++;
                }
            }
            cout<<"Entered name isn't available in system"<<endl;

        }
    }


    // reverse linked list
    void reverse(){
        cout<<"Array is reversing"<<endl;
        Node *p;
        Node *t=NULL;
        Node *result=NULL;
        
        p=head;
        while(p!=NULL){
            t=p->next;
            p->next=result;
            result=p;
            p=t;
        }
        head=result;
        return ;
    }

    //delete class
    void deleted(){
        Node *p,*q=NULL;
        string key;
        cout<<"If user want to delete Phone number by Name then type ""name"" "<<endl;
        cout<<"If user want to delete Phone number by Number then type ""number"" "<<endl;
        cin.ignore();
        getline(cin,key);
        if(key=="name"){
            cout<<"Enter the name to delete:";
            cin>>key;
            p=head;
            if(head->name==key){
                head=head->next;
                delete p;
            }
            else{
                while(p!=NULL && p->name!=key){
                    q=p;p=p->next;
                }

                if(p==NULL){
                    cout<<"Entered name isn't available in system"<<endl;
                }
                else{
                    q->next=p->next;
                    delete p;
                }
            }
        }
        else{
            long long key;
            cout<<"Enter the number to delete:";
            cin>>key;
            p=head;
            if(head->number==key){
                head=head->next;
                delete p;
            }
            else{
                while(p!=NULL && p->number!=key){
                    q=p;p=p->next;
                }

                if(p==NULL){
                    cout<<"Entered number isn't available in system"<<endl;
                }
                else{
                    q->next=p->next;
                    delete p;
                }
            }

        }
    }
    //class constructor
    MySLL(){
        head=NULL;
    }
    void maindup(){
    char choice;
    cout<<"1.Add new contact number"<<endl;
    cout<<"2.Delete existing contact number"<<endl;
    cout<<"3.Search a contact number in system"<<endl;
    cout<<"4.Reverse the list in system"<<endl;
    cout<<"5.To see the entire list in system"<<endl;
    cout<<"6.To exit from program"<<endl;
    cout<<"Enter respective number to do task :"<<endl;
    cin>>choice;
    string choice1;
    switch(choice){
        case '1':
                cout<<"User wants to add a contact number in System"<<endl;
                cout<<"-------------------------------------------------------------------"<<endl;
                cout<<"Enter from 'start', 'end' and 'between'"<<endl;
                cin>>choice1;
                if(choice1=="start"){
                    insert_start();
                }else if(choice1=="end"){
                    insert_end();
                }else if(choice1=="between"){
                    insert_between();
                }
                maindup();
                break;
        case '2':
                cout<<"User wants to delete a contact number in System"<<endl;
                cout<<"-------------------------------------------------------------------"<<endl;
                deleted();
                maindup();
                break;
        case '3':
                cout<<"User wants to search a contact number in System"<<endl;
                cout<<"-------------------------------------------------------------------"<<endl;
                search();
                maindup();
                break;
        case '4':
                cout<<"User wants to reverse contact number System"<<endl;
                cout<<"-------------------------------------------------------------------"<<endl;
                reverse();
                maindup();
                break;
        case '5':
                cout<<"User wants to see entire contact number System"<<endl;
                cout<<"-------------------------------------------------------------------"<<endl;
                display();
                maindup();
                break;
        case '6':
                cout<<"Thank You!"<<endl;
                break;
        default :
                cout<<"Please check your input"<<endl;
                maindup();
    }

    }
};
int main(){
    int n;
    MySLL m1;
    //introduction
    cout<<"Welcome to linked list program"<<endl;

    // cout<<"7.To add multiple number at a time"<<endl;
    //taking number of elements
    m1.maindup();
    return 0;
}
    
