#include <iostream>
#include "Graph.h"

using namespace std;

void displayMenu()
{
    cout << "\nMenu:\n";
    cout << "1. Insert Edge\n";
    cout << "2. Print Graph\n";
    cout << "3. Load Graph from File\n";
    cout << "4. Show Adjacency List of a Vertex\n";
    cout << "5. Kruskal's Algorithm for Minimum Spanning Tree (MST)\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    Graph<string> graph;
    int choice, weight, total = 0;
    string source, destiny, filename;

    while (true)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter source vertex: ";
            cin >> source;
            cout << "Enter destiny vertex: ";
            cin >> destiny;
            cout << "Enter weight of the edge: ";
            cin >> weight;
            graph.insert(source, destiny, weight);
            break;

        case 2:
            cout << "Graph:\n";
            graph.printGraph();
            break;

        case 3:
            cout << "Enter filename to load graph from: ";
            cin >> filename;
            graph.loadFromFile(filename);
            cout << "Graph loaded from file: " << filename << endl;
            break;

        case 4:
            cout << "Enter vertex to show adjacency list: ";
            cin >> source;
            graph.showAdjacencyList(source);
            break;

        case 5:
        {
            Graph<string> MST;
            total = 0;
            graph.kruskal(MST, total);
            cout << "Minimum Spanning Tree (MST) using Kruskal's Algorithm:\n";
            MST.printGraph();
            cout << "Total weight of MST: " << total << endl;
        }
        break;

        case 0:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
