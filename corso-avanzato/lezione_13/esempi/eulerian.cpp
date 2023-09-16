// nodo di destinazione, indice arco
vector<pair<int, int> > adj[100010];
void dfs(int p) {
    for (int i = 0; i < adj[p].size(); i++) {
        if (vis[adj[p][i].second] == 1) continue;
        vis[adj[p][i].second] = 1;
        dfs(adj[p][i].first);
    }
    sol.push_back(p);
}
// se ci sono 2 nodi con grado dispari, allora
// devo chiamare  dfs su uno di questi nodi