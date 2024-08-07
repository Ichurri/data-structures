#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <class T>
class Node
{
private:
    T data;
    bool visited;
    T parent;
    vector<T> adjacencyList;

public:
    Node(T value) : data(value), visited(false), parent(T()) {}

    T getData();
    void setData(T data);
    bool getVisited();
    void setVisited(bool visited);
    T getParent();
    void setParent(T parent);
    const vector<T> &getAdjacencyList();
    void addAdjacent(T value);
};

template <class T>
inline T Node<T>::getData()
{
    return data;
}

template <class T>
inline void Node<T>::setData(T data)
{
    this->data = data;
}

template <class T>
inline bool Node<T>::getVisited()
{
    return visited;
}

template <class T>
inline void Node<T>::setVisited(bool visited)
{
    this->visited = visited;
}

template <class T>
inline T Node<T>::getParent()
{
    return parent;
}

template <class T>
inline void Node<T>::setParent(T parent)
{
    this->parent = parent;
}

template <class T>
inline const vector<T> &Node<T>::getAdjacencyList()
{
    return adjacencyList;
}

template <class T>
inline void Node<T>::addAdjacent(T value)
{
    adjacencyList.push_back(value);
}
