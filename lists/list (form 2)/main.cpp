#include "List.h"

int main()
{
    List<int> intList;

    intList.push_front(10);
    intList.push_back(20);
    intList.push_front(5);
    intList.push_back(25);

    cout << "List after pushing elements:" << endl;
    intList.show();

    intList.pop_front();
    intList.pop_back();

    cout << "List after popping elements:" << endl;
    intList.show();

    int position = intList.search(20);
    if (position != -1)
        cout << "Element 20 found at position: " << position << endl;
    else
        cout << "Element 20 not found in the list." << endl;

    intList.bubbleSort();
    cout << "List after sorting:" << endl;
    intList.show();

    List<int> anotherList;
    anotherList.push_back(30);
    anotherList.push_back(40);
    anotherList.push_back(50);

    List<int> interleavedList = intList.interleaveLists(intList, anotherList);
    cout << "Interleaved list:" << endl;
    interleavedList.show();

    return 0;
}
