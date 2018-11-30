#include <vector>
#include <iostream>
#include <climits>

using Vertex = int;

struct Edge {
    Vertex from, to;
    int distance;
    Edge(Vertex _from, Vertex _to, int _distance): 
        from(_from), to(_to), distance(_distance) {}
};

class Graph {
    public:
        inline void add_edge(Vertex from, Vertex to, int distance);
        inline void add_vertex(int v);
        inline void add_vertices(int numVertices);
        bool BellmanFord(Vertex );
        Graph();
    private:
        std::vector<Edge> edges;
        std::vector<Vertex> vertices;
};

inline void Graph::add_edge(Vertex from, Vertex to, int distance) {
    edges.emplace_back(from, to, distance);
}

inline void Graph::add_vertex(int v) {
    vertices.emplace_back(v);
}

inline void Graph::add_vertices(int numVertices) {
    for (auto i = 1; i <= numVertices; ++i) {
        add_vertex(i);
    }
}

Graph::Graph() {
    add_vertices(7);
    add_edge(2,1,4);
    add_edge(3,1,5);
    add_edge(3,2,6);
    add_edge(4,2,3);
    add_edge(4,3,3);
    add_edge(5,2,10);
    add_edge(4,3,3);
    add_edge(6,3,9);
    add_edge(3,4,4);
    add_edge(5,4,6);
    add_edge(5,6,2);
    add_edge(6,4,3);
    add_edge(6,5,3);
    add_edge(7,5,2);
    add_edge(7,6,2);    
}

bool Graph::BellmanFord(Vertex s) {
    std::vector<Vertex> pi;
    std::vector<int> d;
    for (auto v: this->vertices) {
        d[v] = pi[v] = INT_MAX;
    }
    d[s] = 0;
    for (int i = 1; i < vertices.size(); ++i) {
        for (auto edge: this->edges) {
            if (d[edge.to] > d[edge.from] + edge.distance) {
                d[edge.to] > d[edge.from] + edge.distance;
                pi[edge.to] = edge.from;
            }
        }
    }
    for (auto edge: this->edges) {
        if (d[edge.to] > d[edge.from] + edge.distance)
            return false;
    }
    return true;
}


int main() {  
    Graph graph;
    graph.BellmanFord(1);

}
