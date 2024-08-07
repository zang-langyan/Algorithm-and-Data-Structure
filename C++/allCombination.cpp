#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> combinations(vector<int>& v){
	int n = v.size();
	int count = (1 << n);
	vector<vector<int>> res(count);
	for (int i = 0; i < count; i++){
		vector<int> combo;
		for (int j = 0; j < n; j++){	
			if (i & (1 << j)){
				combo.push_back(v[j]);
			}
		}
		res[i] = combo;
	}
	
	return res;
}

void print_combinations(vector<vector<int>>& combos){
	for (auto& combo:combos){
		cout << '[';
		int n = combo.size();
		for (int i = 0; i < n; i++){
			if (i == n-1) cout << combo[i];
			else cout << combo[i] << ", ";
		}
		cout << ']' << endl;
	}
}

int main(){
	// int n;
	// while (cin >> n){
	//	vector<int> v(n);
	//	for (int i = 0; i < n; i++){
	//		cin >> v[i];
	//	}
	vector<int> v{1,2,3,4,5};
		vector<vector<int>> allCombos = combinations(v);
		print_combinations(allCombos);
	// }
}
