#pragma once
#include <iostream>
#include "List.h"
using namespace std;

template <class T>
class BinarySearchTreeNode
{
private:
	T element;
	BinarySearchTreeNode<T> *left;
	BinarySearchTreeNode<T> *right;

	List<string> m_list;
	T father;

public:
	BinarySearchTreeNode();
	BinarySearchTreeNode(T elem, const List<T> &l);
	~BinarySearchTreeNode();

	T getElement() const;
	void setElement(const T &elem);

	BinarySearchTreeNode<T> *&getLeft();
	void setLeft(BinarySearchTreeNode<T> *l);

	BinarySearchTreeNode<T> *&getRight();
	void setRight(BinarySearchTreeNode<T> *r);

	List<string> &list();
	List<string> getList();
	T getFather();
	void setFather(T f);

	void setList(List<string> l);

	void copiarLista(List<string> &l);
};

template <class T>
inline BinarySearchTreeNode<T>::BinarySearchTreeNode()
{
	left = nullptr;
	right = nullptr;
}

template <class T>
inline BinarySearchTreeNode<T>::BinarySearchTreeNode(T elem, const List<T> &l)
	: element(elem), m_list(l)
{
	left = nullptr;
	right = nullptr;
}

template <class T>
inline BinarySearchTreeNode<T>::~BinarySearchTreeNode()
{
}

template <class T>
inline T BinarySearchTreeNode<T>::getElement() const
{
	return element;
}

template <class T>
inline void BinarySearchTreeNode<T>::setElement(const T &elem)
{
	element = elem;
}

template <class T>
inline BinarySearchTreeNode<T> *&BinarySearchTreeNode<T>::getLeft()
{
	return left;
}

template <class T>
inline void BinarySearchTreeNode<T>::setLeft(BinarySearchTreeNode<T> *l)
{
	left = l;
}

template <class T>
inline BinarySearchTreeNode<T> *&BinarySearchTreeNode<T>::getRight()
{
	return right;
}

template <class T>
inline void BinarySearchTreeNode<T>::setRight(BinarySearchTreeNode<T> *r)
{
	right = r;
}

template <class T>
inline List<string> &BinarySearchTreeNode<T>::list()
{
	return m_list;
}

template <class T>
inline List<string> BinarySearchTreeNode<T>::getList()
{
	return m_list;
}

template <class T>
inline T BinarySearchTreeNode<T>::getFather()
{
	return father;
}

template <class T>
inline void BinarySearchTreeNode<T>::setFather(T f)
{
	father = p;
}

template <class T>
inline void BinarySearchTreeNode<T>::setList(List<string> l)
{
	this->m_list = l;
}

template <class T>
inline void BinarySearchTreeNode<T>::copiarLista(List<string> &l)
{
	ListNode<T> *temp = l.getFirst();
	ListNode<T> *curr = m_list.getFirst();
	while (temp != nullptr)
	{
		curr = new ListNode<T>(temp->getElement(), nullptr, nullptr);
		curr = curr->getNext();
		temp = temp->getNext();
	}
}
