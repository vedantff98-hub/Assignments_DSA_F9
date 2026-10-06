#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    string song;
    Node *next;
    Node *prev;
};

class MusicPlaylist{
    Node *head;
    Node *current; // to keep track of the currently playing song
    public:
    
    //function to make nodes
    Node* getnode(){
        Node *p = new Node;
        cout<<"Enter the song name: ";
        cin >> ws; // to clear buffer before reading string
        getline(cin, p->song);
        p->next = NULL;
        p->prev = NULL;
        return p;
    }
    
    //function to add a song to the end of the playlist
    void add_song(){
        Node *t, *p;
        p = getnode();
        //checking if list exist or not
        if(head == NULL){
            head = p;
            current = head; // first song becomes current
        }
        else{
            t = head;
            while(t->next != NULL){
                t = t->next;
            }
            t->next = p;
            p->prev = t;
        }
        cout<<"Song added successfully!"<<endl;
    }
    
    //function to display linked list
    void display(){
        Node *p;
        p = head;
        int count = 0;
        //checking if list exist or not
        if(head == NULL){
            cout<<"Data not exists to display"<<endl;
        }
        else{
            cout<<"\n--- Current Playlist ---"<<endl;
            while(p != NULL){
                count++;
                if(p == current){
                    cout<<" -> "<<p->song<<" (Now Playing)"<<endl;
                }
                else{
                    cout<<"    "<<p->song<<endl;
                }
                p = p->next; 
            }
            cout<<"------------------------"<<endl;
        }
    }
    
    //function for searching 
    void search(){
        Node *t; //creating node
        t = head; //assigning node t to head to traverse the list
        string key;
        int position = 1;
        cout<<"Enter song name to find :"; //taking what to find from user 
        cin >> ws;
        getline(cin, key);
        
        while(t != NULL){
            if(t->song == key){
                cout<<"Position of the song is :"<<position<<endl;
                return;
            }
            else{
                t = t->next;
                position++;
            }
        }
        cout<<"Song not found in list"<<endl;
    }

    //function for delete nodes
    void deleted(){
        Node *p, *q = NULL;
        string key;
        
        //checking if list exist or not
        if(head == NULL){
             cout<<"Data not exists to delete"<<endl;
             return;
        }
        
        cout<<"Enter the song to delete:";
        cin >> ws;
        getline(cin, key);
        
        p = head;
        if(head->song == key){
            head = head->next;
            if(head != NULL){
                head->prev = NULL;
            }
            // if we are deleting the currently playing song
            if(current == p) current = head; 
            delete p;
            cout<<"Song deleted successfully"<<endl;
        }
        else{
            while(p != NULL && p->song != key){
                q = p; 
                p = p->next;
            }

            if(p == NULL){
                cout<<"Data isn't available"<<endl;
            }
            else{
                q->next = p->next;
                if(p->next != NULL){
                    (p->next)->prev = q;
                }
                // if we delete the current playing song, move current back
                if(current == p) current = q; 
                delete p;
                cout<<"Song deleted successfully"<<endl;
            }
        }
    }
    
    //function to navigate forward
    void play_next(){
        if(current == NULL){
            cout<<"No songs in the playlist."<<endl;
        }
        else if(current->next != NULL){
            current = current->next;
            cout<<"Playing Next: "<<current->song<<endl;
        }
        else{
            cout<<"You are at the end of the playlist."<<endl;
        }
    }
    
    //function to navigate backward
    void play_previous(){
        if(current == NULL){
            cout<<"No songs in the playlist."<<endl;
        }
        else if(current->prev != NULL){
            current = current->prev;
            cout<<"Playing Previous: "<<current->song<<endl;
        }
        else{
            cout<<"You are at the start of the playlist."<<endl;
        }
    }

    //class constructor
    MusicPlaylist(){
        head = NULL;
        current = NULL;
    }
};

int main(){
    char c;
    //making object
    MusicPlaylist m1;
    
    //introduction
    cout<<"Welcome to Music Playlist Manager program"<<endl;
    
    //menu driven loop
    do{
        cout<<"\n==== MENU ===="<<endl;
        cout<<"1. Add Song"<<endl;
        cout<<"2. Delete Song"<<endl;
        cout<<"3. Search Song"<<endl;
        cout<<"4. Display Playlist"<<endl;
        cout<<"5. Play Next Song"<<endl;
        cout<<"6. Play Previous Song"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>c;
        
        switch(c){
            case '1': m1.add_song(); break;
            case '2': m1.deleted(); break;
            case '3': m1.search(); break;
            case '4': m1.display(); break;
            case '5': m1.play_next(); break;
            case '6': m1.play_previous(); break;
            case '7': break;
            default: cout<<"Wrong input"<<endl; break;
        }
    } while(c != '7');
    
    cout<<"Thank You!"<<endl;
    return 0;
}