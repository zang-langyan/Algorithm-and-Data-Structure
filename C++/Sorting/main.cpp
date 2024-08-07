#include "Sorting.h"
#include <iostream>
#include <vector>
using namespace std;  

int main(){
  vector<int> sequence{20,18,1,10,15,12,7,8,5,3,9,14,16,19};

  Sort<int> seq_sort(sequence);
  
  cout << "Original Sequence:" << endl; 
  seq_sort.show();
  cout << endl;
  
  // Insertion Sort
  cout << "Insertion Sort:" << endl;
  seq_sort.insertion_sort(0,sequence.size());
  seq_sort.show();
  cout << endl; 

  cout << "Restoring..." << endl;
  seq_sort.restore();
  cout << endl;

  cout << "Insertion Sort (from 5 to 9):" << endl;
  seq_sort.insertion_sort(4, 9);
  seq_sort.show();
  cout << endl;

  cout << "Restoring..." << endl;
  seq_sort.restore();
  cout << endl;

  
  // Selection Sort
  cout << "Selection Sort:" << endl;
  seq_sort.selection_sort(0,sequence.size());
  seq_sort.show();
  cout << endl; 

  cout << "Restoring..." << endl;
  seq_sort.restore();
  cout << endl;

  cout << "Selection Sort (from 5 to 9):" << endl;
  seq_sort.selection_sort(4, 9);
  seq_sort.show();
  cout << endl;

  cout << "Restoring..." << endl;
  seq_sort.restore();
  cout << endl;

  // Quick Sort
  cout << "Quick Sort:" << endl;
  seq_sort.quick_sort(0,sequence.size());
  seq_sort.show();
  cout << endl; 

  cout << "Restoring..." << endl;
  seq_sort.restore();
  cout << endl;

  cout << "Quick Sort (from 5 to 9):" << endl;
  seq_sort.quick_sort(4, 8);
  seq_sort.show();
  cout << endl;

  cout << "Restoring..." << endl;
  seq_sort.restore();
  cout << endl;

  // Merge Sort
  cout << "Merge Sort:" << endl;
  seq_sort.merge_sort(0,sequence.size());
  seq_sort.show();
  cout << endl; 

  cout << "Restoring..." << endl;
  seq_sort.restore();
  cout << endl;

  cout << "Merge Sort (from 5 to 9):" << endl;
  seq_sort.merge_sort(4, 8);
  seq_sort.show();
  cout << endl;

  cout << "Restoring..." << endl;
  seq_sort.restore();
  cout << endl;



}
