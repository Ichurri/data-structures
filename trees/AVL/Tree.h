#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class Tree
{
private:
    Node<T>* root;

    int calculateHeightHelper(Node<T>* node);
    Node<T>* insertDataHelper(Node<T>* index, T data);
    int balanceFactor(Node<T>* node); 
    Node<T>* rotateRight(Node<T>* y);
    Node<T>* rotateLeft(Node<T>* x);
    Node<T>* balance(Node<T>* node); 
    bool searchDataHelper(Node<T>* index, T data);
    Node<T>* findMinorHelper(Node<T>* index);
    Node<T>* findGreaterHelper(Node<T>* index);
    Node<T>* deleteDataHelper(Node<T>* index, T data);
    int countNodeHelper(Node<T>* index);
    void inOrderTraversalHelper(Node<T>* index);
    void preOrderTraversalHelper(Node<T>* index);
    void postOrderTraversalHelper(Node<T>* index);
    void countBalanceFactorsHelper(Node<T>* index, int& balanceMinusOne, int& balanceZero, int& balancePlusOne);
public:
    Tree();
    ~Tree();

    Node<T>* getRoot();

    void insertData(T data);
    void deleteData(T data);
    bool searchData(T data);
    T findMinor();
    T findGreater();
    int countNode();
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    int calculateHeight();
    void countBalanceFactors(int& balanceMinusOne, int& balanceZero, int& balancePlusOne);
    void readFile(Tree<T>& tree, const string& fileName);
};

template<class T>
inline Tree<T>::Tree()
{
    this->root = nullptr;
}

template<class T>
inline Tree<T>::~Tree()
{
    delete root;
}

template<class T>
inline Node<T>* Tree<T>::getRoot()
{
    return root;
}

template<class T>
inline int Tree<T>::calculateHeightHelper(Node<T>* node)
{
    if (node == nullptr)
        return 0;
    return 1 + std::max(calculateHeightHelper(node->getLeft()), calculateHeightHelper(node->getRight()));
}

template<class T>
inline int Tree<T>::balanceFactor(Node<T>* node)
{
    if (node == nullptr)
        return 0;
    return calculateHeightHelper(node->getLeft()) - calculateHeightHelper(node->getRight());
}

template<class T>
inline Node<T>* Tree<T>::rotateRight(Node<T>* y)
{
    Node<T>* x = y->getLeft();
    Node<T>* T2 = x->getRight();

    x->setRight(y);
    y->setLeft(T2);

    return x;
}

template<class T>
inline Node<T>* Tree<T>::rotateLeft(Node<T>* x)
{
    Node<T>* y = x->getRight();
    Node<T>* T2 = y->getLeft();

    y->setLeft(x);
    x->setRight(T2);

    return y;
}

template<class T>
inline Node<T>* Tree<T>::balance(Node<T>* node)
{
    int bf = balanceFactor(node);

    if (bf > 1) {
        if (balanceFactor(node->getLeft()) < 0) {
            node->setLeft(rotateLeft(node->getLeft()));
        }
        return rotateRight(node);
    }
    if (bf < -1) {
        if (balanceFactor(node->getRight()) > 0) {
            node->setRight(rotateRight(node->getRight()));
        }
        return rotateLeft(node);
    }

    return node;
}

template<class T>
inline Node<T>* Tree<T>::insertDataHelper(Node<T>* index, T data)
{
    if (index == nullptr)
    {
        index = new Node<T>(data);
        return index;
    }

    if (data < index->getData())
        index->setLeft(insertDataHelper(index->getLeft(), data));
    else if (data > index->getData())
        index->setRight(insertDataHelper(index->getRight(), data));

    return balance(index);
}

template<class T>
inline void Tree<T>::insertData(T data)
{
    root = insertDataHelper(root, data);
}

template<class T>
inline bool Tree<T>::searchDataHelper(Node<T>* index, T data)
{
    if (index == nullptr)
        return false;

    if (index->getData() == data)
        return true;

    if (data < index->getData())
        return searchDataHelper(index->getLeft(), data);
    else
        return searchDataHelper(index->getRight(), data);
}

template<class T>
inline bool Tree<T>::searchData(T data)
{
    return searchDataHelper(root, data);
}

template<class T>
inline Node<T>* Tree<T>::findMinorHelper(Node<T>* index)
{
    if (index == nullptr)
        return nullptr;

    if (index->getLeft() == nullptr)
        return index;

    return findMinorHelper(index->getLeft());
}


