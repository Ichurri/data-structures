#include "BinarySearchTreeNode.h"
#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class BinarySearchTree
{
private:
	BinarySearchTreeNode<T>* root;


	BinarySearchTreeNode<T>* insertHelper(const T& data, const T& adjacent, int weight, BinarySearchTreeNode<T>*& root);
public:
	BinarySearchTree() : root(nullptr) {};
	~BinarySearchTree();

	BinarySearchTreeNode<T>*& getRoot();

	void inOrder(BinarySearchTreeNode<T>* index);


	BinarySearchTreeNode<T>* findMinorHelper(BinarySearchTreeNode<T>* index);
	BinarySearchTreeNode<T>* findGreaterHelper(BinarySearchTreeNode<T>* index);
	BinarySearchTreeNode<T>* deleteDataHelper(BinarySearchTreeNode<T>* index, T data);
	BinarySearchTreeNode<T>* searchNodeHelper(BinarySearchTreeNode<T>* index, const T& data);
	BinarySearchTreeNode<T>* searchNode(const T& data);
	void deleteData(T data);
	void insert(const T& data, const T& adjacent, int weight, BinarySearchTreeNode<T>*& root);
	const List<BinarySearchTreeNode<T>*> getNodes() const;

};

template<class T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
	delete root;
}

template<class T>
inline BinarySearchTreeNode<T>*& BinarySearchTree<T>::getRoot()
{
	return root;
}

template<class T>
inline BinarySearchTreeNode<T>* BinarySearchTree<T>::searchNode(const T& data)
{
	return searchNodeHelper(root, data);
}

template<class T>
inline void BinarySearchTree<T>::deleteData(T data)
{
	root = deleteDataHelper(root, data);
}

template<class T>
inline void BinarySearchTree<T>::insert(const T& data, const T& adjacent, int weight, BinarySearchTreeNode<T>*& root)
{
	root = insertHelper(data, adjacent, weight, root);
}

template<class T>
inline const List<BinarySearchTreeNode<T>*> BinarySearchTree<T>::getNodes() const
{
	List<BinarySearchTreeNode<T>*> nodes;
	inOrderH(root, nodes);
	return nodes;
}

template<class T>
inline void BinarySearchTree<T>::inOrder(BinarySearchTreeNode<T>* index)
{
	if (index != nullptr)
	{
		inOrder(index->getLeft());
		cout << index->getData() << endl;
		index->getAdjacencyList().show();
		inOrder(index->getRight());
	}
}

template<class T>
inline BinarySearchTreeNode<T>* BinarySearchTree<T>::findMinorHelper(BinarySearchTreeNode<T>* index)
{
	if (index == nullptr)
		return nullptr;

	if (index->getLeft() == nullptr)
		return index;

	return findMinorHelper(index->getLeft());
}

template<class T>
inline BinarySearchTreeNode<T>* BinarySearchTree<T>::findGreaterHelper(BinarySearchTreeNode<T>* index)
{
	if (index == nullptr)
		return nullptr;

	if (index->getRight() == nullptr)
		return index;

	return findGreaterHelper(index->getRight());
}

template<class T>
inline BinarySearchTreeNode<T>* BinarySearchTree<T>::deleteDataHelper(BinarySearchTreeNode<T>* index, T data)
{
	if (index == nullptr)
		return index;

	if (data < index->getData())
		index->setLeft(deleteDataHelper(index->getLeft(), data));
	else if (data > index->getData())
		index->setRight(deleteDataHelper(index->getRight(), data));
	else
	{
		if (index->getLeft() == nullptr)
		{
			BinarySearchTreeNode<T>* temp = index->getRight();
			delete index;
			return temp;
		}
		else if (index->getRight() == nullptr)
		{
			BinarySearchTreeNode<T>* temp = index->getLeft();
			delete index;
			return temp;
		}

		BinarySearchTreeNode<T>* temp = findMinorHelper(index->getRight());

		index->setData(temp->getData());

		index->setRight(deleteDataHelper(index->getRight(), temp->getData()));
	}
	return index;
}

template<class T>
inline BinarySearchTreeNode<T>* BinarySearchTree<T>::searchNodeHelper(BinarySearchTreeNode<T>* index, const T& data)
{
	if (index == nullptr)
		return nullptr;

	if (index->getData() == data)
		return index;

	if (data < index->getData())
		return searchNodeHelper(index->getLeft(), data);
	else
		return searchNodeHelper(index->getRight(), data);
}


template<class T>
inline BinarySearchTreeNode<T>* BinarySearchTree<T>::insertHelper(const T& data, const T& adjacent, int weight, BinarySearchTreeNode<T>*& index)
{
	if (index != nullptr)
	{
		if (data < index->getData())
			index->setLeft(insertHelper(data, adjacent, weight, index->getLeft()));
		else if (data > index->getData())
			index->setRight(insertHelper(data, adjacent, weight, index->getRight()));
		else
		{
			index->getAdjacencyList().insertLast(adjacent);
			index->getAdjacencyList().getLast()->setWeight(weight);
		}
		return index;
	}
	else
	{
		BinarySearchTreeNode<T>* current = new BinarySearchTreeNode<T>();
		current->setData(data);
		current->setParent(data);
		current->getAdjacencyList().insertLast(adjacent);
		current->getAdjacencyList().getLast()->setWeight(weight);
		return current;
	}
}


