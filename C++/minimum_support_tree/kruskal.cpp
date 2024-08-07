#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class UF {
public:
  UF(int _n): n_sets(_n){
    for (int i = 0; i < _n; i++){
      id.push_back(i);
      sz.push_back(1);
    }
  };

  void insert(int p, int q){
    int pRoot = find(p), qRoot = find(q); 
    if (pRoot == qRoot) return;

    if (sz[pRoot] < sz[qRoot]){
      id[p] = qRoot;
      sz[qRoot] += sz[pRoot];
    } else {
      id[q] = pRoot;
      sz[pRoot] += sz[qRoot];
    }
    n_sets--;
  }

  int find(int p){
    while (p != id[p]) p = id[p];
    return p;
  }

  bool connected(int p, int q){
    return find(p) == find(q);
  }

protected:
  int n_sets;
  vector<int> id, sz;
};


class Kruskal: public UF {
public:
  Kruskal(int _n, vector<vector<int>> _edges): UF::UF(_n), edges(_edges){
    sort(edges.begin(), edges.end(), [](auto& u, auto& v){return u[2] < v[2];}); 
  }

  int mst(){
    int ans = 0;
    for (auto& e : edges){
      if (!this->connected(e[0], e[1])){
        this->insert(e[0], e[1]);
        ans += e[2];
      }
    }
    return ans;
  }

private:
  vector<vector<int>> edges;
};


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
  Kruskal kru(n, edges);

  cout << kru.mst() << endl;
}
