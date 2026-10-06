#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
};
class MySLL{
    Node *head;
    public:
    //function to make nodes
    Node* getnode(){
        Node *p=new Node;
        cout<<"Enter the data:";
        cin>>p->data;
        p->next=NULL;
        p->prev=NULL;
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
                p->prev=q;
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
            cout<<"Data not exists to display";
        }
        else{
            cout<<"Entered list is:"<<endl;

            while(p!=NULL){
                count++;
                cout<<p->data<<endl;
                p=p->next; 
            }
        }
    }
    //function to insert an element at beginning linked list
    void insert_start(){
        Node *p;
        p=getnode();
        //checking if list exist or not
        if(head==NULL){
            head=p;
        }
        else{
        p->next=head;
        head->prev=p;
        head=p;
        }
    }
    void insert_end(){
        Node *t,*p;
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
        p->prev=t;
        }
    }
    void insert_between(){
        Node *t,*p;
        p=getnode();
        t=head;
        int n;
        //checking if list exist or not
        if(head==NULL){
            cout<<"Data not found"<<endl;
            head=p;
            cout<<"New list generated"<<endl; 
        }
        else{
            int temp;
            cout<<"Enter the position after which number is inserted:";
            cin>>temp;
            while(t!=NULL && t->data!=temp){
                t=t->next;
            }
            p->next=t->next;
            p->prev=t;
            t->next=p;
        }
            //with position 

            // cin>>n;//with 
            // for(int i=1;i<n-2;i++){
            //     t=t->next;
            // }
            // p->next=t->next;
            // t->next=p;
        cout<<"Node added successfully"<<endl;
    }
    
    //function for searching 
    void search(){
        Node *t;//creating node
        t=head;//assigning node t to head to traverse the list
        int key;
        int position=1;
        cout<<"Enter key to find :";//taking what to find from user 
        cin>>key;
        while(t!=NULL){
            if(t->data==key){
                cout<<"Position of the data is :"<<position<<endl;
                return;
            }
            else{
                t=t->next;
                position++;
            }
        }
        cout<<"Key not found in list"<<endl;
    }

    void update(){
        Node *t;//creating node
        t=head;//assigning node t to head to traverse the list
        int key,update;
        int position=1;
        cout<<"Enter key to find :";//taking what to find from user
        cin>>key;
        cout<<"Enter the new value to update:"; 
        cin>>update;
        while(t!=NULL){
            if(t->data==key){
                t->data=update;
                return;
            }
            else{
                t=t->next;
                position++;
            }
        }
        cout<<"Key not found in list"<<endl;
    }

    //function for delete nodes
    void deleted(){
        Node *p,*q=NULL;
        int key;
        cout<<"Enter the element to delete:";
        cin>>key;
        p=new Node;
        p=head;
        if(head->data==key){
            head=head->next;
            head->prev=NULL;
            delete p;
        }
        else{
            while(p!=NULL && p->data!=key){
                q=p;p=p->next;
            }

            if(p==NULL){
                cout<<"Data isn't available"<<endl;
            }
            else{
                q->next=p->next;
                (p->next)->prev=q;
                delete p;
            }
        }
    }
    //class constructor
    MySLL(){
        head=NULL;
    }
};
int main(){
    int n;
    //introduction
    cout<<"Welcome to doubly linked list program"<<endl;
    //taking number of elements
    cout<<"Enter the number of elements in the list:";
    cin>>n;
    //making object
    MySLL m1;
    //creating linked list
    m1.create(n);
    //asking use if user wants to insert an element in list
    char c;
    cout<<"Do user want to enter data between the list?(enter 'y' for yes, any key for no) :";
    cin>>c;
    if(c=='y'){
        
        cout<<"Enter 1 for inserting at start"<<endl;
        cout<<"Enter 2 for inserting at last"<<endl;
        cout<<"Enter 3 for inserting at a position"<<endl;
        cout<<"Enter choice:";
        cin>>c;
        switch(c){
            case '1':m1.insert_start();break;
            case '2':m1.insert_end();break;
            case '3':m1.insert_between();break;
        }
    }
    //updation in list
    
    //search operation in list
    m1.search();
    
    // //displaing the list
    // m1.display();
    // //salutation!!
    // m1.deleted();
    // cout<<"Do user want to reverse the linked list(Enter 'y' for yes) :";
    // cin>>c;
    // if(c=='y'){
    //     m1.reverse();
    //     m1.display();
    // }
    m1.deleted();
    m1.display();
    cout<<"Do user want to update data between the list?(enter 'y' for yes, any key for no) :";
    cin>>c;
    if(c=='y')
        m1.update();
    else
        cout<<"Wrong input"<<endl;
    cout<<"Thank You!"<<endl;
    return 0;
}