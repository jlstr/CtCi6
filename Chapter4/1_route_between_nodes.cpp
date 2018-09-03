#include "../Chapter3/Queue2/Queue.h"
#include "../Chapter3/Queue2/Queue.cpp"
#include <iostream>
#include <vector>
using namespace std;

struct Node {
  Node(const int &name) {
    this->name = name;
    this->visited = false;
    this->distance = -1;
  }

  bool visited;
  int name;
  int distance;
  vector<Node*> adj;
};

class Graph {
  public:
  Graph(const int &V) {
    this->V = V;

    for (int i = 0; i < V; ++i) {
      Node *node = new Node(i);
      nodes.push_back(node);
    }
  }

  Node* getNode(const int &v) {
    return nodes[v];
  }

  void addEdge(const int &u, const int &v) {
    getNode(u)->adj.push_back(getNode(v));
  }

  private:
  int V;
  vector<Node*> nodes;
};

bool bfs(Graph&, const int&, const int&);

int main() {
  Graph graph(4);

  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(0, 1);
  graph.addEdge(2, 1);
  graph.addEdge(1, 3);

  bool found = bfs(graph, 0, 3);

  cout << (found ? "TRUE" : "FALSE") << endl;

  return 0;
}

bool bfs(Graph &graph, const int &s, const int &v) {
  Queue<Node*> queue;
  Node *node = graph.getNode(s);
  node->visited = true;
  node->distance = 0;

  queue.add(node);

  // Change the variable to True if node is found.
  bool found = false;

  while (!found && !queue.isEmpty()) {
    Node *u = queue.peek();
    queue.remove();

    vector<Node*>::iterator it = u->adj.begin();

    for (; it != u->adj.end(); ++it) {
      if (!(*it)->visited) {

        if ((*it)->name == v) {
          found = true;
          break;
        }

        (*it)->visited = true;
        (*it)->distance = u->distance + 1;
        queue.add(*it);
      }
    }

    u->visited = true;
  }

  return found;
}