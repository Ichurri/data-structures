#include "List.h"

int main() 
{
    List<int> intList;

    intList.insert(5);
    intList.insert(10);
    intList.insert(15);

    cout << "Data in the list: ";
    intList.show();  

    intList.deleteList();

    cout << endl;
    cout << "After removing an item: ";
    intList.show();

    return 0;
}
