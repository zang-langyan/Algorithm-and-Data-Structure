#include "UF.h"
using namespace std;

int main(){
	vector<vector<int>> inputs{
		{4,3},
		{3,8},
		{6,5},
		{9,4},
		{2,1},
		{8,9},
		{5,0},
		{7,2},
		{6,1},
		{1,0},
		{6,7}
	};

	int N = 10;
	
	UF uf(N);

  cout << "Before Insertion: Total number of sets:" << uf.count() << endl;
	uf.print();

	for (auto& input: inputs){
		uf.insert_union(input[0], input[1]);	
	}

	cout << "After Insertion: Total number of sets:" << uf.count() << endl;
	uf.print();
}
