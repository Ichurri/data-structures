#include <iostream>
#include "BinaryTree.h"

using namespace std;

void displayMenu()
{
    cout << "\nMenu:\n";
    cout << "1. Insert Random Data\n";
    cout << "2. Count Nodes\n";
    cout << "3. Calculate Height\n";
    cout << "4. In-Order Traversal\n";
    cout << "5. Pre-Order Traversal\n";
    cout << "6. Post-Order Traversal\n";
    cout << "7. Show Array\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    int capacity;
    cout << "Enter the capacity of the binary tree: ";
    cin >> capacity;

    BinaryTree<int> binaryTree(capacity);
    int choice, data;

    while (true)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            binaryTree.insertRandom(data);
            break;
        case 2:
            cout << "Number of nodes: " << binaryTree.countNodes() << endl;
            break;
        case 3:
            cout << "Height of the tree: " << binaryTree.calculateHeight() << endl;
            break;
        case 4:
            cout << "In-Order Traversal: ";
            binaryTree.inOrderTraversal(0);
            cout << endl;
            break;
        case 5:
            cout << "Pre-Order Traversal: ";
            binaryTree.preOrderTraversal(0);
            cout << endl;
            break;
        case 6:
            cout << "Post-Order Traversal: ";
            binaryTree.postOrderTraversal(0);
            cout << endl;
            break;
        case 7:
            cout << "Tree Array:\n";
            binaryTree.showArray();
            break;
        case 0:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
