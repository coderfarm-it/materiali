vector<int> adj[100000];
vector<bool> vis(100000);

void bfs(int pos){
  // salvo i nodi in una coda
  queue<int> q;
  q.push(pos);
  while(!q.empty()){
    int cur=q.front();
    q.pop();
    // se ho già visitato il nodo mi fermo
    if(vis[cur])continue;
    vis[cur]=1;
    for(int x:adj[pos]){
      cur.push(x);
    }
  }
}