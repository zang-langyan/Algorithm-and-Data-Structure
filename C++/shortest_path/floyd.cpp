#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void floyd(vector<vector<int>>& g){
  int n = g.size();
  for (int k = 0; k < n; k++){
    for (int x = 0; x < n; x++){
      for (int y = 0; y < n; y++){
        if (g[x][k] == INT_MAX || g[k][y] == INT_MAX) continue;
        g[x][y] = min(g[x][y], g[x][k] + g[k][y]);
      }
    }
  }
}

void print(const vector<vector<int>>& g){
  for (const auto& v: g) {
    cout << "[";
    for (int i = 0; i < v.size(); i++){
      string out;
      if (v[i] == INT_MAX){
        out = "inf";
      }else{
        out = to_string(v[i]);
      }
      if (i == v.size() - 1){
        cout << out;
        break;
      }
      cout << out << ", "; 
    }
    cout << "]" << endl;
  }
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
  vector<vector<int>> g(n, vector<int>(n, INT_MAX));

  for (int i = 0; i < 6; i++){
    g[i][i] = 0;
  }
  for (auto& e: edges){
    g[e[0]][e[1]] = e[2];
  }

  floyd(g);
  print(g);
}
