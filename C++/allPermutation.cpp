#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	while (cin >> n){
		vector<int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		
		do {
			cout << '[';
			for (int i = 0; i < n; i++){
				if (i == n-1) cout << v[i];
				else cout << v[i] << ", ";
			}
			cout << ']' << endl;
		} while (next_permutation(v.begin(), v.end()));
	}

}
