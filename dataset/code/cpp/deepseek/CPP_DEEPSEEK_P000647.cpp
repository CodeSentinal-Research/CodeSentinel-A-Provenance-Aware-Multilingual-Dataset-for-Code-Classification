#include <iostream>
#include <string>

using namespace std;

struct Node {
    string title;
    Node* prev;
    Node* next;
};

class Playlist {
private:
    Node* head;
    Node* tail;
    Node* current;

public:
    Playlist() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }

    void addSong(string title) {
        Node* node = new Node;
        node->title = title;

        if(head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void removeSong(string title) {
        Node* temp = head;
        while(temp != nullptr) {
            if(temp->title == title) {
                if(temp == head) {
                    head = head->next;
                    if(head != nullptr) {
                        head->prev = nullptr;
                    }
                } else if(temp == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    void playNext() {
        if(head != nullptr) {
            if(current != nullptr) {
                current->prev->next = current->next;
                if(current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                delete current;
            }
            current = head;
            head = head->next;
            if(head != nullptr) {
                head->prev = nullptr;
            }
            cout << "Playing: " << current->title << endl;
        }
    }

    void playPrevious() {
        if(current != nullptr) {
            if(current->prev != nullptr) {
                current->prev->next = current->next;
                if(current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    head = current->prev;
                }
                delete current;
            }
            current = tail;
            tail = tail->prev;
            if(tail != nullptr) {
                tail->next = nullptr;
            }
            cout << "Playing: " << current->title << endl;
        }
    }

    void currentSong() {
        if(current != nullptr) {
            cout << "Current song: " << current->title << endl;
        }
    }
};

int main() {
    int q;
    cin >> q;
    Playlist playlist;
    while(q--) {
        string op, title;
        int pos;
        cin >> op;
        if(op == "ADD") {
            cin >> title;
            playlist.addSong(title);
        } else if(op == "REMOVE") {
            cin >> title;
            playlist.removeSong(title);
        } else if(op == "PLAYNEXT") {
            playlist.playNext();
        } else if(op == "PLAYPREVIOUS") {
            playlist.playPrevious();
        } else if(op == "CURRENTSONG") {
            playlist.currentSong();
        }
    }
    return 0;
}
This C++ program uses a doubly linked list to manage a playlist of music songs. It implements the operations addSong(title), removeSong(title), playNext(), playPrevious(), and currentSong(). The playlist is initially empty. The program then processes a sequence of operations and prints the result for every operation.