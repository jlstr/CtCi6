#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
  Node(const char &name) {
    this->name = name;
    this->visited = false;
    this->distance = -1;
  }

  bool visited;
  char name;
  int distance;
  vector<Node*> adj;
};

class Graph {
  public:
  Graph(const int &V) {
    this->V = V;
    this->letters = new char[V];

    this->letters[0] = 'a';
    this->letters[1] = 'b';
    this->letters[2] = 'c';
    this->letters[3] = 'd';
    this->letters[4] = 'e';
    this->letters[5] = 'f';

    for (int i = 0; i < V; ++i) {
      Node *node = new Node(letters[i]);
      nodes.push_back(node);
    }
  }

  Node* getNode(const char &v) {
    int index = std::distance(this->letters, std::find(this->letters, this->letters + 6, v));
    return nodes[index];
  }

  void addEdge(const char &u, const char &v) {
    getNode(u)->adj.push_back(getNode(v));
  }

  private:
  int V;
  vector<Node*> nodes;
  char *letters;
};

int main() {
  Graph graph(6);

  graph.addEdge('a', 'd');
  graph.addEdge('f', 'b');
  graph.addEdge('b', 'd');
  graph.addEdge('f', 'a');
  graph.addEdge('d', 'c');

  return 0;
}