#include <iostream>
#include "Hash.h"

using namespace std;

void displayMenu()
{
    cout << "\nMenu:\n";
    cout << "1. Insert Data\n";
    cout << "2. Delete Data\n";
    cout << "3. Search Data\n";
    cout << "4. Show Data\n";
    cout << "5. Show All Data\n";
    cout << "6. Read Data from File\n";
    cout << "7. Count Collisions\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    Hash<string> hashTable;
    int choice;
    string data, filename;
    int position;

    while (true)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            if (hashTable.insertData(data))
            {
                cout << "Data inserted successfully.\n";
            }
            else
            {
                cout << "Failed to insert data.\n";
            }
            break;
        case 2:
            cout << "Enter data to delete: ";
            cin >> data;
            if (hashTable.deleteData(data))
            {
                cout << "Data deleted successfully.\n";
            }
            else
            {
                cout << "Failed to delete data.\n";
            }
            break;
        case 3:
            cout << "Enter data to search: ";
            cin >> data;
            position = hashTable.searchData(data);
            if (position != -1)
            {
                cout << "Data found at position: " << position << endl;
            }
            else
            {
                cout << "Data not found.\n";
            }
            break;
        case 4:
            cout << "Enter data to show: ";
            cin >> data;
            hashTable.showData(data);
            break;
        case 5:
            hashTable.showAll();
            break;
        case 6:
            cout << "Enter filename to read data from: ";
            cin >> filename;
            hashTable.readFile(filename);
            cout << "Data read from file successfully.\n";
            break;
        case 7:
            hashTable.countCollisions();
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
