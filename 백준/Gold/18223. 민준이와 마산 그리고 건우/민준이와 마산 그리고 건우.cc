#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

const int MAX_VERTICES = 5'000;
const int MAX_EDGES = 10'000;
const int MAX_DISTANCE = 10'000;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n_vertices, n_edges, point;
    std::cin >> n_vertices >> n_edges >> point;

    std::vector<std::pair<int, int>> edges[MAX_VERTICES + 1];
    int a, b, distance;
    for (int i = 0; i < n_edges; i++) {
        std::cin >> a >> b >> distance;
        edges[a].push_back({ b, distance });
        edges[b].push_back({ a, distance });
    }

    int vertices[MAX_VERTICES + 1];
    for (int i = 1; i <= n_vertices; i++) {
        vertices[i] = MAX_EDGES * MAX_DISTANCE + 1;
    }

    bool save_him = false;
    // { distance, destination, SAVE_HIM }
    std::priority_queue<
        std::tuple<int, int, bool>,
        std::vector<std::tuple<int, int, bool>>,
        std::greater<std::tuple<int, int, bool>>
    > queue;
    queue.push({0, 1, point == 1});
    while (!queue.empty()) {
        auto [cost, current, saved_him] = queue.top();
        queue.pop();

        if (current == n_vertices && vertices[current] >= cost) {
            save_him = (save_him || saved_him);
            continue;
        }

        for (auto& edge : edges[current]) {
            auto [to, distance] = edge;
            if (vertices[to] >= cost + distance) {
                vertices[to] = cost + distance;
                queue.push({ cost + distance, to, saved_him || (to == point) });
            }
        }
    }

    std::cout << (save_him ? "SAVE HIM" : "GOOD BYE") << std::endl;

    return 0;
}
