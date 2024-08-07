#include <iostream>
#include <vector>
using namespace std;

class UF{ // weighted quick union find
public:
	UF(int N) : n(N), N_components(N){
		id.reserve(N);
		sz = vector<int>(N,1);
		for (int i = 0; i < N; i++){
			id[i] = i;
		}
	};

	void insert_union(int p, int q){
		int pRoot = find(p);
		int qRoot = find(q);
		if (pRoot == qRoot) return;
		
		if (sz[pRoot] < sz[qRoot]) {
			id[pRoot] = qRoot;
			sz[qRoot] += sz[pRoot];
		} else {
			id[qRoot] = pRoot; 
			sz[pRoot] += sz[qRoot];
		}

		N_components--;
	};

	int find(int p){
		while(p != id[p]) p = id[p];
		return p;
	};

	bool connected(int p, int q){return find(p) == find(q);};
	
	int count(){
		return N_components;
	};

	void print(){
		for (int i = 0; i < n; i++){
			cout << i << "->" << id[i] << endl;
		}
	};
private:
	int n;
	vector<int> id;
	int N_components;
	vector<int> sz;
};	
