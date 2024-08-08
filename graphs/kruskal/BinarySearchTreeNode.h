#pragma once
#include "List.h"

template<class T>
class BinarySearchTreeNode
{
private:
	T data;
	BinarySearchTreeNode<T>* left;
	BinarySearchTreeNode<T>* right;

	List<string> adjacencyList;
	T parent;
public:
	BinarySearchTreeNode() : left(nullptr), right(nullptr) {};
	BinarySearchTreeNode(T data) : data(data), left(nullptr), right(nullptr) {};
	~BinarySearchTreeNode() {};

	T getData() const;
	BinarySearchTreeNode<T>*& getLeft();
	BinarySearchTreeNode<T>*& getRight();
	T getParent();
	List<string>& getAdjacencyList();

	void setData(const T& data);
	void setLeft(BinarySearchTreeNode<T>* left);
	void setRight(BinarySearchTreeNode<T>* right);
	void setParent(T parent);
};

template<class T>
inline T BinarySearchTreeNode<T>::getData() const
{
	return data;
}

template<class T>
inline BinarySearchTreeNode<T>*& BinarySearchTreeNode<T>::getLeft()
{
	return left;
}

template<class T>
inline BinarySearchTreeNode<T>*& BinarySearchTreeNode<T>::getRight()
{
	return right;
}

template<class T>
inline T BinarySearchTreeNode<T>::getParent()
{
	return parent;
}

template<class T>
inline List<string>& BinarySearchTreeNode<T>::getAdjacencyList()
{
	return adjacencyList;
}

template<class T>
inline void BinarySearchTreeNode<T>::setData(const T& data)
{
	this->data = data;
}

template<class T>
inline void BinarySearchTreeNode<T>::setLeft(BinarySearchTreeNode<T>* left)
{
	this->left = left;
}

template<class T>
inline void BinarySearchTreeNode<T>::setRight(BinarySearchTreeNode<T>* right)
{
	this->right = right;
}

template<class T>
inline void BinarySearchTreeNode<T>::setParent(T parent)
{
	this->parent = parent;
}