template<class T>
inline T Tree<T>::findMinor()
{
    Node<T>* minorNode = findMinorHelper(root);
    if (minorNode)
        return minorNode->getData();
    else
        cout << "El arbol esta vacio." << endl;
}

template<class T>
inline Node<T>* Tree<T>::findGreaterHelper(Node<T>* index)
{
    if (index == nullptr)
        return nullptr;

    if (index->getRight() == nullptr)
        return index;

    return findGreaterHelper(index->getRight());
}

template<class T>
inline T Tree<T>::findGreater()
{
    Node<T>* greaterNode = findGreaterHelper(root);
    if (greaterNode)
        return greaterNode->getData();
    else
        cout << "Tree is empty." << endl;
}

template<class T>
inline Node<T>* Tree<T>::deleteDataHelper(Node<T>* index, T data)
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
            Node<T>* temp = index->getRight();
            delete index;
            return temp;
        }
        else if (index->getRight() == nullptr) 
        {
            Node<T>* temp = index->getLeft();
            delete index;
            return temp;
        }
        Node<T>* temp = findMinorHelper(index->getRight());
        index->setData(temp->getData());
        index->setRight(deleteDataHelper(index->getRight(), temp->getData()));
    }
    return balance(index);
}

template<class T>
inline void Tree<T>::deleteData(T data)
{
    root = deleteDataHelper(root, data);
}

template<class T>
inline int Tree<T>::countNodeHelper(Node<T>* index)
{
    if (index == nullptr)
        return 0;

    return 1 + countNodeHelper(index->getLeft()) + countNodeHelper(index->getRight());
}

template<class T>
inline int Tree<T>::countNode()
{
    return countNodeHelper(root);
}

template<class T>
inline void Tree<T>::inOrderTraversalHelper(Node<T>* index)
{
    if (index == nullptr)
        return;

    inOrderTraversalHelper(index->getLeft());
    cout << index->getData() << " ";
    inOrderTraversalHelper(index->getRight());
}


template<class T>
inline void Tree<T>::inOrderTraversal()
{
    inOrderTraversalHelper(root);
}

template<class T>
inline void Tree<T>::preOrderTraversalHelper(Node<T>* index)
{
    if (index == nullptr)
        return;

    cout << index->getData() << " ";
    preOrderTraversalHelper(index->getLeft());
    preOrderTraversalHelper(index->getRight());
}

template<class T>
inline void Tree<T>::preOrderTraversal()
{
    preOrderTraversalHelper(root);
}

template<class T>
inline void Tree<T>::postOrderTraversalHelper(Node<T>* index)
{
    if (index == nullptr)
        return;

    postOrderTraversalHelper(index->getLeft());
    postOrderTraversalHelper(index->getRight());
    cout << index->getData() << " ";
}

template<class T>
inline void Tree<T>::countBalanceFactorsHelper(Node<T>* index, int& balanceMinusOne, int& balanceZero, int& balancePlusOne)
{
    if (index == nullptr)
        return;

    int bf = balanceFactor(index);

    if (bf == -1)
        balanceMinusOne++;
    else if (bf == 0)
        balanceZero++;
    else if (bf == 1)
        balancePlusOne++;

    countBalanceFactorsHelper(index->getLeft(), balanceMinusOne, balanceZero, balancePlusOne);
    countBalanceFactorsHelper(index->getRight(), balanceMinusOne, balanceZero, balancePlusOne);
}

template<class T>
inline void Tree<T>::postOrderTraversal()
{
    postOrderTraversalHelper(root);
}

template<class T>
inline int Tree<T>::calculateHeight()
{
    return calculateHeightHelper(root);
}

template<class T>
inline void Tree<T>::countBalanceFactors(int& balanceMinusOne, int& balanceZero, int& balancePlusOne)
{
    balanceMinusOne = 0;
    balanceZero = 0;
    balancePlusOne = 0;

    countBalanceFactorsHelper(root, balanceMinusOne, balanceZero, balancePlusOne);
}

template<class T>
inline void Tree<T>::readFile(Tree<T>& tree, const string& fileName)
{
    ifstream inputFile(fileName);
    T number;
    while (inputFile >> number)
        tree.insertData(number);
    inputFile.close();
}
