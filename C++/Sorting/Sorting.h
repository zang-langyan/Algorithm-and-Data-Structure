#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<class T = int>
class Sort{
public:
  Sort(vector<T> vec): v(vec), v_origin(vec), aux(vec), n(vec.size()){};
	~Sort() = default;

private:
  vector<T> v;
  vector<T> v_origin;
  int n;

public:
	void show(){
		for (auto& i: v){
			for (int j = 0; j < i; j++){
				cout << '-';
			}
			cout << i << endl;
		}
	}

	bool isSorted(){
		for (int i = 1; i < v.size(); i++){
			if (v[i] < v[i-1]) return false;
		}
		return true;
	}

  void restore(){
    v.assign(v_origin.begin(), v_origin.end());
  }

private:
	bool less(T& lhs, T& rhs){
		return lhs < rhs;
	}
	
	void exch(int i, int j){
		swap(v[i], v[j]);
	}

// Sorting Algorithm Functions
public:
  // 插入排序
  void insertion_sort(int l, int r){
    for (int i = l; i < r; i++){
      for (int j = i; j > l; j--){
        if (less(v[j], v[j-1])){
          exch(j,j-1);
        }
      }
    }
  };

  // 选择排序
  void selection_sort(int l, int r){
    for (int i = l; i < r; i++){
      int min_idx = i;
      for (int j = i+1; j < r; j++){
        if (less(v[j], v[min_idx])) min_idx = j;
      }
      if (min_idx!=i) exch(i,min_idx);
    }    
  }

  // 冒泡排序
  void bubble_sort(int l, int r){
    bool swapped;
    for (int i = l; i < r-1; i++){
      swapped = false;
      for (int j = l; j < r-i-1; j++){
        if (less(v[j+1], v[j])){
          exch(j,j+1);
          swapped = true;
        }
      }

      if (!swapped) break; // break the outer loop when nothing was changed in the inner loop
    }
  }
  
  // 快速排序
  void quick_sort(int l, int r){
    if (r <= l) return;
    int i = partition(l, r);
    quick_sort(l, i-1);
    quick_sort(i+1, r);
  }


private:
  int partition(int l, int r){
    int i = l-1, j = r;
    T temp = v[r];
    while (true){
      while (v[++i] < temp);
      while (temp < v[--j]){
        if (j == l) break;
      }
      if (i >= j) break;
      exch(i, j);
    }

    exch(i, r);
    return i;
  }

public:
  // 归并排序
  void merge_sort(int l, int r){
    if (r <= l) return;
    if (r >= n) r = n-1;
    int mid = l + (r-l)/2;
    merge_sort(l,mid);
    merge_sort(mid+1, r);
    merge(l, mid, r);
  }

private:
  vector<T> aux;
  void merge(int l, int mid, int r){
    // 将左右两个排序好的序列合并成一个
    int i = l;
    int j = mid+1;
    for (int k = l; k <= r; k++){
      aux[k] = v[k];
    }
    for (int k = l; k <= r; k++){
      if (i > mid){  // 左侧已遍历完
        v[k] = aux[j++]; 
      } else if (j > r){ // 右侧已遍历完
        v[k] = aux[i++]; 
      } else if (less(aux[j],aux[i])){
        v[k] = aux[j++];
      } else {
        v[k] = aux[i++];
      } 
    }
  }
};


