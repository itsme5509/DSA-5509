#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node {
    string vertex;
    int time;
    node* next;

    node() {
        next = NULL;
    }
};

class adjmatlist {
    string v[20];
    node* head[20];
    node* temp = NULL;
    int n; // Move the declaration here

public:
    adjmatlist() {
        for (int i = 0; i < 20; i++) {
            head[i] = NULL;
        }
    }
    void getGraph();
    void displayList();
};

void adjmatlist::getGraph() {
    cout << "\n enter no. of cities (max. 20): ";
    cin >> n;
    cout << "\n enter name of cities: ";
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << "\n ****";
    for (int i = 0; i < n; i++) {
        node* p = new struct node;
        p->next = NULL;
        p->vertex = v[i];
        head[i] = p;
        cout << "\n" << head[i]->vertex;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << "\n if path is present between city " << v[i] << " and " << v[j] << " then press 'y'; otherwise press 'n': ";
                char ch;
                cin >> ch;
                if (ch == 'y') {
                    node* p = new struct node;
                    p->vertex = v[j];
                    cout << "\n enter time required to reach city " << v[j] << " from " << v[i] << " in minutes: ";
                    cin >> p->time;
                    p->next = NULL;
                    if (head[i]->next == NULL) {
                        head[i]->next = p;
                    }
                    else {
                        temp = head[i];
                        while (temp->next != NULL) {
                            temp = temp->next;
                        }
                        temp->next = p;
                    }
                }
            }
        }
    }
}

void adjmatlist::displayList() {
    cout << "\n Adjacency list is:\n";
    for (int i = 0; i < n; i++) {
        if (head[i] == NULL) {
            cout << "\n adjacency list not present";
            break;
        }
        else {
            cout << "\n" << head[i]->vertex;
            temp = head[i]->next;
            while (temp != NULL) {
                cout << "-> " << temp->vertex;
                temp = temp->next;
            }
        }
    }
    cout << "\n Path and time required to reach cities:\n";
    for (int i = 0; i < n; i++) {
        if (head[i] == NULL) {
            cout << "\n adjacency list not present";
            break;
        }
        else {
            temp = head[i]->next;
            while (temp != NULL) {
                cout << "\n" << head[i]->vertex;
                cout << "-> " << temp->vertex << "\n   [time required: " << temp->time << " min ]";
                temp = temp->next;
            }
        }
    }
}

int main() {
    adjmatlist a;
    a.getGraph();
    a.displayList();
    return 0;
}

