#include <iostream>
#include "List.h"
#include "Node.h"

using namespace std;

void displayMenu()
{
    cout << "\nMenu:\n";
    cout << "1. Insert First\n";
    cout << "2. Insert Last\n";
    cout << "3. Delete First\n";
    cout << "4. Delete Last\n";
    cout << "5. Delete Data\n";
    cout << "6. Show List\n";
    cout << "7. Bubble Sort\n";
    cout << "8. Delete All\n";
    cout << "9. Search\n";
    cout << "10. Merge Two Lists\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    List<int> list;
    int choice, data, index;
    List<int> list1, list2, mergedList;

    while (true)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert at the beginning: ";
            cin >> data;
            list.insertFirst(data);
            break;
        case 2:
            cout << "Enter data to insert at the end: ";
            cin >> data;
            list.insertLast(data);
            break;
        case 3:
            if (list.deleteFirst())
                cout << "First element deleted successfully.\n";
            else
                cout << "List is empty.\n";
            break;
        case 4:
            if (list.deleteLast())
                cout << "Last element deleted successfully.\n";
            else
                cout << "List is empty.\n";
            break;
        case 5:
            cout << "Enter data to delete: ";
            cin >> data;
            if (list.deleteData(data))
                cout << "Element deleted successfully.\n";
            else
                cout << "Element not found in the list.\n";
            break;
        case 6:
            cout << "List: ";
            list.show();
            break;
        case 7:
            list.bubbleSort();
            cout << "List sorted.\n";
            break;
        case 8:
            list.deleteAll();
            cout << "All elements deleted from the list.\n";
            break;
        case 9:
            cout << "Enter data to search: ";
            cin >> data;
            list.search(data);
            break;
        case 10:
            cout << "Enter elements for first list (end with -1):\n";
            while (true)
            {
                cin >> data;
                if (data == -1)
                    break;
                list1.insertLast(data);
            }
            cout << "Enter elements for second list (end with -1):\n";
            while (true)
            {
                cin >> data;
                if (data == -1)
                    break;
                list2.insertLast(data);
            }
            mergedList = list.merge(list1, list2);
            cout << "Merged List: ";
            mergedList.show();
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
