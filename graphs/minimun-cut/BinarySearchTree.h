#pragma once
#include "BinarySearchTreeNode.h"
#include <fstream>

template <class T>
class BST
{
private:
	BinarySearchTreeNode<T> *m_root;

	BinarySearchTreeNode<T> *insertHelper(const T &elem, const T &Ady, BinarySearchTreeNode<T> *&r);

public:
	BST();
	BST(BST<T> &other);
	~BST();

	BinarySearchTreeNode<T> *&root();
	BinarySearchTreeNode<T> *p_root() const;

	void insert(const T &elem, const T &Ady, BinarySearchTreeNode<T> *&r);
	const int countNodes(BinarySearchTreeNode<T> *r);
	const int calculateHeight(BinarySearchTreeNode<T> *r);

	BinarySearchTreeNode<T> *encontrarMenor(BinarySearchTreeNode<T> *r);
	BinarySearchTreeNode<T> *encontrarMayor(BinarySearchTreeNode<T> *r);

	BinarySearchTreeNode<T> *eliminar(const T &elemento, BinarySearchTreeNode<T> *r);

	void inOrder(BinarySearchTreeNode<T> *r);
	void postOrder(BinarySearchTreeNode<T> *r);
	void preOrder(BinarySearchTreeNode<T> *r);

	void readFile(const string &direc);

	void mirrorArb(BinarySearchTreeNode<T> *r);

	BinarySearchTreeNode<T> *buscar(const T &elem, BinarySearchTreeNode<T> *r);
	BinarySearchTreeNode<T> *copyBST(BinarySearchTreeNode<T> *r);
};

template <class T>
inline BinarySearchTreeNode<T> *BST<T>::insertHelper(const T &elem, const T &Ady, BinarySearchTreeNode<T> *&r)
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
inline BST<T>::BST()
{
	m_root = nullptr;
}

template <class T>
inline BST<T>::BST(BST<T> &o)
{
	m_root = copyBST(o.m_root);
}

template <class T>
inline BST<T>::~BST()
{
	delete m_root;
}

template <class T>
inline BinarySearchTreeNode<T> *&BST<T>::root()
{
	return m_root;
}

template <class T>
inline BinarySearchTreeNode<T> *BST<T>::p_root() const
{
	return m_root;
}

template <class T>
inline void BST<T>::insert(const T &elem, const T &Ady, BinarySearchTreeNode<T> *&r)
{
	m_root = insertHelper(elem, Ady, r);
}

template <class T>
inline const int BST<T>::countNodes(BinarySearchTreeNode<T> *r)
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
inline const int BST<T>::calculateHeight(BinarySearchTreeNode<T> *r)
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
inline BinarySearchTreeNode<T> *BST<T>::encontrarMenor(BinarySearchTreeNode<T> *r)
{
	if (r != nullptr)
	{
		if (r->getLeft() == nullptr)
			return r;
		else
			return encontrarMenor(r->getLeft());
	}
}

template <class T>
inline BinarySearchTreeNode<T> *BST<T>::encontrarMayor(BinarySearchTreeNode<T> *r)
{
	if (r != nullptr)
	{
		if (r->getRight() == nullptr)
			return r;
		else
			return encontrarMayor(r->getRight());
	}
}

template <class T>
inline BinarySearchTreeNode<T> *BST<T>::eliminar(const T &element, BinarySearchTreeNode<T> *r)
{
	if (r != nullptr)
	{
		if (element < r->getElement())
			r->setLeft(eliminar(element, r->getLeft()));
		if (element > r->getElement())
			r->setRight(eliminar(element, r->getRight()));
		if (element == r->getElement())
		{
			if (r->getRight() == nullptr && r->getLeft() == nullptr)
			{
				delete r;
				r = nullptr;
			}
			else
			{
				if (r->getRight() != nullptr)
				{
					BinarySearchTreeNode<T> *min = encontrarMenor(r->getRight());
					r->setElement(min->getElement());
					r->list() = min->list();
					r->setRight(eliminar(min->getElement(), r->getRight()));
				}
				else
				{
					if (r->getLeft() != nullptr)
					{
						BinarySearchTreeNode<T> *may = encontrarMayor(r->getLeft());
						r->setElement(may->getElement());
						r->list() = may->list();
						r->setLeft(eliminar(may->getElement(), r->getLeft()));
					}
				}
			}
		}
	}
	return r;
}

template <class T>
inline void BST<T>::inOrder(BinarySearchTreeNode<T> *r)
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
inline void BST<T>::postOrder(BinarySearchTreeNode<T> *r)
{
	if (r != nullptr)
	{
		inOrder(r->getLeft());
		inOrder(r->getRight());
		cout << r->getElement() << "|";
	}
}

template <class T>
inline void BST<T>::preOrder(BinarySearchTreeNode<T> *r)
{
	if (r != nullptr)
	{
		cout << r->getElement() << "|";
		inOrder(r->getLeft());
		inOrder(r->getRight());
	}
}

template <class T>
inline void BST<T>::readFile(const string &direc)
{
	ifstream file(direc);
	T dato;

	while (file >> dato)
		this->insert(dato, m_root);
}

template <class T>
inline void BST<T>::mirrorArb(BinarySearchTreeNode<T> *r)
{
	BinarySearchTreeNode<T> *temp;
	if (r != nullptr)
	{
		mirrorArb(r->getLeft());
		mirrorArb(r->getRight());
		temp = r->getLeft();
		r->setLeft(r->getRight());
		r->setRight(temp);
	}
}

template <class T>
inline BinarySearchTreeNode<T> *BST<T>::buscar(const T &elem, BinarySearchTreeNode<T> *r)
{
	if (r == nullptr)
		return nullptr;
	else
	{
		if (elem < r->getElement())
			return buscar(elem, r->getLeft());
		if (elem > r->getElement())
			return buscar(elem, r->getRight());
		if (elem == r->getElement())
			return r;
	}
}

template <class T>
inline BinarySearchTreeNode<T> *BST<T>::copyBST(BinarySearchTreeNode<T> *r)
{
	if (r == nullptr)
		return nullptr;
	else
	{
		BinarySearchTreeNode<T> *n = new BinarySearchTreeNode<T>(r->getElement(), r->getList());
		n->setLeft(copyBST(r->getLeft()));
		n->setRight(copyBST(r->getRight()));
		return n;
	}
}
