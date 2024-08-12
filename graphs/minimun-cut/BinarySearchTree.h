#pragma once
#include "BinarySearchTreeNode.h"
#include <fstream>

template <class T>
class BinarySearchTree
{
private:
	BinarySearchTreeNode<T> *m_root;

	BinarySearchTreeNode<T> *insertHelper(const T &elem, const T &Ady, BinarySearchTreeNode<T> *&r);

public:
	BinarySearchTree();
	BinarySearchTree(BinarySearchTree<T> &other);
	~BinarySearchTree();

	BinarySearchTreeNode<T> *&root();
	BinarySearchTreeNode<T> *p_root() const;

	void insert(const T &elem, const T &Ady, BinarySearchTreeNode<T> *&r);
	const int countNodes(BinarySearchTreeNode<T> *r);
	const int calculateHeight(BinarySearchTreeNode<T> *r);

	BinarySearchTreeNode<T> *findMinor(BinarySearchTreeNode<T> *r);
	BinarySearchTreeNode<T> *findMajor(BinarySearchTreeNode<T> *r);

	BinarySearchTreeNode<T> *deleteData(const T &elemento, BinarySearchTreeNode<T> *r);

	void inOrder(BinarySearchTreeNode<T> *r);
	void postOrder(BinarySearchTreeNode<T> *r);
	void preOrder(BinarySearchTreeNode<T> *r);

	void readFile(const string &direc);

	void mirrorTree(BinarySearchTreeNode<T> *r);

	BinarySearchTreeNode<T> *search(const T &elem, BinarySearchTreeNode<T> *r);
	BinarySearchTreeNode<T> *copyBinarySearchTree(BinarySearchTreeNode<T> *r);
};

template <class T>
inline BinarySearchTreeNode<T> *BinarySearchTree<T>::insertHelper(const T &elem, const T &Ady, BinarySearchTreeNode<T> *&r)
{
	if (r != nullptr)
	{
		if (elem < r->getElement())
			r->setLeft(insertHelper(elem, Ady, r->getLeft()));
		else if (elem > r->getElement())
			r->setRight(insertHelper(elem, Ady, r->getRight()));
		else
		{
			r->list().insertLast(Ady);
		}
		return r;
	}
	else
	{
		BinarySearchTreeNode<T> *current = new BinarySearchTreeNode<T>();
		current->setElement(elem);
		current->setFather(elem);
		current->list().insertLast(Ady);
		return current;
	}
}

template <class T>
inline BinarySearchTree<T>::BinarySearchTree()
{
	m_root = nullptr;
}

template <class T>
inline BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T> &o)
{
	m_root = copyBinarySearchTree(o.m_root);
}

template <class T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
	deleteData m_root;
}

template <class T>
inline BinarySearchTreeNode<T> *&BinarySearchTree<T>::root()
{
	return m_root;
}

template <class T>
inline BinarySearchTreeNode<T> *BinarySearchTree<T>::p_root() const
{
	return m_root;
}

template <class T>
inline void BinarySearchTree<T>::insert(const T &elem, const T &Ady, BinarySearchTreeNode<T> *&r)
{
	m_root = insertHelper(elem, Ady, r);
}

template <class T>
inline const int BinarySearchTree<T>::countNodes(BinarySearchTreeNode<T> *r)
{
	if (r == nullptr)
		return 0;
	else
	{
		int resp1 = countNodes(r->getLeft());
		int resp2 = countNodes(r->getRight());
		return 1 + resp1 + resp2;
	}
}

template <class T>
inline const int BinarySearchTree<T>::calculateHeight(BinarySearchTreeNode<T> *r)
{
	int resp = 0;
	int altura1 = 0;
	int altura2 = 0;
	if (r == nullptr)
	{
		return 0;
	}
	else
	{
		altura1 = calculateHeight(r->getLeft());
		altura2 = calculateHeight(r->getRight());
		if (altura1 > altura2)
			resp = altura1 + 1;
		else
			resp = altura2 + 1;
	}
	return resp;
}

