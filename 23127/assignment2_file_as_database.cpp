#include <iostream>
#include <fstream>
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
    Node *current; // keeps track of the currently playing song
    string filename = "playlist.txt"; // Text file acting as the database

    // Internal function to add a node without user input (used for file loading)
    void append_node(string song_name){
        Node *p = new Node;
        p->song = song_name;
        p->next = NULL;
        p->prev = NULL;

        if(head == NULL){
            head = p;
            current = head;
        }
        else{
            Node *t = head;
            while(t->next != NULL){
                t = t->next;
            }
            t->next = p;
            p->prev = t;
        }
    }

    public:
    // class constructor: loads database into memory upon startup
    MusicPlaylist(){
        head = NULL;
        current = NULL;
        load_from_file();
    }

    // Read the text file and build the linked list
    void load_from_file(){
        ifstream file(filename);
        string line;
        
        if (file.is_open()) {
            while (getline(file, line)) {
                if (!line.empty()) {
                    append_node(line);
                }
            }
            file.close();
            cout << "Database loaded successfully." << endl;
        } else {
            cout << "No existing database found. A new one will be created." << endl;
        }
    }

    // Overwrite the text file with current linked list (used after deletion)
    void save_to_file(){
        ofstream file(filename, ios::trunc); // trunc overwrites the file entirely
        Node *t = head;
        while (t != NULL) {
            file << t->song << "\n";
            t = t->next;
        }
        file.close();
    }
    
    // Function to add a song to the list and append it to the file
    void add_song(){
        string song_name;
        cout << "Enter the song name: ";
        cin >> ws;
        getline(cin, song_name);
        
        append_node(song_name); // Add to linked list
        
        // Append to file database directly
        ofstream file(filename, ios::app); 
        file << song_name << "\n";
        file.close();

        cout << "Song added successfully to memory and database!" << endl;
    }
    
    // Function to display linked list
    void display(){
        Node *p = head;
        int count = 0;
        
        if(head == NULL){
            cout << "Playlist is empty." << endl;
        }
        else{
            cout << "\n--- Current Playlist ---" << endl;
            while(p != NULL){
                count++;
                if(p == current){
                    cout << " -> " << p->song << " (Now Playing)" << endl;
                }
                else{
                    cout << "    " << p->song << endl;
                }
                p = p->next; 
            }
            cout << "------------------------" << endl;
        }
    }
    
    // Function for searching in memory
    void search(){
        Node *t = head;
        string key;
        int position = 1;
        
        cout << "Enter song name to find: ";
        cin >> ws;
        getline(cin, key);
        
        while(t != NULL){
            if(t->song == key){
                cout << "Position of the song is: " << position << endl;
                return;
            }
            else{
                t = t->next;
                position++;
            }
        }
        cout << "Song not found in list." << endl;
    }

    // Function to delete nodes and update file database
    void deleted(){
        Node *p, *q = NULL;
        string key;
        
        if(head == NULL){
             cout << "Playlist is empty." << endl;
             return;
        }
        
        cout << "Enter the song to delete: ";
        cin >> ws;
        getline(cin, key);
        
        p = head;
        bool found = false;

        // Deleting the head node
        if(head->song == key){
            head = head->next;
            if(head != NULL) head->prev = NULL;
            if(current == p) current = head; // shift current if playing song is deleted
            delete p;
            found = true;
        }
        // Deleting a middle or end node
        else{
            while(p != NULL && p->song != key){
                q = p; 
                p = p->next;
            }

            if(p != NULL){
                q->next = p->next;
                if(p->next != NULL){
                    (p->next)->prev = q;
                }
                if(current == p) current = q; // shift current if playing song is deleted
                delete p;
                found = true;
            }
        }

        if(found){
            save_to_file(); // Sync changes to the text file
            cout << "Song deleted and database updated." << endl;
        } else {
            cout << "Song isn't available in the playlist." << endl;
        }
    }
    
    // Function to navigate forward
    void play_next(){
        if(current == NULL){
            cout << "No songs in the playlist." << endl;
        }
        else if(current->next != NULL){
            current = current->next;
            cout << "Playing Next: " << current->song << endl;
        }
        else{
            cout << "You are at the end of the playlist." << endl;
        }
    }
    
    // Function to navigate backward
    void play_previous(){
        if(current == NULL){
            cout << "No songs in the playlist." << endl;
        }
        else if(current->prev != NULL){
            current = current->prev;
            cout << "Playing Previous: " << current->song << endl;
        }
        else{
            cout << "You are at the start of the playlist." << endl;
        }
    }
};

int main(){
    char c;
    cout << "Welcome to Music Playlist Manager program" << endl;
    
    // Create object. Constructor will automatically load from playlist.txt
    MusicPlaylist m1;
    
    do{
        cout << "\n==== MENU ====" << endl;
        cout << "1. Add Song" << endl;
        cout << "2. Delete Song" << endl;
        cout << "3. Search Song" << endl;
        cout << "4. Display Playlist" << endl;
        cout << "5. Play Next Song" << endl;
        cout << "6. Play Previous Song" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> c;
        
        switch(c){
            case '1': m1.add_song(); break;
            case '2': m1.deleted(); break;
            case '3': m1.search(); break;
            case '4': m1.display(); break;
            case '5': m1.play_next(); break;
            case '6': m1.play_previous(); break;
            case '7': cout << "Exiting program. Playlist is saved securely." << endl; break;
            default: cout << "Wrong input" << endl; break;
        }
    } while(c != '7');
    
    return 0;
}