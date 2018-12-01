#include <vector>
#include <iostream>
#include <climits>
#include <queue>

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
    add_edge(3,4,4);
    add_edge(4,2,3);
    add_edge(4,3,3);
    add_edge(4,5,4);
    add_edge(5,2,10);
    add_edge(5,4,6);
    add_edge(5,6,2);
    add_edge(6,3,9);
    add_edge(6,4,3);
    add_edge(6,5,3);
    add_edge(7,5,2);
    add_edge(7,6,2);    
}

void print_bf(Vertex s, int V, std::vector<Vertex> pi, std::vector<int> d) {
    std::cout << "Start Vertex: " << s << std::endl;
    std::cout << "Vertex:   ";
    for (int i = 1; i <= V; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "Parent:   ";
    for (auto parents: pi) {
        std::cout << parents << " ";
    }
    std::cout << std::endl;
    std::cout << "Distance: ";
    for (auto dist: d) {
        std::cout << dist << " ";
    }
    std::cout << std::endl;
}

bool Graph::BellmanFord(Vertex s) {
    std::vector<Vertex> pi;
    std::vector<int> d;
    for (auto v: this->vertices) {
        d.push_back(99999);
        pi.push_back(0);
    }
    d[s - 1] = 0;
    for (int i = 1; i < vertices.size(); ++i) {
        for (auto edge: this->edges) {
            if (d[edge.to - 1] > d[edge.from - 1] + edge.distance) {
                d[edge.to - 1] = d[edge.from - 1] + edge.distance;
                pi[edge.to - 1] = edge.from - 1;
            }
        }
    }
    for (auto edge: this->edges) {
        if (d[edge.to - 1] > d[edge.from - 1] + edge.distance)
            return false;
    }
    print_bf(s, vertices.size(), pi, d);    
    
    return true;
}

/*
bool Graph::Dijkstra(Vertex s) {
    std::vector<Vertex> pi;
    std::vector<int> d;
    std::priority_queue<int, std::vector<Vertex >, std::greater<int> > Q;
        for (auto v: this->vertices) {
        d.push_back(99999);
        pi.push_back(0);
    }
    d[s - 1] = 0;
    for (v) 
        Q.push(i);


    print_bf(s, vertices.size(), pi, d);    
    
    return true;
}
*/



int main() {  
    Graph graph;
    for (int i = 1; i <= 7; ++i)
        graph.BellmanFord(i);

}
