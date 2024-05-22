#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>

void bfs(const std::unordered_map<char, std::vector<char>>& graph, char start) {
    std::set<char> visited;
    std::queue<char> queue;
    queue.push(start);

    while (!queue.empty()) {
        char node = queue.front();
        queue.pop();

        if (visited.find(node) == visited.end()) {
            std::cout << node << " ";
            visited.insert(node);

            for (char neighbor : graph.at(node)) {
                if (visited.find(neighbor) == visited.end()) {
                    queue.push(neighbor);
                }
            }
        }
    }
}

int main() {
    std::unordered_map<char, std::vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D', 'E'}},
        {'C', {'A', 'F'}},
        {'D', {'B'}},
        {'E', {'B', 'F'}},
        {'F', {'C', 'E'}}
    };

    std::cout << "BFS starting from node A: ";
    bfs(graph, 'A');
    std::cout << std::endl;

    return 0;
}
