#include "Tree.h"
#include <conio.h>

using namespace std;

void test()
{
    Tree<int> Tree; 

    Tree.insertData(50);
    Tree.insertData(30);
    Tree.insertData(70);
    Tree.insertData(20);
    Tree.insertData(40);
    Tree.insertData(60);
    Tree.insertData(80);

    int searchValue = 40;
    if (Tree.searchData(searchValue)) 
        cout << "The element " << searchValue << " is in the tree." << endl;
    else 
        cout << "The element " << searchValue << " is not in the tree." << endl;

    int deleteValue = 30;
    Tree.deleteData(deleteValue);
    cout << "Element " << deleteValue << " deleted from the tree." << endl;

    cout << "Smallest element: " << Tree.findMinor() << endl;
    cout << "Largest element: " << Tree.findGreater() << endl;

    cout << "Number of nodes in the tree: " << Tree.countNode() << endl;

    cout << "Height of the tree: " << Tree.calculateHeight() << endl;

    cout << "InOrder traversal: ";
    Tree.inOrderTraversal();
    cout << endl;

    cout << "PreOrder traversal: ";
    Tree.preOrderTraversal();
    cout << endl;

    cout << "PostOrder traversal: ";
    Tree.postOrderTraversal();
    cout << endl;
}

void menu()
{
    Tree<int> Tree;

    int choice, value;
    while (true) 
    {
        cout << "AVL Tree Menu:" << endl;
        cout << "1. Insert element" << endl;
        cout << "2. Search for element" << endl;
        cout << "3. Delete element" << endl;
        cout << "4. Show number of nodes" << endl;
        cout << "5. Show height of the tree" << endl;
        cout << "6. InOrder traversal" << endl;
        cout << "7. PreOrder traversal" << endl;
        cout << "8. PostOrder traversal" << endl;
        cout << "9. Read file" << endl;
        cout << "10. Calculate height differences" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        system("cls");

        switch (choice) 
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            Tree.insertData(value);
            cout << "Element " << value << " inserted in the tree." << endl;
            break;

        case 2:
            cout << "Enter the value to search for: ";
            cin >> value;
            if (Tree.searchData(value)) 
                cout << "Element " << value << " found in the tree." << endl;
            else 
                cout << "Element " << value << " not found in the tree." << endl;
            break;

        case 3:
            cout << "Enter the value to delete: ";
            cin >> value;
            Tree.deleteData(value);
            cout << "Element " << value << " deleted from the tree." << endl;
            break;

        case 4:
            cout << "Number of nodes in the tree: " << Tree.countNode() << endl;
            break;
        
        case 5:
            cout << "Height of the tree: " << Tree.calculateHeight() << endl;
            break;

        case 6:
            cout << "InOrder traversal: ";
            Tree.inOrderTraversal();
            cout << endl;
            break;

        case 7:
            cout << "PreOrder traversal: ";
            Tree.preOrderTraversal();
            cout << endl;
            break;

        case 8:
            cout << "PostOrder traversal: ";
            Tree.postOrderTraversal();
            cout << endl;
            break;

        case 9:
            Tree.readFile(Tree,"ThousandNumbers.txt"); // Assuming readFile method only requires file name.
            break;

        case 10:
            cout << "Height differences:" << endl;
            int balanceMinusOne = 0;
            int balanceZero = 0;
            int balancePlusOne = 0;
            Tree.countBalanceFactors(balanceMinusOne, balanceZero, balancePlusOne);

            cout << "Nodes with balance factor -1: " << balanceMinusOne << endl;
            cout << "Nodes with balance factor 0: " << balanceZero << endl;
            cout << "Nodes with balance factor +1: " << balancePlusOne << endl;
            break;
        case 11:
            cout << "Exiting the program." << endl;
            return;

        default:
            cout << "Invalid option. Try again." << endl;
        }
        _getch();
    }
}

int main()
{
    menu();
}