template <class T>
inline BinarySearchTreeNode<T> *BinarySearchTree<T>::findMinor(BinarySearchTreeNode<T> *r)
{
	if (r != nullptr)
	{
		if (r->getLeft() == nullptr)
			return r;
		else
			return findMinor(r->getLeft());
	}
}

template <class T>
inline BinarySearchTreeNode<T> *BinarySearchTree<T>::findMajor(BinarySearchTreeNode<T> *r)
{
	if (r != nullptr)
	{
		if (r->getRight() == nullptr)
			return r;
		else
			return findMajor(r->getRight());
	}
}

template <class T>
inline BinarySearchTreeNode<T> *BinarySearchTree<T>::deleteData(const T &element, BinarySearchTreeNode<T> *r)
{
	if (r != nullptr)
	{
		if (element < r->getElement())
			r->setLeft(deleteData(element, r->getLeft()));
		if (element > r->getElement())
			r->setRight(deleteData(element, r->getRight()));
		if (element == r->getElement())
		{
			if (r->getRight() == nullptr && r->getLeft() == nullptr)
			{
				deleteData r;
				r = nullptr;
			}
			else
			{
				if (r->getRight() != nullptr)
				{
					BinarySearchTreeNode<T> *min = findMinor(r->getRight());
					r->setElement(min->getElement());
					r->list() = min->list();
					r->setRight(deleteData(min->getElement(), r->getRight()));
				}
				else
				{
					if (r->getLeft() != nullptr)
					{
						BinarySearchTreeNode<T> *may = findMajor(r->getLeft());
						r->setElement(may->getElement());
						r->list() = may->list();
						r->setLeft(deleteData(may->getElement(), r->getLeft()));
					}
				}
			}
		}
	}
	return r;
}

template <class T>
inline void BinarySearchTree<T>::inOrder(BinarySearchTreeNode<T> *r)
{
	if (r != nullptr)
	{
		inOrder(r->getLeft());
		cout << r->getElement() << "|" << endl;
		r->list().show();
		inOrder(r->getRight());
	}
}

template <class T>
inline void BinarySearchTree<T>::postOrder(BinarySearchTreeNode<T> *r)
{
	if (r != nullptr)
	{
		inOrder(r->getLeft());
		inOrder(r->getRight());
		cout << r->getElement() << "|";
	}
}

template <class T>
inline void BinarySearchTree<T>::preOrder(BinarySearchTreeNode<T> *r)
{
	if (r != nullptr)
	{
		cout << r->getElement() << "|";
		inOrder(r->getLeft());
		inOrder(r->getRight());
	}
}

template <class T>
inline void BinarySearchTree<T>::readFile(const string &direc)
{
	ifstream file(direc);
	T dato;

	while (file >> dato)
		this->insert(dato, m_root);
}

template <class T>
inline void BinarySearchTree<T>::mirrorTree(BinarySearchTreeNode<T> *r)
{
	BinarySearchTreeNode<T> *temp;
	if (r != nullptr)
	{
		mirrorTree(r->getLeft());
		mirrorTree(r->getRight());
		temp = r->getLeft();
		r->setLeft(r->getRight());
		r->setRight(temp);
	}
}

template <class T>
inline BinarySearchTreeNode<T> *BinarySearchTree<T>::search(const T &elem, BinarySearchTreeNode<T> *r)
{
	if (r == nullptr)
		return nullptr;
	else
	{
		if (elem < r->getElement())
			return search(elem, r->getLeft());
		if (elem > r->getElement())
			return search(elem, r->getRight());
		if (elem == r->getElement())
			return r;
	}
}

template <class T>
inline BinarySearchTreeNode<T> *BinarySearchTree<T>::copyBinarySearchTree(BinarySearchTreeNode<T> *r)
{
	if (r == nullptr)
		return nullptr;
	else
	{
		BinarySearchTreeNode<T> *n = new BinarySearchTreeNode<T>(r->getElement(), r->getList());
		n->setLeft(copyBinarySearchTree(r->getLeft()));
		n->setRight(copyBinarySearchTree(r->getRight()));
		return n;
	}
}
