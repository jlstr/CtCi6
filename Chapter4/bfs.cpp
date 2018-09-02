#include "../Chapter3/Queue2/Queue.h"
#include "../Chapter3/Queue2/Queue.cpp"
#include <iostream>
#include <vector>
using namespace std;

/*
  SIMPLEST GRAPH Representation I could come up with
*/
enum Color { WHITE, GREY, BLACK };

struct Node {
  Node() {
    this->color = Color::WHITE;
    this->distance = -1;
  }

  Color color;
  int name;
  int distance;
  vector<Node*> adj;
};

class Graph {
  public:
  Graph(const int &V) {
    this->V = V;

    for (int i = 0; i < V; ++i) {
      Node *node = new Node();
      node->name = i;
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

void bfs(Graph&, const int&);

int main() {
  Graph graph(4);

  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(1, 3);
  graph.addEdge(2, 3);

  bfs(graph, 0);

  Node *node = graph.getNode(3);

  return 0;
}

void bfs(Graph &graph, const int &s) {
  Queue<Node*> queue;
  
  Node *node = graph.getNode(s);
  node->color = Color::GREY;
  node->distance = 0;

  queue.add(node);

  while (!queue.isEmpty()) {
    Node *u = queue.peek();
    queue.remove();

    vector<Node*>::iterator it = u->adj.begin();

    for (; it != u->adj.end(); ++it) {
      if ((*it)->color == Color::WHITE) {
        (*it)->color = Color::GREY;
        (*it)->distance = u->distance + 1;
        queue.add(*it);
      }
    }

    u->color = Color::BLACK;
  }
}