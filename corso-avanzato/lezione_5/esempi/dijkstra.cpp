vector<pair<int, int>> adj[100000];

int dijkstra(int a, int b) {
    vector<int> dist(100000, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, a});
    while (!q.empty()) {
        auto [d, cur] = q.top();
        q.pop();
        if (dist[cur] != 1e9) continue;
        dist[cur] = d;
        for (auto [nodo, peso] : adj[cur]) {
            q.push({d + peso, nodo});
        }
    }
    return dist[b];
}