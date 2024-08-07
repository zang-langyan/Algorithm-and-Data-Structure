#include <iostream>
#include <vector>
using namespace std;

vector<int> aux;

void merge(vector<int>& v, int l, int mid, int r){
  int i = l, j = mid+1;
  for (int k = l; k <= r; k++){
    aux[k] = v[k];
  }
  for (int k = l; k <= r; k++){
    if (i > mid) v[k] = aux[j++];
    else if (j > r) v[k] = aux[i++];
    else if (aux[j] < aux[i]) v[k] = aux[j++];
    else v[k] = aux[i++];
  }
}

void merge_sort(vector<int>& v, int l, int r){
  if (r <= l) return;
  int mid = l + (r-l)/2;
  merge_sort(v, l, mid);
  merge_sort(v, mid+1, r);
  merge(v, l, mid, r);
}

int main(){
  vector<int> v{9,10,2,3,5,7,4,1,12,6,8};
  aux.resize(v.size());

  merge_sort(v, 0, v.size()-1);
  
  for (auto& vi: v){
    cout << vi << " ";
  }
  cout << endl;
}
