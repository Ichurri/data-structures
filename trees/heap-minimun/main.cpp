#include <iostream>
#include "Heap.h"

using namespace std;

void displayMenu()
{
    cout << "\nMenu:\n";
    cout << "1. Insert Data\n";
    cout << "2. Show Heap\n";
    cout << "3. Remove Root\n";
    cout << "4. Count Nodes\n";
    cout << "5. Calculate Height\n";
    cout << "6. Heap Sort\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    Heap<int> heap;
    int choice, data;
    vector<int> unsortedVector, sortedVector;

    while (true)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            heap.insert(data);
            break;
        case 2:
            cout << "Heap: ";
            heap.show();
            break;
        case 3:
            data = heap.remove();
            if (data != NULL)
                cout << "Removed root: " << data << endl;
            else
                cout << "Heap is empty." << endl;
            break;
        case 4:
            cout << "Number of nodes: " << heap.countNodes(1) << endl;
            break;
        case 5:
            cout << "Height of the heap: " << heap.calculateHeight(1) << endl;
            break;
        case 6:
            cout << "Enter the number of elements to sort: ";
            int numElements;
            cin >> numElements;
            unsortedVector.clear();
            sortedVector.clear();
            cout << "Enter the elements:\n";
            for (int i = 0; i < numElements; i++)
            {
                cin >> data;
                unsortedVector.push_back(data);
            }
            sortedVector = heap.heapSort(unsortedVector);
            cout << "Sorted elements: ";
            for (int i = 0; i < sortedVector.size(); i++)
            {
                cout << sortedVector[i];
                if (i < sortedVector.size() - 1)
                    cout << ", ";
            }
            cout << endl;
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
