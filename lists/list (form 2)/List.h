#pragma once
#define SIZE 10
#include <iostream>

using namespace std;

template<class T>
class List
{
private:
    T arr[SIZE];
    int front;
    int back;
public:
    List();
    ~List();

    bool push_front(T newElement);
    bool push_back(T newElement);
    bool pop_front();
    bool pop_back();
    void show();
    int search(T data);
    void bubbleSort();
    List<T> interleaveLists(List<T> list1, List<T> list2);
};

template<class T>
List<T>::List()
{
    front = -1;
    back = -1;
}

template<class T>
List<T>::~List()
{
}

template<class T>
bool List<T>::push_front(T newElement)
{
    bool result;
    if ((front == 0 && back == SIZE - 1) || (front == back + 1))
        result = false;
    else
    {
        result = true;
        if (front == -1)
        {
            front = 0;
            back = 0;
        }
        else if (front == 0)
            front = SIZE - 1;
        else
            front--;
        arr[front] = newElement;
    }
    return result;
}

template<class T>
bool List<T>::push_back(T newElement)
{
    bool result;
    if ((front == 0 && back == SIZE - 1) || (front == back + 1))
        result = false;
    else
    {
        result = true;
        if (back == -1)
        {
            front = 0;
            back = 0;
        }
        else if (back == SIZE - 1)
            back = 0;
        else
            back++;
        arr[back] = newElement;
    }
    return result;
}

template<class T>
bool List<T>::pop_front()
{
    bool result;
    if (front == -1)
        result = false;
    else
    {
        if (front == back)
        {
            front = -1;
            back = -1;
        }
        else if (front == SIZE - 1)
            front = 0;
        else
            front++;
        result = true;
    }
    return result;
}

template<class T>
bool List<T>::pop_back()
{
    bool result;
    if (back == -1)
        result = false;
    else
    {
        if (front == back)
        {
            front = -1;
            back = -1;
        }
        else if (back == 0)
            back = SIZE - 1;
        else
            back--;
        result = true;
    }
    return result;
}

template<class T>
void List<T>::show()
{
    if (front != -1)
    {
        int it = front;
        cout << "{";
        while (true)
        {
            cout << arr[it];
            if (it == back)
                break;
            if (it == SIZE - 1)
                it = 0;
            else
                it++;
            if (arr[it + 1] != NULL)
                cout << ",";
        }
        cout << "}" << endl;
    }
}

template<class T>
int List<T>::search(T data)
{
    int current = front;
    int pos = -1; 
    if (current != -1)
    {
        do
        {
            if (arr[current] == data)
            {
                pos = current; 
                break;
            }

            if (current == SIZE - 1)
                current = 0;
            else
                current++;
        } while (current != back);
    }

    return pos;
}

template<class T>
void List<T>::bubbleSort()
{
    {
        if (front != -1)
        {
            int i = 0;
            int current = front;
            do
            {
                i++;
                if (current == back)
                    break;
                if (current == SIZE - 1)
                    current = 0;
                else
                    current++;
            } while (current != back);
            i++;

            for (int i = 0; i < n - 1; i++)
            {
                current = front;
                for (int j = 0; j < n - i - 1; j++)
                {
                    int next;
                    if (current == back)
                        break;
                    if (current == SIZE - 1)
                        next = 0;
                    else
                        next = current + 1;

                    if (arr[current] > arr[next])
                        swap(arr[current], arr[next]);
                    current = next;
                }
            }
        }
    }

}

template<class T>
List<T> List<T>::interleaveLists(List<T> list1, List<T> list2)
{
    List<T> result;

    int current1 = list1.front;
    int current2 = list2.front;

    while (current1 != -1 || current2 != -1)
    {
        if (current1 != -1)
        {
            result.push_back(list1.arr[current1]);  
            if (current1 == list1.back)  
                current1 = -1; 
            else
                current1++; 
        }

        if (current2 != -1)
        {
            result.push_back(list2.arr[current2]);
            if (current2 == list2.back)
                current2 = -1;
            else
                current2++;
        }
    }

    return result;
}
