#pragma once
#include "Node.h"

template <class T>
class Graph
{
private:
    vector<Node<T>> nodes;
    bool DFSRecursive(T current, T destination);

public:
    Graph() {}

    const vector<Node<T>> &getNodes();
    void setNodes(const vector<Node<T>> &newNodes);
    void addNode(T value);
    void addEdge(T source, T destination);
    bool BFS(T source, T destination);
    bool DFS(T source, T destination);
    void printGraph();

private:
    Node<T> &getNode(T value)
    {
        for (auto &node : nodes)
        {
            if (node.getData() == value)
                return node;
        }
    }
};

template <class T>
inline bool Graph<T>::DFSRecursive(T current, T destination)
{
    bool found = false;

    getNode(current).setVisited(true);

    for (const auto &adjacent : getNode(current).getAdjacencyList())
    {
        if (!getNode(adjacent).getVisited())
        {
            getNode(adjacent).setParent(current);

            if (adjacent == destination)
                found = true;

            found = DFSRecursive(adjacent, destination);
        }
    }

    return found;
}

template <class T>
inline const vector<Node<T>> &Graph<T>::getNodes()
{
    return nodes;
}

template <class T>
inline void Graph<T>::setNodes(const vector<Node<T>> &newNodes)
{
    this->nodes = newNodes;
}

template <class T>
inline void Graph<T>::addNode(T value)
{
    nodes.push_back(Node<T>(value));
}

template <class T>
inline void Graph<T>::addEdge(T source, T destination)
{
    for (auto &node : nodes)
    {
        if (node.getData() == source)
            node.addAdjacent(destination);
    }
}

template <class T>
inline bool Graph<T>::BFS(T source, T destination)
{
    bool found = false;
    queue<T> queue;

    for (auto &node : nodes)
        node.setVisited(false);

    queue.push(source);
    for (auto &node : nodes)
    {
        if (node.getData() == source)
        {
            node.setVisited(true);
            break;
        }
    }

    while (!queue.empty() && !found)
    {
        T vertex = queue.front();
        queue.pop();

        for (const auto &adjacent : getNode(vertex).getAdjacencyList())
        {
            if (!getNode(adjacent).getVisited())
            {
                getNode(adjacent).setParent(vertex);

                if (adjacent == destination)
                    found = true;

                getNode(adjacent).setVisited(true);
                queue.push(adjacent);
            }
        }
    }

    return found;
}

template <class T>
inline bool Graph<T>::DFS(T source, T destination)
{
    return DFSRecursive(source, destination);
}

template <class T>
inline void Graph<T>::printGraph()
{
    for (Node<T> node : nodes)
    {
        cout << "Node " << node.getData() << ": ";

        for (Node<T> adjacent : node.getAdjacencyList())
            cout << adjacent.getData() << " ";

        cout << endl;
    }
}
