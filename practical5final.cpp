
#include <iostream>

// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a value into a binary search tree
Node* insert(Node* root, int value) {
    // If the tree is empty, create a new node and make it the root
    if (root == nullptr) {
        return new Node(value);
    }

    // Otherwise, recursively insert the value in the appropriate subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to swap left and right pointers at every node
void swapPointers(Node* root) {
    if (root == nullptr) {
        return;
    }

   // Swap left and right pointers
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively swap pointers in the left and right subtrees
    swapPointers(root->left);
    swapPointers(root->right);
}

// Function to search for a value in the binary search tree
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;  // Value not found
    }

    if (value == root->data) {
        return true;  // Value found
    }

    if (value < root->data) {
        return search(root->left, value);  // Search in the left subtree
    } else {
        return search(root->right, value);  // Search in the right subtree
    }
}

// Function to print the binary search tree in inorder traversal
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;

    int choice;
    do {
        std::cout << "Binary Search Tree Operations:" << std::endl;
        std::cout << "1. Insert value" << std::endl;
        std::cout << "2. Swap left and right pointers" << std::endl;
        std::cout << "3. Search for a value" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                std::cout << "Enter the value to insert: ";
                std::cin >> value;
                root = insert(root, value);
                //std::cout << "Value inserted successfully!" << std::endl;
                break;
            }
            case 2: {
                swapPointers(root);
                std::cout << "Left and right pointers swapped successfully!" << std::endl;
                break;
            }
            case 3: {
                int searchValue;
                std::cout << "Enter a value to search: ";
                std::cin >> searchValue;
                bool found = search(root, searchValue);
                if (found) {
                    std::cout << "Value " << searchValue << " found in the tree." << std::endl;
                } else {
                    std::cout << "Value " << searchValue << " not found in the tree." << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << "Exiting program." << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }

        std::cout << std::endl;
    } while (choice != 4);

    return 0;
}

