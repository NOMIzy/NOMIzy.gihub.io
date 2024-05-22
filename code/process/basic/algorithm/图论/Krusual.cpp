#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int src, dest, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                ++rank[rootU];
            }
        }
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

std::vector<Edge> kruskalMST(int numVertices, std::vector<Edge>& edges) {
    std::sort(edges.begin(), edges.end());
    UnionFind uf(numVertices);
    std::vector<Edge> mst;

    for (const Edge& edge : edges) {
        if (uf.find(edge.src) != uf.find(edge.dest)) {
            uf.unite(edge.src, edge.dest);
            mst.push_back(edge);
        }
    }
    return mst;
}

int main() {
    int numVertices = 4;
    std::vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    std::vector<Edge> mst = kruskalMST(numVertices, edges);

    std::cout << "Edges in the MST:\n";
    for (const Edge& edge : mst) {
        std::cout << edge.src << " - " << edge.dest << ": " << edge.weight << "\n";
    }

    return 0;
}
