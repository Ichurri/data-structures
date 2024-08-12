#pragma once
#include "BinarySearchTree.h"
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <random>
#include <chrono>
#include <time.h>
#include <algorithm>

class Graph
{
private:
	BinarySearchTree<string> graph;
	int numNodes = 0;
	vector<string> nodes;
public:
	Graph();
	Graph(Graph& other);
	~Graph() {};
	void insert(string source, string destiny);
	void readFile(const string& fileName);
	void printGraph();
	void contract(string v1);
	void contract(string v1, string v2);
	string randomNodeSource();
	string randomNodeDestiny(List<string>* lista);

	BinarySearchTree<string>& tree() { return graph; }

	int& getNumNodes() { return numNodes; }

	void printAdjacencyList(string ciudad);
	void operator=(const Graph& g);
};



inline Graph::Graph()
{
	srand(time(NULL));
}

inline Graph::Graph(Graph& other)
{
	graph.root() = graph.copyBinarySearchTree(other.graph.p_root());
	numNodes = other.numNodes;
	nodes = other.nodes;
	srand(time(NULL));
}

void Graph::insert(string source, string destiny)
{
	graph.insert(source, destiny, graph.root());

	if (find(nodes.begin(), nodes.end(), source) == nodes.end())
	{
		nodes.push_back(source);
		numNodes++;
	}
}

inline void Graph::readFile(const string& fileName)
{
	ifstream f(fileName);
	string origin, aux;
	aux = "";
	while (!f.eof())
	{
		f >> origin;
		while (f >> aux)
		{
			if (aux == "-1")
				break;
			else
				this->insert(origin, aux);
		}
	}

}

inline void Graph::printGraph()
{
	graph.inOrder(graph.root());
}

inline void Graph::contract(string v1) {
	BinarySearchTreeNode<string>* nodeV1 = this->graph.search(v1, graph.root());
	if (!nodeV1 || nodeV1->list().isEmpty()) {
		return;
	}

	string v2 = randomNodeDestiny(&(nodeV1->list()));

	BinarySearchTreeNode<string>* nodeV2 = this->graph.search(v2, graph.root());

	if (!nodeV2 || nodeV2->list().isEmpty()) 
		return;

	nodeV1->list().deleteElement(v2);

	ListNode<string>* caminante = nodeV2->list().getFirst();
	while (caminante != nullptr)
	{
		string adyacente = caminante->getElement();
		if (adyacente != v1) {
			nodeV1->list().insertFirst(adyacente);
			BinarySearchTreeNode<string>* adjNodeacente = this->graph.search(adyacente, graph.root());
			if (adjNodeacente != nullptr) 
			{
				adjNodeacente->list().insertFirst(v1);
				adjNodeacente->list().deleteElement(v2);
			}
		}
		caminante = caminante->getNext();
	}

	nodeV2->list().deleteAll();

	this->graph.deleteData(v2, graph.root());
	numNodes--;
}

inline void Graph::contract(string v1, string v2)
{
	BinarySearchTreeNode<string>* nodeV1 = this->graph.search(v1, graph.root());
	BinarySearchTreeNode<string>* nodeV2 = this->graph.search(v2, graph.root());

	ListNode<string>* Ady = nodeV2->list().getFirst();
	while (Ady != nullptr)
	{
		BinarySearchTreeNode<string>* adjNode = this->graph.search(Ady->getElement(), graph.root());
		if (Ady->getElement() != v1)
		{
			nodeV1->list().insertLast(Ady->getElement());
			cout << "Inserting: " << v1 << " in " << adjNode->getElement() << endl;
			adjNode->list().insertFirst(v1);
			cout << adjNode->getElement() << " list: ";
			adjNode->list().show();
		}
		adjNode->list().deleteElement(v2);
		Ady = Ady->getNext();
	}
	nodeV2->list().deleteAll();
	graph.deleteData(v2, graph.root());
	numNodes--;
}

inline string Graph::randomNodeSource()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distribucion(0, numNodes - 1);
	int pos = distribucion(gen);
	return nodes[pos];
}

inline string Graph::randomNodeDestiny(List<string>* lista)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distribucion(0, lista->getCant() - 1);

	int pos = distribucion(gen);
	string res;

	ListNode<string>* current = lista->getFirst();
	for (int i = 0; i < pos && current != nullptr; ++i) 
		current = current->getNext();

	if (current != nullptr) 
		res = current->getElement();

	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i] == res)
		{
			pos = i;
			break;
		}
	}

	nodes[pos] = nodes.back();
	nodes.pop_back();

	return res;
}

inline void Graph::printAdjacencyList(string ciudad)
{
	BinarySearchTreeNode<string>* node = graph.search(ciudad, graph.root());
	cout << "City: " << ciudad << endl;
	node->list().show();
}

inline void Graph::operator=(const Graph& g)
{
	graph = g.graph;
}

