#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <utility>
#include <vector>
#include <climits>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v){
  for (auto& i: v){
    os << i << " "; 
  }
  os << endl;
  return os;
}

// priority_queue version
class Dijkstra 
{
private:
  int m_numNodes;
  vector<vector<int>> m_edges;
  vector<vector<pair<int,int>>> m_graph;
  vector<vector<int>> shortest_path;
public:
  explicit Dijkstra(int n_nodes, const vector<vector<int>>& edges) 
    : m_numNodes(n_nodes), m_edges(edges) 
  {
    m_graph.resize(m_numNodes);
    shortest_path.resize(m_numNodes);
    for (const auto& e : m_edges){
      int vert_start = e[0], vert_end = e[1], dist = e[2];
      m_graph[vert_start].emplace_back(vert_end, dist);
    }
  };

  vector<int> solve(int root){
    if (!shortest_path[root].empty()) return shortest_path[root];
    vector<int> ans(m_numNodes, INT_MAX);
    ans[root] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.emplace(0, root);
    while (!pq.empty()){
      auto [d, cur] = pq.top();
      pq.pop();
      if (d > ans[cur]) continue;
      for (const auto& [nxt, d2nxt]: m_graph[cur]){
        if (ans[nxt] > ans[cur] + d2nxt){
          ans[nxt] = ans[cur] + d2nxt;
          pq.emplace(ans[nxt], nxt);
        }
      }
    }
    shortest_path[root] = ans;
    return ans;
  }

};

vector<int> dijkstra(int root, const vector<vector<int>>& g){
  int n = g.size();
  vector<int> l(n, INT_MAX);
  if (root < 0 || root >= n) return l;

  vector<int> vis(n, false);
  l[root] = 0;
  vis[root] = true;
  
  vector<int> q;
  q.push_back(root);
  while (!q.empty()){
    int v = q[0];
    q.pop_back();

    // next vertex
    int cur = INT_MAX, cur_i = -1;
    for (int i = 0; i < n; i++){
      if (!vis[i] && g[v][i]){
        l[i] = min(l[i], l[v]+g[v][i]);
        if (cur > l[i]){
          cur = l[i];
          cur_i = i;
        }
      }
    }
    if (cur_i != -1){
      q.push_back(cur_i);
      vis[cur_i] = true;
    }
  }

  return l;
}


int main(){
  int n = 6;
  vector<vector<int>> edges{
    {0, 1, 7},
    {0, 2, 1},
    {1, 3, 4},
    {1, 5, 1},
    {2, 1, 5},
    {2, 4, 2},
    {2, 5, 7},
    {4, 1, 2},
    {4, 3, 5},
    {5, 4, 3}
  };

  Dijkstra shortest_path_solver = Dijkstra(n, edges);
  cout << shortest_path_solver.solve(0);


  vector<vector<int>> g(n, vector<int>(n));

  for (auto& e: edges){
    g[e[0]][e[1]] = e[2];
  }

  cout << dijkstra(0, g);
}
