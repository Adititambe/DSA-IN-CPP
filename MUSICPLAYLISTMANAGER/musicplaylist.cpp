
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Node class for storing song details
class Node {
public:
    string title;
    string artist;
    Node* prev;
    Node* next;

    Node(string t, string a) {
        title = t;
        artist = a;
        prev = NULL;
        next = NULL;
    }
};

// Music Playlist Manager using Doubly Linked List
class MusicPlaylist {
private:
    Node* head;
    Node* current;

public:
    MusicPlaylist() {
        head = NULL;
        current = NULL;
    }

    // Add song at the end
    void addSong(string title, string artist) {
        Node* p = new Node(title, artist);

        if (head == NULL) {
            head = p;
            current = p;
        } else {
            Node* q = head;

            while (q->next != NULL) {
                q = q->next;
            }

            q->next = p;
            p->prev = q;
        }

        cout << "Song added successfully!\n";
    }

    // Delete song by title
    void deleteSong(string title) {
        Node* q = head;

        while (q != NULL && q->title != title) {
            q = q->next;
        }

        if (q == NULL) {
            cout << "Song not found.\n";
            return;
        }

        if (q->prev != NULL) {
            q->prev->next = q->next;
        } else {
            head = q->next;
        }

        if (q->next != NULL) {
            q->next->prev = q->prev;
        }

        if (current == q) {
            if (q->next != NULL) {
                current = q->next;
            } else {
                current = q->prev;
            }
        }

        delete q;

        cout << "Song deleted successfully!\n";
    }

    // Display playlist from first to last
    void displayPlaylist() {
        Node* q = head;

        if (q == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        cout << "\nForward Playlist:\n";

        while (q != NULL) {
            cout << q->title << " - " << q->artist;

            if (q == current) {
                cout << " [CURRENT]";
            }

            cout << "\n";
            q = q->next;
        }
    }

    // Display playlist in reverse order
    void displayReverse() {
        Node* q = head;

        if (q == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        while (q->next != NULL) {
            q = q->next;
        }

        cout << "\nReverse Playlist:\n";

        while (q != NULL) {
            cout << q->title << " - "
                 << q->artist << "\n";

            q = q->prev;
        }
    }

    // Play current song
    void playCurrent() {
        if (current == NULL) {
            cout << "No song available.\n";
        } else {
            cout << "Now Playing: "
                 << current->title << " - "
                 << current->artist << "\n";
        }
    }

    // Move to next song
    void playNext() {
        if (current == NULL) {
            cout << "Playlist is empty.\n";
        } else if (current->next == NULL) {
            cout << "Already at the last song.\n";
        } else {
            current = current->next;
            playCurrent();
        }
    }

    // Move to previous song
    void playPrevious() {
        if (current == NULL) {
            cout << "Playlist is empty.\n";
        } else if (current->prev == NULL) {
            cout << "Already at the first song.\n";
        } else {
            current = current->prev;
            playCurrent();
        }
    }

    // Show current song
    void showCurrent() {
        playCurrent();
    }

    // Play all songs once
    void playCompletePlaylist() {
        Node* q = head;

        if (q == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        cout << "\nPlaying Complete Playlist:\n";

        while (q != NULL) {
            cout << "Playing: " << q->title
                 << " - " << q->artist << "\n";

            q = q->next;
        }
    }

    // Repeat complete playlist
    void repeatAll(int repetitions) {
        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        for (int i = 1; i <= repetitions; i++) {
            Node* q = head;

            cout << "\nRepetition " << i << ":\n";

            while (q != NULL) {
                cout << "Playing: " << q->title
                     << " - " << q->artist << "\n";

                q = q->next;
            }
        }
    }

    // Free memory used by all nodes
    ~MusicPlaylist() {
        Node* q = head;

        while (q != NULL) {
            Node* p = q;
            q = q->next;
            delete p;
        }
    }
};

// Main function
int main() {
    MusicPlaylist playlist;
    int choice;

    do {
        cout << "\n===== MUSIC PLAYLIST MANAGER =====\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Display Playlist in Reverse\n";
        cout << "5. Play Current Song\n";
        cout << "6. Play Next Song\n";
        cout << "7. Play Previous Song\n";
        cout << "8. Play Complete Playlist\n";
        cout << "9. Repeat All\n";
        cout << "10. Show Current Song\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a number.\n";
            return 0;
        }

        string title, artist;
        int repetitions;

        switch (choice) {
        case 1:
            cout << "Enter song title: ";
            getline(cin >> ws, title);

            cout << "Enter artist name: ";
            getline(cin, artist);

            playlist.addSong(title, artist);
            break;

        case 2:
            cout << "Enter title to delete: ";
            getline(cin >> ws, title);

            playlist.deleteSong(title);
            break;

        case 3:
            playlist.displayPlaylist();
            break;

        case 4:
            playlist.displayReverse();
            break;

        case 5:
            playlist.playCurrent();
            break;

        case 6:
            playlist.playNext();
            break;

        case 7:
            playlist.playPrevious();
            break;

        case 8:
            playlist.playCompletePlaylist();
            break;

        case 9:
            cout << "Enter number of repetitions: ";

            if (cin >> repetitions && repetitions > 0) {
                playlist.repeatAll(repetitions);
            } else {
                cout << "Enter a positive integer.\n";
                return 0;
            }
            break;

        case 10:
            playlist.showCurrent();
            break;

        case 11:
            cout << "Exiting Music Playlist Manager.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 11);

    return 0;
}
