#include <iostream>
#include <vector>
#include <climits>

using namespace std;

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

ostream& operator<<(ostream& os, const vector<int>& v){
  for (auto& i: v){
    os << i << " "; 
  }
  os << endl;
  return os;
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
  vector<vector<int>> g(n, vector<int>(n));

  for (auto& e: edges){
    g[e[0]][e[1]] = e[2];
  }

  cout << dijkstra(0, g);
}
