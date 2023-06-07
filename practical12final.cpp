
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class adjmatlist 
{
    int m[10][10], n, i, j;
    string v[20];

public:
    void getGraph();
    void displayMatrix();
};

void adjmatlist::getGraph() {
    cout << "\n enter no. of cities (max. 20): ";
    cin >> n;
    cout << "\n enter names of cities: ";
    for (i = 0; i < n; i++)
        cin >> v[i];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                char ch;
                cout << "\n If there is a path between city " << v[i] << " and " << v[j] << ", enter 'y'; otherwise enter 'n': ";
                cin >> ch;
                if (ch == 'y') {
                    cout << "\n enter time required to reach city " << v[j] << " from " << v[i] << " in minutes: ";
                    cin >> m[i][j];
                }
                else {
                    m[i][j] = 0;
                }
            }
            else {
                m[i][j] = 0;
            }
        }
    }
}

void adjmatlist::displayMatrix() {
    cout << "\n Adjacency matrix:\n";
    for (j = 0; j < n; j++) {
        cout << "\t" << v[j];
    }
    for (i = 0; i < n; i++) {
        cout << "\n " << v[i];
        for (j = 0; j < n; j++) {
            cout << "\t" << m[i][j];
        }
        cout << "\n";
    }
}

int main() {
    adjmatlist a;
    a.getGraph();
    a.displayMatrix();
    return 0;
}
