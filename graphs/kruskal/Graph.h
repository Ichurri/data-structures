#pragma once
#include "BinarySearchTree.h"
#include <tuple>
#include <string>
#include <queue>
#include <vector>

template<class T>
class Graph
{
private:
	BinarySearchTree<string> graph;
	int countEdges = 0;
	priority_queue<tuple<int, string, string>, vector<tuple<int, string, string>>, greater<tuple<int, string, string>>> priorityQueque;
public:
	Graph() {};
	~Graph() {};
	string cycle(string destiny);
	BinarySearchTree<string> getGraph();
	void insert(string source, string destiny, int weight);
	void printGraph();

	priority_queue<tuple<int, string, string>, vector<tuple<int, string, string>>, greater<tuple<int, string, string>>> getPriorityQueque();

	void loadFromFile(const string& filename);
	void showAdjacencyList(const T& vertex);
	void kruskal(Graph& AE, int& total);
};



template<class T>
inline string Graph<T>::cycle(string destiny)
{
	BinarySearchTreeNode<string>* node = graph.searchNodeHelper(graph.getRoot(), destiny);
	while (destiny != node->getParent())
	{
		destiny = node->getParent();
		node = graph.searchNodeHelper(graph.getRoot(), destiny);
	}
	return destiny;
}

template<class T>
inline BinarySearchTree<string> Graph<T>::getGraph()
{
	return graph;
}

template<class T>
inline void Graph<T>::insert(string source, string destiny, int weight)
{
	graph.insert(source, destiny, weight, graph.getRoot());
	graph.insert(destiny, source, weight, graph.getRoot());
	priorityQueque.push(make_tuple(weight, source, destiny));
	countEdges++;
}

template<class T>
inline void Graph<T>::printGraph()
{
	graph.inOrder(graph.getRoot());
}

template<class T>
inline priority_queue<tuple<int, string, string>, vector<tuple<int, string, string>>, greater<tuple<int, string, string>>> Graph<T>::getPriorityQueque()
{
	return priorityQueque;
}

template<class T>
inline void Graph<T>::loadFromFile(const string& filename)
{
	ifstream file(filename);
	string source, destiny;
	int weight;

	while (file >> source >> destiny >> weight) 
		insert(source, destiny, weight);

	file.close();
}

template<class T>
inline void Graph<T>::showAdjacencyList(const T& vertex)
{
	BinarySearchTreeNode<string>* node = graph.searchNode(vertex);

	if (node)
	{
		cout << "Adjacency list for node: " << vertex << ":" << endl;
		node->getAdjacencyList().show();
	}
	else
		cout << "Node: " << vertex << " not found in graph." << endl;
}

template<class T>
inline void Graph<T>::kruskal(Graph& AE, int& total)
{
	tuple<int, string, string> triplet;
	int count = 0;
	string originVertex, destinyVertex, tmp, aux;

	while (count < this->countEdges)
	{
		triplet = priorityQueque.top();
		priorityQueque.pop();
		tmp = get<1>(triplet);
		aux = get<2>(triplet);
		originVertex = cycle(tmp);
		destinyVertex = cycle(aux);
		if (destinyVertex != originVertex)
		{
			AE.insert(get<1>(triplet), get<2>(triplet), get<0>(triplet));
			total = total + get<0>(triplet);
			BinarySearchTreeNode<string>* node = graph.searchNode(destinyVertex);
			BinarySearchTreeNode<string>* tmpNode = graph.searchNode(originVertex);
			tmpNode->setParent(node->getParent());
		}
		count++;
	}
}



