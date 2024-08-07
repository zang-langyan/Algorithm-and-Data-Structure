/*
 * Prim 算法
 * 通过添加点权来获得最小权和支撑树
 * 1. 选择一个初始点x_0，i.e. k = 0
 *    初始化点权集l(x) = inf, l(x_0) = 0，以及剩余点集V = {x_i}, i != k,
 * 2. 找到剩余点集 V 中与 x_k 相邻的点，更新其 l(x_i) = min{l(x_i), e_{x_k x_i}};
 *    选择剩余点集 V 中 x = argmin{l(x) | x in V} 
 * 3. 重复 2 直到 V 空
 * */

#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int Prim(vector<vector<int>>& g){
  int k = 0;
  int n = g.size();
  
  // 初始化点权数组
  vector<int> l(n, INT_MAX);
  l[k] = 0;

  // 剩余点集
  set<int> V;
  for (int i = 1; i < n; i++){
    V.insert(i);
  }

  while (!V.empty()){
    int cur = -1, cur_min = INT_MAX;
    for (auto& v: V){
      if (g[k][v]){ // x_k v connected
        l[v] = min(l[v], g[k][v]);
      }

      if (l[v] < cur_min) {
        cur = v, cur_min = l[v];
      }
    }
    k = cur;
    V.erase(k);
  }

  int ans = 0;
  for (auto& x : l){
    ans += x;
  }
  return ans;
}

int main(){
  vector<vector<int>> edges{
    {0, 1, 1},
    {0, 2, 2},
    {0, 5, 15},
    {0, 6, 16},
    {1, 2, 10},
    {1, 3, 3},
    {1, 5, 7},
    {2, 3, 9},
    {2, 6, 6},
    {3, 4, 4},
    {4, 5, 5},
    {4, 6, 8}
  };
  int n = 7;

  vector<vector<int>> g(n, vector<int>(n, 0));
  for (auto& e: edges){
    g[e[0]][e[1]] = g[e[1]][e[0]] = e[2];
  }

  cout << "MST: " << Prim(g) << endl;
}
