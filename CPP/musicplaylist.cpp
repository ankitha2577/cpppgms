#include <iostream>
using namespace std;


struct Node {
    string song;
    Node* next;
};

Node* head = NULL;

// 2. Add Song (Insert at End so order is maintained)
void addSong(string name) {
    Node* newNode = new Node();
    newNode->song = name;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 3. Delete Song by name
void deleteSong(string name) {
    if (head == NULL) {
        cout << "Playlist is empty!\n";
        return;
    }
    
    // If the song is at the head
    if (head->song == name) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted '" << name << "' from playlist.\n";
        return;
    }
    
    // Walk to the node just before the song
    Node* temp = head;
    while (temp->next != NULL && temp->next->song != name) {
        temp = temp->next;
    }
    
    if (temp->next == NULL) {
        cout << "Song not found!\n";
        return;
    }
    
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    cout << "Deleted '" << name << "' from playlist.\n";
}

// 4. Sort Playlist (Bubble Sort alphabetically)
void sortPlaylist() {
    if (head == NULL || head->next == NULL) {
        cout << "Not enough songs to sort!\n";
        return;
    }
    
    for (Node* i = head; i->next != NULL; i = i->next) {
        for (Node* j = head; j->next != NULL; j = j->next) {
            if (j->song > j->next->song) {
                string temp = j->song;
                j->song = j->next->song;
                j->next->song = temp;
            }
        }
    }
    cout << "Playlist sorted alphabetically (A-Z)!\n";
}

// 5. Search Song
void searchSong(string name) {
    Node* temp = head;
    int pos = 1;
    
    while (temp != NULL) {
        if (temp->song == name) {
            cout << "Found '" << name << "' at position " << pos << "!\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Song not found in the playlist!\n";
}

// 6. Display function
void display() {
    if (head == NULL) {
        cout << "Playlist is empty!\n";
        return;
    }
    
    Node* temp = head;
    cout << "\n--- CURRENT PLAYLIST ---\n";
    while (temp != NULL) {
        cout << temp->song << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


int main() {
    int choice, n;
    string songName;

 
    cout << "How many songs do you want to add initially? ";
    cin >> n;
    
    if (n > 0) {
        cout << "Enter " << n << " song names (one word each, e.g., Believer):\n";
        for (int i = 0; i < n; i++) {
            cin >> songName;
            addSong(songName);
        }
        cout << "Initial playlist created!\n";
    }

    // --- INTERACTIVE MENU ---
    while (true) {
        cout << "\n--- MUSIC PLAYLIST MENU ---\n";
        cout << "1. Add Song\n2. Delete Song\n3. Sort Playlist\n4. Search Song\n5. Display\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter song name: ";
            cin >> songName;
            addSong(songName);
            cout << "Added '" << songName << "' to the playlist!\n";
        }
        else if (choice == 2) {
            cout << "Enter song name to delete: ";
            cin >> songName;
            deleteSong(songName);
        }
        else if (choice == 3) {
            sortPlaylist();
        }
        else if (choice == 4) {
            cout << "Enter song name to search: ";
            cin >> songName;
            searchSong(songName);
        }
        else if (choice == 5) {
            display();
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
