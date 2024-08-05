#pragma once
#define SIZE 50
#include <iostream>

using namespace std;

template <class T>
class List
{
private:
	T arr[SIZE];
	int last;
public:
	List();
	~List();
	int getLast();
	void insert(T data);
	void deleteList();
	void show();
};

template<class T>
inline List<T>::List()
{
	last = -1;
}

template<class T>
inline List<T>::~List()
{
}

template<class T>
inline int List<T>::getLast()
{
	return last;
}

template<class T>
inline void List<T>::insert(T data)
{
	if (last < SIZE - 1)
	{
		last++;
		arr[last] = data;
	}

}

template<class T>
inline void List<T>::deleteList()
{
	if (last >= 0)
		last--;
}

template<class T>
inline void List<T>::show()
{
	cout << "{";
	for (int i = 0; i <= last; i++)
	{
		cout << arr[i];
		if (i != last)
			cout << ", ";
	}
	cout << "}";
}


