#include<iostream>
#include <list>
#include <vector>
#include <queue>
#include <map>
#include <fstream>
#include <stack>

using namespace std;

class GraphDFS {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    void addEdge(int v, int w);
    void DFS(int v);
};

void GraphDFS::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void GraphDFS::DFS(int v)
{

    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}


class GraphBFS {

    int V;
    vector<int>* adjacent;

public:

    GraphBFS(int V);
    void addEdge(int v, int w);
    void BFS(int s);

};


GraphBFS::GraphBFS(int V)
{
    this->V = V;
    adjacent = new vector<int>[V];
}

void GraphBFS::addEdge(int v, int w)
{
    adjacent[v].push_back(w);
    adjacent[w].push_back(v);
}

void GraphBFS::BFS(int s)
{

    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

 
    list<int> queue;


    visited[s] = true;
    queue.push_back(s);


    vector<int>::iterator i;

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for (i = adjacent[s].begin(); i != adjacent[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}


int main()
{

    GraphBFS graphB(8);
    graphB.addEdge(0, 1);
    graphB.addEdge(0, 3);
    graphB.addEdge(1, 7);
    graphB.addEdge(2, 7);
    graphB.addEdge(4, 1);
    graphB.addEdge(4, 6);
    graphB.addEdge(5, 2);
    graphB.addEdge(6, 0);

    cout << "Breadth First Traversal starting from vertex 0: \n";
    graphB.BFS(0);

    GraphDFS graphD;
    graphD.addEdge(0, 1);
    graphD.addEdge(0, 3);
    graphD.addEdge(1, 7);
    graphD.addEdge(2, 7);
    graphD.addEdge(4, 1);
    graphD.addEdge(4, 6);
    graphD.addEdge(5, 2);
    graphD.addEdge(6, 0);

    cout << endl << endl;
    cout << "Depth First Traversal starting from vertex 0: \n";
    graphD.DFS(0);

    cout << endl << endl;

    return 0;
}