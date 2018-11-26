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

bool dfs(Graph&, const int&, const int&);

int main() {
  Graph graph(4);

  graph.addEdge(0, 1);
  graph.addEdge(0, 3);
  graph.addEdge(1, 2);

  bool found = dfs(graph, 0, 3);
  cout << "Path Found? " << (found ? "TRUE" : "FALSE") << endl;

  return 0;
}

// TODO: Fix
bool dfs(Graph &graph, const int &s, const int &v) {
  Node *node = graph.getNode(s);
  node->visited = true;

  cout << s << " - " << v << endl;

  if (node->name == v)
    return true;

  vector<Node*>::iterator it = node->adj.begin();

  for (; it != node->adj.end(); ++it) {
    Node *n = *it;

    if (!n->visited)
      return dfs(graph, n->name, v);
  }

  return false;
}