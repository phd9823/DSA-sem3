#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int vertex;
    Node* next;
};

class Graph {
private:
    int users;
    Node* socialList[20];
    bool visited[20];

public:
    void createGraph() {
        cout << "Enter the number of users: ";
        cin >> users;

        for (int i = 0; i < users; i++) {
            socialList[i] = NULL;
            visited[i] = false;
        }

        int friendships;
        cout << "Enter the number of friendships: ";
        cin >> friendships;

        for (int k = 0; k < friendships; k++) {
            int user1, user2;
            cout << "Enter friendship connection (user1 user2): ";
            cin >> user1 >> user2;

            if (user1 >= 0 && user1 < users && user2 >= 0 && user2 < users) {
                Node* newNode1 = new Node();
                newNode1->vertex = user2;
                newNode1->next = socialList[user1];
                socialList[user1] = newNode1;

                Node* newNode2 = new Node();
                newNode2->vertex = user1;
                newNode2->next = socialList[user2];
                socialList[user2] = newNode2;
            } else {
                cout << "Invalid user index! Try again.\n";
                k--;
            }
        }
    }

    void displayGraph() {
        cout << "\nSocial Network Adjacency List:\n";
        for (int i = 0; i < users; i++) {
            cout << "User " << i << " -> ";
            Node* current = socialList[i];
            while (current != NULL) {
                cout << current->vertex << " -> ";
                current = current->next;
            }
            cout << "NULL\n";
        }
    }

    void BFS(int startUser) {
        for (int i = 0; i < users; i++) {
            visited[i] = false;
        }

        queue<int> q;
        visited[startUser] = true;
        q.push(startUser);

        cout << "\nUsers connected level by level:\n";
        while (!q.empty()) {
            int currentUser = q.front();
            q.pop();
            cout << currentUser << " ";

            Node* current = socialList[currentUser];
            while (current != NULL) {
                int friendUser = current->vertex;
                if (!visited[friendUser]) {
                    visited[friendUser] = true;
                    q.push(friendUser);
                }
                current = current->next;
            }
        }
        cout << endl;
    }

    int getUsers() {
        return users;
    }
};

int main() {
    Graph socialNetwork;
    int choice;

    do {
        cout << "\n=================================\n";
        cout << " SOCIAL NETWORK CONNECTIVITY (BFS)\n";
        cout << "=================================\n";
        cout << "1. Create Graph\n";
        cout << "2. Display Adjacency List\n";
        cout << "3. Perform BFS\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                socialNetwork.createGraph();
                break;
            case 2:
                socialNetwork.displayGraph();
                break;
            case 3: {
                int startUser;
                cout << "Enter starting user: ";
                cin >> startUser;
                if (startUser >= 0 && startUser < socialNetwork.getUsers()) {
                    socialNetwork.BFS(startUser);
                } else {
                    cout << "Invalid starting user!\n";
                }
                break;
            }
            case 4:
                cout << "Program terminated.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}